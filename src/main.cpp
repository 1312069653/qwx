// Copyright (C) 2020 Leslie Zhai <zhaixiang@loongson.cn>
// Copyright (C) 2014 - 2016 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include <QtQml>
#include <QtQuick/QQuickView>
#include <QScreen>

#include "globaldeclarations.h"
#include "qtsingleapplication/QtSingleApplication"
#include "qwxuuid.h"
#include "scan.h"
#include "cookie.h"
#include "statreport.h"
#include "init.h"
#include "sync.h"
#include "contact.h"
#include "headimg.h"
#include "statusnotify.h"
#include "sendmsg.h"
#include "monitor.h"
#include "getmsg.h"
#include "circleimage.h"
#include "process.h"
#include "xiaodoubi.h"
#include "chatlog.h"
#include "emotion.h"
#include "logout.h"
#include "ipcity.h"
#include "weather.h"
#include "i18n.h"
#include "clipboard.h"

int main(int argc, char* argv[])
{
    QtSingleApplication app(argc, argv);

    if (app.isRunning())
        return 0;

    app.setApplicationName(CODE_NAME);
    app.setApplicationVersion(APPLICATION_VERSION);
    // TODO: session management testcase
    // http://marc.info/?l=kde-core-devel&m=144832700109449
    // KDEBUG-341930
    // perhaps we need to wait Qt5.9.x to fix it ;-)
    //app.setQuitOnLastWindowClosed(false);

    I18N i18n(TRANSLATIONS_PATH, APPLICATION_ENCODING);
    i18n.translate();

    const char*        uri = "cn.com.isoft.qwx";
    const int versionMajor = 1;
    const int versionMinor = 0;
    qmlRegisterType<QwxUUID>(uri, versionMajor, versionMinor, "QwxUUID");
    qmlRegisterType<Scan>(uri, versionMajor, versionMinor, "Scan");
    qmlRegisterType<Cookie>(uri, versionMajor, versionMinor, "Cookie");
    qmlRegisterType<StatReport>(uri, versionMajor, versionMinor, "StatReport");
    qmlRegisterType<Init>(uri, versionMajor, versionMinor, "Init");
    qmlRegisterType<Sync>(uri, versionMajor, versionMinor, "Sync");
    qmlRegisterType<Contact>(uri, versionMajor, versionMinor, "Contact");
    qmlRegisterType<HeadImg>(uri, versionMajor, versionMinor, "HeadImg");
    qmlRegisterType<StatusNotify>(uri, versionMajor, versionMinor, "StatusNotify");
    qmlRegisterType<SendMsg>(uri, versionMajor, versionMinor, "SendMsg");
    qmlRegisterType<Monitor>(uri, versionMajor, versionMinor, "Monitor");
    qmlRegisterType<GetMsg>(uri, versionMajor, versionMinor, "GetMsg");
    qmlRegisterType<CircleImage>(uri, versionMajor, versionMinor, "CircleImage");
    qmlRegisterType<Process>(uri, versionMajor, versionMinor, "Process");
    qmlRegisterType<XiaoDouBi>(uri, versionMajor, versionMinor, "XiaoDouBi");
    qmlRegisterType<ChatLog>(uri, versionMajor, versionMinor, "ChatLog");
    qmlRegisterType<Emotion>(uri, versionMajor, versionMinor, "Emotion");
    qmlRegisterType<LogOut>(uri, versionMajor, versionMinor, "LogOut");
    qmlRegisterType<IpCity>(uri, versionMajor, versionMinor, "IpCity");
    qmlRegisterType<Weather>(uri, versionMajor, versionMinor, "Weather");
    qmlRegisterType<Clipboard>(uri, versionMajor, versionMinor, "Clipboard");

    QQmlApplicationEngine engine(QUrl("qrc:/qml/main.qml"));
    QObject* topLevel = engine.rootObjects().value(0);
    QQuickWindow* window = qobject_cast<QQuickWindow*>(topLevel);
    if (!window) {
        qWarning("Error: Your root item has to be a Window.");
        return -1;
    }
    // FIXME: it does not work for KWin 5.7.x
    // https://blog.martin-graesslin.com/blog/2016/07/multi-screen-woes-in-plasma-5-7/
    // Newly opened windows not placed on the primary screen
#if QWX_DEBUG
    qDebug() << "DEBUG:" << app.primaryScreen()->availableGeometry();
#endif
    window->setScreen(app.primaryScreen());
    window->show();

    return app.exec();
}
