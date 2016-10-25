/****************************************************************************
** Meta object code from reading C++ file 'MainNews.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainNews.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainNews.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainNews_t {
    QByteArrayData data[19];
    char stringdata[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainNews_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainNews_t qt_meta_stringdata_MainNews = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MainNews"
QT_MOC_LITERAL(1, 9, 9), // "idChanged"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 12), // "titleChanged"
QT_MOC_LITERAL(4, 33, 16), // "videoPathChanged"
QT_MOC_LITERAL(5, 50, 14), // "picPathChanged"
QT_MOC_LITERAL(6, 65, 13), // "sourceChanged"
QT_MOC_LITERAL(7, 79, 14), // "contentChanged"
QT_MOC_LITERAL(8, 94, 11), // "timeChanged"
QT_MOC_LITERAL(9, 106, 17), // "replyCountChanged"
QT_MOC_LITERAL(10, 124, 11), // "videoExists"
QT_MOC_LITERAL(11, 136, 2), // "id"
QT_MOC_LITERAL(12, 139, 5), // "title"
QT_MOC_LITERAL(13, 145, 9), // "videoPath"
QT_MOC_LITERAL(14, 155, 7), // "picPath"
QT_MOC_LITERAL(15, 163, 6), // "source"
QT_MOC_LITERAL(16, 170, 7), // "content"
QT_MOC_LITERAL(17, 178, 4), // "time"
QT_MOC_LITERAL(18, 183, 10) // "replyCount"

    },
    "MainNews\0idChanged\0\0titleChanged\0"
    "videoPathChanged\0picPathChanged\0"
    "sourceChanged\0contentChanged\0timeChanged\0"
    "replyCountChanged\0videoExists\0id\0title\0"
    "videoPath\0picPath\0source\0content\0time\0"
    "replyCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainNews[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       8,   68, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,
       7,    0,   64,    2, 0x06 /* Public */,
       8,    0,   65,    2, 0x06 /* Public */,
       9,    0,   66,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      10,    0,   67,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Bool,

 // properties: name, type, flags
      11, QMetaType::QString, 0x00495001,
      12, QMetaType::QString, 0x00495001,
      13, QMetaType::QString, 0x00495001,
      14, QMetaType::QString, 0x00495001,
      15, QMetaType::QString, 0x00495001,
      16, QMetaType::QString, 0x00495001,
      17, QMetaType::QDateTime, 0x00495001,
      18, QMetaType::QReal, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,

       0        // eod
};

void MainNews::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainNews *_t = static_cast<MainNews *>(_o);
        switch (_id) {
        case 0: _t->idChanged(); break;
        case 1: _t->titleChanged(); break;
        case 2: _t->videoPathChanged(); break;
        case 3: _t->picPathChanged(); break;
        case 4: _t->sourceChanged(); break;
        case 5: _t->contentChanged(); break;
        case 6: _t->timeChanged(); break;
        case 7: _t->replyCountChanged(); break;
        case 8: { bool _r = _t->videoExists();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainNews::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainNews::idChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (MainNews::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainNews::titleChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (MainNews::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainNews::videoPathChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (MainNews::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainNews::picPathChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (MainNews::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainNews::sourceChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (MainNews::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainNews::contentChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (MainNews::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainNews::timeChanged)) {
                *result = 6;
            }
        }
        {
            typedef void (MainNews::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainNews::replyCountChanged)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject MainNews::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MainNews.data,
      qt_meta_data_MainNews,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainNews::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainNews::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainNews.stringdata))
        return static_cast<void*>(const_cast< MainNews*>(this));
    return QObject::qt_metacast(_clname);
}

int MainNews::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = id(); break;
        case 1: *reinterpret_cast< QString*>(_v) = title(); break;
        case 2: *reinterpret_cast< QString*>(_v) = videoPath(); break;
        case 3: *reinterpret_cast< QString*>(_v) = picPath(); break;
        case 4: *reinterpret_cast< QString*>(_v) = source(); break;
        case 5: *reinterpret_cast< QString*>(_v) = content(); break;
        case 6: *reinterpret_cast< QDateTime*>(_v) = time(); break;
        case 7: *reinterpret_cast< qreal*>(_v) = replyCount(); break;
        default: break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 7: setReplyCount(*reinterpret_cast< qreal*>(_v)); break;
        default: break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MainNews::idChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MainNews::titleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MainNews::videoPathChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MainNews::picPathChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MainNews::sourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void MainNews::contentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void MainNews::timeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void MainNews::replyCountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
