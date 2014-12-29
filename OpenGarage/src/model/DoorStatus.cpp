/*
 * DoorStatus.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: dustin
 */

#include "DoorStatus.h"

namespace model
{

    DoorStatus::DoorStatus(int status, QObject* parent) :
            QObject(parent), mStatus(status)
    {
    }

    DoorStatus::~DoorStatus()
    {
    }

} /* namespace model */
