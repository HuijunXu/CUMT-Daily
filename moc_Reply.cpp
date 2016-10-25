/****************************************************************************
** Meta object code from reading C++ file 'Reply.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Reply.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Reply.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Reply_t {
    QByteArrayData data[12];
    char stringdata[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Reply_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Reply_t qt_meta_stringdata_Reply = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Reply"
QT_MOC_LITERAL(1, 6, 10), // "uidChanged"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 14), // "nicNameChanged"
QT_MOC_LITERAL(4, 33, 15), // "userIconChanged"
QT_MOC_LITERAL(5, 49, 14), // "contentChanged"
QT_MOC_LITERAL(6, 64, 16), // "replyTimeChanged"
QT_MOC_LITERAL(7, 81, 3), // "uid"
QT_MOC_LITERAL(8, 85, 7), // "nicName"
QT_MOC_LITERAL(9, 93, 8), // "userIcon"
QT_MOC_LITERAL(10, 102, 7), // "content"
QT_MOC_LITERAL(11, 110, 9) // "replyTime"

    },
    "Reply\0uidChanged\0\0nicNameChanged\0"
    "userIconChanged\0contentChanged\0"
    "replyTimeChanged\0uid\0nicName\0userIcon\0"
    "content\0replyTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Reply[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       5,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,
       6,    0,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       7, QMetaType::QString, 0x00495001,
       8, QMetaType::QString, 0x00495001,
       9, QMetaType::QString, 0x00495001,
      10, QMetaType::QString, 0x00495001,
      11, QMetaType::QDateTime, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

void Reply::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Reply *_t = static_cast<Reply *>(_o);
        switch (_id) {
        case 0: _t->uidChanged(); break;
        case 1: _t->nicNameChanged(); break;
        case 2: _t->userIconChanged(); break;
        case 3: _t->contentChanged(); break;
        case 4: _t->replyTimeChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Reply::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Reply::uidChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (Reply::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Reply::nicNameChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (Reply::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Reply::userIconChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (Reply::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Reply::contentChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (Reply::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Reply::replyTimeChanged)) {
                *result = 4;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Reply::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Reply.data,
      qt_meta_data_Reply,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Reply::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Reply::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Reply.stringdata))
        return static_cast<void*>(const_cast< Reply*>(this));
    return QObject::qt_metacast(_clname);
}

int Reply::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = uid(); break;
        case 1: *reinterpret_cast< QString*>(_v) = nicName(); break;
        case 2: *reinterpret_cast< QString*>(_v) = userIcon(); break;
        case 3: *reinterpret_cast< QString*>(_v) = content(); break;
        case 4: *reinterpret_cast< QDateTime*>(_v) = replyTime(); break;
        default: break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Reply::uidChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Reply::nicNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Reply::userIconChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Reply::contentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Reply::replyTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
