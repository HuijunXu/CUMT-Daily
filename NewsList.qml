import QtQuick 2.4
import QtQuick.Controls 1.3
Rectangle {
    id: root
    property string type: ""
    anchors.fill: parent
    color:"white"
    MouseArea{anchors.fill: parent}
        NewsList_Main{
            id: mainNews
            property alias type:root.type
            width: root.width
        }
}

