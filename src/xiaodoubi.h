// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef XIAODOUBI_H
#define XIAODOUBI_H

#include "httpget.h"

class XiaoDouBi : public HttpGet 
{
    Q_OBJECT

public:
    XiaoDouBi(HttpGet* parent = nullptr);
    ~XiaoDouBi();

    Q_INVOKABLE void get(QString word);

Q_SIGNALS:
    void contentChanged(QString content);

protected:
    void finished(QNetworkReply* reply);
};

#endif // XIAODOUBI_H
