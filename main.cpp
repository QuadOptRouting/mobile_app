#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QObject>
#include <QQuickView>
#include <QList>
#include "appcore.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    AppCore appCore;

    QQmlContext *context = engine.rootContext();
    context->setContextProperty("appCore", &appCore);

//    QObject *item = engine.rootObjects()[0];
//    QObject myI = item->findChild<QObject*>("button_1");
//    QObject::connect(item, SIGNAL(butt_cl()), &appCore, SLOT(send()));
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    QList<QObject*> lst = engine.rootObjects();
    int count = lst.count();
    qDebug() << count;

    QObject *object = lst[0];
    QObject *mainForm = object->findChild<QObject*>("mainForm");

//    QObject::connect(mainForm, SIGNAL(butt_cl), &appCore, SLOT(send));
    QObject::connect(mainForm, SIGNAL(butt_cl()), &appCore, SLOT(send()));

    return app.exec();
}
