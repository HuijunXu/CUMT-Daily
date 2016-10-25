#ifndef NEWS_H
#define NEWS_H

#include <QObject>
//#define HOME "http://192.168.191.1"
#define HOME "file:///sdcard/Download"
class News
        :public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id  NOTIFY idChanged)
    Q_PROPERTY(QString title READ title  NOTIFY titleChanged)
    Q_PROPERTY(QString discribe READ discribe  NOTIFY discribeChanged)
    Q_PROPERTY(QString thumbnail READ thumbnail  NOTIFY thumbnailChanged)
public:
    News();
    ~News();
    News(
            QString id,
            QString title,
            QString discribe,
            QString thumbnail);

    QString id();
    QString title();
    QString discribe();
    QString thumbnail();

private:
    QString _id;
    QString _title;
    QString _discribe;
    QString _thumbnail;
signals:
    void idChanged();
    void titleChanged();
    void discribeChanged();
    void thumbnailChanged();
};

#endif // NEWS_H
