#include "dashboard.hpp"
#include <QApplication>

Dashboard::Dashboard(QWidget* parent) : QWidget(parent)
{
    // Create a vertical layout
    QVBoxLayout* layout = new QVBoxLayout();

    // Add a title
    layout->addStretch();
    QLabel* title = new QLabel(tr("Water Quality Dashboard"));
    QFont titleFont = title->font();
    titleFont.setPointSize(24);
    titleFont.setBold(true);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);
    layout->addWidget(title);
    layout->addStretch();

    // Add a search bar
    QLineEdit* searchBar = new QLineEdit();
    searchBar->setPlaceholderText(tr("Search..."));
    layout->addWidget(searchBar);

    // Create a grid layout for the cards
    gridLayout = new QGridLayout();

    // Define data for each card
    cardsData = {
        {tr("Pollutant Overview"), tr("Overview of key pollutants such as 1,1,2-Trichloroethane and Chloroform, offering trends over time and compliance indicators."),
         30, 300, [this]() { emit navigateToPollutantOverview(); }},
        {tr("Persistent Organic Pollutants (POPs)"), tr("Data on long-lasting organic pollutants like PCBs, showing trends over time and compliance with UK/EU safety standards."),
         395, 466, [this]() { emit navigateToPOPs(); }},
        {tr("Environmental Litter Indicators"), tr("Summarizes physical litter trends, including comparisons across locations and water body types, with compliance indicators for EU standards."),
         50, 200, [this]() { emit navigateToEnvironmentalLitter(); }},
        {tr("Fluorinated Compounds"), tr("Displays data on PFAS and other fluorinated compounds, highlighting their distribution and compliance with safety thresholds."),
         70, 300, [this]() { emit navigateToFluorinatedCompounds(); }},
        {tr("Compliance Dashboard"), tr("Provides a regulatory compliance summary across all pollutants, with filters to view non-compliant areas and trends."),
         100, 150, [this]() { emit navigateToComplianceDashboard(); }},
        {tr("Geographical Hotspots"), tr("Highlights pollution hotspots on a map, showing sampling points with high pollutant levels and compliance status."),
         10, 50, [this]() { emit navigateToGeographicalHotspots(); }},
    };

    // Create cards dynamically
    createCards();

    layout->addLayout(gridLayout);
    layout->addStretch();

    // Add a footer with help links
    layout->addStretch();
    QLabel* footer = new QLabel(
        tr("<p style='text-align: center;'>"
           "Need help? Visit our <a href='https://example.com/user-guide'>User Guide</a>! "
           "For more help, check out the <a href='https://www.gov.uk/government/publications/values-for-groundwater-risk-assessments/hazardous-substances-to-groundwater-minimum-reporting-values?utm_source=chatgpt.com'>UK Regulations</a> and "
           "<a href='https://clu-in.org/download/contaminantfocus/pcb/dioxins%20and%20pcbs_final.pdf'>EU Regulations</a>, or "
           "view the <a href='https://environment.data.gov.uk/water-quality/view/download'>Credits</a> for data sources."
           "</p>"));
    footer->setTextFormat(Qt::RichText);
    footer->setTextInteractionFlags(Qt::TextBrowserInteraction);
    footer->setOpenExternalLinks(true);
    footer->setStyleSheet("font-size: 12px; color: #FFFFFF;");
    layout->addWidget(footer);

    layout->addStretch();

    // Set the layout for the dashboard
    setLayout(layout);

    // Connect the search bar to the filtering logic
    connect(searchBar, &QLineEdit::textChanged, this, &Dashboard::filterCards);
}

QWidget* Dashboard::createCard(const QString& title,
                               const QString& summary,
                               const QString& complianceText,
                               const QColor& complianceColor,
                               const std::function<void()>& onClick)
{
    QWidget* card = new QWidget();
    QVBoxLayout* cardLayout = new QVBoxLayout(card);
    card->setStyleSheet("background-color: #f8f9fa; border-radius: 10px; padding: 15px;");

    QPushButton* button = new QPushButton(title);
    button->setStyleSheet(
        "QPushButton {"
        "   font-size: 18px; font-weight: bold; background-color: #0078D4; color: white; "
        "   border: none; padding: 10px; border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #339AF0;"
        "}"
    );
    connect(button, &QPushButton::clicked, onClick);
    cardLayout->addWidget(button);

    QLabel* summaryLabel = new QLabel(summary);
    summaryLabel->setWordWrap(true);
    summaryLabel->setStyleSheet("font-size: 14px; color: #555;");
    cardLayout->addWidget(summaryLabel);

    QHBoxLayout* complianceLayout = new QHBoxLayout();
    QLabel* complianceLabel = new QLabel(complianceText);
    complianceLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: #333;");
    complianceLayout->addWidget(complianceLabel);

    QLabel* trafficLight = new QLabel();
    trafficLight->setFixedSize(20, 20);
    trafficLight->setStyleSheet(QString("background-color: %1; border: 2px solid black; border-radius: 10px;").arg(complianceColor.name()));
    complianceLayout->addWidget(trafficLight);

    cardLayout->addLayout(complianceLayout);

    return card;
}

QColor Dashboard::getComplianceColor(double percentage)
{
    if (percentage >= 75.0) {
        return Qt::green;
    } else if (percentage >= 50.0) {
        return Qt::yellow;
    } else {
        return Qt::red;
    }
}

void Dashboard::createCards()
{
    qDeleteAll(cards);
    cards.clear();

    int row = 0, col = 0;
    for (const auto& card : cardsData) {
        double compliancePercentage = (card.total > 0) ? (static_cast<double>(card.compliant) / card.total) * 100.0 : 0.0;
        QColor complianceColor = getComplianceColor(compliancePercentage);

        QWidget* cardWidget = createCard(
            card.title,
            card.summary,
            QString(tr("%1 Compliant / %2 Total Pollutants")).arg(card.compliant).arg(card.total),
            complianceColor,
            card.onClick
        );
        cards.append(cardWidget);

        gridLayout->addWidget(cardWidget, row, col);

        col++;
        if (col >= 2) {
            col = 0;
            row++;
        }
    }
}

void Dashboard::filterCards(const QString& text)
{
    for (QWidget* card : cards) {
        QPushButton* button = card->findChild<QPushButton*>();
        if (button && button->text().contains(text, Qt::CaseInsensitive)) {
            card->setVisible(true);
        } else {
            card->setVisible(false);
        }
    }
}