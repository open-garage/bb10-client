/*
 * TogglePage.h
 *
 *  Created on: Dec 14, 2014
 *      Author: dustin
 */

#ifndef TOGGLEPAGE_H_
#define TOGGLEPAGE_H_

#include <bb/cascades/Page>

namespace bb
{
    namespace cascades
    {
        class NavigationPane;
        class Label;
        class ActionItem;
    }
}
namespace model
{
    class DoorStatus;
    class ToggleDoor;
}
class QNetworkConfigurationManager;

namespace controller
{

    class TogglePage: public bb::cascades::Page
    {
        Q_OBJECT

        Q_PROPERTY(bool isOnline READ isOnline NOTIFY isOnlineChanged FINAL)
        Q_PROPERTY(bool isTogglingDoor READ isTogglingDoor NOTIFY isTogglingDoorChanged FINAL)
        Q_PROPERTY(bool statusLoading READ statusLoading NOTIFY statusLoadingChanged FINAL)

    public:
        TogglePage(bb::cascades::NavigationPane* navigationPane = 0);
        virtual ~TogglePage();

        bool isOnline() const
        {
            return mIsOnline;
        }

        bool isTogglingDoor() const
        {
            return mIsTogglingDoor;
        }

        bool statusLoading() const
        {
            return mStatusLoading;
        }

        signals:
        void isOnlineChanged(bool isOnline);

        void isTogglingDoorChanged(bool isTogglingDoor);

        void statusLoadingChanged(bool statusLoading);

    public slots:
        void loadStatus();
        void openDoor();
        void closeDoor();

    private slots:
        void onOnlineStateChanged(bool);

        void onDoorStatusResult(model::DoorStatus*);
        void onDoorStatusError();

        void onOpenDoorResult(model::ToggleDoor*);
        void onOpenDoorError();

        void onCloseDoorResult(model::ToggleDoor*);
        void onCloseDoorError();

    private:
        void initContent();
        void initActionbar();

        void updateActionbar();

        void setTogglingDoor(bool loading);
        void setStatusLoading(bool loading);

        bool mIsOnline;
        bool mIsTogglingDoor;
        bool mStatusLoading;

        bb::cascades::NavigationPane* mNavigationPane;
        bb::cascades::Label* mStatusLabel;
        bb::cascades::ActionItem* mStatusAction;

        QNetworkConfigurationManager* mNetworkConfigManager;
    };

} /* namespace controller */

#endif /* TOGGLEPAGE_H_ */
