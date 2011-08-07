import QtQuick 1.1
import com.meego 1.0
import QtQuick 1.0
import com.nokia.extras 1.0

Page
{
    id: aboutPage
//    tools: commonTools

    tools: ToolBarLayout {
        ToolButton { iconSource: "toolbar-back"; onClicked: pageStack.pop() }
    }

Text
{
    id: title
    text: "Chess Clock"
    color: "white"
    font.pointSize: 64
}

Text
{

    text: "text"
    color: "white"
    font.pointSize: 32
    anchors.top: title.bottom
    anchors.topMargin: 64
}

}
