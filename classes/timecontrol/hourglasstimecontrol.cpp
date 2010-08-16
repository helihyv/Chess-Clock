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

#include "hourglasstimecontrol.h"
#include "hourglassclock.h"
#include "../clockswidget.h"
#include "basicdialog.h"

#include <QApplication>
#include <QTime>

HourGlassTimeControl::HourGlassTimeControl()
{
}


QString HourGlassTimeControl::getName()
{
    return qApp->translate("Hour Glass","Hour Glass");
}

QIcon HourGlassTimeControl::getIcon()
{
    return QIcon(":/rc/pic/hourglass.png");
}

QString HourGlassTimeControl::getDescription()
{
    return qApp->translate("Hour Glass","Time added to clock is substracted to another");
}

ClocksWidget* HourGlassTimeControl::initGame(bool useLastSettings)
{
    BasicDialog dialog(getName());
    dialog.disableAddition();
    dialog.init(QTime(0,0,30),QTime(0,0,30));

    if( useLastSettings || dialog.exec() == QDialog::Accepted)
    {
        dialog.store();
        HourGlassClock* white = new HourGlassClock( true);
        white->setTimeAvailable(dialog.getWhiteInitial());

        HourGlassClock* black = new HourGlassClock( false);
        black->setTimeAvailable( dialog.getBlackInitial());

        return( new ClocksWidget(white,black));

    }
    else
        return 0;
}
