 /**************************************************************************;

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

#include "fischertimecontrol.h"
#include "fischerclock.h"
#include "../clockswidget.h"
#include "basicdialog.h"

#include <QApplication>


FischerTimeControl::FischerTimeControl()
{
}

QString FischerTimeControl::getDescription()
{
    return qApp->translate("Fischer","Specified time increment is added to clock before turn.");
}

QIcon FischerTimeControl::getIcon()
{
    return QIcon(":/rc/pic/addbefore.png");
}

ClocksWidget* FischerTimeControl::initGame(bool useLastSettings)
{
    BasicDialog dialog(getName());
    dialog.init();

    if( useLastSettings || dialog.exec() == QDialog::Accepted)
    {
        dialog.store();
        FischerClock* white = new FischerClock( true, dialog.getWhiteAddition(), dialog.getWhitePerTurns());
        white->setTimeAvailable(dialog.getWhiteInitial());

        FischerClock* black = new FischerClock( false, dialog.getBlackAddition(), dialog.getBlackPerTurns());
        black->setTimeAvailable( dialog.getBlackInitial());

        return( new ClocksWidget(white,black));

    }
    else
        return 0;
}
