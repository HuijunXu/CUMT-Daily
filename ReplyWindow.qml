import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3
import QtMultimedia 5.0
import TimeLine 1.0
Rectangle {
    id: root
    function show(){
        newsWindowAnimation.from=0;
        newsWindowAnimation.to = -newsWindow.width/3;
        replyWindowAnimation.from=replyWindow.x;
        replyWindowAnimation.to=0;
        newsWindowAnimation.restart();
        replyWindowAnimation.restart();
    }
    function back(){
        newsWindowAnimation.from=-newsWindow.width/3;
        newsWindowAnimation.to = 0;
        replyWindowAnimation.from=0;
        replyWindowAnimation.to=newsWindow.width;
        newsWindowAnimation.restart();
        replyWindowAnimation.restart();
    }
    function init(nid)
    {
        TL.setReplyListByID(nid);
        title.visible=false
    }
    function initUser(){
        TL.setReplyListByUID(TL.currentUser.uid)
        title.visible=true
    }

    function showUser(){
        replyWindowAnimation.from=replyWindow.x;
        replyWindowAnimation.to=0;
        replyWindowAnimation.restart();
    }
    function backToUserCenter(){
        replyWindowAnimation.from=0;
        replyWindowAnimation.to=newsWindow.width;
        replyWindowAnimation.restart();
    }

    color: "white"

    MouseArea{anchors.fill: parent}
    ListView{
        id: replyList
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: topMenu.bottom
        anchors.bottom: replyArea.top
        model:TL.replyList
        delegate:
            Rectangle{
            width: replyList.width
            height:230*newsList.rate
            Row{
                anchors.fill: parent
                anchors.leftMargin: 20*newsList.rate
                anchors.topMargin: 20*newsList.rate
                spacing: 10*newsList.rate
                Rectangle{
                    width:50*newsList.rate
                    height:50*newsList.rate
                    radius:25*newsList.rate
                    Image{
                        width:50*newsList.rate
                        height:50*newsList.rate
                        source: modelData.userIcon
                    }
                }
                Column{
                    width: replyList.width-100*newsList.rate
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    spacing: 10*newsList.rate
                    Text{
                        height: 40*newsList.rate
                        text: modelData.nicName
                        font.pixelSize: 30*newsList.rate
                        font.family: "微软雅黑"
                        color: "#8FB7DF"
                    }
                    Text{
                        height: 30*newsList.rate
                        text: modelData.replyTime
                        font.pixelSize: 25*newsList.rate
                        font.family: "微软雅黑"
                        color: "grey"
                    }
                    Text{
                        width: parent.width
                        height: 40*newsList.rate
                        text: modelData.content
                        font.pixelSize: 30*newsList.rate
                        font.family: "微软雅黑"
                        color: "black"
                        wrapMode: Text.Wrap
                    }
                }
            }
            Rectangle{anchors.bottom: parent.bottom;width:parent.width;height:1;color:"lightgrey"}
        }
    }

    Rectangle{
        id: topMenu
        width: parent.width
        height: 100*newsList.rate
        color: "white"
        Rectangle{
            width: 70*newsList.rate
            height: 70*newsList.rate
            radius: 35*newsList.rate
            anchors.left: parent.left
            anchors.leftMargin: 20*newsList.rate
            anchors.verticalCenter: parent.verticalCenter
            color: "transparent"


//            border.color: "grey"
//            border.width: 1
            Image{
                id: userIcon
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                width: 30*newsList.rate
                height: 50*newsList.rate
                source: "./images/back.png"

            }
            MouseArea{
                anchors.fill: parent
                onClicked: replyWindow.back()
            }
        }
        Rectangle{anchors.bottom: parent.bottom;width:parent.width;height:1;color:"lightgrey"}
    }

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
                onClicked: root.backToUserCenter()
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


    Rectangle{
        id: replyArea
        width: parent.width
        height:80*newsList.rate
        anchors.bottom: parent.bottom
        color: "white"
        TextField{
            id: textFiled
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 10*newsList.rate
            width:replyArea.width*7/10
            height: 60*newsList.rate
            placeholderText: "写评论"
            font.family: "微软雅黑"
            style: TextFieldStyle {
                textColor: "black"

                background: Rectangle {
                    radius: 25*newsList.rate
                    implicitWidth: replyArea.width*7/10
                    implicitHeight: 70*newsList.rate
                    border.color: "grey"
                    border.width: 1

                }

            }
        }
        Rectangle{
            id: sendButton
            anchors.left: textFiled.right
            anchors.leftMargin: 20*newsList.rate
            anchors.verticalCenter: parent.verticalCenter
            width: 100*newsList.rate
            height:50*newsList.rate
            color: "transparent"
            border.width: 1
            border.color: "grey"
            radius: 10*newsList.rate
            Text{
                anchors.centerIn: parent
                color: "grey"
                text: "发送"
                font.pixelSize: 30*newsList.rate
                font.family: "微软雅黑"
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(textFiled.text!==""){
                        TL.commitReply(TL.mainNews.id,textFiled.text)
                        TL.setReplyListByID(TL.mainNews.id)
                        textFiled.text=""
                    }
                }
            }
        }
        Image{
            anchors.left: sendButton.right
            anchors.leftMargin: 20*newsList.rate
            anchors.verticalCenter: parent.verticalCenter
            width: 50*newsList.rate
            height: width
            source: TL.newsCollected?"./images/collect.png":"./images/uncollect.png"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if (TL.newsCollected){
                        TL.unCollectNews(root.nid);
                    }
                    else TL.collectNews(root.nid);
                }
            }

        }

        Rectangle{color:"grey";width:parent.width;anchors.top: parent.top}
    }

}

