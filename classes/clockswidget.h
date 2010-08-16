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

#ifndef CLOCKSWIDGET_H
#define CLOCKSWIDGET_H

#include <QWidget>
#include <QTime>

class QHBoxLayout;
class QVBoxLayout;
class QLabel;
class TurnInformation;

class ChessClock;

/*! Widget with two clocks

    @author Arto Hyvättinen
    @date 2010-08-14

    Central widget of Chess Clock.
    Needed to create new ClocksWidget to
    every new game.

  */
class ClocksWidget : public QWidget
{
    Q_OBJECT
public:
    ClocksWidget(ChessClock* white, ChessClock* black, QWidget *parent = 0);
    bool isPlayStarted()  { return (status_!=Welcome); }

protected:
    void mouseReleaseEvent(QMouseEvent *event);


signals:
   void TurnFinished(TurnInformation* turnInfo);
   void ClickedWhenStopped();

public slots:
   /*! Pause game */
    void pause();
    /*! End the game */
    void stopPlay();

protected:
    ChessClock* white_;
    ChessClock* black_;

    QLabel* pauseLabel_;
    QLabel* welcomeLabel_;

    enum GameStatus {
        Stopped  /*! Not running */,
        WhiteTurn,
        BlackTurn,
        WhitePause,
        BlackPause,
        Welcome
        };

    GameStatus status_;
    QTime delayTimer_; /*! To avoid double clicks */

    static int const CLICKDELAY = 500 ; /*! Click delay in msecs */



};

#endif // CLOCKSWIDGET_H
