#include "mainwindow.h"
#include "mypushbutton.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    // QApplication
    QApplication a(argc, argv);

    // translator
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "qtwidget_test_231209_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    // MainWindow
    MainWindow w;
    w.show();

    // QPushButton
    QPushButton *button = new QPushButton(
        QApplication::translate("childwidget", "Press me"), &w
        );
    button->move(100,100);
    button->show();

    // QPushButton
    MyPushButton mybutton{&w};

    // return
    return a.exec();
}
