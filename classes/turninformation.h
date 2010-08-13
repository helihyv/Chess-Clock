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

#ifndef TURNINFORMATION_H
#define TURNINFORMATION_H

/*! Turn information class

  @author Arto Hyvättinen
  @date 2010-08-13

  Store information about one turn of player

  */

class TurnInformation
{
public:
    /*! Turn information object

      @param turnId Id of turn of player
      @param white true if turn on white, false id black */
    TurnInformation(int turnId, bool white);

    int getTurnId() { return turnId_; }

    /*! Duration of turn
      @return Duration of turn in msecs */
    int getDuration() { return duration_; }

    /*! Duration of pauses during this turn
      @return Duration of pauses in msecs */
    int getPaused() { return paused_; }

    /*! Time available for this player after this turn
      @return Time available in msecs */
    int getTimeAfter();
    bool isWhiteTurn() { return white_; }

    void addTime( int msecs );
    void addPause( int msecs );

    /*! Mark turn ready

      Turn will be locked to chances.

      @param msecs Time available after this turn in msecs
      */
    void turnReady( int msecs );


protected:
    int turnId_; /*! id of turn */
    int duration_; /*! duration of turn in msecs */
    int paused_; /*! duration of pauses in msecs */
    int timeAfter_; /*! time available after this turn in msecs */
    bool turnReady_; /*! turn is ready and locked */
    bool white_; /*! turn of white player? */
};

#endif // TURNINFORMATION_H
