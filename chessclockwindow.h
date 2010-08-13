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

class ChessClockWindow : public QMainWindow
{
    Q_OBJECT

public:
    ChessClockWindow(QWidget *parent = 0);
    ~ChessClockWindow();
};

#endif // CHESSCLOCKWINDOW_H