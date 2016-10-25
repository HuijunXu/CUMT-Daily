import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3
import QtMultimedia 5.4
import TimeLine 1.0
Rectangle {
    id: root
    function show(){
        newsListAnimation.from=newsList.x;
        newsListAnimation.to = -newsList.width/3;
        newsWindowAnimation.from=newsWindow.x;
        newsWindowAnimation.to=0;
        newsWindowAnimation.restart();
        newsListAnimation.restart();
    }
    function back(){
        newsListAnimation.from=-newsList.width/3;
        newsListAnimation.to = 0;
        newsWindowAnimation.from=0;
        newsWindowAnimation.to=newsWindow.width;
        newsWindowAnimation.restart();
        newsListAnimation.restart();
    }
    function init(newsId){
        if(TL.setMainNewsByID(newsId)){
            newsView.model=0;
            newsView.model=1;
            nid=newsId;
        }
    }
    function getTime(time){
        var temp=time.toString()
        temp=temp.split(" ")
        return "  2015年"+temp[1]+temp[2]+"日"
    }

    property string nid:""
    color: "white"

    MouseArea{anchors.fill: parent}
    ListView{
        id: newsView
        anchors.top: topMenu.bottom
        anchors.bottom: replyArea.top
        anchors.left: parent.left
        anchors.right: parent.right
        model:1
        delegate:
            Rectangle{
            width: newsView.width
            height: cl.height
            ColumnLayout{
                id: cl
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.leftMargin: 10*newsList.rate
                anchors.rightMargin: 10*newsList.rate
                Text{
                    text:TL.mainNews.title
                    font.pixelSize: 45*newsList.rate
                    font.family: "微软雅黑"
                }
                RowLayout{
                    Text{
                        text:TL.mainNews.source
                        font.pixelSize: 30*newsList.rate
                        color: "grey"
                        font.family: "微软雅黑"
                    }
                    Text{
                        text: root.getTime(TL.mainNews.time)
                        font.pixelSize: 30*newsList.rate
                        color: "grey"
                        font.family: "微软雅黑"
                    }

                }
                Rectangle{
                    width:parent.width
                    height: width/16*9
                    Image{
                        width:parent.width
                        height:parent.height
                        source: TL.mainNews.picPath
                        visible: true
                    }
                    Video {
                        id: video
                        width : parent.width
                        height : parent.height
                        source: TL.mainNews.videoPath
                        Component.onCompleted: {
                            if(TL.mainNews.videoExists()){
                                video.visible=true
                                video.seek(1)
                            }
                            else {
                                video.visible=false
                            }
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                if(video.hasVideo){
                                    if(video.playbackState!==MediaPlayer.PlayingState){
                                        video.play()
                                    }
                                    else {

                                        video.pause()
                                    }
                                }
                            }
                        }


                        focus: true
                        Slider {
                            id: slider
                            anchors.bottom: parent.bottom
                            anchors.bottomMargin: 10*newsList.rate
                            anchors.horizontalCenter: parent.horizontalCenter
                            maximumValue: video.duration
                            stepSize: 1
                            value: video.position
                            visible: video.playbackState!==MediaPlayer.PlayingState?false:true
                            onValueChanged:{
                                if((slider.value-video.position)>100||(slider.value-video.position)<-100){
                                    video.seek(slider.value)

                                }
                            }

                            style: SliderStyle {
                                groove: Rectangle {
                                    radius: 5*newsList.rate
                                    implicitWidth: newsList.width-30*newsList.rate
                                    implicitHeight: 10*newsList.rate
                                    color: "#5B5C5E"
                                    Rectangle{
                                        color: "#22C064"
                                        radius: 5*newsList.rate
                                        implicitHeight: 10*newsList.rate
                                        implicitWidth:parent.width*control.value/control.maximumValue+3*newsList.rate
                                    }

                                    Rectangle {
                                        anchors.fill: parent
                                        radius: 3*newsList.rate
                                        color: "gray"
                                        opacity: 0.7
                                        visible: !control.enabled
                                    }
                                }
                                handle: Rectangle {
                                    anchors.centerIn: parent
                                    color: control.pressed ? "lightgray"  : "white"
                                    border.color: "white"
                                    border.width: 4*newsList.rate
                                    implicitWidth: 26*newsList.rate
                                    implicitHeight: 26*newsList.rate
                                    radius: 13*newsList.rate
//                                    Rectangle{
//                                        anchors.centerIn: parent
//                                        implicitWidth: 8*newsList.rate
//                                        implicitHeight: 8*newsList.rate
//                                        radius: 4*newsList.rate
//                                        gradient: Gradient {
//                                               GradientStop { position: 0.0; color: "#6488BC" }
//                                               GradientStop { position: 1.0; color: "#385387" }
//                                           }
//                                    }
                                }
                            }
                        }
                    }
                }

                Rectangle{
                    width: parent.width
                    height: contentArea.contentHeight


                    Text{
                        id: contentArea
                        text:TL.mainNews.content
                        //                     anchors.left: parent.left
                        //                     anchors.right: parent.right
                        width: parent.width
                        wrapMode: Text.WrapAnywhere
                        font.pixelSize: 35*newsList.rate
                        font.family: "微软雅黑"
                    }
                }
            }
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
                onClicked: newsWindow.back()
            }
        }

        Rectangle{
            anchors.right: parent.right
            anchors.rightMargin: 10*newsList.rate
            anchors.verticalCenter: parent.verticalCenter
            width: replyCount.contentWidth+20*newsList.rate
            height: 40*newsList.rate
            radius: 15*newsList.rate
            color:"#E13E3F"
            Text{
                id: replyCount
                anchors.centerIn: parent
                color: "white"
                text: TL.mainNews.replyCount+"跟帖"
                font.family: "微软雅黑"
                font.pixelSize: 25*newsList.rate
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    replyWindow.init(nid)
                    replyWindow.show()
                }
            }
        }
        Rectangle{anchors.bottom: parent.bottom;width:parent.width;height:1;color:"lightgrey"}

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
//            border.color: "#E13E3F"
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
                        TL.commitReply(root.nid,textFiled.text)
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

