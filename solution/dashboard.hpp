#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QGridLayout>
#include <QColor>
#include <QLineEdit>
#include <functional>
#include <QFileDialog>
#include <QDebug>
#include <QList> 
#include <QString> 

class Dashboard : public QWidget
{
    Q_OBJECT

public:
    // Constructor
    explicit Dashboard(QWidget* parent = nullptr);

signals:
    // Signal to navigate to different pages
    void navigateToPollutantOverview();
    void navigateToPOPs();
    void navigateToEnvironmentalLitter();
    void navigateToFluorinatedPage();
    void navigateToComplianceDashboard();
    
    // Signal to load custom database
    void customDatabaseLoaded(const QString& filePath);

private:
    // Widgets for the page
    QWidget* createCard(const QString& title, 
                        const QString& summary, 
                        const QString& complianceText, 
                        const QColor& complianceColor, 
                        const std::function<void()>& onClick);

    QColor getComplianceColor(double percentage);

    void createCards();
    void filterCards(const QString& text);

    QGridLayout* gridLayout;
    QList<QWidget*> cards;
    struct CardData {
        QString title;
        QString summary;
        int compliant;
        int total;
        std::function<void()> onClick;
    };
    QList<CardData> cardsData;
};