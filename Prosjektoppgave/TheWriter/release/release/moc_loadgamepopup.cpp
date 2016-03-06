/****************************************************************************
** Meta object code from reading C++ file 'loadgamepopup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../model/loadgamepopup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loadgamepopup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LoadGamePopUp_t {
    QByteArrayData data[9];
    char stringdata[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoadGamePopUp_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoadGamePopUp_t qt_meta_stringdata_LoadGamePopUp = {
    {
QT_MOC_LITERAL(0, 0, 13), // "LoadGamePopUp"
QT_MOC_LITERAL(1, 14, 17), // "NotifyLoadClicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 20), // "NotifyNewGameClicked"
QT_MOC_LITERAL(4, 54, 22), // "on_btnLoadGame_clicked"
QT_MOC_LITERAL(5, 77, 21), // "on_btnNewGame_clicked"
QT_MOC_LITERAL(6, 99, 34), // "on_listLoadGames_itemDoubleCl..."
QT_MOC_LITERAL(7, 134, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(8, 151, 4) // "item"

    },
    "LoadGamePopUp\0NotifyLoadClicked\0\0"
    "NotifyNewGameClicked\0on_btnLoadGame_clicked\0"
    "on_btnNewGame_clicked\0"
    "on_listLoadGames_itemDoubleClicked\0"
    "QListWidgetItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoadGamePopUp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    1,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void LoadGamePopUp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoadGamePopUp *_t = static_cast<LoadGamePopUp *>(_o);
        switch (_id) {
        case 0: _t->NotifyLoadClicked(); break;
        case 1: _t->NotifyNewGameClicked(); break;
        case 2: _t->on_btnLoadGame_clicked(); break;
        case 3: _t->on_btnNewGame_clicked(); break;
        case 4: _t->on_listLoadGames_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LoadGamePopUp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoadGamePopUp::NotifyLoadClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (LoadGamePopUp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoadGamePopUp::NotifyNewGameClicked)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject LoadGamePopUp::staticMetaObject = {
    { &PopUp::staticMetaObject, qt_meta_stringdata_LoadGamePopUp.data,
      qt_meta_data_LoadGamePopUp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LoadGamePopUp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoadGamePopUp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LoadGamePopUp.stringdata))
        return static_cast<void*>(const_cast< LoadGamePopUp*>(this));
    return PopUp::qt_metacast(_clname);
}

int LoadGamePopUp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PopUp::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void LoadGamePopUp::NotifyLoadClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void LoadGamePopUp::NotifyNewGameClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
