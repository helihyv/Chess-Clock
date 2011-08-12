/**************************************************************************

   Chess Clock

   This file is part of Chess Clock software.

   (This file) Copyright (c) Heli Hyvättinen 2011

   Chess Clock is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Chess Clock is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.


**************************************************************************/

#ifndef WRAPPEDCLOCKSWIDGET_H
#define WRAPPEDCLOCKSWIDGET_H

#include <QGraphicsProxyWidget>
#include "clockswidget.h"
#include "chessclockwidget.h"

/*! A proxy for ClocksWidget for using it from QML

    @author Heli Hyvättinen
    @date 2011-08-12

  */

class WrappedClocksWidget : public QGraphicsProxyWidget
{
    Q_OBJECT
public:
    explicit WrappedClocksWidget(QObject *parent = 0);
    virtual ~WrappedClocksWidget();

    bool isPlayStarted();

signals:

public slots:

    /*! Start a new game */
     void startGame(QString timeControl, int whiteInitialTime, int whiteAdditionalTime, int whiteTurnsPerAddition, int blackInitialTime, int blackAdditionalTime, int blackTurnsPerAddition);
    /*! Pause game */
     void pause();
     /*! End the game */
     void stopPlay();
     /*! Not to keep screen lit */
     void saveScreen();

private:

    void deleteOldWidgets();
    ClocksWidget * pClocksWidget_;
    ChessClock * pWhiteClock_;
    ChessClock * pBlackClock_;

};

#endif // WRAPPEDCLOCKSWIDGET_H
