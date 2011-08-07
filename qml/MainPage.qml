import QtQuick 1.1
import com.meego 1.0
import QtQuick 1.0
import com.nokia.extras 1.0


Page {
    id: mainPage
    tools: commonTools






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




        title:Label
        {
            color:"white"
            font.pointSize: 40
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
                        id: switchComponent
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
                    inputMask: "000"
                }



                Button
                {
                    id: blackInitialTime
                    text: "pick time"
  //                  color: "white"
                    onClicked: initialTimePicker.open()
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
                    inputMask: "000"
                }

                ListModel
                {
                    id: hoursList
                    ListElement { value: 0}
                    ListElement {value: 1}
                    ListElement { value: 2}
                }

                TumblerColumn
                {

                    id: hours
                    selectedIndex: 0
                    items: hoursList

                    //for (var day = 1; day <= 31; day++) {hoursList.append({"value" : day});
                }

//                TumblerColumn
//                {
//                    id: minutes
//                    selectedIndex: 0
//                    items: [0,1,2]
//                    //for (var day = 1; day <= 31; day++) {minutesList.append({"value" : day});
//                }

//                TumblerColumn
//                {
//                    id: seconds
//                    selectedIndex:0
//                    items: [0,1,2]
//                    //for (var day = 1; day <= 31; day++) {daysList.append({"value" : day});
//                }

//                Tumbler
//                {
//                    columns:[hours]
//                }

        Slider
        {
            id: blackAdditionalTime
            minimumValue: 0
            maximumValue: 100
            value: 1
            stepSize: 1
            valueIndicatorVisible: true

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
                    inputMask: "000"
                }

                Slider
                {
                    id: blackTurnsPerAddition
                    minimumValue: 0
                    maximumValue: 100
                    value: 1
                    stepSize: 1
                    valueIndicatorVisible: true

                }

         }


        buttons:

            Button
            {
                id: bOk
                text: "Start game"
                y: 150

                onClicked: newGameDialog.accept()
            }
    }

    TimePickerDialog
    {
        id: initialTimePicker
        titleText: "Choose initial time"
    }

}




