/****************************************************************************
** Meta object code from reading C++ file 'dialogpopup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../view/dialogpopup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogpopup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DialogPopUp_t {
    QByteArrayData data[6];
    char stringdata[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogPopUp_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogPopUp_t qt_meta_stringdata_DialogPopUp = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DialogPopUp"
QT_MOC_LITERAL(1, 12, 19), // "NotifyAcceptClicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 20), // "NotifyDeclineClicked"
QT_MOC_LITERAL(4, 54, 20), // "on_acceptbtn_clicked"
QT_MOC_LITERAL(5, 75, 21) // "on_declinebtn_clicked"

    },
    "DialogPopUp\0NotifyAcceptClicked\0\0"
    "NotifyDeclineClicked\0on_acceptbtn_clicked\0"
    "on_declinebtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogPopUp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogPopUp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogPopUp *_t = static_cast<DialogPopUp *>(_o);
        switch (_id) {
        case 0: _t->NotifyAcceptClicked(); break;
        case 1: _t->NotifyDeclineClicked(); break;
        case 2: _t->on_acceptbtn_clicked(); break;
        case 3: _t->on_declinebtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DialogPopUp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogPopUp::NotifyAcceptClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (DialogPopUp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogPopUp::NotifyDeclineClicked)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DialogPopUp::staticMetaObject = {
    { &PopUp::staticMetaObject, qt_meta_stringdata_DialogPopUp.data,
      qt_meta_data_DialogPopUp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DialogPopUp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogPopUp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DialogPopUp.stringdata))
        return static_cast<void*>(const_cast< DialogPopUp*>(this));
    return PopUp::qt_metacast(_clname);
}

int DialogPopUp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PopUp::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DialogPopUp::NotifyAcceptClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void DialogPopUp::NotifyDeclineClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
