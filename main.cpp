#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
   
    QCoreApplication::setOrganizationName("IJHack");
    QCoreApplication::setOrganizationDomain("ijhack.org");
    QCoreApplication::setApplicationName("QtPass");
    QCoreApplication::setApplicationVersion("0.0.1");

    //Setup and load translator for localization
    QTranslator translator;
    QString locale = QLocale::system().name();
    translator.load(QString(":localization/localization_") + locale + QString(".qm"));
    app.installTranslator(&translator);
    
    MainWindow w;

    app.setWindowIcon(QIcon(":artwork/icon.png"));
    w.checkConfig();
    w.show();

    return app.exec();
}
