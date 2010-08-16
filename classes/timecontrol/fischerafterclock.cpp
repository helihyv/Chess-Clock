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

#include "fischerafterclock.h"

FischerAfterClock::FischerAfterClock(bool white, int addition, int perTurns, QWidget *parent) :
    ChessClockWidget(white, parent)
{
    addition_ = addition;
    perTurns_ = perTurns;

    setGreenTime( addition );
}

TurnInformation* FischerAfterClock::endTurn()
{
    if( getTurn() % perTurns_ == 0)
        addTime( addition_ );
    return ChessClock::endTurn() ;
}
