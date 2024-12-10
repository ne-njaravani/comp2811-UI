#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include "dashboard.hpp"
#include "pops.hpp"
#include "fluorinated.hpp"
#include "pollutantOverview.hpp"
#include "envlitter.hpp"
#include "compliance.hpp"

class QString;
class QComboBox;
class QLabel;
class QPushButton;
class QTableView;
class StatsDialog;

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window();

private:
    void createMainWidget();
    void createStatusBar();

    void csvFileLoaded(const QString& filePath);

    QString currentFileName;   // Name of the current file
    QPushButton* loadButton;   // Button to load a new CSV file
    QPushButton* statsButton;  // Button to display dataset stats
    QTableView* table;         // Table of quake data
    QLabel* fileInfo;          // Status bar info on current file
    StatsDialog* statsDialog;  // Dialog to display stats
    QStackedWidget* pages;     // Stacked widget for multiple pages
    Dashboard* dashboard;      // Dashboard page
    POPsPage* popsPage;        // POPs page
    FluorinatedPage* fluorinatedPage; // Fluorinated Compounds page
    PollutantOverviewPage* pollutantOverviewPage; // Pollutant Overview page
    EnvironmentalLitterIndicatorsPage* litterIndicatorsPage; // Environmental Litter Indicators page
    ComplianceDashboardPage* complianceDashboardPage; // Compliance Dashboard page

private slots:
    void updateStatusBarFile(const QString& filePath);
};