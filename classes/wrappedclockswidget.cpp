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


WrappedClocksWidget::WrappedClocksWidget(QObject *parent) :
    QGraphicsProxyWidget()
{
    pClocksWidget_ = NULL;
    pWhiteClock_ = NULL;
    pBlackClock_ = NULL;
}

void WrappedClocksWidget::startGame(QString timeControl, int whiteInitialTime, int whiteAdditionalTime, int whiteTurnsPerAddition, int blackInitialTime, int blackAdditionalTime, int blackTurnsPerAddition)
{

    deleteOldWidgets();

    pWhiteClock_ = new ChessClockWidget(true);
    pWhiteClock_->setTimeAvailable(whiteInitialTime);

    pBlackClock_ = new ChessClockWidget(false);
    pBlackClock_->setTimeAvailable(blackInitialTime);

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
        delete pClocksWidget_;
        pClocksWidget_ = NULL;
    }

    if (pWhiteClock_)
    {
        delete pWhiteClock_;
        pWhiteClock_ = NULL;
    }

    if (pBlackClock_)
    {
        delete pBlackClock_;
        pBlackClock_ = NULL;
    }
}

