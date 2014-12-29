/*
 * ToggleDoorRequest.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: dustin
 */

#include "ToggleDoorRequest.h"
#include "../model/ToggleDoor.h"
#include <QDebug>
#include <bb/data/JsonDataAccess>

using namespace model;
using namespace bb::data;

namespace api
{

    ToggleDoorRequest::ToggleDoorRequest(QObject* parent) :
            ServiceCall(parent), mState(Toggle)
    {
#ifdef QT_DEBUG
        mDebug = true;
#else
        mDebug = false;
#endif
    }

    ToggleDoorRequest::~ToggleDoorRequest()
    {
    }

    void ToggleDoorRequest::onNetworkFinished()
    {
        QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

        if (reply->error() != QNetworkReply::NoError) {
            return;
        }

        QByteArray body = reply->readAll();
        qDebug() << Q_FUNC_INFO << body;
        JsonDataAccess jda;
        QVariantMap map = jda.loadFromBuffer(body).toMap();

        ToggleDoor* result = new ToggleDoor(map["status"].toInt(), this);
        emit resultReady(result);

        reply->deleteLater();
    }

    void ToggleDoorRequest::onNetworkError(QNetworkReply::NetworkError err)
    {
        QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

        qDebug() << Q_FUNC_INFO << err;
        emit error();

        reply->deleteLater();
    }

    void ToggleDoorRequest::prepareRequest(QNetworkRequest& request)
    {
        QUrl url = baseUrl();
        url.setPath("/api/v1/toggle");
        request.setUrl(url);

        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    }

    void ToggleDoorRequest::prepareBody(QVariantMap& map)
    {
        map["debug"] = mDebug;
        map["state"] = stateFromEnum(mState);
    }

    QString ToggleDoorRequest::stateFromEnum(State state)
    {
        static QMap<State, QString> strings;
        if (strings.isEmpty()) {
            strings[Close] = "close";
            strings[Open] = "open";
            strings[Toggle] = "toggle";
        }

        return strings.contains(state) ? strings[state] : "";
    }

} /* namespace api */
