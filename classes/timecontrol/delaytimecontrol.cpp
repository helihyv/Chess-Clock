 /**************************************************************************

    Chess Clock

    Copyright (c) Arto Hyvättinen 2010

    This file is part of Chess Clock software.

    Chess Clock is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Chess Clock is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.


**************************************************************************/

#include "delaytimecontrol.h"
#include "delayclock.h"
#include "../clockswidget.h"
#include "basicdialog.h"

#include <QApplication>

DelayTimeControl::DelayTimeControl()
{
}

QString DelayTimeControl::getName()
{
    return qApp->translate("Delay","Delay");
}

QIcon DelayTimeControl::getIcon()
{
    return QIcon(":/rc/pic/pausebefore.png");
}

QString DelayTimeControl::getDescription()
{
    return qApp->translate("Delay","The clock waits for the delay period before starting");
}

ClocksWidget* DelayTimeControl::initGame(bool useLastSettings)
{
    BasicDialog dialog(getName());
    dialog.disablePerTurns();
    dialog.init();

    if( useLastSettings || dialog.exec() == QDialog::Accepted)
    {
        dialog.store();
        DelayClock* white = new DelayClock( true, dialog.getWhiteAddition());
        white->setTimeAvailable(dialog.getWhiteInitial());

        DelayClock* black = new DelayClock( false, dialog.getBlackAddition());
        black->setTimeAvailable( dialog.getBlackInitial());

        return( new ClocksWidget(white,black));

    }
    else
        return 0;
}
