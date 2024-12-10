#include "fluorinated.hpp"
#include <QFile>
#include <QTextStream>
#include <QStandardItem>
#include <QHeaderView>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QLegendMarker>
#include <QComboBox>
#include <QToolTip>
#include <QDebug>
#include <QDateTime>

FluorinatedPage::FluorinatedPage(QWidget* parent) : QWidget(parent)
{
    // Initialize the layout
    layout = new QVBoxLayout(this);

    // Add a title
    QLabel* title = new QLabel("Fluorinated Compounds Page", this);
    QFont titleFont = title->font();
    titleFont.setPointSize(16);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);

    // Create a back button
    backButton = new QPushButton("Back to Dashboard", this);
    connect(backButton, &QPushButton::clicked, this, &FluorinatedPage::navigateToDashboard);

    // Create a search box
    searchBox = new QLineEdit(this);
    searchBox->setPlaceholderText("Search...");
    connect(searchBox, &QLineEdit::textChanged, this, &FluorinatedPage::filterTableData);

    // Create the table view and model
    tableView = new QTableView(this);
    dataModel = new QStandardItemModel(this);
    dataModel->setHorizontalHeaderLabels({"Sampling Point", "Date", "Compound", "Result", "Unit", "Compliance"});
    tableView->setModel(dataModel);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Set custom delegate for Compliance column
    tableView->setItemDelegateForColumn(5, new ComplianceDelegate(this));

    // Create dropdown for sampling points and dates
    samplingPointDropdown = new QComboBox(this);
    connect(samplingPointDropdown, &QComboBox::currentTextChanged, this, &FluorinatedPage::createChartForPoint);

    // Create the chart view
    chartView = new QChartView(this);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Add widgets to the layout
    layout->addWidget(title);
    layout->addWidget(searchBox);
    layout->addWidget(tableView);
    layout->addWidget(samplingPointDropdown);
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

void FluorinatedPage::loadCsvFile(const QString& filePath)
{
    // Clear the previous data
    dataModel->removeRows(0, dataModel->rowCount());
    samplingPointDropdown->clear();

    // Load new data
    loadData(filePath);
    populateDropdown();
}

void FluorinatedPage::loadData(const QString& filePath)
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
            QString compound = columns[6].trimmed();

            // Filter only fluorinated compounds
            if (compound.contains("fluoro", Qt::CaseInsensitive)) {

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
                row.append(makeItem(compound));

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

                // Compliance check
                QString compliance;
                if (ok) {
                    compliance = numericResult <= 0.1 ? "Compliant" : "Non-Compliant";
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

QStringList FluorinatedPage::parseCSVLine(const QString& line) const
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

void FluorinatedPage::populateDropdown()
{
    QSet<QString> locationDateSet;
    for (int i = 0; i < dataModel->rowCount(); ++i) {
        QString location = dataModel->item(i, 0)->text();
        QString date = dataModel->item(i, 1)->text();
        QString locationDate = QString("%1 - %2").arg(location, date);
        locationDateSet.insert(locationDate);
    }

    QStringList sortedLocationDates = locationDateSet.values();
    std::sort(sortedLocationDates.begin(), sortedLocationDates.end());
    samplingPointDropdown->addItems(sortedLocationDates);
}

void FluorinatedPage::createChartForPoint(const QString& pointWithDate)
{
    QChart* chart = new QChart();
    QLineSeries* series = new QLineSeries();
    QMap<QString, QScatterSeries*> dotMap;

    // Split the dropdown value into location and date
    int lastDashIndex = pointWithDate.lastIndexOf(" - ");
    if (lastDashIndex == -1) {
        qWarning() << "Invalid dropdown selection format:" << pointWithDate;
        return;
    }

    QString location = pointWithDate.left(lastDashIndex).trimmed();
    QString date = pointWithDate.mid(lastDashIndex + 3).trimmed();

    double maxValue = 0.0;
    bool hasData = false;
    int minIndex = std::numeric_limits<int>::max();
    int maxIndex = std::numeric_limits<int>::min();
    double padding = (maxIndex - minIndex) * 0.02;
    if (padding < 1) padding = 1;

    // Process data and populate the series
    for (int i = 0; i < dataModel->rowCount(); ++i) {
        QString rowLocation = dataModel->item(i, 0)->text();
        QString rowDate = dataModel->item(i, 1)->text();
        QString compound = dataModel->item(i, 2)->text();
        QString result = dataModel->item(i, 3)->text();
        QString unit = dataModel->item(i, 4)->text();

        if (rowLocation == location && rowDate == date) {
            bool ok;
            double value = result.toDouble(&ok);
            if (!ok) continue;

            // Convert units if necessary
            if (unit == "mg/l") value *= 1000;

            QPointF dataPoint(i + 1, value);
            series->append(dataPoint);

            // Add pollutant-specific scatter series
            if (!dotMap.contains(compound)) {
                QScatterSeries* dotSeries = new QScatterSeries();
                dotSeries->setName(""); 
                dotSeries->setMarkerSize(10);
                dotSeries->setColor(Qt::blue); 
                dotMap[compound] = dotSeries;

                // Tooltip on hover for dots
                connect(dotSeries, &QScatterSeries::hovered, this, [compound](const QPointF& point, bool state) {
                    if (state) {
                        QString tooltip = QString("Pollutant: %1\nConcentration: %2 µg/L")
                                              .arg(compound)
                                              .arg(point.y(), 0, 'f', 5);
                        QToolTip::showText(QCursor::pos(), tooltip);
                    } else {
                        QToolTip::hideText();
                    }
                });
            }

            dotMap[compound]->append(dataPoint);

            maxValue = qMax(maxValue, value);
            hasData = true;
        }
    }

    if (!hasData) {
        qWarning() << "No data found for the selected point.";
        return;
    }

    // Add threshold line
    QLineSeries* thresholdLine = new QLineSeries();
    thresholdLine->setName("Threshold (0.1 µg/L)");
    thresholdLine->setColor(Qt::red);
    thresholdLine->setPen(QPen(Qt::red, 2, Qt::DashLine));
    thresholdLine->append(series->at(0).x(), 0.1);
    thresholdLine->append(series->at(series->count() - 1).x(), 0.1); 
    chart->addSeries(thresholdLine);

    // Add the main line series
    series->setName("Concentration Levels");
    series->setColor(Qt::black);
    series->setPen(QPen(Qt::black, 2));
    chart->addSeries(series);

    // Add scatter series for each pollutant
    for (auto dotSeries : dotMap.values()) {
        chart->addSeries(dotSeries);

        // Hide legend markers for pollutant scatter series
        for (QLegendMarker* marker : chart->legend()->markers(dotSeries)) {
            marker->setVisible(false);
        }
    }

    for (int i = 0; i < dataModel->rowCount(); ++i) {
    QString rowLocation = dataModel->item(i, 0)->text();
    QString rowDate = dataModel->item(i, 1)->text();

    if (rowLocation == location && rowDate == date) {
        minIndex = qMin(minIndex, i);
        maxIndex = qMax(maxIndex, i);
        }
    }

    // Configure axes
    QValueAxis* xAxis = new QValueAxis();
    xAxis->setTitleText("Index"); 
    xAxis->setLabelsVisible(true); 
    xAxis->setRange(minIndex - padding, maxIndex + padding); 
    chart->addAxis(xAxis, Qt::AlignBottom);
    
    QValueAxis* yAxis = new QValueAxis();
    yAxis->setRange(0, maxValue + (0.1 * maxValue));
    yAxis->setTitleText("Concentration (µg/L)");
    chart->addAxis(yAxis, Qt::AlignLeft);

    series->attachAxis(xAxis);
    series->attachAxis(yAxis);
    thresholdLine->attachAxis(xAxis);
    thresholdLine->attachAxis(yAxis);
    for (auto dotSeries : dotMap.values()) {
        dotSeries->attachAxis(xAxis);
        dotSeries->attachAxis(yAxis);
    }

    // Configure chart title
    chart->setTitle(QString("Concentration Trends at %1 on %2").arg(location, date));
    chartView->setChart(chart);
}

void FluorinatedPage::filterTableData(const QString& text)
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