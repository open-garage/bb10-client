/*
 * ToggleDoor.h
 *
 *  Created on: Dec 14, 2014
 *      Author: dustin
 */

#ifndef TOGGLEDOOR_H_
#define TOGGLEDOOR_H_

#include <QObject>

namespace model
{

    class ToggleDoor: public QObject
    {
        Q_OBJECT

        Q_PROPERTY(int status READ status FINAL CONSTANT)

    public:
        ToggleDoor(int status, QObject* parent = 0);
        virtual ~ToggleDoor();

        int status() const
        {
            return mStatus;
        }

        static const int STATUS_OK = 0;
        static const int STATUS_ERROR_TOKEN = -1;
        static const int STATUS_ERROR_STATE = -2;

    private:
        int mStatus;
    };

} /* namespace model */

#endif /* TOGGLEDOOR_H_ */
