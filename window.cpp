#include <QtWidgets>
#include <stdexcept>
#include <iostream>
#include "window.hpp"

static const int MIN_WIDTH = 620;


Window::Window(): QMainWindow(), statsDialog(nullptr)
{
    createMainWidget();
    createStatusBar();

    setMinimumWidth(MIN_WIDTH);
    
    setWindowTitle("Water Quality Monitoring Application");
    }


void Window::createMainWidget()
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
    connect(dashboard, &Dashboard::csvFileLoaded, pollutantOverviewPage, &PollutantOverviewPage::loadCsvFile);
    pages->addWidget(pollutantOverviewPage);

    // POPs page
    popsPage = new POPsPage();
    connect(popsPage, &POPsPage::navigateToDashboard, [this]() {
        pages->setCurrentIndex(0); // Switch back to Dashboard
    });
    connect(dashboard, &Dashboard::csvFileLoaded, popsPage, &POPsPage::loadCsvFile);
    pages->addWidget(popsPage);

    // Environmental Litter Indicators page
    litterIndicatorsPage = new EnvironmentalLitterIndicatorsPage();
    connect(litterIndicatorsPage, &EnvironmentalLitterIndicatorsPage::navigateToDashboard, [this]() {
        pages->setCurrentIndex(0); // Switch back to Dashboard
    });
    connect(dashboard, &Dashboard::csvFileLoaded, litterIndicatorsPage, &EnvironmentalLitterIndicatorsPage::loadCsvFile);
    pages->addWidget(litterIndicatorsPage);

    // Fluorinated Compounds page
    fluorinatedPage = new FluorinatedPage();
    connect(fluorinatedPage, &FluorinatedPage::navigateToDashboard, [this]() {
        pages->setCurrentIndex(0); // Switch back to Dashboard
    });
    connect(dashboard, &Dashboard::csvFileLoaded, fluorinatedPage, &FluorinatedPage::loadCsvFile);
    pages->addWidget(fluorinatedPage);

    // Compliance Dashboard page
    complianceDashboardPage = new ComplianceDashboardPage();
    connect(complianceDashboardPage, &ComplianceDashboardPage::navigateToDashboard, [this]() {
        pages->setCurrentIndex(0); // Switch back to Dashboard
    });
    connect(dashboard, &Dashboard::csvFileLoaded, complianceDashboardPage, &ComplianceDashboardPage::loadCsvFile);
    pages->addWidget(complianceDashboardPage);

    setCentralWidget(pages);
}

void Window::createStatusBar()
{
    // Default file name
    currentFileName = "None";

    // Create a label to show the current file
    fileInfo = new QLabel(QString("Loaded file: %1").arg(QFileInfo(currentFileName).fileName()));
    QStatusBar* status = statusBar();
    status->addWidget(fileInfo);

    // Connect the Dashboard's csvFileLoaded signal to dynamically update the status bar
    connect(dashboard, &Dashboard::csvFileLoaded, this, &Window::updateStatusBarFile);
}

void Window::updateStatusBarFile(const QString& filePath)
{
    currentFileName = filePath; // Update the internal file name
    fileInfo->setText(QString("Loaded file: %1").arg(QFileInfo(filePath).fileName())); // Extract and display the file name
}
