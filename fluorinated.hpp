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
#include <QtCharts/QScatterSeries>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QDateTime> // Added this to fix incomplete type errors

class FluorinatedPage : public QWidget
{
    Q_OBJECT

public:
    // Constructor
    explicit FluorinatedPage(QWidget* parent = nullptr);

    // New method to provide a CSV file to the page
    void loadCsvFile(const QString& filePath);

signals:
    // Signal to navigate back to the dashboard
    void navigateToDashboard();

private:
    // Widgets for the page
    QVBoxLayout* layout;                  
    QPushButton* backButton;              
    QTableView* tableView;                 
    QLineEdit* searchBox;                 
    QStandardItemModel* dataModel;        
    QComboBox* samplingPointDropdown;    
    QChartView* chartView;                 
    QString getPollutantInfo(const QString& pollutant) const;

    void loadData(const QString& filePath); 
    void populateDropdown();               
    void createChartForPoint(const QString& point);       
    QStringList parseCSVLine(const QString& line) const;  

    // Inner class for compliance delegate
    class ComplianceDelegate : public QStyledItemDelegate {
    public:
        explicit ComplianceDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

        // Paint method to color the cell based on compliance status
        void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
            QString compliance = index.data().toString();
            QColor backgroundColor;

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