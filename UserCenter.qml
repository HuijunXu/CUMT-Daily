import QtQuick 2.0
import TimeLine 1.0
import QtQuick.Layouts 1.1
Rectangle {
    function show(){
        newsListAnimation.from=newsList.x;
        newsListAnimation.to = -newsList.width/3;
        userCenterAnimation.from=newsWindow.x;
        userCenterAnimation.to=0;
        userCenterAnimation.restart();
        newsListAnimation.restart();
    }
    function back(){
        newsListAnimation.from=-newsList.width/3;
        newsListAnimation.to = 0;
        userCenterAnimation.from=0;
        userCenterAnimation.to=newsWindow.width;
        userCenterAnimation.restart();
        newsListAnimation.restart();
    }
    MouseArea{anchors.fill: parent}

    Rectangle{
        width: parent.width
        height: 380*newsList.rate
        color: "red"
        Image{
            id: backIcon
            anchors.top: parent.top
            anchors.topMargin: 20*newsList.rate
            anchors.left: parent.left
            anchors.leftMargin: 20*newsList.rate
            width: 30*newsList.rate
            height: 50*newsList.rate
            source: "./images/back_white.png"
            MouseArea{
                anchors.fill: parent
                onClicked: userCenter.back()
            }
        }
        Rectangle{
            id: userIcon
            width: 140*newsList.rate
            height: 140*newsList.rate
            anchors.top: parent.top
            anchors.topMargin: 70*newsList.rate
            anchors.horizontalCenter: parent.horizontalCenter
            color: "transparent"
            radius: width/2
            Image {
                anchors.fill: parent
                source: TL.currentUser.userIcon

            }
        }
        Text{
            anchors.top:userIcon.bottom
            anchors.topMargin: 10*newsList.rate
            anchors.horizontalCenter: parent.horizontalCenter
            text: TL.currentUser.nicName
            font.family: "微软雅黑"
            font.pixelSize: 40*newsList.rate
            color: "white"
        }

    }
    Rectangle{
        id: main
        width: parent.width
        height: parent.height-380*newsList.rate
        y:380*newsList.rate
        ListView{
            id: listView
            width: main.width
            height: 130*newsList.rate
            model:listModel
            orientation: ListView.Horizontal
            delegate:Rectangle{
                width: listView.width/3
                height: listView.height
                color: mouseArea.pressed?"lightgrey":"white"
                Rectangle{height:parent.height;color:"grey";width:1;anchors.right: parent.right}
                Image{
                    id: img
                    width: parent.height/2
                    height: width
                    anchors.top: parent.top
                    anchors.topMargin: 20*newsList.rate
                    anchors.horizontalCenter: parent.horizontalCenter
                    source: icon
                }
                Text{
                    text: name
                    anchors.top:img.bottom
                    anchors.topMargin: 10*newsList.rate
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.family: "微软雅黑"
                    font.pixelSize: 25*newsList.rate
                    color: "grey"
                }
                MouseArea{
                    id: mouseArea
                    anchors.fill: parent
                    onClicked: {
                        switch(index){
                        case 0:
                            userRead.show();
                            break;
                        case 1:
                            userCollect.show();
                            break;
                        case 2:
                            replyWindow.showUser();
                            replyWindow.initUser();
                            break;
                        }
                    }
                }
            }
        }
        Rectangle{
            id: logOff
            width: 140*newsList.rate
            height: 140*newsList.rate
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 140*newsList.rate
            anchors.horizontalCenter: parent.horizontalCenter
            color: "transparent"
            radius: width/2
            Image {
                anchors.fill: parent
                source: "./images/logoff.png"

            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(TL.currentUser.logOff())
                        userCenter.back()
                }
            }
        }
    }
//    Text{
//        text:"热点新闻"
//    }



    ListModel {
        id: listModel
        ListElement {
            icon: "./images/read.png"
            name: "阅读"
        }
        ListElement {
            icon: "./images/collectIcon.png"
            name: "收藏"
        }
        ListElement {
            icon: "./images/reply.png"
            name: "跟帖"
        }
    }
    UserReply{
        id: userReply
        x: parent.width
        width: parent.width
        height: parent.height
        NumberAnimation on x {id: userReplyAnimation;duration: 300 }
    }
}

