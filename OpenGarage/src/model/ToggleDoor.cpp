/*
 * ToggleDoor.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: dustin
 */

#include "ToggleDoor.h"

namespace model
{

    ToggleDoor::ToggleDoor(int status, QObject* parent) :
            QObject(parent), mStatus(status)
    {
    }

    ToggleDoor::~ToggleDoor()
    {
    }

} /* namespace model */
