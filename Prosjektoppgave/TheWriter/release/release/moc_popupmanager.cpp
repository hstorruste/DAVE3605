/****************************************************************************
** Meta object code from reading C++ file 'popupmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../viewmodel/popupmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'popupmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PopUpManager_t {
    QByteArrayData data[7];
    char stringdata[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PopUpManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PopUpManager_t qt_meta_stringdata_PopUpManager = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PopUpManager"
QT_MOC_LITERAL(1, 13, 11), // "popUpChance"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14), // "acceptRecieved"
QT_MOC_LITERAL(4, 41, 14), // "rejectRecieved"
QT_MOC_LITERAL(5, 56, 9), // "rentIsDue"
QT_MOC_LITERAL(6, 66, 11) // "startedBook"

    },
    "PopUpManager\0popUpChance\0\0acceptRecieved\0"
    "rejectRecieved\0rentIsDue\0startedBook"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PopUpManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PopUpManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PopUpManager *_t = static_cast<PopUpManager *>(_o);
        switch (_id) {
        case 0: _t->popUpChance(); break;
        case 1: _t->acceptRecieved(); break;
        case 2: _t->rejectRecieved(); break;
        case 3: _t->rentIsDue(); break;
        case 4: _t->startedBook(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject PopUpManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PopUpManager.data,
      qt_meta_data_PopUpManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PopUpManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PopUpManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PopUpManager.stringdata))
        return static_cast<void*>(const_cast< PopUpManager*>(this));
    return QObject::qt_metacast(_clname);
}

int PopUpManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}
QT_END_MOC_NAMESPACE
