#ifndef MAINNEWS_H
#define MAINNEWS_H
#include <QObject>
#include <QDateTime>
class MainNews:
        public QObject

{
    Q_OBJECT
    Q_PROPERTY(QString id READ id NOTIFY idChanged)
    Q_PROPERTY(QString title READ title NOTIFY titleChanged)
    Q_PROPERTY(QString videoPath READ videoPath NOTIFY videoPathChanged)
    Q_PROPERTY(QString picPath READ picPath NOTIFY picPathChanged)
    Q_PROPERTY(QString source READ source NOTIFY sourceChanged)
    Q_PROPERTY(QString content READ content NOTIFY contentChanged)
    Q_PROPERTY(QDateTime time READ time NOTIFY timeChanged)
    Q_PROPERTY(qreal replyCount READ replyCount WRITE setReplyCount NOTIFY replyCountChanged)
public:
    MainNews();
    MainNews( QString id,
              QString title,
              QString videoPath,
              QString picPath,
              QString source,
              QString content,
              QDateTime time
              );

    ~MainNews();
    QString id();
    QString title();
    QString videoPath();
    QString picPath();
    QString source();
    QString content();
    QDateTime time();
    qreal replyCount();

    Q_INVOKABLE bool videoExists();

    void setReplyCount(int count);

private:
    QString _id;
    QString _title;
    QString _videoPath;
    QString _picPath;
    QString _source;
    QString _content;
    QDateTime _time;
    qreal _replyCount;
signals:
    void idChanged();
    void titleChanged();
    void videoPathChanged();
    void picPathChanged();
    void sourceChanged();
    void contentChanged();
    void timeChanged();
    void replyCountChanged();


};

#endif // MAINNEWS_H
