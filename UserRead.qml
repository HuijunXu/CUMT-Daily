import QtQuick 2.0
import TimeLine 1.0
Rectangle {
    function show(){
        newsListAnimation.from=newsList.x;
        newsListAnimation.to = -newsList.width/3;
        userReadAnimation.from=newsWindow.x;
        userReadAnimation.to=0;
        userReadAnimation.restart();
        newsListAnimation.restart();
        readtNewsList.model=TL.getReadNews()
    }
    function back(){
        newsListAnimation.from=-newsList.width/3;
        newsListAnimation.to = 0;
        userReadAnimation.from=0;
        userReadAnimation.to=newsWindow.width;
        userReadAnimation.restart();
        newsListAnimation.restart();
    }
    MouseArea{anchors.fill: parent}
   ListView{
        id: readtNewsList
        anchors.fill: parent
        anchors.topMargin: top.height

        delegate:Rectangle{
            id: dele
            width: top.width
            height:165*newsList.rate
            Image{
                id: pic
                width: 180*newsList.rate
                height: 120*newsList.rate
                anchors.left: parent.left
                anchors.leftMargin: 20*newsList.rate
                anchors.top: parent.top
                anchors.topMargin: 20*newsList.rate
                source: modelData.thumbnail
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        newsWindow.init(modelData.id);
                        newsWindow.show();
                    }
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
                height:50
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
//                anchors.fill: parent
                width: top.width
                height: 165*newsList.rate
                onClicked: {
                    newsWindow.init(modelData.id);
                    newsWindow.show();
                }
            }
        }
    }
   Rectangle{
       id: top
       width: parent.width
       height: 100*newsList.rate
       color: "#E13E3F"
       Rectangle{
           width: 70*newsList.rate
           height: 70*newsList.rate
           radius: 35*newsList.rate
           anchors.left: parent.left
           anchors.leftMargin: 20*newsList.rate
           anchors.verticalCenter: parent.verticalCenter
           color: "transparent"
           Image{
               id: backIcon
               anchors.verticalCenter: parent.verticalCenter
               anchors.horizontalCenter: parent.horizontalCenter
               width: 30*newsList.rate
               height: 50*newsList.rate
               source: "./images/back_white.png"
           }
           MouseArea{
               anchors.fill: parent
               onClicked: userRead.back()
           }
       }



       Text{
           id: titleText
           anchors.centerIn: parent
           color: "white"
           text: "已读列表"
           font.family: "微软雅黑"
           font.pixelSize: 40*newsList.rate
       }
   }

}

