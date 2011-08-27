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

PageStackWindow {
    id: appWindow


    property bool applicationActive: true //This is supposed to be set from C++


    Component.onCompleted: theme.inverted = true

    initialPage: mainPage

    MainPage{id: mainPage}

    AboutPage{id: aboutPage}

    ClocksPage{id: clocksPage}

    NewGameDialogPage{id: newGameDialogPage}

    ToolBarLayout {
        id: commonTools
        visible: true
        ToolIcon { platformIconId: "toolbar-view-menu";
             anchors.right: parent===undefined ? undefined : parent.right
             onClicked: (myMenu.status == DialogStatus.Closed) ? myMenu.open() : myMenu.close()
        }
    }

    Menu {
        id: myMenu
        visualParent: pageStack
        MenuLayout {
            MenuItem
            {
                text: "Visit web page"
                onClicked: Qt.openUrlExternally("http://chessclock.garage.maemo.org/")
            }
            MenuItem
            {
                text: "About"
                onClicked: pageStack.push(aboutPage)
            }
        }
    }
}
