import QtQuick 2.0
import TimeLine 1.0
Rectangle{
    id: topNews //上方轮播部分
    width: parent.width
    height: parent.width*9/16+70*newsList.rate
    color:"white"
    function setModel(type){
        console.log(type)
        type = type+"1";
        topNewsPic.model=TL.getNewsByType(type);
    }

    ListView{
        id: topNewsPic
        width: parent.width
        height: parent.width*9/16
        function set(position){
            if(position<5||(position<width&&position>(width-250))){
//                        contentX=0
                topNewsPic.currentIndex=0
                picAnimation.to=0
                picAnimation.from=position
                picAnimation.restart()
            }
            else if(position<(width+5)||(position<2*width&&position>(2*width-250))){
//                        contentX=width
                topNewsPic.currentIndex=1
                picAnimation.to=width
                picAnimation.from=position
                picAnimation.restart()
            }
            else if(position<(2*width+5)||(position<3*width&&position>(3*width-250))){
//                        contentX=2*width
                topNewsPic.currentIndex=2
                picAnimation.to=2*width
                picAnimation.from=position
                picAnimation.restart()
            }
            else {
//                        contentX=3*width
                topNewsPic.currentIndex=3
                picAnimation.to=3*width
                picAnimation.from=position
                picAnimation.restart()
            }
        }
        orientation: ListView.Horizontal
         NumberAnimation on contentX {id:picAnimation;duration: 500 }
        delegate: Image{
            property string title:modelData.title
            property string nid:modelData.id
            width: root.width
            height: root.width*9/16

            Component.onCompleted: {
                source= modelData.thumbnail
            }
        }

    }
    MouseArea{
        width: root.width
        height: root.width*9/16
        anchors.top: topNews.top
        anchors.left: topNews.left
        property real xPress : -1
        onPressed:
        {
            xPress = mouse.x
        }
        onMouseXChanged:
        {
            if(x==-1)
                return;
            topNewsPic.contentX += -(mouse.x- xPress)
            xPress=mouse.x
            //                x = mouse.x
        }
        onMouseYChanged:
        {

        }
        onReleased:
        {
            xPress= -1
            topNewsPic.set(topNewsPic.contentX)
        }
        onClicked: {
            if(topNewsPic.contentX%topNewsPic.width==0){
            newsWindow.init(topNewsPic.currentItem.nid);
            newsWindow.show();
            }
        }

    }
    Rectangle{
        width: parent.width
        height: 70*newsList.rate
        color: "white"
        anchors.bottom: parent.bottom
        Text{
            id:topNewsText
            font.pixelSize: 30*newsList.rate
            font.family: "微软雅黑"
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: 10*newsList.rate
            anchors.left: parent.left
            color: "black"
            text: topNewsPic.currentItem.title
        }
        Rectangle{
            height: parent.height
            width: 160*newsList.rate
            anchors.right: parent.right
            anchors.rightMargin: 20*newsList.rate
            ListView{
                id: topNewsStat
                anchors.fill: parent
                orientation: ListView.Horizontal
                model: 4
                delegate: Rectangle{
                    width: topNewsStat.width/4
                    height: topNewsStat.height
                    color: "transparent"
                    Rectangle{
                        anchors.centerIn: parent
                        width: topNewsPic.currentIndex==index?20*newsList.rate:15*newsList.rate
                        height: width
                        radius: 10*newsList.rate
                        color: topNewsPic.currentIndex===index?"red":"grey"
                    }
                }
            }
        }


    }
}
