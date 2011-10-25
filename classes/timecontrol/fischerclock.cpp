 /**************************************************************************

    Chess Clock

    Copyright (c) Arto Hyvättinen 2010
    Fix that prevents time to be added at first turn if perTurns > 1
    (c) Heli Hyvättinen 2011

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

#include "fischerclock.h"

FischerClock::FischerClock(bool white, int addition, int perTurns,  QWidget *parent) :
    ChessClockWidget(white, parent)
{
    addition_ = addition;
    perTurns_ = perTurns;

    setGreenTime( addition );
}

void FischerClock::startTurn()
{
    //The turn number is incremented in ChessClock::startTurn(), here it is real - 1!
    //The +1 is needed to compensate for that.
    //Otherwise it always increments at the first turn as 0 % x is always 0.
    //(And increments at right interval but wrong turns for the rest of the game).
    //Added by Heli Hyvättinen 25 Oct 2011


    if(getTurn()+1 % perTurns_ == 0)
        addTime( addition_ );
    ChessClock::startTurn();
}
