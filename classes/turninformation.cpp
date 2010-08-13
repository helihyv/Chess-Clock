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

#include "turninformation.h"

TurnInformation::TurnInformation(int turnId, bool white)
{
    turnId_ = turnId;
    white_ = white;
    duration_ = 0;
    paused_ = 0;
    turnReady_ = false;
}


void TurnInformation::addTime(int msecs)
{
    if( !turnReady_ )
        duration_ += msecs;
}

void TurnInformation::addPause(int msecs)
{
    if( !turnReady_ )
        pause_ += msecs;
}

void TurnInformation::turnReady(int msecs)
{
    timeAfter_ = msecs;
    turnReady_ = true;
}

int TurnInformation::getTimeAfter()
{
    if( turnReady_ )
        return timeAfter_;
    else
        return 0;
}
