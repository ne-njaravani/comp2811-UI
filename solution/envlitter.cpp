#include "envlitter.hpp"
#include <QFile>
#include <QTextStream>
#include <QHeaderView>
#include <QDateTime>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QToolTip>
#include <QLabel>
#include <QDebug>

EnvironmentalLitterIndicatorsPage::EnvironmentalLitterIndicatorsPage(QWidget* parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this); 

    QVBoxLayout* topLayout = new QVBoxLayout();

    QLabel* title = new QLabel("Environmental Litter Indicators", this);
    QFont titleFont = title->font();
    titleFont.setPointSize(16);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);

    backButton = new QPushButton("Back to Dashboard", this);
    connect(backButton, &QPushButton::clicked, this, &EnvironmentalLitterIndicatorsPage::navigateToDashboard);

    searchBox = new QLineEdit(this);
    searchBox->setPlaceholderText("Search for litter or water types...");
    connect(searchBox, &QLineEdit::textChanged, this, &EnvironmentalLitterIndicatorsPage::filterTableData);

    tableView = new QTableView(this);
    dataModel = new QStandardItemModel(this);
    dataModel->setHorizontalHeaderLabels({"Location", "Date", "Litter Type", "Water Type", "Result", "Compliance"});
    tableView->setModel(dataModel);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->setItemDelegateForColumn(5, new ComplianceDelegate(this));

    litterDateDropdown = new QComboBox(this);
    connect(litterDateDropdown, &QComboBox::currentTextChanged, this, &EnvironmentalLitterIndicatorsPage::displayTablesForSelection);

    topLayout->addWidget(title);
    topLayout->addWidget(searchBox);
    topLayout->addWidget(tableView);
    topLayout->addWidget(litterDateDropdown);
    topLayout->addWidget(backButton);

    scrollArea = new QScrollArea(this);
    scrollAreaWidget = new QWidget(this);
    scrollAreaLayout = new QVBoxLayout(scrollAreaWidget);
    scrollAreaWidget->setLayout(scrollAreaLayout);

    scrollArea->setWidget(scrollAreaWidget);
    scrollArea->setWidgetResizable(true); 

    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(scrollArea);

    loadData("solution/Y-2024.csv");
    populateDropdown();
}

void EnvironmentalLitterIndicatorsPage::loadData(const QString& filePath)
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
        if (columns.size() >= 13) {
            QString litterType = columns[5].trimmed();
            QString waterType = columns[12].trimmed();

            // Only process specific litter types
            if (litterType == "BWP - O.L." || litterType == "BWP - A.F.") {
                QString location = columns[3].trimmed();
                QString date = columns[4].trimmed();
                QString result = columns[9].trimmed();
                QString compliance = result.toDouble() < 0.05 ? "Compliant" : "Non-Compliant";

                QList<QStandardItem*> row = {
                    new QStandardItem(location),
                    new QStandardItem(date),
                    new QStandardItem(litterType),
                    new QStandardItem(waterType),
                    new QStandardItem(result),
                    new QStandardItem(compliance)
                };
                dataModel->appendRow(row);

                QString key = litterType + " | " + waterType;
                dropdownGroups[key].append(date);
            }
        }
    }

    file.close();
}

QStringList EnvironmentalLitterIndicatorsPage::parseCSVLine(const QString& line) const
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

void EnvironmentalLitterIndicatorsPage::populateDropdown()
{
    litterDateDropdown->clear();
    for (auto it = dropdownGroups.begin(); it != dropdownGroups.end(); ++it) {
        litterDateDropdown->addItem(it.key());
    }

    if (litterDateDropdown->count() > 0) {
        displayTablesForSelection(litterDateDropdown->currentText());
    }
}

void EnvironmentalLitterIndicatorsPage::displayTablesForSelection(const QString& selection)
{
    if (!dropdownGroups.contains(selection)) {
        qWarning() << "Invalid selection: " << selection;
        return;
    }

    // Clear existing charts in the scroll area
    QLayoutItem* item;
    while ((item = scrollAreaLayout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }

    QMap<QString, QMap<QString, double>> locationDataMap;

    // Group data by location and date for the selected pollutant-water source
    for (int i = 0; i < dataModel->rowCount(); ++i) {
        QString litterTypeWaterType = dataModel->item(i, 2)->text() + " | " + dataModel->item(i, 3)->text();
        if (litterTypeWaterType == selection) {
            QString location = dataModel->item(i, 0)->text();
            QString dateStr = dataModel->item(i, 1)->text();
            QString resultStr = dataModel->item(i, 4)->text();

            bool ok;
            double result = resultStr.toDouble(&ok);
            if (ok) {
                locationDataMap[location][dateStr] = result;
            }
        }
    }

    // Create a bar chart for each location and add it to the scrollable layout
    for (auto it = locationDataMap.begin(); it != locationDataMap.end(); ++it) {
        QString location = it.key();
        QMap<QString, double> dateToResultMap = it.value();

        QChart* chart = new QChart();
        QBarSeries* series = new QBarSeries();

        QBarSet* barSet = new QBarSet("Results");
        QStringList categories;

        for (auto dateIt = dateToResultMap.begin(); dateIt != dateToResultMap.end(); ++dateIt) {
            QDateTime date = QDateTime::fromString(dateIt.key(), "yyyy-MM-ddThh:mm:ss");
            categories.append(date.toString("MM:dd"));
            barSet->append(dateIt.value());
        }

        series->append(barSet);
        chart->addSeries(series);

        // Configure X-axis
        QBarCategoryAxis* xAxis = new QBarCategoryAxis();
        xAxis->append(categories);
        xAxis->setTitleText("Date (MM:dd)");
        chart->addAxis(xAxis, Qt::AlignBottom);
        series->attachAxis(xAxis);

        // Configure Y-axis
        QValueAxis* yAxis = new QValueAxis();
        yAxis->setTitleText("Result");
        yAxis->setRange(0, 3.0);
        chart->addAxis(yAxis, Qt::AlignLeft);
        series->attachAxis(yAxis);

        chart->setTitle("Location: " + location);

        // Add chart to the scrollable area
        QChartView* locationChartView = new QChartView(chart, this);
        locationChartView->setRenderHint(QPainter::Antialiasing);
        locationChartView->setMinimumSize(800, 600); 
        scrollAreaLayout->addWidget(locationChartView);
    }
}


void EnvironmentalLitterIndicatorsPage::updateChartForLocation(QStandardItemModel* locationModel)
{
    QChart* chart = new QChart();
    QLineSeries* series = new QLineSeries();

    // Extract data for the chart
    QMap<QDateTime, double> dateToResultMap;
    for (int i = 0; i < locationModel->rowCount(); ++i) {
        QString dateStr = locationModel->item(i, 1)->text();
        QString resultStr = locationModel->item(i, 4)->text();
        QDateTime date = QDateTime::fromString(dateStr, "yyyy-MM-ddThh:mm:ss");
        bool ok;
        double result = resultStr.toDouble(&ok);
        if (ok && date.isValid()) {
            dateToResultMap[date] = result;
        }
    }

    // Populate the series with data
    for (auto it = dateToResultMap.begin(); it != dateToResultMap.end(); ++it) {
        series->append(it.key().toMSecsSinceEpoch(), it.value());
    }

    // Configure X-axis (Date-Time)
    QDateTimeAxis* xAxis = new QDateTimeAxis();
    xAxis->setFormat("dd-MM hh:mm");
    xAxis->setTitleText("Date & Time");
    chart->addAxis(xAxis, Qt::AlignBottom);
    series->attachAxis(xAxis);

    // Configure Y-axis (Result)
    QValueAxis* yAxis = new QValueAxis();
    yAxis->setTitleText("Result");
    yAxis->setRange(0, 1.0);
    chart->addAxis(yAxis, Qt::AlignLeft);
    series->attachAxis(yAxis);

    // Add the series to the chart
    chart->addSeries(series);
    chart->setTitle("Trend for Selected Location");

    // Dynamically add the chart to the scroll area
    QChartView* dynamicChartView = new QChartView(chart, this);
    dynamicChartView->setRenderHint(QPainter::Antialiasing);
    scrollAreaLayout->addWidget(dynamicChartView);
}

void EnvironmentalLitterIndicatorsPage::clearLocationSpecificCharts()
{
    // Remove only dynamically added charts
    while (layout->count() > 6) { 
        QLayoutItem* item = layout->takeAt(6); 
        if (item->widget()) {
            delete item->widget(); 
        }
        delete item;
    }
}

void EnvironmentalLitterIndicatorsPage::filterTableData(const QString& text)
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