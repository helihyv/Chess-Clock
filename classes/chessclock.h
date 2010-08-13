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

  ChessClock has not GUI itself, but it is subclass of QWidget
  avoiding polymorphism.

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
    bool isWhite() const { return isWhite_; }
    RunningStatus getStatus() const { return status_ ; }


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

    /*! Get total time played
      @return Time played in msecs */
    virtual int getTimePlayed() const;

    /*! Set time available

      @param msecs Time available in msecs */
    void setTimeAvailable(int msecs);


signals:
    void timeOutLoser();
    void endTurn();

public slots:    

    /*! Refresh clock information */
    virtual void repaintClock() = 0;

    /*! Update clock information, check looser state and refresh */
    virtual void updateClock();

private:
    ChessClock* another_; /*! Another player's clock */

    bool loser_;        /*! Is player losed because of timeout */
    int turn_;          /*! Current turn */
    RunningStatus status_;
    TurnInformation* currentTurn_;

    int timePlayedBeforeTurn_;    /*! Time played in this game BEFORE this turn msecs */
    int timeAvailableBeforeTurn_; /*! Time available for play BEFORE this turn msecs !*/

    bool isWhite_;      /*! True if white player */

    QTime clockTime_;
    QTimer updateTimer_;

    static const int UPDATEINTERVAL = 1000; /** Clock updating interval in msecs */

};

#endif // CHESSCLOCK_H
