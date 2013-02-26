/**************************************************************************

   Chess Clock

   This file is part of Chess Clock software.

   (This file) Copyright (c) Heli Hyvättinen 2011–2013

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
import Sailfish.Silica 1.0
import ChessClocks 1.2



Page {
    id: mainPage
//    tools: commonTools
//    orientationLock: PageOrientation.LockLandscape
    allowedOrientations: Orientation.Landscape


    Image
    {
        id: bigLogo
//        anchors.fill: parent
//        anchors.left: menuList.right
        anchors.verticalCenter: parent.verticalCenter

        source: ":/rc/pic/logo.png"
    }

    ListModel
    {
        id: menuModel

        ListElement
        {
            name: "Normal clock"
            timeControl: WrappedClocksWidget.NormalClock
            askAddition: false
            askTurnsPerAddition: false
            logoFile: ":/rc/pic/oldclock.png"


        }

        ListElement
        {
            name: "Addition before"
            timeControl: WrappedClocksWidget.AdditionBefore
            askAddition: true
            askTurnsPerAddition: true
            logoFile: ":/rc/pic/addbefore.png"
        }

        ListElement
        {
            name: "Addition after"
            timeControl: WrappedClocksWidget.AdditionAfter
            askAddition: true
            askTurnsPerAddition: true
            logoFile: ":/rc/pic/addafter.png"
        }

        ListElement
        {
            name: "Delay"
            timeControl: WrappedClocksWidget.Delay
            askAddition: true
            askTurnsPerAddition: false
            logoFile: ":/rc/pic/pausebefore.png"
        }

        ListElement
        {
            name: "Delay after"
            timeControl: WrappedClocksWidget.DelayAfter
            askAddition: true
            askTurnsPerAddition: false
            logoFile: ":/rc/pic/pauseafter.png"
        }

        ListElement
        {
            name:"Hour Glass"
            timeControl: WrappedClocksWidget.HourGlass
            askAddition: false
            askTurnsPerAddition: false
            logoFile:":/rc/pic/hourglass.png"
        }

    }


    SilicaListView
    {
        id: menuList

        anchors.left: bigLogo.right
        anchors.leftMargin: 40
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom

        PullDownMenu
        {
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

        header: PageHeader
        {
        title: "ChessClock"
        }

//        spacing:  10

         model: menuModel

         delegate: Row
         {


            Image
            {
                source: logoFile
                width:  40
                height: 40
                anchors.verticalCenter: parent.verticalCenter

                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        newGameDialogPage.name = name
                        newGameDialogPage.timeControl = timeControl
                        newGameDialogPage.askAddition = askAddition
                        newGameDialogPage.askTurnsPerAddition = askTurnsPerAddition
                        PageStack.push(newGameDialogPage)                     }
                }
            }

            Label
            {
                text: name
//                font.pointSize: 36
//                anchors.topMargin: 12
//                color: "white"
                font.pixelSize: theme.fontSizeLarge


                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        newGameDialogPage.name = name
                        newGameDialogPage.timeControl = timeControl
                        newGameDialogPage.askAddition = askAddition
                        newGameDialogPage.askTurnsPerAddition = askTurnsPerAddition
                        pageStack.push(newGameDialogPage)
                    }
                }
            }

        }



    }

}




