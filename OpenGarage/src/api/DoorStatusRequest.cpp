/*
 * DoorStatusRequest.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: dustin
 */

#include "DoorStatusRequest.h"
#include "../model/DoorStatus.h"
#include <QDebug>
#include <bb/data/JsonDataAccess>

using namespace model;
using namespace bb::data;

namespace api
{

    DoorStatusRequest::DoorStatusRequest(QObject* parent) :
            ServiceCall(parent)
    {
    }

    DoorStatusRequest::~DoorStatusRequest()
    {
    }

    void DoorStatusRequest::onNetworkFinished()
    {
        QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

        if (reply->error() != QNetworkReply::NoError) {
            return;
        }

        QByteArray body = reply->readAll();
        qDebug() << Q_FUNC_INFO << body;
        JsonDataAccess jda;
        QVariantMap map = jda.loadFromBuffer(body).toMap();

        DoorStatus* result = new DoorStatus(map["status"].toInt(), this);
        emit doorStatusResult(result);

        reply->deleteLater();
    }

    void DoorStatusRequest::onNetworkError(QNetworkReply::NetworkError err)
    {
        QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

        qDebug() << Q_FUNC_INFO << err;
        emit error();

        reply->deleteLater();
    }

    void DoorStatusRequest::prepareRequest(QNetworkRequest& request)
    {
        QUrl url = baseUrl();
        url.setPath("/api/v1/status");
        request.setUrl(url);

        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    }

}
/* namespace api */
