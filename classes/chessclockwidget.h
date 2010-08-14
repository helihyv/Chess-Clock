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

#ifndef CHESSCLOCKWIDGET_H
#define CHESSCLOCKWIDGET_H

#include "chessclock.h"
#include <QPixmap>
#include <QString>

class QVBoxLayout;
class QLabel;

/*!  Simple chess clock widget

  @author Arto Hyvättinen
  @date 2010-08-14


  */
class ChessClockWidget : public ChessClock
{
    Q_OBJECT
public:
    ChessClockWidget(bool white, QWidget *parent = 0);
    /*! Set time begin of turn shown green.

      Extra time of turn is shown green.
      @param msecs Green time in msecs
      */
    void setGreenTime(int msecs);

signals:

public slots:
    virtual void repaintClock();

protected:
    /*! Init pictures from resources */
    virtual void initPictures();
    /*! Init QLabels */
    virtual void initLabels();
    /*! Init top: picture, details, loser mark */
    virtual void initTop();
    /*! Init time left in bottom.
      Override to make different bottom area */
    virtual void initBottom();

    /*! Convert msecs to h:mm:ss QString */
    QString timeString(int msecs);

protected:

    QPixmap picActive_;
    QPixmap picPassive_;
    QPixmap picLoser_;

    QLabel* pictureLabel_;
    QLabel* timeUsedLabel_;
    QLabel* timeAverageLabel_;
    QLabel* turnLabel_;
    QLabel* turnTimeLabel_;
    QLabel* loserLabel_;
    QLabel* leftLabel_;

    QVBoxLayout* mainLayout;

    int greenTime_; /*! Green time in begin of turn */


};

#endif // CHESSCLOCKWIDGET_H
