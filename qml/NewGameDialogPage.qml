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


Page
{
    id: newGameDialogPage

    orientationLock: PageOrientation.LockLandscape

    property string name
    property int timeControl //QML does not allow properties to be declared as enums...
    property bool askAddition
    property bool askTurnsPerAddition

    property int test

    Settings
    {
        id: settings

    }
    onTimeControlChanged:
    {
        equalTimesSwitch = settings.isEqualTimes(timeControl)

        var whiteInitial = settings.getInitialTime(timeControl,true)
        whiteInitialTime.hours = Qt.formatTime(whiteInitial,"h")
        whiteInitialTime.minutes = Qt.formatTime(whiteInitial,"m")
        whiteInitialTime.seconds = Qt.formatTime(whiteInitial,"s")

        var blackInitial = settings.getInitialTime(timeControl,false)
        blackInitialTime.hours = Qt.formatTime(blackInitial,"h")
        blackInitialTime.minutes = Qt.formatTime(blackInitial,"m")
        blackInitialTime.seconds = Qt.formatTime(blackInitial,"s")

        var whiteAdditional = settings.getAdditionalTime(timeControl,true)
        whiteAdditionalTime.hours = Qt.formatTime(whiteAdditional,"h")
        whiteAdditionalTime.minutes = Qt.formatTime(whiteAdditional,"m")
        whiteAdditionalTime.seconds = Qt.formatTime(whiteAdditional,"s")

        var blackAdditional = settings.getAdditionalTime(timeControl,false)
        blackAdditionalTime.hours = Qt.formatTime(blackAdditional,"h")
        blackAdditionalTime.minutes = Qt.formatTime(blackAdditional,"m")
        blackAdditionalTime.seconds = Qt.formatTime(blackAdditional,"s")


        whiteTurnsPerAddition.text = settings.getTurnsPerAddition(timeControl,true)
        blackTurnsPerAddition.text = settings.getTurnsPerAddition(timeControl,false)
    }

    tools: ToolBarLayout
    {
        ToolIcon { iconId: "toolbar-back"; onClicked: pageStack.pop() }
    }



           Text
            {
                id: title

                anchors.horizontalCenter: parent.horizontalCenter

                color:"white"
                font.pointSize: 26
                text: newGameDialogPage.name
            }

            Row
            {
                id: rowRow
                spacing: 10

                anchors.top: title.bottom

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
                            whiteSmall.anchors.horizontalCenter = undefined
                            whiteSmall.anchors.right = whiteInitialTime.horizontalCenter

                            blackSmall.anchors.horizontalCenter = undefined
                            blackSmall.anchors.left = whiteInitialTime.horizontalCenter


                        }

                        else
                        {

                            whiteSmall.anchors.right = undefined
                            whiteSmall.anchors.horizontalCenter = whiteInitialTime.horizontalCenter

                            blackSmall.anchors.left = undefined
                            blackSmall.anchors.horizontalCenter = blackInitialTime.horizontalCenter

                        }

                    }
                }
            }




            Image
            {
                id: whiteSmall

                anchors.top: rowRow.bottom

                source: ":/rc/pic/white_small.png"

                Component.onCompleted:
                {
                    if (equalTimesSwitch.checked)
                        anchors.right = whiteInitialTime.horizontalCenter
                    else
                        anchors.horizontalCenter = whiteInitialTime.horizontalCenter
                }
            }

            Image
            {

                id: blackSmall

                anchors.top: rowRow.bottom


                source: ":/rc/pic/black_small.png"

                Component.onCompleted:
                {
                    if (equalTimesSwitch.checked)
                        anchors.left = whiteInitialTime.horizontalCenter
                    else
                        anchors.horizontalCenter = blackInitialTime.horizontalCenter
                }
            }

            Text
            {
                id: initialTimeText
                text: "Initial time"
                color: "white"
                font.pointSize: 26
                anchors.verticalCenter: whiteInitialTime.verticalCenter
              }


            TextField
            {
                id: whiteInitialTime
                readOnly: true

                anchors.top: whiteSmall.bottom
                anchors.left: whiteTurnsPerAddition.left

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
                visible: !equalTimesSwitch.checked

                readOnly: true

                anchors.top: whiteSmall.bottom
                anchors.left:  blackTurnsPerAddition.left

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

                anchors.verticalCenter: whiteAdditionalTime.verticalCenter

                text: "Additional time"
                color: "white"
                font.pointSize: 26
                visible: newGameDialogPage.askAddition
//                    anchors.top: initialTimeText.bottom
//                    anchors.horizontalCenter: parent.horizontalCenter
            }



            TextField
            {
                id: whiteAdditionalTime
                visible:  newGameDialogPage.askAddition
                readOnly: true

                anchors.top: whiteInitialTime.bottom
                anchors.topMargin: 15
  //              anchors.left: additionalTimeText.right
                anchors.left: whiteTurnsPerAddition.left
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
                visible: newGameDialogPage.askAddition && !equalTimesSwitch.checked
                readOnly: true

                anchors.top: whiteAdditionalTime.top
                anchors.left: blackTurnsPerAddition.left

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
                id: turnsPerAdditionText
                text:  "Turns per addition"
                color: "white"
                font.pointSize: 26
                visible: newGameDialogPage.askTurnsPerAddition
                anchors.verticalCenter: whiteTurnsPerAddition.verticalCenter
            }

            TextField
            {
                id: whiteTurnsPerAddition
                visible: newGameDialogPage.askTurnsPerAddition
                readOnly: true;

                anchors.top: whiteAdditionalTime.bottom
                anchors.topMargin: 15
                anchors.left: turnsPerAdditionText.right
                anchors.leftMargin: 25

                MouseArea
                {
                    anchors.fill: parent
                    onClicked: {turnsDialog.player = "white";  turnsDialog.open()}
                }

            }

            TextField
            {
                id: blackTurnsPerAddition
                visible: newGameDialogPage.askTurnsPerAddition && !equalTimesSwitch.checked
                readOnly: true;

                anchors.top: whiteTurnsPerAddition.top
                anchors.left: whiteTurnsPerAddition.right
                anchors.leftMargin: 25

                MouseArea
                {
                    anchors.fill: parent
                    onClicked: {turnsDialog.player = "black";  turnsDialog.open()}
                }

            }


            Button
            {
                id: okButton
                text:  "Start game"

                anchors.top: whiteTurnsPerAddition.bottom
                anchors.topMargin: 15
                anchors.right: parent.right

                onClicked:
                {


                clocksPage.timeControl = timeControl


                clocksPage.whiteInitialTime = 60*60*1000*whiteInitialTime.hours+60*1000*whiteInitialTime.minutes+1000*whiteInitialTime.seconds
                clocksPage.whiteAdditionalTime = 60*60*1000*whiteAdditionalTime.hours+60*1000*whiteAdditionalTime.minutes+1000*whiteAdditionalTime.seconds
                clocksPage.whiteTurnsPerAddition = whiteTurnsPerAddition.text



//                //Save settings for white
//                settings.setInitialTime(timeControl,true,clocksPage.whiteInitialTime)
//                settings.setAdditionalTime(timeControl,true,clocksPage.whiteAdditionalTime)
//                settings.setTurnsPerAddition(timeControl,true,clocksPage.whiteTurnsPerAddition)

//                settings.setEqualTimes(timeControl,equalTimesSwitch.checked) //save equal times setting

                if (equalTimesSwitch.checked)
                {
                    //use same values for white and black
                    clocksPage.blackInitialTime = 60*60*1000*whiteInitialTime.hours+60*1000*whiteInitialTime.minutes+1000*whiteInitialTime.seconds
                    clocksPage.blackAdditionalTime = 60*60*1000*whiteAdditionalTime.hours+60*1000*whiteAdditionalTime.minutes+1000*whiteAdditionalTime.seconds
                    clocksPage.blackTurnsPerAddition = whiteTurnsPerAddition.text

                    //If black values in dialog are not used they are not saved to settings
                }
                else
                {
                    clocksPage.blackInitialTime = 60*60*1000*blackInitialTime.hours+60*1000*blackInitialTime.minutes+1000*blackInitialTime.seconds
                    clocksPage.blackAdditionalTime = 60*60*1000*blackAdditionalTime.hours+60*1000*blackAdditionalTime.minutes+1000*blackAdditionalTime.seconds
                    clocksPage.blackTurnsPerAddition = blackTurnsPerAddition.text

//                    //Save settings for black
//                    settings.setInitialTime(timeControl,false,clocksPage.blackInitialTime)
//                    settings.setAdditionalTime(timeControl,false,clocksPage.blackAdditionalTime)
//                    settings.setTurnsPerAddition(timeControl,false,clocksPage.blackTurnsPerAddition)
                }




                pageStack.push(clocksPage)

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
