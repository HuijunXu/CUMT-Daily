#ifndef TIMELINE_H
#define TIMELINE_H
#include <QtSql/QSqlDatabase>
#include <QObject>
#include "News.h"
#include "Reply.h"
#include "User.h"
#include <QList>
#include "MainNews.h"
class TimeLine
        :public QObject
{
    Q_OBJECT
    Q_PROPERTY(MainNews* mainNews READ mainNews  NOTIFY mainNewsChanged)
    Q_PROPERTY(QList<QObject*> replyList READ replyList  NOTIFY replyListChanged)
    Q_PROPERTY(QObject* currentUser READ currentUser  NOTIFY currentUserChanged)
    Q_PROPERTY(bool newsCollected READ newsCollected  NOTIFY newsCollectedChanged)
public:
    TimeLine();
    ~TimeLine();

    MainNews* mainNews();
    Q_INVOKABLE QList<QObject*> replyList();
    QObject* currentUser();
    bool newsCollected();

    bool connSqlite();
    Q_INVOKABLE QList<QObject *> getNewsByType(QString type);
    Q_INVOKABLE QList<QObject *> getReadNews();
    Q_INVOKABLE QList<QObject *> getCollectNews();
     Q_INVOKABLE QList<QObject*> getReplyList();

    Q_INVOKABLE bool setMainNewsByID(QString id);
    Q_INVOKABLE bool setReplyListByID(QString id);
    Q_INVOKABLE bool setReplyListByUID(QString id);
    Q_INVOKABLE bool collectNews(QString nid);
    Q_INVOKABLE bool unCollectNews(QString nid);
    Q_INVOKABLE bool commitReply(QString nid,QString content);

private:
    QSqlDatabase db;
    MainNews* _mainNews=new MainNews();
    QList<Reply*> _replyList;
    User* _currentUser;
    bool _newsCollected=false;
signals:
    void mainNewsChanged();
    void replyListChanged();
    void currentUserChanged();
    void newsCollectedChanged();
};
extern void Initalize();

#endif // TIMELINE_H
