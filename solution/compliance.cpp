#include "compliance.hpp"
#include <QFile>
#include <QTextStream>
#include <QHeaderView>
#include <QDebug>

ComplianceDashboardPage::ComplianceDashboardPage(QWidget* parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);

    // Title
    QLabel* title = new QLabel("Compliance Dashboard", this);
    QFont titleFont = title->font();
    titleFont.setPointSize(16);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);

    // Back to Dashboard Button
    backButton = new QPushButton("Back to Dashboard", this);
    connect(backButton, &QPushButton::clicked, this, &ComplianceDashboardPage::navigateToDashboard);

    // Dropdown for filters
    filterTypeDropdown = new QComboBox(this);
    filterTypeDropdown->addItems({"None", "Location", "Pollutant", "Compliance Status"});
    connect(filterTypeDropdown, &QComboBox::currentTextChanged, this, &ComplianceDashboardPage::updateFilterOptions);

    filterValueDropdown = new QComboBox(this);
    filterValueDropdown->addItem("None");
    connect(filterValueDropdown, &QComboBox::currentTextChanged, this, &ComplianceDashboardPage::applyFilter);

    // Table setup
    tableView = new QTableView(this);
    dataModel = new QStandardItemModel(this);
    dataModel->setHorizontalHeaderLabels({"Location", "Date", "Pollutant", "Result", "Units", "Compliance"});
    tableView->setModel(dataModel);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->setItemDelegateForColumn(5, new ComplianceDelegate(this));
    
    // Connect table row selection to update info panel
    connect(tableView->selectionModel(), &QItemSelectionModel::currentRowChanged, 
            this, &ComplianceDashboardPage::onRowSelected);

    // Info Panel for non-compliance details
    infoPanel = new QTextEdit(this);
    infoPanel->setReadOnly(true); // Make it read-only to avoid user edits
    infoPanel->setPlaceholderText("Select a row to view detailed information about compliance.");

    // Add widgets to the layout
    mainLayout->addWidget(title);
    mainLayout->addWidget(filterTypeDropdown);
    mainLayout->addWidget(filterValueDropdown);
    mainLayout->addWidget(tableView);
    mainLayout->addWidget(infoPanel);
    mainLayout->addWidget(backButton);

    // Load data
    loadData("solution/Y-2024.csv");

    // Set default view to show all records
    applyFilter("None");
}

void ComplianceDashboardPage::loadData(const QString& filePath)
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
        if (columns.size() >= 14) {
            QString location = columns[3].trimmed();
            QString date = columns[4].trimmed();
            QString pollutant = columns[5].trimmed();
            QString result = columns[9].trimmed();
            QString units = columns[11].trimmed();
            QString compliance = columns[13].trimmed().toLower() == "true" ? "Compliant" : "Non-Compliant";

            QList<QStandardItem*> row = {
                new QStandardItem(location),
                new QStandardItem(date),
                new QStandardItem(pollutant),
                new QStandardItem(result),
                new QStandardItem(units),
                new QStandardItem(compliance)
            };
            dataModel->appendRow(row);

            // Store values for filtering
            locations.insert(location);
            pollutants.insert(pollutant);
            complianceStatuses.insert(compliance);
        }
    }

    file.close();
}

QStringList ComplianceDashboardPage::parseCSVLine(const QString& line) const
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

void ComplianceDashboardPage::updateFilterOptions(const QString& filterType)
{
    filterValueDropdown->clear();
    filterValueDropdown->addItem("None"); // Default option

    QStringList sortedItems;

    if (filterType == "Location") {
        sortedItems = QStringList(locations.begin(), locations.end());
    } else if (filterType == "Pollutant") {
        sortedItems = QStringList(pollutants.begin(), pollutants.end());
    } else if (filterType == "Compliance Status") {
        sortedItems = QStringList(complianceStatuses.begin(), complianceStatuses.end());
    }

    sortedItems.sort(Qt::CaseInsensitive); // Sort the list alphabetically
    filterValueDropdown->addItems(sortedItems); // Add the sorted items to the dropdown
}

void ComplianceDashboardPage::applyFilter(const QString& filterValue)
{
    QString filterType = filterTypeDropdown->currentText();

    if (filterType == "None" || filterValue == "None") {
        // Show all rows if the filter is "None"
        for (int i = 0; i < dataModel->rowCount(); ++i) {
            tableView->setRowHidden(i, false);
        }
        return;
    }

    for (int i = 0; i < dataModel->rowCount(); ++i) {
        bool matches = false;
        if (filterType == "Location") {
            matches = dataModel->item(i, 0)->text() == filterValue;
        } else if (filterType == "Pollutant") {
            matches = dataModel->item(i, 2)->text() == filterValue;
        } else if (filterType == "Compliance Status") {
            matches = dataModel->item(i, 5)->text() == filterValue;
        }
        tableView->setRowHidden(i, !matches);
    }
}

void ComplianceDashboardPage::onRowSelected(const QModelIndex& index)
{
    if (!index.isValid())
        return;

    QString location = dataModel->item(index.row(), 0)->text();
    QString date = dataModel->item(index.row(), 1)->text();
    QString pollutant = dataModel->item(index.row(), 2)->text();
    QString compliance = dataModel->item(index.row(), 5)->text();

    QString details = QString("Location: %1\nDate: %2\nPollutant: %3\nCompliance: %4")
                        .arg(location, date, pollutant, compliance);

    if (compliance == "Non-Compliant") {
        details.append("\nPossible Causes: Elevated pollutant levels detected.\n"
                       "Historical Trend: Site has consistently exceeded safe levels.");
    }

    updateInfoPanel(details);
}

void ComplianceDashboardPage::updateInfoPanel(const QString& complianceInfo)
{
    infoPanel->setText(complianceInfo);
}