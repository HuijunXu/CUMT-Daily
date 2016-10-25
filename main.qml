import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.3
import QtMultimedia 5.4
import TimeLine 1.0
ApplicationWindow {
    title: qsTr("My Timeline")
    width: 1080//Screen.desktopAvailableWidth//360
    height: 1920//Screen.desktopAvailableHeight//540
    visible: true
    flags: Qt.FramelessWindowHint

    Rectangle{
        id: newsList
        property real rate: parent.width/768
        width: parent.width
        height:parent.height
        TabView{
            id: tabView
            anchors.top: title.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            style:TabViewStyle {
                frameOverlap: -1
                frame:Rectangle{color:"white"}
                tabsMovable:true
                tab:Rectangle {
                    color:"white"
                    implicitHeight: 70*newsList.rate;
                    implicitWidth: tabView.width/5+1
                    Text {
                        text:styleData.title
                        anchors.centerIn: parent
                        color:styleData.selected?"red":"black"
                        font.pixelSize: styleData.selected?40*newsList.rate:30*newsList.rate
                    }
                    Rectangle{
                        height: 3
                        width: parent.width
                        color: "red"
                        visible:styleData.selected?true:false
                        anchors.bottom: parent.bottom
                    }
                }
            }
            Tab{
                title: "校园"
                NewsList{
                    anchors.fill: parent
                    type: "TT"
                }
            }
            Tab{
                title: "财经"
                NewsList{
                    type: "CJ"
                }
            }
            Tab{
                title: "体育"
                NewsList{
                    type: "TY"
                }
            }
            Tab{
                title: "科技"
                NewsList{
                    type: "KJ"
                }
            }
            Tab{
                title: "NBA"
                NewsList{
                    type: "NBA"
                }
            }
        }
     NumberAnimation on x {id: newsListAnimation;duration: 300 }
     Rectangle{
         id: title
         width: parent.width
         height: 100*newsList.rate
         color: "#E13E3F"
         Rectangle{
             width: 100*newsList.rate
             height: 100*newsList.rate
             anchors.right: parent.right
             color: "transparent"
             Image{
                 id: userIcon
                 anchors.centerIn: parent
                 width: 80*newsList.rate
                 height: 80*newsList.rate
                 source: TL.currentUser.loginState?TL.currentUser.userIcon:"./images/user.png"
             }
             MouseArea{
                 anchors.fill: parent
                 onClicked:
                 {
                     if(TL.currentUser.loginState){
                         userCenter.show();
                     }
                     else{
                         userLogin.show();
                     }
                 }
             }
         }


         Text{
             id: titleText
             anchors.centerIn: parent
             color: "white"
             text: "今日矿大"
             font.family: "微软雅黑"
             font.pixelSize: 40*newsList.rate
         }
     }

    }

    UserCenter{
        id: userCenter
        x: parent.width
        width: parent.width
        height: parent.height
        NumberAnimation on x {id: userCenterAnimation;duration: 300 }
    }
    UserRead{
        id: userRead
        x: parent.width
        width: parent.width
        height: parent.height
        NumberAnimation on x {id: userReadAnimation;duration: 300 }
    }
    UserCollect{
        id: userCollect
        x: parent.width
        width: parent.width
        height: parent.height
        NumberAnimation on x {id: userCollectAnimation;duration: 300 }
    }
    UserLogin{
        id: userLogin
        x: parent.width
        width: parent.width
        height: parent.height
        NumberAnimation on x {id: userLoginAnimation;duration: 300 }
    }

    NewsWindow{
        id: newsWindow
        x: parent.width
        width: parent.width
        height: parent.height
        NumberAnimation on x {id: newsWindowAnimation;duration: 300 }
    }


    ReplyWindow{
        id: replyWindow
        x: width
        width: parent.width
        height:parent.height
        NumberAnimation on x {id: replyWindowAnimation;duration: 300 }
    }

}
