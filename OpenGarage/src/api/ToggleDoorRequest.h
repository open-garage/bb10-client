/*
 * ToggleDoorRequest.h
 *
 *  Created on: Dec 14, 2014
 *      Author: dustin
 */

#ifndef TOGGLEDOORREQUEST_H_
#define TOGGLEDOORREQUEST_H_

#include "ServiceCall.h"

namespace model
{
    class ToggleDoor;
}

namespace api
{

    class ToggleDoorRequest: public ServiceCall
    {
    Q_OBJECT

    public:
        enum State
        {
            Close, Open, Toggle
        };

        ToggleDoorRequest(QObject* parent = 0);
        virtual ~ToggleDoorRequest();

        void setState(State newValue)
        {
            mState = newValue;
        }

        void setDebug(bool newValue)
        {
            mDebug = newValue;
        }

    signals:
        void resultReady(model::ToggleDoor*);

    protected slots:
        virtual void onNetworkFinished();
        virtual void onNetworkError(QNetworkReply::NetworkError);

    protected:
        virtual CallType callType()
        {
            return ServiceCall::Post;
        }

        virtual bool isAuthenticated()
        {
            return true;
        }

        virtual void prepareRequest(QNetworkRequest& request);

        virtual void prepareBody(QVariantMap& map);

    private:
        State mState;
        bool mDebug;

        static QString stateFromEnum(State state);
    };

} /* namespace api */

#endif /* TOGGLEDOORREQUEST_H_ */
