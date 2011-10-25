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

import QtQuick 1.0
import com.meego 1.0
import QtQuick 1.1 
import ChessClocks 1.1



Page
{
    id: clocksPage


    property int timeControl //properties cannot be declared as enumerations in QML
                             //...must be a valid enum from WrappedClocksWidget
    property int whiteInitialTime
    property int blackInitialTime
    property int whiteAdditionalTime
    property int blackAdditionalTime
    property int whiteTurnsPerAddition
    property int blackTurnsPerAddition

    orientationLock: PageOrientation.LockLandscape

    onStatusChanged:
    {
        if (status == PageStatus.Activating)
        {
              wrappedClocksWidget.startGame(timeControl,whiteInitialTime,whiteAdditionalTime,whiteTurnsPerAddition,blackInitialTime,blackAdditionalTime,blackTurnsPerAddition)
              pauseButton.visible = false
        }
    }

    property bool appActive: applicationActive

    onAppActiveChanged:
    {
        if (appActive == false)
        {
            wrappedClocksWidget.pause()
            pauseButton.visible = false
        }
    }

    tools: ToolBarLayout
    {
        ToolIcon
        {
            iconId: "toolbar-back"
            onClicked:
            {
                wrappedClocksWidget.pause()
                pauseButton.visible = false
                confirmationDialog.open()
            }
        }

        ToolIcon
        {
            id: pauseButton
            iconId: "toolbar-mediacontrol-pause"
            onClicked:
                {
                    wrappedClocksWidget.pause()
                    visible = false
                }
        }

        Item{}  //placeholder needed to put pause button in the middle


    }




    WrappedClocksWidget
    {
        id: wrappedClocksWidget
        onUnPaused: pauseButton.visible = true
    }


    QueryDialog
    {
        id: confirmationDialog
        titleText: "Quit?"
        message:  "Are you sure you want to quit the game?"
        acceptButtonText: "Quit"
        rejectButtonText: "Continue play"

        onAccepted:
        {
           pageStack.pop()
        }

    }
}
