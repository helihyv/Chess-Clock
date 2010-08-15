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

#ifndef TIMECONTROL_H
#define TIMECONTROL_H

#include <QString>
#include <QIcon>
class ClocksWidget;

/*! Base class of virtual controls

  @author Arto Hyvättinen
  @date 2010-08-15

  */
class TimeControl
{
public:
    /*! Name of the time control */
    virtual QString getName() = 0;
    /*! Description of the time control */
    virtual QString getDescription() = 0;
    /*! Icon of the time control */
    virtual QIcon getIcon() { return QIcon(":/rc/pic/chessclock.png"); }
    /*! Init new game

      Ask options, and init new game.
      @param useLastSettings Use last settings, don't ask
      @return Clocks widget for new game, or NULL if unsuccess. */
    virtual ClocksWidget* initGame(bool useLastSettings=false) = 0;
};


#endif // TIMECONTROL_H
