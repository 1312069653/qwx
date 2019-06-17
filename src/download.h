// Copyright (C) 2014 - 2016 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkCookie>
#include <QFile>

class Download : public QObject 
{
    Q_OBJECT

public:
    Download(QObject* parent = nullptr);
    ~Download();

    void get(QString url,
             QString filePath,
             bool needCookie = true,
             bool isApped = true);

Q_SIGNALS:
    void downloaded(qreal progress);
    void finished();
    void error();

private:
    QNetworkAccessManager m_nam;
    QNetworkReply* m_reply;
    QFile m_file;
    QMetaObject::Connection m_finishConnection;
    QMetaObject::Connection m_sslErrorConnection;
    QMetaObject::Connection m_downloadProgressConnection;
    QMetaObject::Connection m_readyReadConnection;
};

#endif // DOWNLOAD_H
