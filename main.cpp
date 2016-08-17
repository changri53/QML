#include <QApplication>
#include <QQmlApplicationEngine>
#include <CPositioner.hpp>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CPositioner p;
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    p.setRootObjects(engine.rootObjects());
    p.show();
    return app.exec();
}
