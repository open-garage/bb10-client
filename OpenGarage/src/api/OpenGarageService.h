/*
 * OpenGarageService.h
 *
 *  Created on: Dec 13, 2014
 *      Author: dustin
 */

#ifndef OPENGARAGESERVICE_H_
#define OPENGARAGESERVICE_H_

#include <QObject>

class QNetworkAccessManager;

namespace api
{

    class OpenGarageService: public QObject
    {
        Q_OBJECT

    public:
        static OpenGarageService* instance();

        virtual ~OpenGarageService();

        bool isSecureServer() const
        {
            return mSecureServer;
        }

        QString serverHost() const
        {
            return mServerHost;
        }

        int serverPort() const
        {
            return mServerPort;
        }

        QString apiToken() const
        {
            return mApiToken;
        }

        void setServerHost(QString newValue);

        void setServerPort(int newValue);

        void setApiToken(QString newValue);

        QNetworkAccessManager* networkAccess() const
        {
            return mNetworkAccess;
        }

    private:
        OpenGarageService();

        bool mSecureServer;
        QString mServerHost;
        int mServerPort;
        QString mApiToken;

        QNetworkAccessManager* mNetworkAccess;

        static OpenGarageService* sInstance;
    };

} /* namespace api */

#endif /* OPENGARAGESERVICE_H_ */
