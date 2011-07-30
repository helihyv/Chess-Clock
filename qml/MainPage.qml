import QtQuick 1.1
import com.meego 1.0
import QtQuick 1.0


Page {
    id: mainPage
    tools: commonTools
    Label {
        id: label
        anchors.centerIn: parent
        text: qsTr("Hello world!")
        visible: false
    }
    Button{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: label.bottom
        anchors.topMargin: 10
        text: qsTr("Click here!")
        onClicked: newGameDialog.open()
    }

//    Image {
//        id: image1
//        anchors.centerIn: parent
//        x: 0
//        y: 0
//        width: 100
//        height: 100
//        source: ":/pic/logo.png"
//    }

//    ListView {
//        id: list_view1
//        x: 0
//        y: 0
//        width: 300
//        height: 300
//    }

    Dialog
    {
        id:newGameDialog
        title:Label   { color:"white" ;text:"Normal Clock"}

        content:
            Row
            {
                id: rowRow
                spacing: 10
                anchors.fill: parent

                Switch
                {
                    id: switchComponent
                }

//                Text
//                {
//                  width: rowRow.width - rowRow.spacing - switchComponent.width
//                  height: switchComponent.height
//                  verticalAlignment: Text.AlignVCenter
//                  text: "Equal times"
//    //              font.pixelSize: platformStyle.fontSizeMedium
//                  color: white
//                }

        content: Row
            }
  //          Label   { color:"white" ;text:"Content Comes Here"}
        buttons:Button {id: bOk; text: "OK"; onClicked: newGameDialog.accept()}
    }

}


