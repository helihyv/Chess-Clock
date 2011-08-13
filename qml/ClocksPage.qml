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
import ChessClocks 1.0



Page
{
    id: clocksPage

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
            wrappedClocksWidget.startGame("",whiteInitialTime,whiteAdditionalTime,whiteTurnsPerAddition,blackInitialTime,blackAdditionalTime,blackTurnsPerAddition)
    }



    tools: ToolBarLayout
    {
        ToolButton { iconSource: "toolbar-back"; onClicked: pageStack.pop() }
        ToolButton
        {
            iconSource: ":/rc/pic/pausebutton.png"
            onClicked: wrappedClocksWidget.pause()
        }
    }




    WrappedClocksWidget
    {
        id: wrappedClocksWidget
    }



}
