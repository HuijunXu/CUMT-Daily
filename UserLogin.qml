import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3
import TimeLine 1.0
Rectangle {
    id: root
    function show(){
        newsListAnimation.from=newsList.x;
        newsListAnimation.to = -newsList.width/3;
        userLoginAnimation.from=newsWindow.x;
        userLoginAnimation.to=0;
        userLoginAnimation.restart();
        newsListAnimation.restart();
    }
    function back(){
        newsListAnimation.from=-newsList.width/3;
        newsListAnimation.to = 0;
        userLoginAnimation.from=0;
        userLoginAnimation.to=newsWindow.width;
        userLoginAnimation.restart();
        newsListAnimation.restart();

    }
    MouseArea{anchors.fill: parent}
    Rectangle{
        anchors.top: top.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        Image{
//            id: backIcon
            width: 140*newsList.rate
            height: 140*newsList.rate
            anchors.top: parent.top
            anchors.topMargin: 70*newsList.rate
            anchors.horizontalCenter: parent.horizontalCenter
            source: "./images/user.ico"
        }
        TextField{
            id: user
            anchors.top: parent.top
            anchors.topMargin: 300*newsList.rate
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width-100*newsList.rate
            height: 100*newsList.rate
            placeholderText: "请输入账号"
            font.pixelSize: 30*newsList.rate
             font.family: "微软雅黑"
            style:TextFieldStyle {
                textColor: "black"

                background: Rectangle {
                }

            }
        }
        Rectangle{width:user.width;height:1;color:"lightgrey";anchors.top: user.bottom;anchors.horizontalCenter: parent.horizontalCenter}
        TextField{
            id: password
            anchors.top: user.bottom
            anchors.topMargin: 2
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width-100*newsList.rate
            height: 100*newsList.rate
            placeholderText: "请输入密码"
            font.pixelSize: 30*newsList.rate
            font.family: "微软雅黑"
            echoMode:TextInput.Password
            style:TextFieldStyle {
                textColor: "black"

                background: Rectangle {
                }

            }
        }
        Rectangle{width:user.width;height:1;color:"lightgrey";anchors.top: password.bottom;anchors.horizontalCenter: parent.horizontalCenter}
        Rectangle{
            width: parent.width-100*newsList.rate
            anchors.top: password.bottom
            anchors.topMargin: 50*newsList.rate
            anchors.horizontalCenter: parent.horizontalCenter
            height: 100*newsList.rate
            border.color: "lightgrey"
            border.width: 1
            radius:10*newsList.rate
            Text{
                text: "确认"
                font.pixelSize: 40*newsList.rate
                anchors.centerIn: parent
                font.family: "微软雅黑"
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(TL.currentUser.userLogin(user.text,password.text)){
                        root.back();
                        user.text="";
                        password.text="";
                    }
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
                onClicked: root.back()
            }

        }



        Text{
            id: titleText
            anchors.centerIn: parent
            color: "white"
            text: "用户登录"
            font.family: "微软雅黑"
            font.pixelSize: 40*newsList.rate
        }
    }

}

