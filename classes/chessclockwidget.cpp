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

#include "chessclockwidget.h"

#include <QLabel>
#include <QFont>
#include <QVBoxLayout>
#include <QHBoxLayout>

ChessClockWidget::ChessClockWidget(bool white, QWidget *parent) :
    ChessClock(white, parent)
{
    mainLayout = new QVBoxLayout;

    initPictures();
    initLabels();
    initTop();
    initBottom();

    setLayout( mainLayout );
}


void ChessClockWidget::initPictures()
{
    // Load pictures from resources.
    if(  isWhite() )
      {
          picActive_.load(":/rc/pic/white_blue.png");
          picPassive_.load(":/rc/pic/white_gray.png");
      }
      else
      {
          picActive_.load(":/rc/pic/black_blue.png");
          picPassive_.load(":/rc/pic/black_gray.png");
      }
      picLoser_.load(":/rc/pic/loser.png");
}

void ChessClockWidget::initLabels()
{
    QFont normalFont("Helvetica",24);

    pictureLabel_ = new QLabel;
    pictureLabel_->setPixmap( picPassive_ );

    timeUsedLabel_ = new QLabel;
    timeAverageLabel_ = new QLabel;
    turnLabel_=new QLabel;

    timeUsedLabel_->setFont(normalFont);
    timeAverageLabel_->setFont(normalFont);
    turnLabel_->setFont(normalFont);

    loserLabel_ = new QLabel;
    loserLabel_->setPixmap(picLoser_);
    loserLabel_->setVisible(false);

}

void ChessClockWidget::initTop()
{
    QVBoxLayout* details = new QVBoxLayout();
    details->addWidget(timeUsedLabel_);
    details->addWidget(timeAverageLabel_);
    details->addWidget(turnLabel_);

    QHBoxLayout* topLayout = new QHBoxLayout();
    if( isWhite() )
    {
        // White player
        //  Picture  |  Details | .. | LOSER
        topLayout->addWidget( pictureLabel_ );
        topLayout->addLayout( details );
        topLayout->addStretch();
        topLayout->addWidget(loserLabel_);
    }
    else
    {
        // Black player
        // LOSER | ... | Details | Picture
        topLayout->addWidget(loserLabel_);
        topLayout->addStretch();
        topLayout->addLayout( details );
        topLayout->addWidget( pictureLabel_ );
    }
    mainLayout->addLayout(topLayout);
}

void ChessClockWidget::initBottom()
{
    // At bottom, time left in BIG font!
    QFont bigfont("Helvetica",65,QFont::Bold);
    leftLabel_ = new QLabel("0.00.00");
    leftLabel_->setFont(bigfont);
    // Black player: right alignment
    if( isWhite() )
       leftLabel_->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    mainLayout->addWidget(leftLabel_);
}

void ChessClockWidget::repaintClock()
{
    // Set picture
    if( getStatus() == Running )
        pictureLabel_->setPixmap( picActive_);
    else
        pictureLabel_->setPixmap(picPassive_);

    timeUsedLabel_->setText( timeString( getTimePlayed() ));

    // Time average per turn
    int timeAverage;
    if( getTurn() == 0)
        timeAverage = 0;
    else
        timeAverage = getTimePlayed() / getTurn();
    timeAverageLabel_->setText( tr("Average %1 per turn").arg( timeString( timeAverage ) ) );

    turnLabel_->setText( tr("Turn %1").arg(getTurn()));

    // Loser flag
    loserLabel_->setVisible( isLoser());

    leftLabel_->setText( timeString(getTimeAvailable()));

}

QString ChessClockWidget::timeString(int msecs)
{
    int secs = msecs / 1000 % 60;
    int mins = msecs / ( 60 * 1000) % 60;
    int hours = msecs / ( 60 * 60 * 1000 );
    if( msecs < 0)
        return QString(tr("<font color=red> %1:%2:%3 <font>").arg(0-hours).arg(0-mins,2,10,QChar('0')).arg(0-secs,2,10,QChar('0')));
    else
        return QString(tr("%1:%2:%3").arg(hours).arg(mins,2,10,QChar('0')).arg(secs,2,10,QChar('0')));

}
