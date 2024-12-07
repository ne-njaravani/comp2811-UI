#ifndef POLLUTANTOVERVIEW_HPP
#define POLLUTANTOVERVIEW_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTableView>
#include <QStandardItemModel>
#include <QChartView>
#include <QPushButton>
#include <QComboBox>
#include <QStyledItemDelegate>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QMap>
#include <QStringList>

class PollutantOverviewPage : public QWidget {
    Q_OBJECT

public:
    // Constructor
    explicit PollutantOverviewPage(QWidget* parent = nullptr);

signals:
    // Signal to navigate back to the dashboard
    void navigateToDashboard();

private:
    // Widgets for the page
    QVBoxLayout* layout;
    QLineEdit* searchBox;
    QTableView* tableView;
    QStandardItemModel* dataModel;
    QChartView* chartView;
    QComboBox* pollutantDateDropdown;
    QPushButton* backButton;

    // Add dropdownGroups to store times for each group
    QMap<QString, QStringList> dropdownGroups;

    void loadData(const QString& filePath);
    QStringList parseCSVLine(const QString& line) const;
    void populateDropdown();
    void createChartForGroup(const QString& selection);

    // Inner class for compliance delegate
    class ComplianceDelegate : public QStyledItemDelegate {
    public:
        explicit ComplianceDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

        // Paint method to color the cell based on compliance status
        void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
            QString compliance = index.data().toString();
            QColor backgroundColor;

            // Define color based on compliance status
            if (compliance == "Compliant") {
                backgroundColor = QColor(34, 139, 34); // Green
            } else if (compliance == "Caution") {
                backgroundColor = QColor(255, 165, 0); // Amber
            } else if (compliance == "Exceeds") {
                backgroundColor = QColor(178, 34, 34); // Red
            } else {
                backgroundColor = QColor(169, 169, 169); // Gray
            }

            painter->fillRect(option.rect, backgroundColor);
            QStyledItemDelegate::paint(painter, option, index);
        }
    };

private slots:
    void filterTableData(const QString& text);
};

#endif // POLLUTANTOVERVIEW_HPP