/*
 * SystemInfosRequest.cpp
 *
 *  Created on: Dec 13, 2014
 *      Author: dustin
 */

#include "SystemInfosRequest.h"
#include "../model/SystemInfos.h"
#include <QDebug>
#include <bb/data/JsonDataAccess>

using namespace model;
using namespace bb::data;

namespace api
{

    SystemInfosRequest::SystemInfosRequest(QObject* parent) :
            ServiceCall(parent)
    {
    }

    SystemInfosRequest::~SystemInfosRequest()
    {
    }

    void SystemInfosRequest::onNetworkFinished()
    {
        QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

        if (reply->error() != QNetworkReply::NoError) {
            return;
        }

        QByteArray body = reply->readAll();
        qDebug() << Q_FUNC_INFO << body;
        JsonDataAccess jda;
        QVariantMap map = jda.loadFromBuffer(body).toMap();

        SystemInfos* result = new SystemInfos(map["name"].toString(), map["version"].toString(),
                this);
        emit resultReady(result);

        reply->deleteLater();
    }

    void SystemInfosRequest::onNetworkError(QNetworkReply::NetworkError err)
    {
        QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

        qDebug() << Q_FUNC_INFO << err;
        emit error();

        reply->deleteLater();
    }

    void SystemInfosRequest::prepareRequest(QNetworkRequest& request)
    {
        QUrl url = baseUrl();
        url.setPath("/api/v1");
        request.setUrl(url);
    }

} /* namespace api */
