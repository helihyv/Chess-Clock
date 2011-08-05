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


        }

        ListElement
        {
            name: "Addition before"
        }

        ListElement
        {
            name: "Addition after"


        }

        ListElement
        {
            name: "Delay"

        }

        ListElement
        {
            name: "Delay after"
        }

        ListElement
        {
            name:"Hour Glass"
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

            MouseArea
            {
                anchors.fill: parent
                onClicked: {newGameDialog.name = name; newGameDialog.open()}
            }
        }

    }





    Dialog
    {
        id:newGameDialog

        property string name


        title:Label
        {
            color:"white"
            font.pointSize: 40
            text: newGameDialog.name
        }


        content:
            Row
            {
                id: rowRow
                spacing: 10
                anchors.fill: parent

                Text
                {
                  width: rowRow.width - rowRow.spacing - switchComponent.width
                  height: switchComponent.height
                  verticalAlignment: Text.AlignVCenter
                  text: "Equal times"
                  color: "white"
                  font.pointSize: 16
                }

                Switch
                {
                    id: switchComponent
                }

            }

        buttons:

            Button
            {
                id: bOk
                text: "OK"
                y: 300

                onClicked: newGameDialog.accept()
            }
    }

}


