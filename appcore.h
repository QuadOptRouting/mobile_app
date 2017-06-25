#ifndef APPCORE_H
#define APPCORE_H

#include "json_pars.h"
#include <string>
#include <QObject>
#include <QTcpSocket>
#include <QByteArray>

class AppCore : public QObject
{
    Q_OBJECT
public:
    explicit AppCore(QObject *parent = 0);
    virtual ~AppCore() {}
signals:
    void res(QString result);
public slots:
    void send();
private slots:
    void read();

private:
    QTcpSocket sock;
};

#endif // APPCORE_H
