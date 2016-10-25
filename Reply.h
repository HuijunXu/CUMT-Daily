#ifndef REPLY_H
#define REPLY_H
#include <QObject>
#include <QDateTime>
class Reply:
        public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString uid READ uid NOTIFY uidChanged)
    Q_PROPERTY(QString nicName READ nicName NOTIFY nicNameChanged)
    Q_PROPERTY(QString userIcon READ userIcon NOTIFY userIconChanged)
    Q_PROPERTY(QString content READ content NOTIFY contentChanged)
    Q_PROPERTY(QDateTime replyTime READ replyTime NOTIFY replyTimeChanged)
public:
    Reply();
    ~Reply();

    Reply(QString uid,
          QString nicName,
          QString userIcon,
          QString content,
          QDateTime replyTime
          );
    QString uid();
    QString nicName();
    QString userIcon();
    QString content();
    QDateTime replyTime();

private:
    QString _uid;
    QString _nicName;
    QString _userIcon;
    QString _content;
    QDateTime _replyTime;
signals:
    void uidChanged();
    void nicNameChanged();
    void userIconChanged();
    void contentChanged();
    void replyTimeChanged();
};

#endif // REPLY_H
