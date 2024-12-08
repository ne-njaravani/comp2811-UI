#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include "model.hpp"
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

class QuakeWindow: public QMainWindow
{
  Q_OBJECT

  public:
    QuakeWindow();

  private:
    void createMainWidget();
    void createStatusBar();
    void addFileMenu();
    void addHelpMenu();

    QuakeModel model;          // data model used by table
    QString dataLocation;      // location of CSV data files
    QString currentFileName;   // name of current file  
    QString csvFilePath = "solution/Y-2024.csv"; // default file path
    QPushButton* loadButton;   // button to load a new CSV file
    QPushButton* statsButton;  // button to display dataset stats
    QTableView* table;         // table of quake data
    QLabel* fileInfo;          // status bar info on current file
    StatsDialog* statsDialog;  // dialog to display stats
    QStackedWidget* pages;     // stacked widget for multiple pages
    Dashboard* dashboard;      // dashboard page
    POPsPage* popsPage;        // POPs page
    FluorinatedPage* fluorinatedPage; // Fluorinated Compounds page
    PollutantOverviewPage* pollutantOverviewPage; // Pollutant Overview page
    EnvironmentalLitterIndicatorsPage* litterIndicatorsPage; // Environmental Litter Indicators page
    ComplianceDashboardPage* complianceDashboardPage; // Compliance Dashboard page


  private slots:
    void setDataLocation();
    void about();
};
