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

#ifndef CHESSCLOCK_H
#define CHESSCLOCK_H

#include <QWidget>
#include <QTime>
#include <QTimer>

class TurnInformation;


/*! Clock of a individual player

  @author Arto Hyvättinen
  @date 2010-08-13

  Base class of chess clock.

  */
class ChessClock : public QWidget
{
    Q_OBJECT
public:
    ChessClock(bool white, QWidget *parent = 0);

public:
    enum RunningStatus {
        NotRunning /*! Not turn  */ = 0,
        Running /*! Turn running */ = 1,
        Paused /*! Turn paused */ = 2
    };

    bool isLoser() const  { return loser_; }
    int getTurn() const  { return turn_; }


    /*! Start new turn */
    virtual void startTurn();

    /*! End this turn.

      Player has done his move.
      @return Locked turn information */
    virtual TurnInformation* endTurn();

    /*! Pause clock */
    virtual void pauseTurn();

    /*! Continue paused game */
    virtual void continueTurn();

    /*! Set another chess clock for connecting
      @param another Clock of opposite player */
    void setAnother( ChessClock* another);

    /*! Get total time available

      Time does't contain delays.

      @return Time available in msecs */
    virtual int getTimeAvailable();

signals:
    void timeOut();

public slots:    

    /*! Refresh clock information */
    virtual void repaintClock() = 0;


protected:
    ChessClock* another_; /*! Another player's clock */

    bool loser_;        /*! Is player losed because of timeout */
    int turn_;          /*! Current turn */
    RunningStatus status_;
    TurnInformation* currentTurn_;

    int timePlayed_;    /*! Time played in this game */
    int timeAvailableBeforeTurn_; /*! Time available for play BEFORE this turn!*/

    bool isWhite_;      /*! True if white player */

    QTime clockTime_;
    QTimer updateTimer_;

    static const int UPDATEINTERVAL = 1000; /** Clock updating interval in msecs */

};

#endif // CHESSCLOCK_H
