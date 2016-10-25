#ifndef USER_H
#define USER_H
#include <QObject>
#include "News.h"
class User
        :public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString uid READ uid  NOTIFY uidChanged)
    Q_PROPERTY(QString userIcon READ userIcon  NOTIFY userIconChanged)
    Q_PROPERTY(QString nicName READ nicName  NOTIFY nicNameChanged)
    Q_PROPERTY(bool loginState READ loginState  NOTIFY loginStateChanged)
public:
    User();
    ~User();

    QString uid();
    QString userIcon();
    QString nicName();
    bool loginState();

    Q_INVOKABLE bool userLogin(QString user,QString password);
    Q_INVOKABLE bool logOff();
private:
    bool _loginState=false;
    QString _uid;
    QString _nicName="FaintzZ";
    QString _userIcon=QString(HOME)+"/timeline/pic/user.ico";
signals:
    void uidChanged();
    void userIconChanged();
    void nicNameChanged();
    void loginStateChanged();
};

#endif // USER_H
