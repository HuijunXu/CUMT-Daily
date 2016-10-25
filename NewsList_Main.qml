import QtQuick 2.0
import TimeLine 1.0
Rectangle {
    id: root
    width:1000
    height: 1650
    color: "transparent"
    MouseArea{anchors.fill: parent}
    ListView{
        id: mainNewsList
        anchors.fill: parent
        Component.onCompleted: {
            console.log(root.type)
            mainNewsList.model=TL.getNewsByType(root.type)
            //root.height=(count-1)*165*360/820+(parent.width*9/16+70*360/768)
            root.height=(count+2)*165+(parent.width*9/16+70*newsList.rate)-165*newsList.rate
        }

        delegate:Rectangle{
            id: dele
            width: mainNews.width
            height: index===0?(parent.width*9/16+70*newsList.rate):165*newsList.rate
            Component.onCompleted: {
                if(index===0){
                    var component = Qt.createComponent("NewsList_Top.qml");
                    var sprite = component.createObject(dele, {"x": 0, "y": 0});
                    sprite.setModel(root.type);

                }

            }

            Image{
                id: pic
                width: 180*newsList.rate
                height: 120*newsList.rate
                anchors.left: parent.left
                anchors.leftMargin: 20*newsList.rate
                anchors.top: parent.top
                anchors.topMargin: 20*newsList.rate
                Component.onCompleted: {
                    source= modelData.thumbnail
                }

            }
            Text{
                id: title
                anchors.top: parent.top
                anchors.topMargin: 20*newsList.rate
                anchors.left: pic.right
                anchors.leftMargin: 10*newsList.rate
                width: parent.width-220*newsList.rate
                text: modelData.title
                font.family: "微软雅黑"
                font.pixelSize: 30*newsList.rate
            }
            Text{
                anchors.top: title.bottom
                anchors.topMargin: 10*newsList.rate
                anchors.left: pic.right
                anchors.leftMargin: 10*newsList.rate
                width: parent.width-220*newsList.rate
                height:50*newsList.rate
                text: modelData.discribe
                font.family: "微软雅黑"
                font.pixelSize: 25*newsList.rate
                color: "grey"
                wrapMode: Text.Wrap
            }

            Rectangle{
                anchors.bottom: parent.bottom
                width: parent.width
                height: 1
                color: "lightgrey"
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    newsWindow.init(modelData.id);
                    newsWindow.show();
                }
            }
        }
    }

}

