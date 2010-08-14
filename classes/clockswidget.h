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
class WelcomeScreenWidget;

class ChessClock;

/*! Widget with two clocks

    @author Arto Hyvättinen
    @date 2010-08-14

    Central widget of Chess Clock

  */
class ClocksWidget : public QWidget
{
    Q_OBJECT
public:
    ClocksWidget(QWidget *parent = 0);

    /*! Set clocks and paint them.

      */
    void setClocks(ChessClock* white, ChessClock* black);


protected:
//    void mouseReleaseEvent(QMouseEvent *event);

    void initEmptyScreen();

signals:
    void setupTouch();

public slots:

protected:
    ChessClock* white_;
    ChessClock* black_;

    QHBoxLayout* clockLayout_;

    QLabel* pauseLabel_;
    QLabel* welcomeLabel_;
    WelcomeScreenWidget* welcomeScreen_;

    enum GameStatus {
        Stopped  /*! Not running */,
        WhiteTurn,
        BlackTurn,
        WhitePause,
        BlackPause,
        NoClocks,    /*! Clocks not set ! */
        Welcome
        };

    GameStatus status_;
    QTime delayTimer_; /*! To avoid double clicks */

    static int const CLICKDELAY = 500 ; /*! Click delay in msecs */



};

#endif // CLOCKSWIDGET_H
