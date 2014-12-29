#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>

namespace bb
{
    namespace cascades
    {
        class LocaleHandler;
        class Page;
    }
    namespace system
    {
        class InvokeManager;
    }
}

class QTranslator;

class ApplicationUI: public QObject
{
    Q_OBJECT

public:
    ApplicationUI();
    virtual ~ApplicationUI()
    {
    }

    Q_INVOKABLE
    void resendNotification();

private slots:
    void onSystemLanguageChanged();

    void onPopTransitionEnded(bb::cascades::Page*);

    void onOpenSettings();

private:
    void initUI();
    void initAppMenu();

    QTranslator* mTranslator;
    bb::cascades::LocaleHandler* mLocaleHandler;
    bb::system::InvokeManager* mInvokeManager;
};

#endif /* ApplicationUI_HPP_ */
