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

#ifndef DELAYCLOCK_H
#define DELAYCLOCK_H

#include "../chessclockwidget.h"
/*! Simple delay

  @author Arto Hyvättinen
  @date 2010-08-16



  */
class DelayClock : public ChessClockWidget
{
    Q_OBJECT
public:
    DelayClock(bool white, int delay, QWidget *parent = 0);

    int getTimeAvailable();
signals:

public slots:

protected:
    int delay_;


};

#endif // DELAYCLOCK_H
