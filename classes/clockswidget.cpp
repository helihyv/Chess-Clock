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

#include "clockswidget.h"
#include "chessclock.h"

#include <QLabel>
#include <QPixmap>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFont>
#include <cstdio>
#include <QMouseEvent>

ClocksWidget::ClocksWidget(ChessClock *white, ChessClock *black, QWidget *parent):
    QWidget(parent)
{
    // Set up clocks
    white_ = white;
    black_ = black;

    // SET UP UI
    // Make layout for clocks
    QHBoxLayout* clockLayout = new QHBoxLayout;
    clockLayout->addWidget(white_ );
    clockLayout->addWidget( black_ );

    // Pause information label
    pauseLabel_ = new QLabel( tr("<font color=yellow>Paused. Touch to continue.</font>"));
    pauseLabel_->setFont( QFont("Helvetica",25));
    pauseLabel_->setAlignment( Qt::AlignCenter);
    pauseLabel_->setVisible( false );

    // Welcome label for first touch
    welcomeLabel_ = new QLabel( tr("<font color=green>Welcome! Please touch to start game.<br>"
                                   "Then touch to end turn.</font>"));
    welcomeLabel_->setFont( QFont("Helvetica",25));
    welcomeLabel_->setAlignment( Qt::AlignCenter);
    welcomeLabel_->setVisible( true );  // Show welcome message

    // Put all in layout
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(clockLayout);
    mainLayout->addWidget(pauseLabel_);
    mainLayout->addWidget(welcomeLabel_);

    setLayout( mainLayout);
    status_ = Welcome;

    // First paint
    white_->repaintClock();
    black_->repaintClock();

    // Set up others
    white_->setAnother(black_);
    black_->setAnother(white_);

    delayTimer_.start(); // Initial start

    recentX = recentY = -1;
}

ClocksWidget::~ClocksWidget()
{
    delete white_;
    delete black_;
}

void ClocksWidget::pause()
{
    if(status_ == WhiteTurn)
    {
        status_= WhitePause;
        white_->pauseTurn();
        pauseLabel_->setVisible(true);
    }
    else if( status_ == BlackTurn)
    {
        status_ = BlackPause;
        black_->pauseTurn();
        pauseLabel_->setVisible(true);
    }
}

void ClocksWidget::stopPlay()
{
    if( status_ == BlackTurn || status_ == BlackPause )
       emit TurnFinished( black_->endTurn());
    else if( status_ == WhiteTurn || status_ == WhitePause )
        emit TurnFinished( white_->endTurn());
    status_ = Stopped;
}


void ClocksWidget::mouseReleaseEvent(QMouseEvent *event)
{

    // To avoid double clicks
    // a) delay (default 1,2 secs) OR
    // b) distance more than 90 pixels in axis.
    if( delayTimer_.elapsed() > CLICKDELAY ||
        std::abs( event->x() - recentX ) > 90 ||
        std::abs( event->y() - recentY ) > 90
        )
    {
        delayTimer_.start();    // to reset delay timer!
        switch( status_)
        {
        case Welcome :
            // Start game!
            welcomeLabel_->setVisible(false);
            white_->startTurn();
            status_ = WhiteTurn;
            break;
        case WhiteTurn:
            // White turn finished, then black
            emit TurnFinished( white_->endTurn());
            black_->startTurn();
            status_=BlackTurn;
            break;
        case BlackTurn:
            // Black finished, then white
            emit TurnFinished( black_->endTurn());
            white_->startTurn();
            status_=WhiteTurn;
            break;
        case WhitePause:
            // Continue play
            pauseLabel_->setVisible(false);
            white_->continueTurn();
            status_=WhiteTurn;
            break;
        case BlackPause:
            // Continue play
            pauseLabel_->setVisible(false);
            black_->continueTurn();
            status_=BlackTurn;
            break;
        case Stopped:
            emit ClickedWhenStopped();


        }
    }
    recentX = event->x();
    recentY = event->y();
}

int const ClocksWidget::CLICKDELAY;
