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

#ifndef DELAYTIMECONTROL_H
#define DELAYTIMECONTROL_H

#include "../timecontrol.h"

class DelayTimeControl : public TimeControl
{
public:
    DelayTimeControl();

    QString getName();
    QIcon getIcon();
    QString getDescription();
    ClocksWidget* initGame(bool useLastSettings);
};

#endif // DELAYTIMECONTROL_H
