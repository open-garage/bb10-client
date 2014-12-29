/*
 * SystemInfos.h
 *
 *  Created on: Dec 13, 2014
 *      Author: dustin
 */

#ifndef SYSTEMINFOS_H_
#define SYSTEMINFOS_H_

#include <QObject>

namespace model
{

    class SystemInfos: public QObject
    {
        Q_OBJECT

        Q_PROPERTY(QString name READ name FINAL CONSTANT)
        Q_PROPERTY(QString version READ version FINAL CONSTANT)

    public:
        SystemInfos(QString name, QString version, QObject* parent = 0);
        virtual ~SystemInfos();

        QString name() const
        {
            return mName;
        }

        QString version() const
        {
            return mVersion;
        }

    private:
        QString mName;
        QString mVersion;
    };

} /* namespace model */

#endif /* SYSTEMINFOS_H_ */
