#include "User.h"
#include <QCryptographicHash>
#include <QDebug>
#include <QtSql/QtSql>
User::User()
{
}

User::~User()
{

}

QString User::uid()
{
    return _uid;

}



QString User::userIcon()
{
    return _userIcon;

}

QString User::nicName()
{
    return _nicName;
}

bool User::loginState()
{
    return _loginState;
}

bool User::userLogin(QString user, QString password)
{
    QString md5;
    QByteArray bb;
    bb = QCryptographicHash::hash ( password.toLocal8Bit(), QCryptographicHash::Md5 );
    md5.append(bb.toHex());
    QString sql="select * from user where account='"+user+"' and password='"+md5+"'";
    QSqlQuery query;
    query.exec(sql);
    qDebug()<<sql;
    while (query.next())
    {
        _uid= query.value("uid").toString();
        _nicName=query.value("nicname").toString();
        _userIcon=QString(HOME)+"/timeline/pic/"+query.value("usericon").toString();
        _loginState=true;
        emit uidChanged();
        emit nicNameChanged();
        emit userIconChanged();
        emit loginStateChanged();
        return true;
    }
    return false;
}

bool User::logOff()
{
    _loginState=false;
    emit loginStateChanged();
    return true;
}
