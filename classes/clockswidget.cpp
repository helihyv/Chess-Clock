 /**************************************************************************

    Chess Clock

    Copyright (c) Arto Hyvättinen 2010

    Changes made for porting to Harmattan (c) Heli Hyvättinen 2011

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

#include "screenlitkeeper.h"

#include <QLabel>
#include <QPixmap>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFont>
#include <cstdlib>
#include <QMouseEvent>
#include <QToolButton>
#include <QSize>
#include <QWidget>
#include <QDebug>

ClocksWidget::ClocksWidget(ChessClock *white, ChessClock *black, QWidget *parent):
    QWidget(parent)
{
    // Set up clocks
    white_ = white;
    black_ = black;

    // SET UP UI


    //Harmattan specific: brute force the width to a working value. (Adding a stretch didn't work.)

    setMinimumWidth(860);

    // Make layout for clocks
    QHBoxLayout* clockLayout = new QHBoxLayout;
    clockLayout->addWidget(white_ );
    clockLayout->addWidget( black_ );

    // Pause information label
    pauseLabel_ = new QLabel( tr("<font color=yellow>Paused. Touch to continue.</font>"),this);
    pauseLabel_->setFont( QFont("Helvetica",25));
 //   For Fremantle:
//    pauseLabel_->setAlignment( Qt::AlignCenter);
 //For Harmattan (QML)
        pauseLabel_->setAlignment( Qt::AlignHCenter | Qt::AlignTop);

    pauseLabel_->setVisible( false );

    // Welcome label for first touch
    welcomeLabel_ = new QLabel( tr("<font color=green>Welcome! Please touch to start game.<br>"
                                   "Then touch to end turn.</font>"),this);
    welcomeLabel_->setFont( QFont("Helvetica",25));
    welcomeLabel_->setAlignment( Qt::AlignCenter);
    welcomeLabel_->setVisible( true );  // Show welcome message

//For Harmattan pause button is moved to the toolbar (in QML)

//    // Pause button
//    pauseButton_ = new QToolButton;
//    pauseButton_->setIcon( QIcon(":/rc/pic/pausebutton.png"));
//    pauseButton_->setIconSize(QSize(75,75));
//    connect(pauseButton_, SIGNAL(clicked()), this, SLOT(pause()));
//    pauseButton_->setVisible(false);

    // Put all in layout
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(clockLayout);

    // Extra layout and widget for information
    QVBoxLayout* extraLayout = new QVBoxLayout;
    extraLayout->addWidget(pauseLabel_);
    extraLayout->addWidget(welcomeLabel_);

//For Harmattan pause button is moved to the toolbar (in QML)

//    QHBoxLayout* pbLayout = new QHBoxLayout;
//    pbLayout->addStretch();
////    pbLayout->addWidget(pauseButton_);
//    pbLayout->addStretch();
//    extraLayout->addLayout(pbLayout);

    QWidget* extraWidget = new QWidget(this);
    extraWidget->setLayout(extraLayout);
    // Some fun event filtering to grap clicking welcome and pause labels...
    extraWidget->installEventFilter(this);
    pauseLabel_->installEventFilter(this);
    welcomeLabel_->installEventFilter(this);

    mainLayout->addWidget(extraWidget);
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

    // ScreenLitKeeper to keep screen lit when playing
    keeper_ = new ScreenLitKeeper(this);

    connect( white, SIGNAL(dontEatBattery()), this, SLOT(saveScreen()));
    connect( black, SIGNAL(dontEatBattery()), this, SLOT(saveScreen()));
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
 //For Harmattan pause button is moved to the toolbar (in QML)
//        pauseButton_->setVisible(false);
        keeper_->keepScreenLit(false);

    }
    else if( status_ == BlackTurn)
    {
        status_ = BlackPause;
        black_->pauseTurn();
        pauseLabel_->setVisible(true);
 //For Harmattan pause button is moved to the toolbar (in QML)
//        pauseButton_->setVisible(false);
        keeper_->keepScreenLit(false);
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

void ClocksWidget::saveScreen()
{
    keeper_->keepScreenLit(false);
}


void ClocksWidget::mousePressEvent(QMouseEvent *event)
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
 //For Harmattan pause button is moved to the toolbar (in QML)
//            pauseButton_->setVisible(true);
            emit unPaused(); //To tell QML that game is going (used to show pause button)
            keeper_->keepScreenLit(true);
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
            keeper_->keepScreenLit(true);
            pauseLabel_->setVisible(false);
//For Harmattan pause button is moved to the toolbar (in QML)
//            pauseButton_->setVisible(true);
            white_->continueTurn();
            status_=WhiteTurn;
            emit unPaused(); //For Harmattan, to inform QML
            break;
        case BlackPause:
            // Continue play
            keeper_->keepScreenLit(true);
            pauseLabel_->setVisible(false);
//For Harmattan pause button is moved to the toolbar (in QML)
//            pauseButton_->setVisible(true);
            black_->continueTurn();
            status_=BlackTurn;
            emit unPaused(); //For Harmattan, to inform QML
            break;
        case Stopped:
            emit ClickedWhenStopped();


        }
    }
    recentX = event->x();
    recentY = event->y();
}

// to grap clicking pause or welcome label
bool ClocksWidget::eventFilter(QObject *obj, QEvent *event)
{
//    qDebug() << "Event for pause button or welcome label received " << event->type();
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mEvent = static_cast<QMouseEvent *>(event);
        mousePressEvent( mEvent );
        return true;
    } else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}


int const ClocksWidget::CLICKDELAY;
