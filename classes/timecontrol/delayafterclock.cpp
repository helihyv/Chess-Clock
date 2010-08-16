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

#include "delayafterclock.h"

DelayAfterClock::DelayAfterClock(bool white, int delay, QWidget *parent) :
    ChessClockWidget(white, parent)
{
    delay_ = delay;
    setGreenTime( delay_);
}

TurnInformation* DelayAfterClock::endTurn()
{
    int turntime = currentTurnPlayed();

    if( turntime > delay_ )
        addTime( delay_ );  // Add whole delay
    else
        addTime( currentTurnPlayed());  // Add time of turn

    return ChessClock::endTurn();

}
