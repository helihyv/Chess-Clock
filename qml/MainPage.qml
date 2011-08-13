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
            askAddition: false
            logoFile: ":/rc/pic/oldclock.png"


        }

        ListElement
        {
            name: "Addition before"
            askAddition: true
            logoFile: ":/rc/pic/addbefore.png"
        }

        ListElement
        {
            name: "Addition after"
            askAddition: true
            logoFile: ":/rc/pic/addafter.png"
        }

        ListElement
        {
            name: "Delay"
            askAddition: true
            logoFile: ":/rc/pic/pausebefore.png"
        }

        ListElement
        {
            name: "Delay after"
            askAddition: true
            logoFile: ":/rc/pic/pauseafter.png"
        }

        ListElement
        {
            name:"Hour Glass"
            askAddition: false
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
                    onClicked: {newGameDialog.name = name; newGameDialog.askAddition = askAddition; newGameDialog.open()}
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
                    onClicked: {newGameDialog.name = name; newGameDialog.askAddition = askAddition; newGameDialog.open()}
                }
            }

        }
    }





    Dialog
    {
        id:newGameDialog

        property string name
        property bool askAddition

        onAccepted:
        {
            clocksPage.whiteInitialTime = 60*60*1000*whiteInitialTime.hours+60*1000*whiteInitialTime.minutes+1000*whiteInitialTime.seconds
            clocksPage.blackInitialTime = 60*60*1000*blackInitialTime.hours+60*1000*blackInitialTime.minutes+1000*blackInitialTime.seconds
            clocksPage.whiteAdditionalTime = 60*60*1000*whiteAdditionalTime.hours+60*1000*whiteAdditionalTime.minutes+1000*whiteAdditionalTime.seconds
            clocksPage.blackAdditionalTime = 60*60*1000*blackAdditionalTime.hours+60*1000*blackAdditionalTime.minutes+1000*blackAdditionalTime.seconds
            clocksPage.whiteTurnsPerAddition = whiteTurnsPerAddition.text
            clocksPage.blackTurnsPerAddition = blackTurnsPerAddition.text
            pageStack.push(clocksPage)

        }

        title:Label
        {
            color:"white"
            font.pointSize: 64
            text: newGameDialog.name
        }


        content:
            Grid
            {
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
                                blackInitialTime.text = whiteInitialTime.text
                                blackAdditionalTime.text = whiteAdditionalTime.text
                                blackTurnsPerAddition.text = whiteTurnsPerAddition.text

                            }
                        }
                    }
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

                    onTextChanged: {if (equalTimesSwitch.checked) blackInitialTime.text = text}

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

                    onTextChanged: {if (equalTimesSwitch.checked) blackAdditionalTime.text = text}

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
                    visible: newGameDialog.askAddition
//                    anchors.top: additionalTimeText.bottom
//                    anchors.horizontalCenter: parent.horizontalCenter
                }
                TextField
                {
                    id: whiteTurnsPerAddition
                    visible: newGameDialog.askAddition

                    inputMask: "D00"
                    text: "1"

                    onTextChanged: {if (equalTimesSwitch.checked) blackTurnsPerAddition.text = text}
                }

                TextField
                {
                    id: blackTurnsPerAddition
                    visible: newGameDialog.askAddition
                    enabled: !equalTimesSwitch.checked
                    inputMask: "D00"
                    text: "1"
                }



         }


        buttons:

            Button
            {
                id: bOk
                text: "Start game"
                y: 45

                onClicked: newGameDialog.accept()
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
}




