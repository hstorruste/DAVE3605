/****************************************************************************
** Meta object code from reading C++ file 'mainviewmanager.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../viewmodel/mainviewmanager.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainviewmanager.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainViewManager_t {
    QByteArrayData data[11];
    char stringdata[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainViewManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainViewManager_t qt_meta_stringdata_MainViewManager = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MainViewManager"
QT_MOC_LITERAL(1, 16, 12), // "minuteUpdate"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 10), // "hourUpdate"
QT_MOC_LITERAL(4, 41, 9), // "dayUpdate"
QT_MOC_LITERAL(5, 51, 10), // "weekUpdate"
QT_MOC_LITERAL(6, 62, 21), // "sixhourintervalUpdate"
QT_MOC_LITERAL(7, 84, 7), // "endBook"
QT_MOC_LITERAL(8, 92, 7), // "endGame"
QT_MOC_LITERAL(9, 100, 6), // "lagbok"
QT_MOC_LITERAL(10, 107, 10) // "saveToFile"

    },
    "MainViewManager\0minuteUpdate\0\0hourUpdate\0"
    "dayUpdate\0weekUpdate\0sixhourintervalUpdate\0"
    "endBook\0endGame\0lagbok\0saveToFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainViewManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainViewManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainViewManager *_t = static_cast<MainViewManager *>(_o);
        switch (_id) {
        case 0: _t->minuteUpdate(); break;
        case 1: _t->hourUpdate(); break;
        case 2: _t->dayUpdate(); break;
        case 3: _t->weekUpdate(); break;
        case 4: _t->sixhourintervalUpdate(); break;
        case 5: _t->endBook(); break;
        case 6: _t->endGame(); break;
        case 7: _t->lagbok(); break;
        case 8: _t->saveToFile(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainViewManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MainViewManager.data,
      qt_meta_data_MainViewManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainViewManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainViewManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainViewManager.stringdata))
        return static_cast<void*>(const_cast< MainViewManager*>(this));
    return QObject::qt_metacast(_clname);
}

int MainViewManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}
QT_END_MOC_NAMESPACE
