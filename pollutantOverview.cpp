#include "pollutantOverview.hpp"
#include <QFile>
#include <QTextStream>
#include <QStandardItem>
#include <QHeaderView>
#include <QDateTime>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QLegendMarker>
#include <QComboBox>
#include <QToolTip>
#include <QDebug>

PollutantOverviewPage::PollutantOverviewPage(QWidget* parent) : QWidget(parent)
{
    // Initialize the layout
    layout = new QVBoxLayout(this);

    // Add a title
    QLabel* title = new QLabel("Pollutant Overview Page", this);
    QFont titleFont = title->font();
    titleFont.setPointSize(16);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);

    // Create a back button
    backButton = new QPushButton("Back to Dashboard", this);
    connect(backButton, &QPushButton::clicked, this, &PollutantOverviewPage::navigateToDashboard);

    // Create a search box
    searchBox = new QLineEdit(this);
    searchBox->setPlaceholderText("Search pollutants...");
    connect(searchBox, &QLineEdit::textChanged, this, &PollutantOverviewPage::filterTableData);

    // Create the table view and model
    tableView = new QTableView(this);
    dataModel = new QStandardItemModel(this);
    dataModel->setHorizontalHeaderLabels({"Sampling Point", "Date", "Compound", "Result", "Unit", "Compliance"});
    tableView->setModel(dataModel);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Set compliance delegate for color-coding
    tableView->setItemDelegateForColumn(5, new ComplianceDelegate(this));

    // Create dropdown for pollutants
    pollutantDateDropdown = new QComboBox(this);
    connect(pollutantDateDropdown, &QComboBox::currentTextChanged, this, &PollutantOverviewPage::createChartForGroup);

    // Create the chart view
    chartView = new QChartView(this);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Add widgets to the layout
    layout->addWidget(title);
    layout->addWidget(searchBox);
    layout->addWidget(tableView);
    layout->addWidget(pollutantDateDropdown);
    layout->addWidget(chartView);
    layout->addWidget(backButton);

    // Adjust layout stretch
    layout->setStretch(0, 1);
    layout->setStretch(1, 1);
    layout->setStretch(2, 4);
    layout->setStretch(3, 1);
    layout->setStretch(4, 6);
    layout->setStretch(5, 1);
}

void PollutantOverviewPage::loadCsvFile(const QString& filePath)
{
    // Clear existing data
    dataModel->removeRows(0, dataModel->rowCount());
    pollutantDateDropdown->clear();
    dropdownGroups.clear();

    // Load new data
    loadData(filePath);
    populateDropdown();
}

void PollutantOverviewPage::loadData(const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Unable to open file:" << filePath;
        return;
    }

    QTextStream in(&file);
    bool isHeader = true;

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (isHeader) {
            isHeader = false;
            continue;
        }

        QStringList columns = parseCSVLine(line);
        if (columns.size() >= 12) {
            QString pollutant = columns[5].trimmed(); 

            // Filter only specified pollutants
            if ((pollutant == "112TCEthan" || pollutant == "Chloroform" || 
                 pollutant == "Benzene" || pollutant == "Toluene")) {

                QString samplingPoint = columns[3].trimmed();
                QString date = columns[4].trimmed();
                QString result = columns[9].trimmed();
                QString unit = columns[11].trimmed();

                QList<QStandardItem*> row;

                // Helper function to create items
                auto makeItem = [](const QString& text) {
                    QStandardItem* item = new QStandardItem(text);
                    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                    return item;
                };

                row.append(makeItem(samplingPoint));
                row.append(makeItem(date));
                row.append(makeItem(pollutant));

                // Process the "Result" column
                bool ok;
                double numericResult = result.startsWith("<") ? result.mid(1).toDouble(&ok) : result.toDouble(&ok);
                if (ok) {
                    // Convert mg/L to µg/L if necessary
                    if (unit == "mg/l") {
                        numericResult *= 1000;
                        unit = "ug/l"; 
                    }
                    row.append(makeItem(QString::number(numericResult, 'f', 5)));
                } else {
                    row.append(makeItem("N/A"));
                }

                row.append(makeItem(unit));

                // Compliance check with thresholds
                QString compliance;
                if (ok) {
                    if (pollutant == "112TCEthan" || pollutant == "Chloroform") {
                        if (numericResult < 0.1)
                            compliance = "Compliant";
                        else if (qFuzzyCompare(numericResult, 0.1))
                            compliance = "Caution";
                        else
                            compliance = "Exceeds";
                    } else if (pollutant == "Benzene") {
                        if (numericResult < 1.0)
                            compliance = "Compliant";
                        else if (qFuzzyCompare(numericResult, 1.0))
                            compliance = "Caution";
                        else
                            compliance = "Exceeds";
                    } else if (pollutant == "Toluene") {
                        if (numericResult < 4.0)
                            compliance = "Compliant";
                        else if (qFuzzyCompare(numericResult, 4.0))
                            compliance = "Caution";
                        else
                            compliance = "Exceeds";
                    } else {
                        compliance = "Unknown";
                    }
                } else {
                    compliance = "Unknown";
                }
                row.append(makeItem(compliance));

                dataModel->appendRow(row);
            }
        }
    }

    file.close();
    dataModel->sort(0, Qt::AscendingOrder);
}

QStringList PollutantOverviewPage::parseCSVLine(const QString& line) const
{
    QStringList result;
    QString currentField;
    bool insideQuotes = false;

    for (QChar ch : line) {
        if (ch == '"') {
            insideQuotes = !insideQuotes;
        } else if (ch == ',' && !insideQuotes) {
            result.append(currentField.trimmed());
            currentField.clear();
        } else {
            currentField.append(ch);
        }
    }

    if (!currentField.isEmpty()) {
        result.append(currentField.trimmed());
    }

    return result;
}

void PollutantOverviewPage::populateDropdown() {
    QMap<QString, QStringList> pollutantMonthTimesMap;

    for (int i = 0; i < dataModel->rowCount(); ++i) {
        QString pollutant = dataModel->item(i, 2)->text();
        QString date = dataModel->item(i, 1)->text();

        QDateTime dateTime = QDateTime::fromString(date, "yyyy-MM-ddThh:mm:ss");
        if (!dateTime.isValid()) continue;

        QString monthYear = dateTime.toString("yyyy-MM");
        QString dayTime = dateTime.toString("yyyy-MM-dd hh:mm:ss");

        QString key = QString("%1 - %2").arg(pollutant, monthYear);
        pollutantMonthTimesMap[key].append(dayTime);
    }

    for (auto it = pollutantMonthTimesMap.begin(); it != pollutantMonthTimesMap.end(); ++it) {
        QString key = it.key();
        QStringList times = it.value();
        times.sort(); 
        int groupCount = (times.size() + 9) / 10; 

        for (int group = 0; group < groupCount; ++group) {
            QString dropdownText = QString("%1 (%2)").arg(key).arg(group + 1);
            dropdownGroups[dropdownText] = times.mid(group * 10, 10); 
            pollutantDateDropdown->addItem(dropdownText);
        }
    }

    connect(pollutantDateDropdown, &QComboBox::currentTextChanged, this, &PollutantOverviewPage::createChartForGroup);

    // Automatically set default chart using the first dropdown item
    if (pollutantDateDropdown->count() > 0) {
        QString defaultSelection = pollutantDateDropdown->itemText(0);
        createChartForGroup(defaultSelection);
    }
}

void PollutantOverviewPage::createChartForGroup(const QString& selection) {
    if (!dropdownGroups.contains(selection)) {
        qWarning() << "Invalid selection:" << selection;
        return;
    }

    QChart* chart = new QChart();
    QBarSeries* series = new QBarSeries();

    QStringList times = dropdownGroups[selection];
    times.sort(); 

    QMap<QString, QMap<QString, double>> timeToSamplingPointMap; 
    QSet<QString> uniqueSamplingPoints; 
    QStringList xAxisLabels;   

    // Populate data for chart and X-axis labels
    for (const QString& time : times) {
        for (int i = 0; i < dataModel->rowCount(); ++i) {
            QString rowDate = dataModel->item(i, 1)->text();
            QString samplingPoint = dataModel->item(i, 0)->text();
            QString result = dataModel->item(i, 3)->text();

            QDateTime dateTime = QDateTime::fromString(rowDate, "yyyy-MM-ddThh:mm:ss");
            if (!dateTime.isValid() || dateTime.toString("yyyy-MM-dd hh:mm:ss") != time) {
                continue;
            }

            bool ok;
            double value = result.toDouble(&ok);
            if (!ok) continue;

            if (!timeToSamplingPointMap.contains(time)) {
                timeToSamplingPointMap[time] = QMap<QString, double>();
            }

            timeToSamplingPointMap[time][samplingPoint] = value; 
            uniqueSamplingPoints.insert(samplingPoint);      

            // Add formatted label for X-axis
            QString formattedLabel = QString("%1\n%2")
                                         .arg(dateTime.toString("dd -")) 
                                         .arg(dateTime.toString("hh:mm:ss")); 
            if (!xAxisLabels.contains(formattedLabel)) {
                xAxisLabels.append(formattedLabel);
            }
        }
    }

    // Add bar sets for each sampling point
    for (const QString& samplingPoint : uniqueSamplingPoints) {
        QBarSet* barSet = new QBarSet(samplingPoint);

        for (const QString& time : times) {
            if (timeToSamplingPointMap[time].contains(samplingPoint)) {
                barSet->append(timeToSamplingPointMap[time][samplingPoint]);
            } else {
                barSet->append(0.0); 
            }
        }
        series->append(barSet);
    }

    chart->addSeries(series);

    // Configure X-axis with custom labels (day on one line, time on the next)
    QBarCategoryAxis* xAxis = new QBarCategoryAxis();
    xAxis->append(xAxisLabels); 
    xAxis->setLabelsAngle(0);
    xAxis->setTitleText("Day and Time (dd - hh:mm:ss)"); 
    chart->addAxis(xAxis, Qt::AlignBottom);
    series->attachAxis(xAxis);

    // Configure Y-axis (concentration)
    QValueAxis* yAxis = new QValueAxis();
    yAxis->setTitleText("Concentration (µg/L)");
    yAxis->setRange(0, 1.0); 
    chart->addAxis(yAxis, Qt::AlignLeft);
    series->attachAxis(yAxis);

    // Chart title and legend
    QString title = selection.left(selection.lastIndexOf("(")).trimmed();
    chart->setTitle(QString("Trends for %1").arg(title));
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    chartView->setChart(chart);
}

void PollutantOverviewPage::filterTableData(const QString& text)
{
    for (int i = 0; i < dataModel->rowCount(); ++i) {
        bool matches = false;
        for (int j = 0; j < dataModel->columnCount(); ++j) {
            if (dataModel->item(i, j)->text().contains(text, Qt::CaseInsensitive)) {
                matches = true;
                break;
            }
        }
        tableView->setRowHidden(i, !matches);
    }
}