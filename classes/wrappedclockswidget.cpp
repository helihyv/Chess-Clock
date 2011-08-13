/**************************************************************************

   Chess Clock

   This file is part of Chess Clock software.

   (This file) Copyright (c) Heli Hyvättinen 2011

   Chess Clock is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Chess Clock is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.


**************************************************************************/


#include "wrappedclockswidget.h"
#include "classes/timecontrol/hourglassclock.h"
#include "classes/timecontrol/delayclock.h"
#include "classes/timecontrol/delayafterclock.h"
#include "classes/timecontrol/fischerclock.h"
#include "classes/timecontrol/fischerafterclock.h"
#include "classes/chessclockwidget.h"
#include <QDebug>


WrappedClocksWidget::WrappedClocksWidget(QObject *parent) :
    QGraphicsProxyWidget()
{
    pClocksWidget_ = NULL;
    pWhiteClock_ = NULL;
    pBlackClock_ = NULL;
}

void WrappedClocksWidget::startGame(TimeControlType timeControl, int whiteInitialTime, int whiteAdditionalTime, int whiteTurnsPerAddition, int blackInitialTime, int blackAdditionalTime, int blackTurnsPerAddition)
{

    deleteOldWidgets();


    switch (timeControl)
    {
        case NormalClock:

            pWhiteClock_ = new ChessClockWidget (true);
            pWhiteClock_->setTimeAvailable(whiteInitialTime);

            pBlackClock_ = new ChessClockWidget (false);
            pBlackClock_->setTimeAvailable(blackInitialTime);

            break;

        case AdditionBefore:

            pWhiteClock_ = new FischerClock (true,whiteAdditionalTime,whiteTurnsPerAddition);
            pWhiteClock_->setTimeAvailable(whiteInitialTime);

            pBlackClock_ = new FischerClock (false,blackAdditionalTime,blackTurnsPerAddition);
            pBlackClock_->setTimeAvailable(blackInitialTime);

            break;

        case AdditionAfter:

            pWhiteClock_ = new FischerAfterClock (true,whiteAdditionalTime,whiteTurnsPerAddition);
            pWhiteClock_->setTimeAvailable(whiteInitialTime);

            pBlackClock_ = new FischerAfterClock (false,blackAdditionalTime,blackTurnsPerAddition);
            pBlackClock_->setTimeAvailable(blackInitialTime);

            break;

        case Delay:

            pWhiteClock_ = new DelayClock (true,whiteAdditionalTime);
            pWhiteClock_->setTimeAvailable(whiteInitialTime);

            pBlackClock_ = new DelayClock (false,blackAdditionalTime);
            pBlackClock_->setTimeAvailable(blackInitialTime);

            break;

        case DelayAfter:

            pWhiteClock_ = new DelayAfterClock (true,whiteAdditionalTime);
            pWhiteClock_->setTimeAvailable(whiteInitialTime);

            pBlackClock_ = new DelayAfterClock (false,blackAdditionalTime);
            pBlackClock_->setTimeAvailable(blackInitialTime);

            break;

        case HourGlass:

            pWhiteClock_ = new HourGlassClock (true);
            pWhiteClock_->setTimeAvailable(whiteInitialTime);

            pBlackClock_ = new HourGlassClock (false);
            pBlackClock_->setTimeAvailable(blackInitialTime);

            break;


        default:

        //QML has no type safety for enums (using int for real!)
        //So there is possibility of getting invalid values if there is a bug in QML files

        //Defaulting to normal clock


        qDebug() << "Invalid time control type. Defaulting to Normal Clock.";

        pWhiteClock_ = new ChessClockWidget (true);
        pWhiteClock_->setTimeAvailable(whiteInitialTime);

        pBlackClock_ = new ChessClockWidget (false);
        pBlackClock_->setTimeAvailable(blackInitialTime);

        break;


    }


    pClocksWidget_ = new ClocksWidget(pWhiteClock_, pBlackClock_);

    pClocksWidget_->setAttribute(Qt::WA_NoSystemBackground);
    setWidget(pClocksWidget_);

}

 WrappedClocksWidget::~WrappedClocksWidget()
{
     deleteOldWidgets();
}

bool WrappedClocksWidget::isPlayStarted()
{
    if (!pClocksWidget_)
        return false;

    return  pClocksWidget_->isPlayStarted();
}

void WrappedClocksWidget::deleteOldWidgets()
{


    if (pClocksWidget_)
    {
        pClocksWidget_->deleteLater();
        pClocksWidget_ = NULL;
    }

    if (pWhiteClock_)
    {
        pWhiteClock_->deleteLater();
        pWhiteClock_ = NULL;
    }

    if (pBlackClock_)
    {
        pBlackClock_->deleteLater();
        pBlackClock_ = NULL;
    }
}

void WrappedClocksWidget::pause()
{
    if (pClocksWidget_)
        pClocksWidget_->pause();
}

void WrappedClocksWidget::stopPlay()
{
    if (pClocksWidget_)
        pClocksWidget_->stopPlay();
}

void WrappedClocksWidget::saveScreen()
{
    if (pClocksWidget_)
        pClocksWidget_->saveScreen();
}

