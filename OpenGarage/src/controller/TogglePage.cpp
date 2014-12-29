/*
 * TogglePage.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: dustin
 */

#include "TogglePage.h"
#include <bb/cascades/NavigationPane>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/Control>
#include <bb/cascades/Label>
#include <bb/cascades/ActionItem>
#include "../api/DoorStatusRequest.h"
#include "../model/DoorStatus.h"
#include "../api/ToggleDoorRequest.h"
#include "../model/ToggleDoor.h"
#include <QtNetwork/QNetworkConfigurationManager>

using namespace api;
using namespace model;
using namespace bb::cascades;

namespace controller
{

    TogglePage::TogglePage(NavigationPane* navigationPane) :
            Page(navigationPane), mIsTogglingDoor(false), mStatusLoading(false), mNavigationPane(
                    navigationPane), mNetworkConfigManager(new QNetworkConfigurationManager(this))
    {
        mIsOnline = mNetworkConfigManager->isOnline();
        connect(mNetworkConfigManager, SIGNAL(onlineStateChanged(bool)), this,
                SLOT(onOnlineStateChanged(bool)));

        initContent();
        initActionbar();
        loadStatus();
    }

    TogglePage::~TogglePage()
    {
    }

    void TogglePage::initContent()
    {
        QmlDocument* qml = QmlDocument::create("asset:///content/TogglePage.qml").parent(this);
        qml->setContextProperty("controller", this);
        Control* root = qml->createRootObject<Control>();
        setContent(root);

        mStatusLabel = root->findChild<Label*>("statusLabel");
    }

    void TogglePage::initActionbar()
    {
        mStatusAction = ActionItem::create().parent(this).title(tr("Status")).imageSource(
                QUrl("asset:///images/ic_reload.png")).onTriggered(this, SLOT(loadStatus()));
        addAction(mStatusAction, ActionBarPlacement::OnBar);
    }

    void TogglePage::updateActionbar()
    {
        mStatusAction->setEnabled(mIsOnline && !mStatusLoading);
    }

    void TogglePage::setTogglingDoor(bool loading)
    {
        mIsTogglingDoor = loading;
        emit isTogglingDoorChanged(loading);
        updateActionbar();
    }

    void TogglePage::setStatusLoading(bool loading)
    {
        if (loading) {
            mStatusLabel->setText(tr("loading"));
        }

        mStatusLoading = loading;
        emit statusLoadingChanged(loading);
        updateActionbar();
    }

    void TogglePage::onOnlineStateChanged(bool isOnline)
    {
        mIsOnline = isOnline;
        emit isOnlineChanged(isOnline);

        if (!isOnline) {
            mStatusLabel->setText(tr("offline"));
        }

        updateActionbar();
    }

    void TogglePage::loadStatus()
    {
        if (mStatusLoading) {
            return;
        }

        setStatusLoading(true);

        DoorStatusRequest* request = new DoorStatusRequest(this);
        connect(request, SIGNAL(doorStatusResult(model::DoorStatus*)), this,
                SLOT(onDoorStatusResult(model::DoorStatus*)));
        connect(request, SIGNAL(error()), this, SLOT(onDoorStatusError()));
        request->call();
    }

    void TogglePage::onDoorStatusResult(DoorStatus* status)
    {
        static QMap<int, QString> statusMap;
        if (statusMap.isEmpty()) {
            int i = DoorStatus::STATUS_OPEN;
            statusMap[i] = tr("open");
            i = DoorStatus::STATUS_CLOSED;
            statusMap[i] = tr("closed");
            i = DoorStatus::STATUS_ERROR;
            statusMap[i] = tr("error :(");
        }
        mStatusLabel->setText(statusMap[status->status()]);

        setStatusLoading(false);

        sender()->deleteLater();
    }

    void TogglePage::onDoorStatusError()
    {
        // TODO: error

        setStatusLoading(false);

        sender()->deleteLater();
    }

    void TogglePage::openDoor()
    {
        ToggleDoorRequest* request = new ToggleDoorRequest(this);
        connect(request, SIGNAL(resultReady(model::ToggleDoor*)), this,
                SLOT(onOpenDoorResult(model::ToggleDoor*)));
        connect(request, SIGNAL(error()), this, SLOT(onOpenDoorError()));
        request->setState(ToggleDoorRequest::Open);
        request->call();
    }

    void TogglePage::onOpenDoorResult(ToggleDoor* result)
    {
        loadStatus();
        // TODO

        sender()->deleteLater();
    }

    void TogglePage::onOpenDoorError()
    {
        loadStatus();
        // TODO

        sender()->deleteLater();
    }

    void TogglePage::closeDoor()
    {
        ToggleDoorRequest* request = new ToggleDoorRequest(this);
        connect(request, SIGNAL(resultReady(model::ToggleDoor*)), this,
                SLOT(onCloseDoorResult(model::ToggleDoor*)));
        connect(request, SIGNAL(error()), this, SLOT(onCloseDoorError()));
        request->setState(ToggleDoorRequest::Close);
        request->call();
    }

    void TogglePage::onCloseDoorResult(ToggleDoor* result)
    {
        loadStatus();
        // TODO

        sender()->deleteLater();
    }

    void TogglePage::onCloseDoorError()
    {
        loadStatus();
        // TODO

        sender()->deleteLater();
    }

} /* namespace controller */
