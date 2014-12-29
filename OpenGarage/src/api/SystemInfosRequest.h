/*
 * SystemInfosRequest.h
 *
 *  Created on: Dec 13, 2014
 *      Author: dustin
 */

#ifndef SYSTEMINFOSREQUEST_H_
#define SYSTEMINFOSREQUEST_H_

#include "ServiceCall.h"

namespace model
{
    class SystemInfos;
}

namespace api
{

    class SystemInfosRequest: public ServiceCall
    {
    Q_OBJECT

    public:
        SystemInfosRequest(QObject* parent = 0);
        virtual ~SystemInfosRequest();

    signals:
        void resultReady(model::SystemInfos*);

    protected slots:
        virtual void onNetworkFinished();
        virtual void onNetworkError(QNetworkReply::NetworkError);

    protected:
        virtual CallType callType()
        {
            return ServiceCall::Get;
        }

        virtual void prepareRequest(QNetworkRequest& request);
    };

} /* namespace api */

#endif /* SYSTEMINFOSREQUEST_H_ */
