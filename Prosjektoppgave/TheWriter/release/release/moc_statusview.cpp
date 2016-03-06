/****************************************************************************
** Meta object code from reading C++ file 'statusview.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../view/statusview.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'statusview.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StatusView_t {
    QByteArrayData data[12];
    char stringdata[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StatusView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StatusView_t qt_meta_stringdata_StatusView = {
    {
QT_MOC_LITERAL(0, 0, 10), // "StatusView"
QT_MOC_LITERAL(1, 11, 16), // "NotifySpeedPause"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 17), // "NotifySpeedNormal"
QT_MOC_LITERAL(4, 47, 17), // "NotifySpeedFaster"
QT_MOC_LITERAL(5, 65, 18), // "NotifySpeedFastest"
QT_MOC_LITERAL(6, 84, 10), // "paintEvent"
QT_MOC_LITERAL(7, 95, 12), // "QPaintEvent*"
QT_MOC_LITERAL(8, 108, 22), // "on_clk_lb_play_clicked"
QT_MOC_LITERAL(9, 131, 23), // "on_clk_lb_pause_clicked"
QT_MOC_LITERAL(10, 155, 24), // "on_clk_lb_faster_clicked"
QT_MOC_LITERAL(11, 180, 25) // "on_clk_lb_fastest_clicked"

    },
    "StatusView\0NotifySpeedPause\0\0"
    "NotifySpeedNormal\0NotifySpeedFaster\0"
    "NotifySpeedFastest\0paintEvent\0"
    "QPaintEvent*\0on_clk_lb_play_clicked\0"
    "on_clk_lb_pause_clicked\0"
    "on_clk_lb_faster_clicked\0"
    "on_clk_lb_fastest_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StatusView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   63,    2, 0x0a /* Public */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StatusView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StatusView *_t = static_cast<StatusView *>(_o);
        switch (_id) {
        case 0: _t->NotifySpeedPause(); break;
        case 1: _t->NotifySpeedNormal(); break;
        case 2: _t->NotifySpeedFaster(); break;
        case 3: _t->NotifySpeedFastest(); break;
        case 4: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 5: _t->on_clk_lb_play_clicked(); break;
        case 6: _t->on_clk_lb_pause_clicked(); break;
        case 7: _t->on_clk_lb_faster_clicked(); break;
        case 8: _t->on_clk_lb_fastest_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StatusView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StatusView::NotifySpeedPause)) {
                *result = 0;
            }
        }
        {
            typedef void (StatusView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StatusView::NotifySpeedNormal)) {
                *result = 1;
            }
        }
        {
            typedef void (StatusView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StatusView::NotifySpeedFaster)) {
                *result = 2;
            }
        }
        {
            typedef void (StatusView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StatusView::NotifySpeedFastest)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject StatusView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StatusView.data,
      qt_meta_data_StatusView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StatusView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StatusView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StatusView.stringdata))
        return static_cast<void*>(const_cast< StatusView*>(this));
    return QWidget::qt_metacast(_clname);
}

int StatusView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void StatusView::NotifySpeedPause()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void StatusView::NotifySpeedNormal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void StatusView::NotifySpeedFaster()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void StatusView::NotifySpeedFastest()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
