/*
 * DoorStatus.h
 *
 *  Created on: Dec 14, 2014
 *      Author: dustin
 */

#ifndef DOORSTATUS_H_
#define DOORSTATUS_H_

#include <QObject>

namespace model
{

    class DoorStatus: public QObject
    {
        Q_OBJECT

        Q_PROPERTY(int status READ status FINAL CONSTANT)

    public:
        DoorStatus(int status, QObject* parent = 0);
        virtual ~DoorStatus();

        int status() const
        {
            return mStatus;
        }

        static const int STATUS_OPEN = 1;
        static const int STATUS_CLOSED = 0;
        static const int STATUS_ERROR = -1;

    private:
        int mStatus;
    };

} /* namespace model */

#endif /* DOORSTATUS_H_ */
