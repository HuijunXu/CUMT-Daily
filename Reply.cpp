#include "Reply.h"

Reply::Reply()
{

}

Reply::~Reply()
{

}

Reply::Reply(QString uid, QString nicName, QString userIcon, QString content, QDateTime replyTime)
{
    _uid=uid;
    _nicName=nicName;
    _userIcon=userIcon;
    _content=content;
    _replyTime=replyTime;
}

QString Reply::uid()
{
    return _uid;
}

QString Reply::nicName()
{
    return _nicName;
}

QString Reply::userIcon()
{
    return _userIcon;
}

QString Reply::content()
{
    return _content;
}

QDateTime Reply::replyTime()
{

    return _replyTime;
}

