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
import ChessClocks 1.0


Page {
    id: mainPage
    tools: commonTools
    orientationLock: PageOrientation.LockLandscape






//    Label {
//        id: label
//        anchors.centerIn: parent
//        text: qsTr("Hello world!")
//        visible: false
//    }


    Image
    {
        id: bigLogo
//        anchors.fill: parent
//        anchors.left: menuList.right

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


    ListView
    {
        id: menuList

        anchors.left: bigLogo.right
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom


         model: menuModel

         delegate: Row
         {
            Image
            {
                source: logoFile

                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        newGameDialog.name = name
                        newGameDialog.timeControl = timeControl
                        newGameDialog.askAddition = askAddition
                        newGameDialog.askTurnsPerAddition = askTurnsPerAddition
                        newGameDialog.open()
                    }
                }
            }

            Text
            {
                text: name
                font.pointSize: 40
                anchors.topMargin: 12
                color: "white"

                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        newGameDialog.name = name
                        newGameDialog.timeControl = timeControl
                        newGameDialog.askAddition = askAddition
                        newGameDialog.askTurnsPerAddition = askTurnsPerAddition
                        newGameDialog.open()
                    }
                }
            }

        }
    }





    Sheet
    {
        id:newGameDialog

        property string name
        property int timeControl //QML does not allow properties to be declared as enums...
        property bool askAddition
        property bool askTurnsPerAddition

        onAccepted:
        {
            clocksPage.timeControl = timeControl
            clocksPage.whiteInitialTime = 60*60*1000*whiteInitialTime.hours+60*1000*whiteInitialTime.minutes+1000*whiteInitialTime.seconds
            clocksPage.blackInitialTime = 60*60*1000*blackInitialTime.hours+60*1000*blackInitialTime.minutes+1000*blackInitialTime.seconds
            clocksPage.whiteAdditionalTime = 60*60*1000*whiteAdditionalTime.hours+60*1000*whiteAdditionalTime.minutes+1000*whiteAdditionalTime.seconds
            clocksPage.blackAdditionalTime = 60*60*1000*blackAdditionalTime.hours+60*1000*blackAdditionalTime.minutes+1000*blackAdditionalTime.seconds
            clocksPage.whiteTurnsPerAddition = whiteTurnsPerAddition.text
            clocksPage.blackTurnsPerAddition = blackTurnsPerAddition.text
            pageStack.push(clocksPage)

        }

//        title:Label
//        {
//            color:"white"
//            font.pointSize: 64
//            text: newGameDialog.name
//        }

        acceptButtonText: "Start game"
        rejectButtonText: "Cancel"

        content:



            Grid
            {
//                anchors.top: rowRow.bottom
                columns: 3


                Row
                {
                    id: rowRow
                    spacing: 10
//                    anchors.top: parent.top
//                    anchors.horizontalCenter: parent.horizontalCenter

                    Text
                    {
//                     width: rowRow.width - rowRow.spacing - switchComponent.width - whiteSmall.width - blackSmall.width
//                     height: switchComponent.height
                        verticalAlignment: Text.AlignVCenter
                        text: "Equal times"
                        color: "white"
                        font.pointSize: 26
                    }

                    Switch
                    {
                        id: equalTimesSwitch
                        onCheckedChanged:
                        {
                            if (checked)
                            {
                            }

                        }
                    }
                }


                Item
                {
                    id: placeholder
                }

                Image
                {
                    id: whiteSmall
                    source: ":/rc/pic/white_small.png"
                }

                Image
                {
                    id: blackSmall
                    source: ":/rc/pic/black_small.png"
                }

                Text
                {
                    id: initialTimeText
                    text: "Initial time"
                    color: "white"
                    font.pointSize: 26
//                    anchors.top: rowRow.bottom
//                    anchors.horizontalCenter: parent.horizontalCenter
//                    visible: true
                }


                TextField
                {
                    id: whiteInitialTime
                    readOnly: true

                    property int hours
                    property int minutes
                    property int seconds

                    text: {hours + " h " + minutes + " min " + seconds + " s"}


                    MouseArea
                    {
                        anchors.fill: parent
                        onClicked: {timePicker.timeType = "initial";  timePicker.player = "white"; timePicker.open()}
                    }
                }



                TextField
                {
                    id: blackInitialTime
                    enabled: !equalTimesSwitch.checked

                    readOnly: true

                    property int hours
                    property int minutes
                    property int seconds

                    text: hours + " h " + minutes + " min " + seconds + " s"



                    MouseArea
                    {
                    anchors.fill: parent
                    onClicked: {timePicker.timeType = "initial";  timePicker.player = "black"; timePicker.open()}
                    }
                }



                Text
                {
                    id: additionalTimeText
                    text: "Additional time"
                    color: "white"
                    font.pointSize: 26
                    visible: newGameDialog.askAddition
//                    anchors.top: initialTimeText.bottom
//                    anchors.horizontalCenter: parent.horizontalCenter
                }



                TextField
                {
                    id: whiteAdditionalTime
                    visible:  newGameDialog.askAddition
                    readOnly: true

                    property int hours
                    property int minutes
                    property int seconds

                    text: hours + " h " + minutes + " min " + seconds + " s"


                    MouseArea
                    {
                        anchors.fill: parent
                        onClicked: {timePicker.timeType = "additional";  timePicker.player = "white"; timePicker.open()}
                    }
                }

                TextField
                {
                    id: blackAdditionalTime
                    visible: newGameDialog.askAddition
                    enabled: !equalTimesSwitch.checked
                    readOnly: true

                    property int hours
                    property int minutes
                    property int seconds

                    text: hours + " h " + minutes + " min " + seconds + " s"

                    MouseArea
                    {
                        anchors.fill: parent
                        onClicked: {timePicker.timeType = "additional";  timePicker.player = "black"; timePicker.open()}
                    }
        }



                Text
                {
                    text:  "Turns per addition"
                    color: "white"
                    font.pointSize: 26
                    visible: newGameDialog.askTurnsPerAddition
//                    anchors.top: additionalTimeText.bottom
//                    anchors.horizontalCenter: parent.horizontalCenter
                }

                TextField
                {
                    id: whiteTurnsPerAddition
                    visible: newGameDialog.askTurnsPerAddition
                    readOnly: true;
                    text: "1"

                    MouseArea
                    {
                        anchors.fill: parent
                        onClicked: {turnsDialog.player = "white";  turnsDialog.open()}
                    }

                }

        TextField
        {
            id: blackTurnsPerAddition
            visible: newGameDialog.askTurnsPerAddition
            readOnly: true;
            text: "1"

            MouseArea
            {
                anchors.fill: parent
                onClicked: {turnsDialog.player = "black";  turnsDialog.open()}
            }

        }

    }
         }



    TimePickerDialog
    {
        id: timePicker

        property string timeType
        property string player

        titleText: "Choose " + timeType + " time for " + player
        rejectButtonText: "Cancel"
        acceptButtonText: "Ok"
        hourMode: DateTime.TwentyFourHours
        onAccepted:
        {
            if (timeType == "initial")
            {
                if (player == "white")
                {
                    whiteInitialTime.hours = hour
                    whiteInitialTime.minutes = minute
                    whiteInitialTime.seconds = second
                }
                else
                {
                    blackInitialTime.hours = hour
                    blackInitialTime.minutes = minute
                    blackInitialTime.seconds = second
                }
            }
            else if (player == "white")
                {
                    whiteAdditionalTime.hours = hour
                    whiteAdditionalTime.minutes = minute
                    whiteAdditionalTime.seconds = second
                }
                else
                {
                    blackAdditionalTime.hours = hour
                    blackAdditionalTime.minutes = minute
                    blackAdditionalTime.seconds = second
                }

        }
    }



    TumblerColumn
    {
        id: turnsColumn
        selectedIndex: 1
        items: turnsList


    }

    ListModel
    {
        id: turnsList

        Component.onCompleted:
        {
            for (var turn = 1; turn <= 99; turn++)
                  {
                     turnsList.append({"value" : turn});
                  }

        }

    }


    TumblerDialog
    {
        id: turnsDialog

        property string player

        titleText: "Choose turns per addition for " + player
        acceptButtonText: "Ok"
        rejectButtonText: "Cancel"

        columns: [turnsColumn]

        onAccepted:
        {
            if (player == "white")
                whiteTurnsPerAddition.text = turnsColumn.selectedIndex+1
            else if (player == "black")
                blackTurnsPerAddition.text = turnsColumn.selectedIndex+1


        }
    }
}




