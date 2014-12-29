/*
 * SettingsPage.cpp
 *
 *  Created on: Dec 29, 2014
 *      Author: dustin
 */

#include "SettingsPage.h"
#include <bb/cascades/QmlDocument>
#include <bb/cascades/Control>
#include <bb/cascades/TitleBar>
#include <bb/cascades/ActionItem>
#include <bb/cascades/Sheet>
#include <bb/cascades/StandardListItem>
#include "../api/OpenGarageService.h"
#include "../api/SystemInfosRequest.h"
#include "../model/SystemInfos.h"
#include <bb/system/SystemPrompt>

using namespace api;
using namespace model;
using namespace bb::cascades;
using namespace bb::system;

namespace controller
{

    SettingsPage::SettingsPage(QObject* parent) :
            Page(parent)
    {
        initTitleBar();
        initContent();
        loadServerInfo();
    }

    SettingsPage::~SettingsPage()
    {
    }

    void SettingsPage::initTitleBar()
    {
        ActionItem* dismissAction = ActionItem::create().title(tr("Close")).onTriggered(this,
                SLOT(onClose()));

        TitleBar* titleBar =
                TitleBar::create(TitleBarKind::Default).title(tr("Settings")).dismissAction(
                        dismissAction);
        setTitleBar(titleBar);
    }

    void SettingsPage::initContent()
    {
        QmlDocument* qml = QmlDocument::create("asset:///content/SettingsPage.qml").parent(this);
        qml->setContextProperty("controller", this);
        Control* root = qml->createRootObject<Control>();
        setContent(root);

        mServerHostItem = root->findChild<StandardListItem*>("serverHostItem");
        mServerPortItem = root->findChild<StandardListItem*>("serverPortItem");
        mApiTokenItem = root->findChild<StandardListItem*>("apiTokenItem");
        mServerNameItem = root->findChild<StandardListItem*>("serverNameItem");
        mServerVersionItem = root->findChild<StandardListItem*>("serverVersionItem");

        loadSettings();
    }

    void SettingsPage::loadSettings()
    {
        QString serverHost = OpenGarageService::instance()->serverHost();
        int serverPort = OpenGarageService::instance()->serverPort();
        QString apiToken = OpenGarageService::instance()->apiToken();

        mServerHostItem->setDescription(serverHost);
        mServerPortItem->setDescription(QString::number(serverPort));
        mApiTokenItem->setDescription(apiToken);
    }

    void SettingsPage::loadServerInfo()
    {
        SystemInfosRequest* request = new SystemInfosRequest(this);
        connect(request, SIGNAL(resultReady(model::SystemInfos*)), this,
                SLOT(onSystemInfosResult(model::SystemInfos*)));
        connect(request, SIGNAL(error()), this, SLOT(onSystemInfosError()));
        request->call();
    }

    void SettingsPage::onSystemInfosResult(model::SystemInfos* infos)
    {
        mServerNameItem->setDescription(infos->name());
        mServerVersionItem->setDescription(infos->version());

        sender()->deleteLater();
    }

    void SettingsPage::onSystemInfosError()
    {
        // TODO: show error stuff
        mServerNameItem->setDescription("?");
        mServerVersionItem->setDescription("?");

        sender()->deleteLater();
    }

    void SettingsPage::onServerHostTapped()
    {
        SystemPrompt* prompt = new SystemPrompt(this);
        prompt->setTitle(tr("Set Server Host"));
        prompt->inputField()->setEmptyText(tr("e.g. localhost"));
        prompt->inputField()->setDefaultText(mServerHostItem->description());
        connect(prompt, SIGNAL(finished(bb::system::SystemUiResult::Type)), this,
                SLOT(onServerHostEntered(bb::system::SystemUiResult::Type)));
        prompt->show();
    }

    void SettingsPage::onServerHostEntered(SystemUiResult::Type type)
    {
        SystemPrompt* prompt = qobject_cast<SystemPrompt*>(sender());
        if (type == SystemUiResult::ConfirmButtonSelection) {
            QString value = prompt->inputFieldTextEntry();
            // TODO: validate!
            if (value != mServerHostItem->description()) {
                OpenGarageService::instance()->setServerHost(value);
                mServerHostItem->setDescription(value);

                loadServerInfo();
            }
        }

        prompt->deleteLater();
    }

    void SettingsPage::onServerPortTapped()
    {
        SystemPrompt* prompt = new SystemPrompt(this);
        prompt->setTitle(tr("Set Server Port"));
        prompt->inputField()->setInputMode(SystemUiInputMode::NumericKeypad);
        prompt->inputField()->setEmptyText(tr("e.g. 8000"));
        prompt->inputField()->setDefaultText(mServerPortItem->description());
        connect(prompt, SIGNAL(finished(bb::system::SystemUiResult::Type)), this,
                SLOT(onServerPortEntered(bb::system::SystemUiResult::Type)));
        prompt->show();
    }

    void SettingsPage::onServerPortEntered(SystemUiResult::Type type)
    {
        SystemPrompt* prompt = qobject_cast<SystemPrompt*>(sender());
        if (type == SystemUiResult::ConfirmButtonSelection) {
            QString value = prompt->inputFieldTextEntry();
            if (value != mServerPortItem->description()) {
                bool ok = false;
                int intValue = value.toInt(&ok);
                if (!ok) {
                    // TODO: show error
                } else {
                    OpenGarageService::instance()->setServerPort(intValue);
                    mServerPortItem->setDescription(value);

                    loadServerInfo();
                }
            }
        }

        prompt->deleteLater();
    }

    void SettingsPage::onApiTokenTapped()
    {
        SystemPrompt* prompt = new SystemPrompt(this);
        prompt->setTitle(tr("Set API Token"));
        prompt->setBody(tr("You should have received one from your Open Garage Admin"));
        prompt->inputField()->setDefaultText(mApiTokenItem->description());
        connect(prompt, SIGNAL(finished(bb::system::SystemUiResult::Type)), this,
                SLOT(onApiTokenEntered(bb::system::SystemUiResult::Type)));
        prompt->show();
    }

    void SettingsPage::onApiTokenEntered(SystemUiResult::Type type)
    {
        SystemPrompt* prompt = qobject_cast<SystemPrompt*>(sender());
        if (type == SystemUiResult::ConfirmButtonSelection) {
            QString value = prompt->inputFieldTextEntry();
            // TODO: validate!
            if (value != mApiTokenItem->description()) {
                OpenGarageService::instance()->setApiToken(value);
                mApiTokenItem->setDescription(value);

                loadServerInfo();
            }
        }

        prompt->deleteLater();
    }

    void SettingsPage::onClose()
    {
        Sheet* s = sheet();
        if (s == NULL) {
            return;
        }

        // TODO: save settings
        s->close();
    }

    Sheet* SettingsPage::sheet()
    {
        return qobject_cast<Sheet*>(parent());
    }

} /* namespace controller */
