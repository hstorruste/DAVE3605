/****************************************************************************
** Meta object code from reading C++ file 'inputpopup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../view/inputpopup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inputpopup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_InputPopUp_t {
    QByteArrayData data[4];
    char stringdata[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InputPopUp_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InputPopUp_t qt_meta_stringdata_InputPopUp = {
    {
QT_MOC_LITERAL(0, 0, 10), // "InputPopUp"
QT_MOC_LITERAL(1, 11, 19), // "NotifySubmitClicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 20) // "on_submitBtn_clicked"

    },
    "InputPopUp\0NotifySubmitClicked\0\0"
    "on_submitBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InputPopUp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void InputPopUp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InputPopUp *_t = static_cast<InputPopUp *>(_o);
        switch (_id) {
        case 0: _t->NotifySubmitClicked(); break;
        case 1: _t->on_submitBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (InputPopUp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InputPopUp::NotifySubmitClicked)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject InputPopUp::staticMetaObject = {
    { &PopUp::staticMetaObject, qt_meta_stringdata_InputPopUp.data,
      qt_meta_data_InputPopUp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *InputPopUp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InputPopUp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_InputPopUp.stringdata))
        return static_cast<void*>(const_cast< InputPopUp*>(this));
    return PopUp::qt_metacast(_clname);
}

int InputPopUp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PopUp::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void InputPopUp::NotifySubmitClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
