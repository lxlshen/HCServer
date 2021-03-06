#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <tufao-1/Tufao/HttpsServer>
#include <tufao-1/Tufao/HttpServerRequest>
#include <tufao-1/Tufao/HttpServerResponse>
#include <QUrl>
#include <QCoreApplication>
#include <QFile>
#include <QSsl>
#include <QSslCertificate>
#include <QSslKey>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

using namespace Tufao;

#define USE_HTTPS 0

class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);

#if USE_HTTPS
    HttpsServer* _server;
#else
    HttpServer* _server;
#endif
    void handleRequestReady(HttpServerRequest& request, HttpServerResponse&);
    QJsonObject handle(QJsonObject reqObj);
    QJsonObject handleLogin(QJsonObject obj);
    QJsonObject handleReg(QJsonObject obj);
    QJsonObject handleLocationChange(QJsonObject obj);

    static ssize_t curlCallback(char* ptr, int m, int n, void* arg);
    QString md5(QString value);

    QJsonObject execute(QJsonObject );
signals:

public slots:
    void slotRequestReady(Tufao::HttpServerRequest&, Tufao::HttpServerResponse&);
};

#endif // MYSERVER_H
