#include "News.h"
#include <QString>
News::News()
{

}

News::~News()
{

}

News::News(QString id, QString title, QString discribe, QString thumbnail)
{
    _id=id;
    _title=title;
    _discribe=discribe;
    _thumbnail=QString(HOME)+QString("/timeline/pic/")+thumbnail;
}

QString News::id()
{
    return _id;
}

QString News::title()
{
    return _title;
}

QString News::discribe()
{
    return _discribe;
}

QString News::thumbnail()
{
    return _thumbnail;
}

