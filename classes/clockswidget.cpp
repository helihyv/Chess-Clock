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
#include "welcomescreenwidget.h"

#include <QLabel>
#include <QPixmap>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFont>


ClocksWidget::ClocksWidget(QWidget *parent) :
    QWidget(parent)
{
    white_ = 0;
    black_ = 0;
    status_ = NoClocks;

    // Make layout for clocks
    QHBoxLayout* clockLayout_ = new QHBoxLayout;

    // Pause information label
    pauseLabel_ = new QLabel( tr("<font color=yellow>Paused. Touch to continue.</font>"));
    pauseLabel_->setFont( QFont("Helvetica",25));
    pauseLabel_->setAlignment( Qt::AlignCenter);
    pauseLabel_->setVisible( false );

    // Welcome label for first touch
    welcomeLabel_ = new QLabel( tr("<font color=yellow>Welcome! Please touch to start game.<br>"
                                   "Then touch to end turn.</font>"));
    welcomeLabel_->setFont( QFont("Helvetica",25));
    welcomeLabel_->setAlignment( Qt::AlignCenter);
    welcomeLabel_->setVisible( false );

    // Welcome screen if no clocks set
    welcomeScreen_ = new WelcomeScreenWidget(this);

    // Put all in layout
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(clockLayout_);
    mainLayout->addWidget(pauseLabel_);
    mainLayout->addWidget(welcomeLabel_);
    mainLayout->addWidget(welcomeScreen_);

    setLayout( mainLayout);

}



void ClocksWidget::setClocks(ChessClock *white, ChessClock *black)
{
    // Remove old clocks
    if( white_ )
    {
        clockLayout_->removeWidget( white_ );
        delete white_;
    }
    if( black_ )
    {
        clockLayout_->removeWidget( black_ );
        delete black_;
    }

    // Set up new ones
    white_ = white;
    black_ = black;

    clockLayout_->addWidget(white_);
    clockLayout_->addWidget( black_ );

    // First paint
    white_->repaintClock();
    black_->repaintClock();

    // Welcome status for first touch
    welcomeLabel_->setVisible(true);
    status_ = Welcome;


}

int const ClocksWidget::CLICKDELAY;
