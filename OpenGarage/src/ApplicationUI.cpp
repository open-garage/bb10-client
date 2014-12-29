#include "ApplicationUI.hpp"
#include <bb/cascades/Application>
#include <bb/cascades/LocaleHandler>
#include <bb/system/InvokeManager>
#include "controller/TogglePage.h"
#include <bb/cascades/NavigationPane>
#include <bb/cascades/Page>
#include <bb/cascades/Menu>
#include <bb/cascades/SettingsActionItem>
#include "controller/SettingsSheet.h"

using namespace controller;
using namespace bb::cascades;
using namespace bb::system;

ApplicationUI::ApplicationUI() :
        QObject(), mTranslator(new QTranslator(this)), mLocaleHandler(new LocaleHandler(this)), mInvokeManager(
                new InvokeManager(this))
{
    if (!QObject::connect(mLocaleHandler, SIGNAL(systemLanguageChanged()), this,
            SLOT(onSystemLanguageChanged()))) {
        qWarning() << "Recovering from a failed connect()";
    }

    onSystemLanguageChanged();

    initUI();
    initAppMenu();
}

ApplicationUI::~ApplicationUI()
{
}

void ApplicationUI::onSystemLanguageChanged()
{
    QCoreApplication::instance()->removeTranslator(mTranslator);
    QString locale_string = QLocale().name();
    QString file_name = QString("OpenGarage_%1").arg(locale_string);
    if (mTranslator->load(file_name, "app/native/qm")) {
        QCoreApplication::instance()->installTranslator(mTranslator);
    }
}
void ApplicationUI::onPopTransitionEnded(Page* page)
{
    if (page != NULL) {
        page->deleteLater();
    }
}

void ApplicationUI::initUI()
{
    NavigationPane* pane = new NavigationPane(this);
    connect(pane, SIGNAL(popTransitionEnded(bb::cascades::Page*)), this,
            SLOT(onPopTransitionEnded(bb::cascades::Page*)));

    TogglePage* page = new TogglePage(pane);
    pane->push(page);

    Application::instance()->setScene(pane);
}

void ApplicationUI::initAppMenu()
{
    SettingsActionItem* settingsAction =
            SettingsActionItem::create().title(tr("Settings")).onTriggered(this,
                    SLOT(onOpenSettings()));

    Menu* menu = Menu::create().settings(settingsAction);
    Application::instance()->setMenu(menu);
}

void ApplicationUI::onOpenSettings()
{
    SettingsSheet::open();
}

void ApplicationUI::resendNotification()
{
    //InvokeRequest request;
    //request.setTarget("com.example.OpenGarageService");
    //request.setAction("com.example.OpenGarageService.RESET");
    //m_invokeManager->invoke(request);
    //Application::instance()->minimize();
}
