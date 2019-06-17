// Copyright (C) 2014 - 2015 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef STATUS_NOTIFY_H
#define STATUS_NOTIFY_H

#include "httppost.h"

class StatusNotify : public HttpPost 
{
    Q_OBJECT

public:
    StatusNotify(HttpPost* parent = nullptr);
    ~StatusNotify();

    Q_INVOKABLE void post(QString uin, 
                          QString sid, 
                          QString skey, 
                          QString deviceId, 
                          QString userName);
    Q_INVOKABLE void postV2(QString uin,
                          QString sid,
                          QString skey,
                          QString deviceId,
                          QString userName);

protected:
    void finished(QNetworkReply* reply);

private:
    void m_post(QString host, 
                QString uin, 
                QString sid, 
                QString skey, 
                QString deviceId, 
                QString userName);
};

#endif // STATUS_NOTIFY_H
