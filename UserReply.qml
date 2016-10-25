import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3
import TimeLine 1.0
Rectangle {
    function show(){
//        replyList.model=TL.getReplyList();
        TL.setReplyListByUID(TL.currentUser.uid)
        newsListAnimation.from=newsList.x;
        newsListAnimation.to = -newsList.width/3;
        userReplyAnimation.from=newsWindow.x;
        userReplyAnimation.to=0;
        userReplyAnimation.restart();
        newsListAnimation.restart();
    }
    function back(){
        newsListAnimation.from=-newsList.width/3;
        newsListAnimation.to = 0;
        userReplyAnimation.from=0;
        userReplyAnimation.to=newsWindow.width;
        userReplyAnimation.restart();
        newsListAnimation.restart();
    }
    MouseArea{anchors.fill: parent}
    color: "white"
    NumberAnimation on x {id: replyWindowAnimation;duration: 300 }
    MouseArea{anchors.fill: parent}
//    ListView{
//        id: replyList
//        anchors.left: parent.left
//        anchors.right: parent.right
//        anchors.top: topMenu.bottom
//        anchors.bottom: replyArea.top
//        model:TL.replyList
//        delegate:
//            Rectangle{
//            width: replyList.width
//            height:230*newsList.rate
//            Row{
//                anchors.fill: parent
//                anchors.leftMargin: 20*newsList.rate
//                anchors.topMargin: 20*newsList.rate
//                spacing: 10*newsList.rate
//                Rectangle{
//                    width:50*newsList.rate
//                    height:50*newsList.rate
//                    radius:25*newsList.rate
//                    Image{
//                        width:50*newsList.rate
//                        height:50*newsList.rate
//                        source: modelData.userIcon
//                    }
//                }
//                Column{
//                    width: replyList.width-100*newsList.rate
//                    anchors.top: parent.top
//                    anchors.bottom: parent.bottom
//                    spacing: 10*newsList.rate
//                    Text{
//                        height: 40*newsList.rate
//                        text: modelData.nicName
//                        font.pixelSize: 30*newsList.rate
//                        font.family: "微软雅黑"
//                        color: "#8FB7DF"
//                    }
//                    Text{
//                        height: 30*newsList.rate
//                        text: modelData.replyTime
//                        font.pixelSize: 25*newsList.rate
//                        font.family: "微软雅黑"
//                        color: "grey"
//                    }
//                    Text{
//                        width: parent.width
//                        height: 40*newsList.rate
//                        text: modelData.content
//                        font.pixelSize: 30*newsList.rate
//                        font.family: "微软雅黑"
//                        color: "black"
//                        wrapMode: Text.Wrap
//                    }
//                }
//            }
//            Rectangle{anchors.bottom: parent.bottom;width:parent.width;height:1;color:"lightgrey"}
//        }
//    }

    Rectangle{
        id: title
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
                onClicked: userReply.back()
            }
        }



        Text{
            id: titleText
            anchors.centerIn: parent
            color: "white"
            text: "跟帖列表"
            font.family: "微软雅黑"
            font.pixelSize: 40*newsList.rate
        }
    }

}

