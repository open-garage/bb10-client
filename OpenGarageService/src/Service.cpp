#include "Service.hpp"
#include <bb/Application>
#include <bb/platform/Notification>
#include <bb/platform/NotificationDefaultApplicationSettings>
#include <bb/system/InvokeManager>
#include <QTimer>

using namespace bb::platform;
using namespace bb::system;

Service::Service() :
        QObject(), m_notify(new Notification(this)), m_invokeManager(new InvokeManager(this))
{
    m_invokeManager->connect(m_invokeManager, SIGNAL(invoked(const bb::system::InvokeRequest&)),
            this, SLOT(handleInvoke(const bb::system::InvokeRequest&)));

    NotificationDefaultApplicationSettings settings;
    settings.setPreview(NotificationPriorityPolicy::Allow);
    settings.apply();

    //m_notify->setTitle("OpenGarage Service");
    //m_notify->setBody("OpenGarage service requires attention");

    //bb::system::InvokeRequest request;
    //request.setTarget("com.example.OpenGarage");
    //request.setAction("bb.action.START");
    //m_notify->setInvokeRequest(request);

    //onTimeout();
}

void Service::handleInvoke(const bb::system::InvokeRequest & request)
{
    if (request.action().compare("com.example.OpenGarageService.RESET") == 0) {
        triggerNotification();
    }
}

void Service::triggerNotification()
{
    // Timeout is to give time for UI to minimize
    QTimer::singleShot(2000, this, SLOT(onTimeout()));
}

void Service::onTimeout()
{
    Notification::clearEffectsForAll();
    Notification::deleteAllFromInbox();
    m_notify->notify();
}
