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

#ifndef CHESSCLOCKWINDOW_H
#define CHESSCLOCKWINDOW_H

#include <QtGui/QMainWindow>

class ClocksWidget;
class StartWidget;
class TimeControl;
class QStackedWidget;
class TurnInformation;

class ChessClockWindow : public QMainWindow
{
    Q_OBJECT

public:
    ChessClockWindow(QWidget *parent = 0);
    ~ChessClockWindow();

public slots:
    void startGame( TimeControl* timecontrol);
    void pause();
    void newGame();
    /*! Visit ChessClock web page */
    void visitWeb();
    void about();
    void aboutQt();
    /*! Delete turn information to avoid memory leaks

      @todo Save turn log and function to show it.
    @since 1.1.2 */
    void dontEatMemory(TurnInformation* turnInformation);


protected:
    void initTimeControls();
    /*! Pauses the game if the application main window is not active e.g. the app is minimized*/
    bool eventFilter(QObject *obj, QEvent *event);

protected:
    ClocksWidget*   clocks_;
    StartWidget* start_;
    QStackedWidget* stack_;
};

#endif // CHESSCLOCKWINDOW_H
