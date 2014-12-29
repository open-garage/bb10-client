/*
 * SystemInfos.cpp
 *
 *  Created on: Dec 13, 2014
 *      Author: dustin
 */

#include "SystemInfos.h"

namespace model
{

    SystemInfos::SystemInfos(QString name, QString version, QObject* parent) :
            QObject(parent), mName(name), mVersion(version)
    {
    }

    SystemInfos::~SystemInfos()
    {
    }

} /* namespace model */
