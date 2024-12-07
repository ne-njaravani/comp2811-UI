#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QTableView>
#include <QStandardItemModel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QChartView>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QLineSeries>
#include <QScrollArea>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QDateTime>
#include <QMap>

// EnvironmentalLitterIndicatorsPage class definition
class EnvironmentalLitterIndicatorsPage : public QWidget
{
    Q_OBJECT

public:
    // Constructor
    explicit EnvironmentalLitterIndicatorsPage(QWidget* parent = nullptr);

signals:
    // Signal to navigate back to the dashboard
    void navigateToDashboard();

private:
    // Widgets for the page
    QVBoxLayout* mainLayout;               
    QVBoxLayout* layout;                   
    QVBoxLayout* scrollAreaLayout;           
    QWidget* scrollAreaWidget;              
    QScrollArea* scrollArea;              
    QPushButton* backButton;          
    QTableView* tableView;               
    QLineEdit* searchBox;                
    QStandardItemModel* dataModel;     
    QComboBox* litterDateDropdown;         

    QMap<QString, QStringList> dropdownGroups; // Maps for dropdown data

    // Methods
    void loadData(const QString& filePath);                       
    void populateDropdown();                                       
    void displayTablesForSelection(const QString& selection);     
    void updateChartForLocation(QStandardItemModel* locationModel); 
    void clearLocationSpecificCharts();                          
    QStringList parseCSVLine(const QString& line) const;         

    // Inner class for compliance delegate
    class ComplianceDelegate : public QStyledItemDelegate {
    public:
        explicit ComplianceDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

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

            painter->fillRect(option.rect, backgroundColor);
            QStyledItemDelegate::paint(painter, option, index);
        }
    };

private slots:
    // Slot to filter table data based on search text
    void filterTableData(const QString& text); 
};