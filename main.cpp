#include "werewolves.h"
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QFontDatabase>
#include <QtAndroidExtras>
#include <QtAndroid>


void keepScreenOn()
{
    QAndroidJniObject activity = QtAndroid::androidActivity();
    if (activity.isValid()) {
        QAndroidJniObject window = activity.callObjectMethod("getWindow", "()Landroid/view/Window;");

        if (window.isValid()) {
            const int FLAG_KEEP_SCREEN_ON = 128;
            window.callObjectMethod("addFlags", "(I)V", FLAG_KEEP_SCREEN_ON);
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QScreen *dpi = qApp->primaryScreen();

    QFile styleFile(":/qss/lowdpistyle.qss");
    styleFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleFile.readAll());
    a.setStyleSheet(styleSheet);

    /*
    QFile fontFile("qrc:/fonts/fonts/FEASFBI_.TTF");
    fontFile.open(QFile::ReadOnly);
    qDebug() << fontFile.exists();
    qDebug() << fontFile.size();
    QByteArray fontArray = fontFile.readAll();



    int id = QFontDatabase::addApplicationFontFromData(fontArray);
    qDebug() << ((id != -1) ? "Success" : "Failure");
    */

    //keepScreenOn();
    Werewolves w;
    w.show();




    return a.exec();
}
