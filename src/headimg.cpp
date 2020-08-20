// Copyright (C) 2020 Leslie Zhai <zhaixiang@loongson.cn>
// Copyright (C) 2014 - 2016 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include <QFile>
#include <QDir>

#include "headimg.h"
#include "globaldeclarations.h"

HeadImg::HeadImg(QObject* parent)
  : QObject(parent),
    m_v2(false),
    m_userName(""),
    m_headImgUrl(""),
    m_filePath(""),
    m_skey("")
{
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
#endif
}

HeadImg::~HeadImg()
{
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
#endif
}

void HeadImg::setV2(bool v2)
{
    if (m_v2 != v2) {
        m_v2 = v2;
        Q_EMIT v2Changed();
    }
}

void HeadImg::setUserName(const QString & userName)
{
    m_userName = userName;
    Q_EMIT userNameChanged();
    if (m_v2)
        m_get(WX_V2_SERVER_HOST);
    else
        m_get(WX_SERVER_HOST);
}

void HeadImg::setHeadImgUrl(const QString & headImgUrl)
{
    m_headImgUrl = headImgUrl;
    Q_EMIT headImgUrlChanged();
    if (m_v2)
        m_get(WX_V2_SERVER_HOST);
    else
        m_get(WX_SERVER_HOST);
}

void HeadImg::m_get(QString host)
{
    QString url = host + (m_headImgUrl.contains("webwxgeticon") ?
        WX_CGI_PATH + "webwxgeticon?username=" + m_userName :
        WX_CGI_PATH + "webwxgetheadimg?username=" + m_userName) + "&skey=" + m_skey;
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << url;
#endif
    QString headImgPath = QWXDIR + "/" + m_userName;
    if (QFile::exists(headImgPath)) {
        m_filePath = "file://" + QWXDIR + "/" + m_userName;
        Q_EMIT filePathChanged();
    } else {
        m_downLoad.get(url, headImgPath);
        m_connection = connect(&m_downLoad, &Download::finished, [this] {
                    disconnect(m_connection);
                    m_filePath = "file://" + QWXDIR + "/" + m_userName;
                    Q_EMIT filePathChanged();
                });
    }
}

void HeadImg::setSkey(const QString& skey)
{
    m_skey = skey;
    Q_EMIT skeyChanged();
}
