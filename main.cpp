#include <QApplication>
#include <QQmlApplicationEngine>
#include "TimeLine.h"
int main(int argc, char *argv[])
{
    Initalize();
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
