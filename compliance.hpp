#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QTableView>
#include <QStandardItemModel>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QSet>
#include <QStringList>
#include <QTextEdit>

class ComplianceDashboardPage : public QWidget
{
    Q_OBJECT

public:
    // Constructor
    explicit ComplianceDashboardPage(QWidget* parent = nullptr);

    // New public method to provide CSV file to loadData
    void loadCsvFile(const QString& filePath);

signals:
    // Signal to navigate back to the dashboard
    void navigateToDashboard();

private:
    // Widgets for the page
    QVBoxLayout* mainLayout;
    QTableView* tableView;
    QStandardItemModel* dataModel; // Ensure this is correctly defined
    QComboBox* filterTypeDropdown;
    QComboBox* filterValueDropdown;
    QPushButton* backButton;
    QTextEdit* infoPanel;

    // Data containers for filtering
    QSet<QString> locations;
    QSet<QString> pollutants;
    QSet<QString> complianceStatuses;

    // Methods for functionality
    void loadData(const QString& filePath);             
    void updateFilterOptions(const QString& filterType); 
    void applyFilter(const QString& filterValue);       

    // Methods for dynamic info panel updates
    void onRowSelected(const QModelIndex& index); // Add declaration
    void updateInfoPanel(const QString& complianceInfo); // Add declaration

    // Parse a CSV line to split fields, considering commas inside quotes
    QStringList parseCSVLine(const QString& line) const; 

    // Delegate for coloring table rows based on compliance
    class ComplianceDelegate : public QStyledItemDelegate {
    public:
        explicit ComplianceDelegate(QObject* parent = nullptr)
            : QStyledItemDelegate(parent) {}

        void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
            QString compliance = index.data().toString();
            QColor backgroundColor;

            // Set background color based on compliance status
            if (compliance == "Compliant") {
                backgroundColor = QColor(34, 139, 34); // Green for compliant
            } else if (compliance == "Non-Compliant") {
                backgroundColor = QColor(178, 34, 34); // Red for non-compliant
            } else {
                backgroundColor = option.palette.base().color(); // Default background
            }

            painter->fillRect(option.rect, backgroundColor);
            QStyledItemDelegate::paint(painter, option, index);
        }
    };
};