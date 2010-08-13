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

#include "chessclock.h"

#include "turninformation.h"

const int ChessClock::UPDATEINTERVAL;

ChessClock::ChessClock(bool white, QWidget *parent) :
    QWidget(parent)
{
    isWhite_ = white;
    loser_ = false;
    turn_ = 0;
    timePlayedBeforeTurn_ = 0;
    status_ = NotRunning;
    another_ = 0;

    // Set clock timer calculating played time
    clockTime_.start();

    // Set updating timer
    updateTimer_.setInterval( UPDATEINTERVAL );
    connect( &updateTimer_, SIGNAL(timeout()),this,SLOT(updateClock()));
}

void ChessClock::startTurn()
{
    turn_++;

    // Turn information for this new turn
    currentTurn_ = new TurnInformation(turn_, isWhite_);
    clockTime_.restart();
    updateTimer_.start();
    status_=Running;

    // Repaint clock
    updateClock();
}

void ChessClock::pauseTurn()
{
    updateTimer_.stop();
    // Update turn time
    currentTurn_->addTime( clockTime_.restart() );
    status_ = Paused;
    updateClock();
}

void ChessClock::continueTurn()
{
    // Continue paused game
    // Add pause duration to information object
    currentTurn_->addPause( clockTime_.restart() );
    status_ = Running;
    updateTimer_.start();
    updateClock();
}


TurnInformation* ChessClock::endTurn()
{
    status_ = NotRunning;
    updateTimer_.stop();
    // Update turn time
    currentTurn_->addTime( clockTime_.restart());
    // Count time played
    timePlayedBeforeTurn_ = getTimePlayed();
    // Count time available
    timeAvailableBeforeTurn_ = getTimeAvailable();
    updateClock();

    // Close and return turn information
    currentTurn_->turnReady(timeAvailableBeforeTurn_ );
    TurnInformation* information = currentTurn_;
    currentTurn_ = 0;
    emit endTurn();
    return information;
}

void ChessClock::setAnother(ChessClock *another)
{
    another_ = another;
}

int ChessClock::getTimeAvailable()
{
    // Most simple - will be overwritten in more complex time controls:
    // subtract duration time!
    if( currentTurn_)
    {
        // Update turn time
        currentTurn_->addTime( clockTime_.restart());
        return timeAvailableBeforeTurn_-currentTurn_->getDuration();
    }
    else
        return timeAvailableBeforeTurn_;
}


int ChessClock::getTimePlayed() const
{
    // Count time played time
    if( currentTurn_ )
        return timePlayedBeforeTurn_ + currentTurn_->getDuration();
    else
        return timePlayedBeforeTurn_;
}


void ChessClock::setTimeAvailable(int msecs)
{
    timeAvailableBeforeTurn_ = msecs;
}

void ChessClock::updateClock()
{
    // Check loser
    if( another_ && !another_->isLoser())
    {
        if( getTimeAvailable() < 0 && !loser_)
        {
            loser_ = true;
            emit timeOutLoser();
        }

    }
    repaintClock();

}

