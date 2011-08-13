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

import QtQuick 1.1
import com.meego 1.0
import QtQuick 1.0
import com.nokia.extras 1.0

Page
{
    id: aboutPage
//    tools: commonTools
    orientationLock: PageOrientation.LockLandscape

    tools: ToolBarLayout {
        ToolButton { iconSource: "toolbar-back"; onClicked: pageStack.pop() }
    }

    Image {
        id: logo
        source: ":/rc/pic/logo.png"
    }

Text
{
    id: title
    text: "Chess Clock"
    color: "white"
    font.pointSize: 42

    anchors.left: logo.right
    anchors.leftMargin: 50
}

Text
{

    text: "© Arto Hyvättinen 2010 & Heli Hyvättinen 2011<p>Chess Clock is free software under the terms <br>of GNU General Public License 3 <p> Bugtracker and instructions at <br>http://chessclock.garage.maemo.org"

    color: "white"
    font.pointSize: 22


    anchors.top: title.bottom
    anchors.topMargin: 50
    anchors.left: logo.right
}

}
