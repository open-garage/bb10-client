/*
 * OpenGarageService.cpp
 *
 *  Created on: Dec 13, 2014
 *      Author: dustin
 */

#include "OpenGarageService.h"
#include <QSettings>
#include <QtNetwork/QNetworkAccessManager>

namespace api
{

    OpenGarageService* OpenGarageService::sInstance = 0;

    OpenGarageService* OpenGarageService::instance()
    {
        if (!sInstance) {
            sInstance = new OpenGarageService();
        }
        return sInstance;
    }

    OpenGarageService::OpenGarageService() :
            QObject(0), mNetworkAccess(new QNetworkAccessManager(this))
    {
        QSettings settings;
        mSecureServer = settings.value("server/secure", true).toBool();
        mServerHost = settings.value("server/host", "localhost").toString();
        mServerPort = settings.value("server/port", 8000).toInt();
        mApiToken = settings.value("server/token", "A").toString();
    }

    OpenGarageService::~OpenGarageService()
    {
    }

    void OpenGarageService::setServerHost(QString newValue)
    {
        if (mServerHost != newValue) {
            mServerHost = newValue;

            QSettings settings;
            settings.setValue("server/host", newValue);
        }
    }

    void OpenGarageService::setServerPort(int newValue)
    {
        if (mServerPort != newValue) {
            mServerPort = newValue;

            QSettings settings;
            settings.setValue("server/port", newValue);
        }
    }

    void OpenGarageService::setApiToken(QString newValue)
    {
        if (mApiToken != newValue) {
            mApiToken = newValue;

            QSettings settings;
            settings.setValue("server/token", newValue);
        }
    }

} /* namespace api */
