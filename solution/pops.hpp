#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QTableView>
#include <QStandardItemModel>
#include <QLineEdit>
#include <QComboBox>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QStyledItemDelegate>
#include <QPainter>

class POPsPage : public QWidget
{
    Q_OBJECT

public:
    explicit POPsPage(QWidget* parent = nullptr);

signals:
    void navigateToDashboard();

private:
    QVBoxLayout* layout;                   // Main layout for the POPs page
    QPushButton* backButton;               // Button to return to the Dashboard
    QTableView* tableView;                 // Table view for displaying POPs data
    QLineEdit* searchBox;                  // Search box for filtering table data
    QStandardItemModel* dataModel;         // Model for managing table data
    QComboBox* samplingPointDropdown;      // Dropdown for selecting sampling points
    QComboBox* dateDropdown;               // Dropdown for selecting dates
    QChartView* chartView;                 // Chart view for displaying data

    void loadData(const QString& filePath); // Load data from a CSV file
    void populateDropdown();                // Populate the dropdown with sampling points
    void createChartForPoint(const QString& point);        // Create a chart for the selected sampling point
    QString getPollutantInfo(const QString& pollutant) const; // Get information about a pollutant
    QStringList parseCSVLine(const QString& line) const;   // Parse a line from a CSV file

    // Inner class for compliance delegate
    class ComplianceDelegate : public QStyledItemDelegate {
    public:
        explicit ComplianceDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

        void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
            QString compliance = index.data().toString();
            QColor backgroundColor;

            // Use darker colors for better contrast
            if (compliance == "Compliant") {
                backgroundColor = QColor(34, 139, 34); // Dark green
            } else if (compliance == "Non-Compliant") {
                backgroundColor = QColor(178, 34, 34); // Dark red
            } else {
                backgroundColor = QColor(169, 169, 169); // Dark gray for "Unknown"
            }

            // Set background color for the cell
            painter->fillRect(option.rect, backgroundColor);

            // Draw the default text on top of the colored background
            QStyledItemDelegate::paint(painter, option, index);
        }
    };

private slots:
    void filterTableData(const QString& text); // Slot for filtering table data
};