/*
 * SettingsSheet.cpp
 *
 *  Created on: Dec 29, 2014
 *      Author: dustin
 */

#include "SettingsSheet.h"
#include "SettingsPage.h"
#include <bb/cascades/UIObject>

using namespace bb::cascades;

namespace controller
{

    Sheet* SettingsSheet::create(UIObject* parent)
    {
        Sheet* sheet = Sheet::create().parent(parent).content(new SettingsPage());
        QObject::connect(sheet, SIGNAL(closed()), sheet, SLOT(deleteLater()));
        return sheet;
    }

    void SettingsSheet::open(UIObject* parent)
    {
        create(parent)->open();
    }

    SettingsSheet::SettingsSheet()
    {
    }

    SettingsSheet::~SettingsSheet()
    {
    }

} /* namespace controller */
