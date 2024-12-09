#include <QtWidgets>
#include <stdexcept>
#include <iostream>
#include "window.hpp"
#include "stats.hpp"

static const int MIN_WIDTH = 620;


QuakeWindow::QuakeWindow(): QMainWindow(), statsDialog(nullptr)
{
  createMainWidget();
  createStatusBar();
  addFileMenu();
  addHelpMenu();

  setMinimumWidth(MIN_WIDTH);
  setWindowTitle("Quake Tool");
}


void QuakeWindow::createMainWidget()
{
    // Initialize QStackedWidget
    pages = new QStackedWidget(this);

    // Create and add the Dashboard page
    dashboard = new Dashboard();

    // Connect Dashboard buttons to navigate to respective pages
    connect(dashboard, &Dashboard::navigateToPollutantOverview, [this]() {
        pages->setCurrentIndex(1); // Switch to Pollutant Overview page
    });
    connect(dashboard, &Dashboard::navigateToPOPs, [this]() {
        pages->setCurrentIndex(2); // Switch to POPs page
    });
    connect(dashboard, &Dashboard::navigateToEnvironmentalLitter, [this]() {
        pages->setCurrentIndex(3); // Switch to Environmental Litter Indicators page
    });
    connect(dashboard, &Dashboard::navigateToFluorinatedPage, [this]() {
        pages->setCurrentIndex(4); // Switch to Fluorinated Compounds page
    });
    connect(dashboard, &Dashboard::navigateToComplianceDashboard, [this]() {
        pages->setCurrentIndex(5); // Switch to Compliance Dashboard
    });
    pages->addWidget(dashboard);

    // Pollutant Overview page
    pollutantOverviewPage = new PollutantOverviewPage();
    connect(pollutantOverviewPage, &PollutantOverviewPage::navigateToDashboard, [this]() {
        pages->setCurrentIndex(0); // Switch back to Dashboard
    });
    pages->addWidget(pollutantOverviewPage);

    // POPs page
    popsPage = new POPsPage();
    connect(popsPage, &POPsPage::navigateToDashboard, [this]() {
        pages->setCurrentIndex(0); // Switch back to Dashboard
    });
    pages->addWidget(popsPage);

    // Environmental Litter Indicators page
    litterIndicatorsPage = new EnvironmentalLitterIndicatorsPage();
    connect(litterIndicatorsPage, &EnvironmentalLitterIndicatorsPage::navigateToDashboard, [this]() {
        pages->setCurrentIndex(0); // Switch back to Dashboard
    });
    pages->addWidget(litterIndicatorsPage);

    // Fluorinated Compounds page
    fluorinatedPage = new FluorinatedPage();
    connect(fluorinatedPage, &FluorinatedPage::navigateToDashboard, [this]() {
        pages->setCurrentIndex(0); // Switch back to Dashboard
    });
    pages->addWidget(fluorinatedPage);

    // Compliance Dashboard page
    complianceDashboardPage = new ComplianceDashboardPage();
    connect(complianceDashboardPage, &ComplianceDashboardPage::navigateToDashboard, [this]() {
        pages->setCurrentIndex(0); // Switch back to Dashboard
    });
    pages->addWidget(complianceDashboardPage);

    // Set QStackedWidget as the central widget
    setCentralWidget(pages);
}


void QuakeWindow::createStatusBar()
{
    currentFileName = "Y-2024.csv";
    fileInfo = new QLabel(QString("Current file: %1").arg(currentFileName));
    QStatusBar* status = statusBar();
    status->addWidget(fileInfo);
}


void QuakeWindow::addFileMenu()
{
  QAction* locAction = new QAction("Set Data &Location", this);
  locAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_L));
  connect(locAction, SIGNAL(triggered()), this, SLOT(setDataLocation()));

  QAction* closeAction = new QAction("Quit", this);
  closeAction->setShortcut(QKeySequence::Close);
  connect(closeAction, SIGNAL(triggered()), this, SLOT(close()));

  QMenu* fileMenu = menuBar()->addMenu("&File");
  fileMenu->addAction(locAction);
  fileMenu->addAction(closeAction);
}


void QuakeWindow::addHelpMenu()
{
  QAction* aboutAction = new QAction("&About", this);
  connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

  QAction* aboutQtAction = new QAction("About &Qt", this);
  connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

  QMenu* helpMenu = menuBar()->addMenu("&Help");
  helpMenu->addAction(aboutAction);
  helpMenu->addAction(aboutQtAction);
}


void QuakeWindow::setDataLocation()
{
  QString directory = QFileDialog::getExistingDirectory(
    this, "Data Location", ".",
    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

  if (directory.length() > 0) {
    dataLocation = directory;
  }
}

void QuakeWindow::about()
{
  QMessageBox::about(this, "About Quake Tool",
    "Quake Tool displays and analyzes earthquake data loaded from"
    "a CSV file produced by the USGS Earthquake Hazards Program.\n\n"
    "(c) 2024 Nick Efford");
}
