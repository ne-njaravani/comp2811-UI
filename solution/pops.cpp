#include "pops.hpp"
#include <QFile>
#include <QTextStream>
#include <QStandardItem>
#include <QHeaderView>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QScatterSeries>
#include <QComboBox>
#include <QToolTip>
#include <QDebug>

POPsPage::POPsPage(QWidget* parent) : QWidget(parent)
{
    // Initialize the layout
    layout = new QVBoxLayout(this);

    // Add a title
    QLabel* title = new QLabel("Persistent Organic Pollutants (POPs) Page", this);
    QFont titleFont = title->font();
    titleFont.setPointSize(16);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);

    // Create a back button
    backButton = new QPushButton("Back to Dashboard", this);
    connect(backButton, &QPushButton::clicked, this, &POPsPage::navigateToDashboard);

    // Create a search box
    searchBox = new QLineEdit(this);
    searchBox->setPlaceholderText("Search...");
    connect(searchBox, &QLineEdit::textChanged, this, &POPsPage::filterTableData);

    // Create the table view and model
    tableView = new QTableView(this);
    dataModel = new QStandardItemModel(this);
    dataModel->setHorizontalHeaderLabels({"Sampling Point", "Date", "Pollutant", "Result", "Unit", "Compliance (UK/EU Regulations)"});
    tableView->setModel(dataModel);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Set custom delegate for Compliance column
    tableView->setItemDelegateForColumn(5, new ComplianceDelegate(this));

    // Create dropdown for sampling points and dates
    samplingPointDropdown = new QComboBox(this);
    connect(samplingPointDropdown, &QComboBox::currentTextChanged, this, &POPsPage::createChartForPoint);

    // Create the chart view
    chartView = new QChartView(this);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Load data and set up the charts
    loadData("solution/Y-2024.csv"); 
    populateDropdown();

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

void POPsPage::loadData(const QString& filePath)
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
            QString samplingPoint = columns[3].trimmed();
            QString date = columns[4].trimmed();
            QString pollutant = columns[6].trimmed();

            // Skip "PCB : Total"
            if (pollutant.compare("PCB : Total", Qt::CaseInsensitive) == 0) {
                continue;
            }

            QString result = columns[9].trimmed();
            QString unit = columns[11].trimmed();

            // Check for "PCB"
            if (pollutant.contains("PCB", Qt::CaseInsensitive)) {
                QList<QStandardItem*> row;

                // Create items and set them as non-editable
                auto makeItem = [](const QString& text) {
                    QStandardItem* item = new QStandardItem(text);
                    item->setFlags(item->flags() & ~Qt::ItemIsEditable); 
                    return item;
                };

                row.append(makeItem(samplingPoint));
                row.append(makeItem(date));
                row.append(makeItem(pollutant));

                // Process "Result" column
                bool ok;
                double numericResult = result.startsWith("<") ? result.mid(1).toDouble(&ok) : result.toDouble(&ok);
                if (ok) {
                    row.append(makeItem(QString::number(numericResult, 'f', 5)));
                } else {
                    row.append(makeItem("N/A"));
                }

                row.append(makeItem(unit));

                // Calculate compliance based on the "Result" column
                QString compliance;
                if (ok) {
                    compliance = numericResult <= 0.001 ? "Compliant" : "Non-Compliant";
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

QStringList POPsPage::parseCSVLine(const QString& line) const
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

void POPsPage::populateDropdown()
{
    QSet<QString> locationDateSet; // To store "Location - Date" pairs
    for (int i = 0; i < dataModel->rowCount(); ++i) {
        QString location = dataModel->item(i, 0)->text(); // Get the sampling point
        QString date = dataModel->item(i, 1)->text();     // Get the date
        QString locationDate = QString("%1 - %2").arg(location, date); // Format as "Location - Date"
        locationDateSet.insert(locationDate); // Add to set
    }

    QStringList sortedLocationDates = locationDateSet.values();
    std::sort(sortedLocationDates.begin(), sortedLocationDates.end()); // Sort alphabetically
    samplingPointDropdown->addItems(sortedLocationDates); // Add to dropdown
}

void POPsPage::createChartForPoint(const QString& pointWithDate) {
    QChart* chart = new QChart();
    QLineSeries* series = new QLineSeries();
    QMap<QString, QColor> colorMap;
    QMap<QString, QScatterSeries*> dotMap;

    // Split the selected dropdown value into location and date
    QStringList parts = pointWithDate.split(" - ");
    if (parts.size() != 2) {
        qWarning() << "Invalid dropdown selection format:" << pointWithDate;
        return;
    }
    QString location = parts[0];
    QString date = parts[1];

    // Color mapping for pollutants
    colorMap["PCB - 028"] = Qt::blue;
    colorMap["PCB - 052"] = Qt::green;
    colorMap["PCB - 101"] = Qt::yellow;
    colorMap["PCB - 153"] = Qt::cyan;
    colorMap["PCB - 180"] = Qt::magenta;
    colorMap["PCB - 156"] = Qt::darkCyan;
    colorMap["PCB - 138"] = Qt::darkGreen;
    colorMap["PCB - 105"] = Qt::darkBlue;
    colorMap["PCB - 118"] = Qt::darkRed;

    int minIndex = std::numeric_limits<int>::max();
    int maxIndex = std::numeric_limits<int>::min();
    double maxValue = 0.0;

    // Process the data and populate series
    for (int i = 0; i < dataModel->rowCount(); ++i) {
        QString rowLocation = dataModel->item(i, 0)->text();
        QString rowDate = dataModel->item(i, 1)->text();

        if (rowLocation == location && rowDate == date) {
            QString pollutant = dataModel->item(i, 2)->text();

            if (pollutant == "PCB : Total") {
                continue;
            }

            bool ok;
            double value = dataModel->item(i, 3)->text().toDouble(&ok);

            if (ok) {
                QPointF dataPoint(i, value);
                series->append(dataPoint);

                if (!dotMap.contains(pollutant)) {
                    QScatterSeries* dotSeries = new QScatterSeries();
                    dotSeries->setName(pollutant);
                    dotSeries->setMarkerSize(10);
                    dotSeries->setColor(colorMap[pollutant]);
                    dotMap[pollutant] = dotSeries;

                    // Tooltip on hover for dots
                    connect(dotSeries, &QScatterSeries::hovered, this, [this, pollutant](const QPointF& point, bool state) {
                        if (state) {
                            QString pollutantInfo = getPollutantInfo(pollutant);
                            QString tooltipText = QString("Pollutant: %1\nLevel: %2 µg/L\n%3")
                                .arg(pollutant)
                                .arg(point.y(), 0, 'f', 5)
                                .arg(pollutantInfo);
                            QToolTip::showText(QCursor::pos(), tooltipText);
                        } else {
                            QToolTip::hideText();
                        }
                    });
                }

                dotMap[pollutant]->append(dataPoint);

                minIndex = qMin(minIndex, i);
                maxIndex = qMax(maxIndex, i);
                maxValue = qMax(maxValue, value);
            }
        }
    }

    // Add a threshold line
    QLineSeries* thresholdLine = new QLineSeries();
    thresholdLine->setName("Non-Compliant Threshold");
    thresholdLine->setColor(Qt::red);
    thresholdLine->setPen(QPen(Qt::red, 2, Qt::DashLine));
    thresholdLine->append(minIndex, 0.001);
    thresholdLine->append(maxIndex, 0.001);
    chart->addSeries(thresholdLine);

    // Add the main series
    series->setName("Pollutant Levels");
    series->setColor(Qt::black);
    series->setPen(QPen(Qt::black, 2));
    chart->addSeries(series);

    // Add scatter series for each pollutant
    for (auto dotSeries : dotMap.values()) {
        chart->addSeries(dotSeries);
    }

    // Create and configure the x-axis
    QValueAxis* xAxis = new QValueAxis();
    xAxis->setLabelsVisible(false);
    double padding = (maxIndex - minIndex) * 0.02;
    if (padding < 1) padding = 1;
    xAxis->setRange(minIndex - padding, maxIndex + padding);
    chart->addAxis(xAxis, Qt::AlignBottom);

    // Create and configure the y-axis
    QValueAxis* yAxis = new QValueAxis();
    yAxis->setRange(0, maxValue + (0.1 * maxValue));
    yAxis->setTitleText("Pollutant Level (µg/L)");
    chart->addAxis(yAxis, Qt::AlignLeft);

    // Attach axes
    thresholdLine->attachAxis(xAxis);
    thresholdLine->attachAxis(yAxis);
    series->attachAxis(xAxis);
    series->attachAxis(yAxis);
    for (auto dotSeries : dotMap.values()) {
        dotSeries->attachAxis(xAxis);
        dotSeries->attachAxis(yAxis);
    }

    chart->setTitle(QString("Pollutant Levels at %1 on %2").arg(location, date));
    chartView->setChart(chart);
}

void POPsPage::filterTableData(const QString& text)
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

// Pollutant info for the tooltip
QString POPsPage::getPollutantInfo(const QString& pollutant) const {
    if (pollutant == "PCB - 028") {
        return "Health Risk: Potential endocrine disruptor.\nMonitoring: High priority in water sources due to persistence and bioaccumulation.\nSafety Level: ≤ 0.001 µg/L.";
    } else if (pollutant == "PCB - 052") {
        return "Health Risk: May cause liver toxicity.\nMonitoring: Regular assessment in industrial areas; prevalent in soil and water.\nSafety Level: ≤ 0.001 µg/L.";
    } else if (pollutant == "PCB - 101") {
        return "Health Risk: Possible reproductive toxicity.\nMonitoring: Essential in urban runoff; frequent checks in aquatic systems.\nSafety Level: ≤ 0.001 µg/L.";
    } else if (pollutant == "PCB - 153") {
        return "Health Risk: Linked to developmental delays.\nMonitoring: Critical in human biomonitoring; detected in breast milk.\nSafety Level: ≤ 0.001 µg/L.";
    } else if (pollutant == "PCB - 180") {
        return "Health Risk: Associated with skin conditions.\nMonitoring: Necessary in agriculture; can accumulate in crops.\nSafety Level: ≤ 0.001 µg/L.";
    } else if (pollutant == "PCB - 156") {
        return "Health Risk: May disrupt thyroid function.\nMonitoring: Important due to dioxin-like toxicity; analyze air and food products.\nSafety Level: ≤ 0.001 µg/L.";
    } else if (pollutant == "PCB - 138") {
        return "Health Risk: Potential neurotoxin.\nMonitoring: Persistent in sediments; requires sediment and biota sampling.\nSafety Level: ≤ 0.001 µg/L.";
    } else if (pollutant == "PCB - 105") {
        return "Health Risk: Can impair immune function.\nMonitoring: High priority in marine environments; bioaccumulates in fish.\nSafety Level: ≤ 0.001 µg/L.";
    } else if (pollutant == "PCB - 118") {
        return "Health Risk: Suspected endocrine disruptor.\nMonitoring: Found in indoor dust; necessitates indoor air quality assessments.\nSafety Level: ≤ 0.001 µg/L.";
    } else if (pollutant == "PCB : Total") {
        return "Health Risk: Includes cancer and developmental issues.\nMonitoring: Mandated under EU/UK regulations; comprehensive environmental monitoring required.\nSafety Level: ≤ 0.001 µg/L.";
    }
    return "Health Risk: Unknown.\nMonitoring: Not specified.\nSafety Level: General ≤ 0.001 µg/L.";
}