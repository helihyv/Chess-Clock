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

#include "hourglassclock.h"
#include "../turninformation.h"

HourGlassClock::HourGlassClock(bool white, QWidget *parent) :
    ChessClockWidget(white, parent)
{
}


int HourGlassClock::getTimeAvailable()
{
    if( !another_)
        return timeAvailableBeforeTurn_;

    if( currentTurn_ )
    {
        return timeAvailableBeforeTurn_ - currentTurnPlayed();
    }
    else
    {
        return timeAvailableBeforeTurn_ + another_->currentTurnPlayed();
    }
}


TurnInformation* HourGlassClock::endTurn()
{
    updateTimer_.stop();
    status_ = NotRunning;

    updateClock();

    timePlayedBeforeTurn_ = getTimePlayed();

    // Count available times of BOTH the clocks!
    setTimeAvailable( getTimeAvailable() );
    another_->setTimeAvailable( another_->getTimeAvailable());

    // Close and return turn information
    currentTurn_->turnReady(timeAvailableBeforeTurn_ );
    TurnInformation* information = currentTurn_;
    currentTurn_ = 0;

    emit turnEnded();
    return information;
}

void HourGlassClock::updateClock()
{
    ChessClock::updateClock();
    another_->ChessClock::updateClock();
}
