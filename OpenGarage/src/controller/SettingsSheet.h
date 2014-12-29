/*
 * SettingsSheet.h
 *
 *  Created on: Dec 29, 2014
 *      Author: dustin
 */

#ifndef SETTINGSSHEET_H_
#define SETTINGSSHEET_H_

#include <bb/cascades/Sheet>

namespace bb
{
    namespace cascades
    {
        class UIObject;
    } // namespace cascades
} // namespace bb

namespace controller
{

    class SettingsSheet
    {
    public:
        static bb::cascades::Sheet* create(bb::cascades::UIObject* parent = 0);
        static void open(bb::cascades::UIObject* parent = 0);

        virtual ~SettingsSheet();

    private:
        SettingsSheet();
    };

} /* namespace controller */

#endif /* SETTINGSSHEET_H_ */
