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

#include "fischeraftertimecontrol.h"
#include "fischerafterclock.h"
#include "../clockswidget.h"
#include "basicdialog.h"


FischerAfterTimeControl::FischerAfterTimeControl()
{
}

QString FischerAfterTimeControl::getDescription()
{
    return qApp->translate("FischerAfter","Specified time increment is added to clock after turn.");
}

QIcon FischerAfterTimeControl::getIcon()
{
    return QIcon(":/rc/pic/addafter.png");
}

ClocksWidget* FischerAfterTimeControl::initGame(bool useLastSettings)
{
    BasicDialog dialog(getName());
    dialog.init();

    if( useLastSettings || dialog.exec() == QDialog::Accepted)
    {
        dialog.store();
        FischerAfterClock* white = new FischerAfterClock( true, dialog.getWhiteAddition(), dialog.getWhitePerTurns());
        white->setTimeAvailable(dialog.getWhiteInitial());

        FischerAfterClock* black = new FischerAfterClock( false, dialog.getBlackAddition(), dialog.getBlackPerTurns());
        black->setTimeAvailable( dialog.getBlackInitial());

        return( new ClocksWidget(white,black));

    }
    else
        return 0;
}
