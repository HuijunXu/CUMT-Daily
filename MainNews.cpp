#include "MainNews.h"

MainNews::MainNews()
{

}

MainNews::MainNews(QString id, QString title,QString videoPath, QString picPath, QString source, QString content, QDateTime time)
{
    _id=id;
    _title=title;
    _videoPath=videoPath;
    _picPath=picPath;
    _source=source;
    _content=content;
    _time=time;
}

MainNews::~MainNews()
{

}

QString MainNews::id()
{
    return _id;
}

QString MainNews::title()
{
    return _title;
}

QString MainNews::videoPath()
{
    return _videoPath;
}

QString MainNews::picPath()
{
    return _picPath;
}

QString MainNews::source()
{
    return _source;
}

QString MainNews::content()
{
    return _content;
}

QDateTime MainNews::time()
{
    return _time;
}

qreal MainNews::replyCount()
{
    return _replyCount;
}

bool MainNews::videoExists()
{
    if(_videoPath=="")
        return false;
    else return true;

}

void MainNews::setReplyCount(int count)
{
    _replyCount=count;
    emit replyCountChanged();
}

//#include "MainNews.moc"

