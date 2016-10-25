#include "TimeLine.h"
#include <QObject>
#include <QApplication>
#include <QQmlEngine>
#include <QScreen>
#include <QDir>
#include <QtQml>
#include <QtSql/QtSql>
#include <QDebug>
#include <QDir>
#include <QDateTime>
#include <QApplication>
#include <QScreen>
#include <QDesktopWidget>
#include <qjsonarray.h>
static TimeLine* timeline = NULL;

static QObject* getTimeLine(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    return timeline;
}

extern void Initalize()
{

    qmlRegisterSingletonType<TimeLine>("TimeLine", 1, 0, "TL", getTimeLine);
    qmlRegisterType<News>("TimeLine",1,0,"News");
    qmlRegisterType<MainNews>("TimeLine",1,0,"MainNews");
    qmlRegisterType<Reply>("TimeLine",1,0,"Reply");
    qmlRegisterType<User>("TimeLine",1,0,"User");
    Q_ASSERT(timeline==NULL);
    timeline = new TimeLine();

}
TimeLine::TimeLine()
{
    this->connSqlite();
    _currentUser=new User();
//    emit newsCollectedChanged();
}

TimeLine::~TimeLine()
{

}

bool TimeLine::connSqlite()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/D:/wamp/www/timeline/database.db");
//    db = QSqlDatabase::addDatabase("QODBC");
//    db.setHostName("192.168.191.1:Mysql");
//    db.setDatabaseName("Mysql");
//    db.setUserName("root");
//    db.setPassword("");
    //此处填写数据库连接信息
     if(!db.open()){
         qDebug()<<"Failed!!!";
         qDebug()<<db.lastError().text();
         db.setDatabaseName("/mnt/sdcard/Download/database.db");
         if(!db.open()){
             qDebug()<<"Failed!!!";
             return false;
         }
         else return true;
     }
     else {

         qDebug()<<"success";
         return true;
     }

}

QList<QObject *> TimeLine::getNewsByType(QString type)
{
    QString sql="SELECT * FROM News where news_index='"+type+"'";
    QSqlQuery query;
    query.exec(sql);
    QList<QObject *> newsList;
    while (query.next())
    {
        newsList.append(new News(query.value("nid").toString(),
                             query.value("title").toString(),
                             query.value("discribe").toString(),
                             query.value("thumbnail").toString()
                            ));
    }
    return newsList;
}

QList<QObject *> TimeLine::getReadNews()
{
    QString sql="SELECT  * FROM News,reads where News.nid="
                "reads.nid and reads.uid='"+_currentUser->uid()
            +"' order by read_time desc limit 20 ";
    QSqlQuery query;
    query.exec(sql);
    QList<QObject *> newsList;
    while (query.next())
    {
        newsList.append(new News(query.value("nid").toString(),
                             query.value("title").toString(),
                             query.value("discribe").toString(),
                             query.value("thumbnail").toString()
                            ));
    }
    return newsList;
}

QList<QObject *> TimeLine::getCollectNews()
{
    QString sql="SELECT * FROM News,collect where News.nid=collect.nid and collect.uid='"+_currentUser->uid()+"' order  by collect_time desc";
    QSqlQuery query;
    query.exec(sql);
    QList<QObject *> newsList;
    while (query.next())
    {
        newsList.append(new News(query.value("nid").toString(),
                             query.value("title").toString(),
                             query.value("discribe").toString(),
                             query.value("thumbnail").toString()
                            ));
    }
    return newsList;
}

QList<QObject *> TimeLine::getReplyList()
{
    QString uid;
    QString nicName;
    QString userIco;
    QString content;
    QDateTime replyTime;
    QList<QObject *> replyList;
    QString sql="select * from user,reply where user.uid=reply.uid and reply.uid='"+_currentUser->uid()+"' order by replyTime desc";
    QSqlQuery query;
    query.exec(sql);
    while (query.next())
    {

        uid=query.value("uid").toString();
        nicName=query.value("nicName").toString();
        userIco=QString(HOME)+QString("/timeline/pic/")+query.value("userIcon").toString();
        content=query.value("content").toString();
        replyTime=query.value("replyTime").toDateTime();
        replyList.append(new Reply( uid,
                                     nicName,
                                     userIco,
                                     content,
                                     replyTime
                                     ));
    }
    return replyList;
}

bool TimeLine::setMainNewsByID(QString id)
{
    QString title;
    QString videoPath="";
    QString picPath="";
    QString source;
    QString content;
    QDateTime time;

    QString sql="SELECT * FROM News where nid='"+id+"'";
    QSqlQuery query;
    query.exec(sql);
    if (query.next())
    {
        title=query.value("title").toString();
        content=query.value("content").toString();
        source=query.value("source").toString();
        time=query.value("time").toDateTime();
        sql="SELECT * FROM Video where nid='"+id+"'";
        query.exec(sql);
        if (query.next())
        {
            videoPath=QString(HOME)+QString("/timeline/video/")+query.value("videoPath").toString();
        }
        sql="SELECT * FROM Picture where nid='"+id+"'";
        query.exec(sql);
        if (query.next())
        {
            picPath=QString(HOME)+QString("/timeline/pic/")+query.value("picPath").toString();
        }
        _mainNews=new MainNews(  id,
                                 title,
                                 videoPath,
                                 picPath,
                                 source,
                                 content,
                                 time
                                );
        emit mainNewsChanged();

        _mainNews->setReplyCount(0);
        sql="SELECT count(*) FROM reply where nid='"+id+"'";
        query.exec(sql);
        if (query.next())
        {
            _mainNews->setReplyCount(query.value("count(*)").toInt());
        }

        sql="SELECT * FROM COLLECT where nid='"+id+"' and uid='"+_currentUser->uid()+"'";
        query.exec(sql);
        qDebug()<<sql;
        if (query.next())
        {
            _newsCollected=true;
        }
        else _newsCollected=false;
        emit newsCollectedChanged();

        QString time=QDateTime::currentDateTime().toString("yyyy.MM.dd:hh:mm:ss");

        if(_currentUser->loginState())
        {
            sql="DELETE FROM READS where nid='"+id+"' and uid='"+_currentUser->uid()+"'";
            query.exec(sql);
            sql="INSERT INTO READS (nid,uid,read_time) VALUES ('"+id+"','"+ _currentUser->uid()+"','"+time+"')";
            query.exec(sql);
        }
        return true;


    }
    else return false;
}

bool TimeLine::setReplyListByID(QString id)
{

        QString uid;
        QString nicName;
        QString userIco;
        QString content;
        QDateTime replyTime;
    _replyList.clear();
    QString sql="select * from user,reply where user.uid=reply.uid and reply.nid='"+id+"' order by replyTime desc";
    QSqlQuery query;
    query.exec(sql);
    while (query.next())
    {

        uid=query.value("uid").toString();
        nicName=query.value("nicName").toString();
        userIco=QString(HOME)+QString("/timeline/pic/")+query.value("userIcon").toString();
        content=query.value("content").toString();
        replyTime=query.value("replyTime").toDateTime();
        _replyList.append(new Reply( uid,
                           nicName,
                           userIco,
                           content,
                           replyTime
                              ));
    }
    emit replyListChanged();
    return true;
}

bool TimeLine::setReplyListByUID(QString id)
{

    QString uid;
    QString nicName;
    QString userIco;
    QString content;
    QDateTime replyTime;
    _replyList.clear();
    QString sql="select * from user,reply where user.uid=reply.uid and reply.uid='"+id+"'";
    QSqlQuery query;
    query.exec(sql);
    while (query.next())
    {

        uid=query.value("uid").toString();
        nicName=query.value("nicName").toString();
        userIco=QString(HOME)+QString("/timeline/pic/")+query.value("userIcon").toString();
        content=query.value("content").toString();
        replyTime=query.value("replyTime").toDateTime();
        _replyList.append(new Reply( uid,
                                     nicName,
                                     userIco,
                                     content,
                                     replyTime
                                     ));
    }

    emit replyListChanged();
    return true;
}

bool TimeLine::collectNews(QString nid)
{
    if(!_currentUser->loginState())
    {
        return false;
    }
    QString time=QDateTime::currentDateTime().toString("yyyy.MM.dd:hh:mm:ss");
    QString sql="INSERT INTO collect (nid,uid,collect_time) VALUES ('"+nid+"','"+ _currentUser->uid()+"','"+time+"')";
    QSqlQuery query;
    if(query.exec(sql) ){
        _newsCollected=true;
        emit newsCollectedChanged();
        return true;
    }
    else return false;
}

bool TimeLine::unCollectNews(QString nid)
{
    if(!_currentUser->loginState())
    {
        return false;
    }
    QString sql="DELETE FROM collect where nid='"+nid+"' and uid='"+ _currentUser->uid()+"'";
    QSqlQuery query;
    if(query.exec(sql) ){
        _newsCollected=false;
        emit newsCollectedChanged();
        return true;
    }
    else return false;
}

bool TimeLine::commitReply(QString nid, QString content)
{
    if(!_currentUser->loginState())
    {
        return false;
    }
    QString time=QDateTime::currentDateTime().toString("yyyy.MM.dd:hh:mm:ss");
    QString sql="INSERT INTO reply (nid,uid,content,replyTime) VALUES ('"+nid+"','"+ _currentUser->uid()+"','"+content+"','"+time+"')";
    QSqlQuery query;
    if(query.exec(sql) ){
        sql="SELECT count(*) FROM reply where nid='"+nid+"'";
        query.exec(sql);
        if (query.next())
        {
            _mainNews->setReplyCount(query.value("count(*)").toInt());
        }
        return true;
    }
    else return false;
}



MainNews* TimeLine::mainNews()
{
    return _mainNews;
}

QList<QObject *> TimeLine::replyList()
{
    QList<QObject*> r;
    foreach(QObject* o,_replyList)
        r.append(o);
    return r;
}

QObject* TimeLine::currentUser()
{
    return _currentUser;
}

bool TimeLine::newsCollected()
{
    return _newsCollected;
}





