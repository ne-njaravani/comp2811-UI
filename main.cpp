#include <QtWidgets>
#include "window.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QTranslator translator;

    // Detect system locale
    QString locale = QLocale::system().name().split('_').first();

    // Attempt to load the appropriate translation file
    QString translationFilePath = "translations/" + locale + ".qm";
    if (translator.load(translationFilePath)) {
        QCoreApplication::installTranslator(&translator);
        qDebug() << "Loaded translation file:" << translationFilePath;
    } else {
        qDebug() << "No translation file found for locale:" << locale;
    }

    // Create and show the main window
    Window window;
    window.show();

    return app.exec();
}