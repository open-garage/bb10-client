/*
 * ServiceCall.h
 *
 *  Created on: Dec 13, 2014
 *      Author: dustin
 */

#ifndef SERVICECALL_H_
#define SERVICECALL_H_

#include <QObject>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

namespace api
{

    class ServiceCall: public QObject
    {
        Q_OBJECT

    public:
        ServiceCall(QObject* parent = 0);
        virtual ~ServiceCall();

        Q_INVOKABLE
        void call();

        signals:
        void error();

    protected slots:
        virtual void onNetworkFinished() = 0;
        virtual void onNetworkError(QNetworkReply::NetworkError) = 0;

    protected:
        enum CallType
        {
            Get, Post
        };

        QUrl baseUrl();

        QByteArray body();

        virtual CallType callType() = 0;

        virtual bool isAuthenticated()
        {
            return false;
        }

        virtual void prepareRequest(QNetworkRequest& request) = 0;

        virtual void prepareBody(QVariantMap& map)
        {
            Q_UNUSED(map);
        }
    };

} /* namespace api */

#endif /* SERVICECALL_H_ */
