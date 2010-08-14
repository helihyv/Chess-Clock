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

#include "chessclockwindow.h"

#include "classes/clockswidget.h"
#include "classes/chessclockwidget.h"

#include <QIcon>
#include <QApplication>

ChessClockWindow::ChessClockWindow(QWidget *parent)
    : QMainWindow(parent)
{

    setWindowIcon( QIcon(":/rc/pic/chessclock.png"));
    setWindowTitle( QString("%1 %2").arg(qApp->applicationName()).arg(qApp->applicationVersion()) );

    ChessClockWidget* white = new ChessClockWidget(true, this);
    white->setGreenTime(5000);
    ChessClockWidget* black = new ChessClockWidget(false, this);
    white->startTurn();
    black->repaintClock();

    clocks_ = new ClocksWidget( this );
    setCentralWidget( clocks_ );
    clocks_->setClocks(white, black);

}

ChessClockWindow::~ChessClockWindow()
{

}
