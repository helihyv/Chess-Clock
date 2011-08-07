import QtQuick 1.1
import com.meego 1.0
import QtQuick 1.0


Page {
    id: mainPage
    tools: commonTools






//    Label {
//        id: label
//        anchors.centerIn: parent
//        text: qsTr("Hello world!")
//        visible: false
//    }
//    Button{
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.top: label.bottom
//        anchors.topMargin: 10
//        text: qsTr("Click here!")
//        onClicked: newGameDialog.open()
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


        }

        ListElement
        {
            name: "Addition before"
            askAddition: true
        }

        ListElement
        {
            name: "Addition after"
            askAddition: true
        }

        ListElement
        {
            name: "Delay"
            askAddition: true
        }

        ListElement
        {
            name: "Delay after"
            askAddition: true
        }

        ListElement
        {
            name:"Hour Glass"
            askAddition: false
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

         delegate: Text
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

                Text
                {
                    id: additionalTimeText
                    text: "Additional time"
                    color: "white"
                    font.pointSize: 26
//                    visible: newGameDialog.askAddition
//                    anchors.top: initialTimeText.bottom
//                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Text
                {
                    text:  "Turns per addition"
                    color: "white"
                    font.pointSize: 26
//                    visible: newGameDialog.askAddition
//                    anchors.top: additionalTimeText.bottom
//                    anchors.horizontalCenter: parent.horizontalCenter
                }
    }


        buttons:

            Button
            {
                id: bOk
                text: "Start game"
                y: 170

                onClicked: newGameDialog.accept()
            }
    }

}


