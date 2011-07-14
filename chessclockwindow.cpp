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
#include "classes/startwidget.h"
#include "classes/timecontrol.h"
#include "classes/turninformation.h"

// Time controls
#include "classes/timecontrol/notimecontrol.h"
#include "classes/timecontrol/fischertimecontrol.h"
#include "classes/timecontrol/fischeraftertimecontrol.h"
#include "classes/timecontrol/delaytimecontrol.h"
#include "classes/timecontrol/delayaftertimecontrol.h"
#include "classes/timecontrol/hourglasstimecontrol.h"

#include <QIcon>
#include <QApplication>
#include <QMenuBar>
#include <QMessageBox>
#include <QStackedWidget>
#include <QProcess>


ChessClockWindow::ChessClockWindow(QWidget *parent)
    : QMainWindow(parent)
{

    showFullScreen();

    setWindowIcon( QIcon(":/rc/pic/chessclock.png"));
    setWindowTitle( QString("%1 %2").arg(qApp->applicationName()).arg(qApp->applicationVersion()) );

    // Start widget to select time control
    start_ = new StartWidget;
    clocks_ = 0;

    initTimeControls();

    stack_ = new QStackedWidget;
    stack_->addWidget(start_);

    setCentralWidget( stack_ );

    connect( start_, SIGNAL(selected(TimeControl*)), this, SLOT(startGame(TimeControl*)));


    // Set up menu
//    menuBar()->addAction( tr("Pause"), this, SLOT(pause()));   // UNUSED - Pause button
    menuBar()->addAction( tr("New game"), this, SLOT(newGame()));

    menuBar()->addAction( tr("Visit web page"), this, SLOT(visitWeb()));
    menuBar()->addAction( tr("About"),this, SLOT(about()));
    menuBar()->addAction(tr("About Qt"), this, SLOT(aboutQt()));

    //set the event filter to grap window deactivate

    installEventFilter(this);

}

void ChessClockWindow::pause()
{
    if( clocks_ )
        clocks_->pause();
}

void ChessClockWindow::newGame()
{
    pause();
    if(  clocks_ == 0 ||  !clocks_->isPlayStarted()  || QMessageBox::question(this, tr("Start new game"),
                              tr("Really quit the current game and start a new one?"),
                              QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes)
    {
        stack_->setCurrentWidget(start_);

        if( clocks_ )
        {   stack_->removeWidget(clocks_);
            delete clocks_;
        }
        clocks_=0;
    }
}

void ChessClockWindow::visitWeb()
{
    pause();
    QProcess* process = new QProcess(this);
    process->start(QString("browser --url=chessclock.garage.maemo.org"));
}

void ChessClockWindow::about()
{
    pause();
    QMessageBox::about(this, tr("About ChessClock"),
                       tr("<h1>Chess Clock %1</h1>"
                          "&copy;Arto Hyv&auml;ttinen 2010"
                          "<p>Chess Clock is free software under the terms of GNU General Public License 3"
                          "<p>Bugtracker and instructions at <a>http://chessclock.garage.maemo.org</a>"
                          ).arg(qApp->applicationVersion())) ;
}

void ChessClockWindow::aboutQt()
{
    pause();
    qApp->aboutQt();
}


void ChessClockWindow::initTimeControls()
{
    start_->addTimeControl( new NoTimeControl );
    start_->addTimeControl( new FischerTimeControl);
    start_->addTimeControl( new FischerAfterTimeControl);
    start_->addTimeControl( new DelayTimeControl );
    start_->addTimeControl( new DelayAfterTimeControl);
    start_->addTimeControl( new HourGlassTimeControl);
}

void ChessClockWindow::startGame(TimeControl *timecontrol)
{
    ClocksWidget* newWidget = timecontrol->initGame(false);
    if( newWidget )
    {

        clocks_ = newWidget;
        stack_->addWidget(clocks_);
        stack_->setCurrentWidget(clocks_);
        connect( clocks_, SIGNAL(TurnFinished(TurnInformation*)), this, SLOT(dontEatMemory(TurnInformation*)));
    }
}


ChessClockWindow::~ChessClockWindow()
{

}

bool ChessClockWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::WindowDeactivate) {
        pause();
        return QObject::eventFilter(obj,event);
    } else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}

void ChessClockWindow::dontEatMemory(TurnInformation *turnInformation)
{
    delete turnInformation; // hopefully don't cause Segematation Fault
}
