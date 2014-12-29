/*
 * ServiceCall.cpp
 *
 *  Created on: Dec 13, 2014
 *      Author: dustin
 */

#include "ServiceCall.h"
#include "OpenGarageService.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QSslCertificate>
#include <QtNetwork/QSslError>
#include <QDebug>
#include <QDir>
#include <bb/data/JsonDataAccess>

using namespace bb::data;

namespace api
{

    ServiceCall::ServiceCall(QObject* parent) :
            QObject(parent)
    {
    }

    ServiceCall::~ServiceCall()
    {
    }

    QUrl ServiceCall::baseUrl()
    {
        OpenGarageService* ogs = OpenGarageService::instance();
        QString url;
        if (ogs->isSecureServer()) {
            url += "https://";
        } else {
            url += "http://";
        }
        url += ogs->serverHost() + ":" + QString::number(ogs->serverPort());

        return QUrl(url);
    }

    QByteArray ServiceCall::body()
    {
        QVariantMap map;
        prepareBody(map);
        if (isAuthenticated()) {
            map["token"] = OpenGarageService::instance()->apiToken();
        }

        JsonDataAccess jda;
        QByteArray buffer;
        jda.saveToBuffer(map, &buffer);
        return buffer;
    }

    void ServiceCall::call()
    {
        QNetworkAccessManager* accessManager = OpenGarageService::instance()->networkAccess();

        QNetworkRequest request;
        prepareRequest(request);

        QString certLocation = QDir::currentPath() + "/app/native/assets/helmsdeep.pem";
        QList<QSslCertificate> cert = QSslCertificate::fromPath(certLocation);
        QSslError error(QSslError::SelfSignedCertificate, cert.at(0));
        QList<QSslError> expectedSslErrors;
        expectedSslErrors.append(error);

        QNetworkReply* reply = 0;
        if (callType() == Get) {
            reply = accessManager->get(request);
        } else {
            reply = accessManager->post(request, body());
        }
        connect(reply, SIGNAL(finished()), this, SLOT(onNetworkFinished()));
        connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this,
                SLOT(onNetworkError(QNetworkReply::NetworkError)));
        reply->ignoreSslErrors(expectedSslErrors);
    }

} /* namespace api */
