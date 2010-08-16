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

#include "notimecontrol.h"

#include "../chessclock.h"
#include "basicdialog.h"
#include "../chessclockwidget.h"
#include "../clockswidget.h"

#include <QApplication>

NoTimeControl::NoTimeControl()
{
}


QString NoTimeControl::getDescription()
{
    return qApp->translate("NoneTimeControl","Never add time.");
}

QIcon NoTimeControl::getIcon()
{
    return QIcon(":/rc/pic/oldclock.png");
}

ClocksWidget* NoTimeControl::initGame(bool useLastSettings)
{
    BasicDialog dialog(getName());

    dialog.disableAddition();
    dialog.init();

    if( useLastSettings || dialog.exec() == QDialog::Accepted)
    {
        dialog.store();
        ChessClockWidget* white = new ChessClockWidget(true);
        white->setTimeAvailable(dialog.getWhiteInitial());

        ChessClockWidget* black = new ChessClockWidget(false);
        black->setTimeAvailable( dialog.getBlackInitial());

        return( new ClocksWidget(white,black));

    }
    else
        return 0;
}
