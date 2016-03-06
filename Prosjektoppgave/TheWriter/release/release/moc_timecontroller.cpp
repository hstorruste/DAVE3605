/****************************************************************************
** Meta object code from reading C++ file 'timecontroller.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../model/timecontroller.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timecontroller.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TimeController_t {
    QByteArrayData data[11];
    char stringdata[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimeController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimeController_t qt_meta_stringdata_TimeController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TimeController"
QT_MOC_LITERAL(1, 15, 10), // "timeTicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "hourTicked"
QT_MOC_LITERAL(4, 38, 9), // "dayTicked"
QT_MOC_LITERAL(5, 48, 10), // "weekTicked"
QT_MOC_LITERAL(6, 59, 13), // "sixhourTicked"
QT_MOC_LITERAL(7, 73, 7), // "endGame"
QT_MOC_LITERAL(8, 81, 10), // "timeUpdate"
QT_MOC_LITERAL(9, 92, 7), // "addTime"
QT_MOC_LITERAL(10, 100, 1) // "t"

    },
    "TimeController\0timeTicked\0\0hourTicked\0"
    "dayTicked\0weekTicked\0sixhourTicked\0"
    "endGame\0timeUpdate\0addTime\0t"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimeController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    0,   58,    2, 0x06 /* Public */,
       7,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   60,    2, 0x08 /* Private */,
       9,    1,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void TimeController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimeController *_t = static_cast<TimeController *>(_o);
        switch (_id) {
        case 0: _t->timeTicked(); break;
        case 1: _t->hourTicked(); break;
        case 2: _t->dayTicked(); break;
        case 3: _t->weekTicked(); break;
        case 4: _t->sixhourTicked(); break;
        case 5: _t->endGame(); break;
        case 6: _t->timeUpdate(); break;
        case 7: _t->addTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TimeController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimeController::timeTicked)) {
                *result = 0;
            }
        }
        {
            typedef void (TimeController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimeController::hourTicked)) {
                *result = 1;
            }
        }
        {
            typedef void (TimeController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimeController::dayTicked)) {
                *result = 2;
            }
        }
        {
            typedef void (TimeController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimeController::weekTicked)) {
                *result = 3;
            }
        }
        {
            typedef void (TimeController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimeController::sixhourTicked)) {
                *result = 4;
            }
        }
        {
            typedef void (TimeController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimeController::endGame)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject TimeController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TimeController.data,
      qt_meta_data_TimeController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimeController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimeController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimeController.stringdata))
        return static_cast<void*>(const_cast< TimeController*>(this));
    return QObject::qt_metacast(_clname);
}

int TimeController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void TimeController::timeTicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void TimeController::hourTicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void TimeController::dayTicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void TimeController::weekTicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void TimeController::sixhourTicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void TimeController::endGame()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
