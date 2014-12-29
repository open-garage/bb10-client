/*
 * DoorStatusRequest.h
 *
 *  Created on: Dec 14, 2014
 *      Author: dustin
 */

#ifndef DOORSTATUSREQUEST_H_
#define DOORSTATUSREQUEST_H_

#include "ServiceCall.h"

namespace model
{
    class DoorStatus;
}

namespace api
{

    class DoorStatusRequest: public ServiceCall
    {
    Q_OBJECT

    public:
        DoorStatusRequest(QObject* parent = 0);
        virtual ~DoorStatusRequest();

    signals:
        void doorStatusResult(model::DoorStatus*);

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
    };

} /* namespace api */

#endif /* DOORSTATUSREQUEST_H_ */
