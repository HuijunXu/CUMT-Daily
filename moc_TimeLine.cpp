/****************************************************************************
** Meta object code from reading C++ file 'TimeLine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TimeLine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TimeLine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TimeLine_t {
    QByteArrayData data[26];
    char stringdata[317];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimeLine_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimeLine_t qt_meta_stringdata_TimeLine = {
    {
QT_MOC_LITERAL(0, 0, 8), // "TimeLine"
QT_MOC_LITERAL(1, 9, 15), // "mainNewsChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 16), // "replyListChanged"
QT_MOC_LITERAL(4, 43, 18), // "currentUserChanged"
QT_MOC_LITERAL(5, 62, 20), // "newsCollectedChanged"
QT_MOC_LITERAL(6, 83, 9), // "replyList"
QT_MOC_LITERAL(7, 93, 15), // "QList<QObject*>"
QT_MOC_LITERAL(8, 109, 13), // "getNewsByType"
QT_MOC_LITERAL(9, 123, 4), // "type"
QT_MOC_LITERAL(10, 128, 11), // "getReadNews"
QT_MOC_LITERAL(11, 140, 14), // "getCollectNews"
QT_MOC_LITERAL(12, 155, 12), // "getReplyList"
QT_MOC_LITERAL(13, 168, 15), // "setMainNewsByID"
QT_MOC_LITERAL(14, 184, 2), // "id"
QT_MOC_LITERAL(15, 187, 16), // "setReplyListByID"
QT_MOC_LITERAL(16, 204, 17), // "setReplyListByUID"
QT_MOC_LITERAL(17, 222, 11), // "collectNews"
QT_MOC_LITERAL(18, 234, 3), // "nid"
QT_MOC_LITERAL(19, 238, 13), // "unCollectNews"
QT_MOC_LITERAL(20, 252, 11), // "commitReply"
QT_MOC_LITERAL(21, 264, 7), // "content"
QT_MOC_LITERAL(22, 272, 8), // "mainNews"
QT_MOC_LITERAL(23, 281, 9), // "MainNews*"
QT_MOC_LITERAL(24, 291, 11), // "currentUser"
QT_MOC_LITERAL(25, 303, 13) // "newsCollected"

    },
    "TimeLine\0mainNewsChanged\0\0replyListChanged\0"
    "currentUserChanged\0newsCollectedChanged\0"
    "replyList\0QList<QObject*>\0getNewsByType\0"
    "type\0getReadNews\0getCollectNews\0"
    "getReplyList\0setMainNewsByID\0id\0"
    "setReplyListByID\0setReplyListByUID\0"
    "collectNews\0nid\0unCollectNews\0commitReply\0"
    "content\0mainNews\0MainNews*\0currentUser\0"
    "newsCollected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimeLine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       4,  120, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    0,   92,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       6,    0,   93,    2, 0x02 /* Public */,
       8,    1,   94,    2, 0x02 /* Public */,
      10,    0,   97,    2, 0x02 /* Public */,
      11,    0,   98,    2, 0x02 /* Public */,
      12,    0,   99,    2, 0x02 /* Public */,
      13,    1,  100,    2, 0x02 /* Public */,
      15,    1,  103,    2, 0x02 /* Public */,
      16,    1,  106,    2, 0x02 /* Public */,
      17,    1,  109,    2, 0x02 /* Public */,
      19,    1,  112,    2, 0x02 /* Public */,
      20,    2,  115,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    0x80000000 | 7,
    0x80000000 | 7, QMetaType::QString,    9,
    0x80000000 | 7,
    0x80000000 | 7,
    0x80000000 | 7,
    QMetaType::Bool, QMetaType::QString,   14,
    QMetaType::Bool, QMetaType::QString,   14,
    QMetaType::Bool, QMetaType::QString,   14,
    QMetaType::Bool, QMetaType::QString,   18,
    QMetaType::Bool, QMetaType::QString,   18,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,   18,   21,

 // properties: name, type, flags
      22, 0x80000000 | 23, 0x00495009,
       6, 0x80000000 | 7, 0x00495009,
      24, QMetaType::QObjectStar, 0x00495001,
      25, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void TimeLine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimeLine *_t = static_cast<TimeLine *>(_o);
        switch (_id) {
        case 0: _t->mainNewsChanged(); break;
        case 1: _t->replyListChanged(); break;
        case 2: _t->currentUserChanged(); break;
        case 3: _t->newsCollectedChanged(); break;
        case 4: { QList<QObject*> _r = _t->replyList();
            if (_a[0]) *reinterpret_cast< QList<QObject*>*>(_a[0]) = _r; }  break;
        case 5: { QList<QObject*> _r = _t->getNewsByType((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QObject*>*>(_a[0]) = _r; }  break;
        case 6: { QList<QObject*> _r = _t->getReadNews();
            if (_a[0]) *reinterpret_cast< QList<QObject*>*>(_a[0]) = _r; }  break;
        case 7: { QList<QObject*> _r = _t->getCollectNews();
            if (_a[0]) *reinterpret_cast< QList<QObject*>*>(_a[0]) = _r; }  break;
        case 8: { QList<QObject*> _r = _t->getReplyList();
            if (_a[0]) *reinterpret_cast< QList<QObject*>*>(_a[0]) = _r; }  break;
        case 9: { bool _r = _t->setMainNewsByID((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { bool _r = _t->setReplyListByID((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: { bool _r = _t->setReplyListByUID((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { bool _r = _t->collectNews((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { bool _r = _t->unCollectNews((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: { bool _r = _t->commitReply((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TimeLine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimeLine::mainNewsChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (TimeLine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimeLine::replyListChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (TimeLine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimeLine::currentUserChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (TimeLine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimeLine::newsCollectedChanged)) {
                *result = 3;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MainNews* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QObject*> >(); break;
        }
    }

}

const QMetaObject TimeLine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TimeLine.data,
      qt_meta_data_TimeLine,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimeLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimeLine::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimeLine.stringdata))
        return static_cast<void*>(const_cast< TimeLine*>(this));
    return QObject::qt_metacast(_clname);
}

int TimeLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< MainNews**>(_v) = mainNews(); break;
        case 1: *reinterpret_cast< QList<QObject*>*>(_v) = replyList(); break;
        case 2: *reinterpret_cast< QObject**>(_v) = currentUser(); break;
        case 3: *reinterpret_cast< bool*>(_v) = newsCollected(); break;
        default: break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void TimeLine::mainNewsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void TimeLine::replyListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void TimeLine::currentUserChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void TimeLine::newsCollectedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
