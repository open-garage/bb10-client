/*
 * SettingsPage.h
 *
 *  Created on: Dec 29, 2014
 *      Author: dustin
 */

#ifndef SETTINGSPAGE_H_
#define SETTINGSPAGE_H_

#include <bb/cascades/Page>
#include <bb/system/SystemUiResult>

namespace bb
{
    namespace cascades
    {
        class Sheet;
        class StandardListItem;
    } // namespace cascades
} // namespace bb
namespace model
{
    class SystemInfos;
} // namespace model

namespace controller
{

    class SettingsPage: public bb::cascades::Page
    {
        Q_OBJECT

    public:
        SettingsPage(QObject* parent = 0);
        virtual ~SettingsPage();

    public slots:
        void onServerHostTapped();
        void onServerPortTapped();
        void onApiTokenTapped();

    private slots:
        void onSystemInfosResult(model::SystemInfos*);
        void onSystemInfosError();

        void onServerHostEntered(bb::system::SystemUiResult::Type);
        void onServerPortEntered(bb::system::SystemUiResult::Type);
        void onApiTokenEntered(bb::system::SystemUiResult::Type);

        void onClose();

    private:
        void initTitleBar();
        void initContent();
        void loadSettings();
        void loadServerInfo();

        bb::cascades::Sheet* sheet();

        bb::cascades::StandardListItem* mServerHostItem;
        bb::cascades::StandardListItem* mServerPortItem;
        bb::cascades::StandardListItem* mApiTokenItem;
        bb::cascades::StandardListItem* mServerNameItem;
        bb::cascades::StandardListItem* mServerVersionItem;
    };

} /* namespace controller */

#endif /* SETTINGSPAGE_H_ */
