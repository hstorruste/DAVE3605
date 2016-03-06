/****************************************************************************
** Meta object code from reading C++ file 'boostercontroller.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../model/boostercontroller.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'boostercontroller.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BoosterController_t {
    QByteArrayData data[12];
    char stringdata[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BoosterController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BoosterController_t qt_meta_stringdata_BoosterController = {
    {
QT_MOC_LITERAL(0, 0, 17), // "BoosterController"
QT_MOC_LITERAL(1, 18, 11), // "emptyEvents"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 14), // "nonEmptyEvents"
QT_MOC_LITERAL(4, 46, 14), // "onAppleClicked"
QT_MOC_LITERAL(5, 61, 15), // "onCoffeeClicked"
QT_MOC_LITERAL(6, 77, 15), // "onWindowClicked"
QT_MOC_LITERAL(7, 93, 13), // "onWineClicked"
QT_MOC_LITERAL(8, 107, 13), // "onSofaClicked"
QT_MOC_LITERAL(9, 121, 14), // "onBooksClicked"
QT_MOC_LITERAL(10, 136, 15), // "continueWriting"
QT_MOC_LITERAL(11, 152, 11) // "stopWriting"

    },
    "BoosterController\0emptyEvents\0\0"
    "nonEmptyEvents\0onAppleClicked\0"
    "onCoffeeClicked\0onWindowClicked\0"
    "onWineClicked\0onSofaClicked\0onBooksClicked\0"
    "continueWriting\0stopWriting"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BoosterController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
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

void BoosterController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BoosterController *_t = static_cast<BoosterController *>(_o);
        switch (_id) {
        case 0: _t->emptyEvents(); break;
        case 1: _t->nonEmptyEvents(); break;
        case 2: _t->onAppleClicked(); break;
        case 3: _t->onCoffeeClicked(); break;
        case 4: _t->onWindowClicked(); break;
        case 5: _t->onWineClicked(); break;
        case 6: _t->onSofaClicked(); break;
        case 7: _t->onBooksClicked(); break;
        case 8: _t->continueWriting(); break;
        case 9: _t->stopWriting(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BoosterController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoosterController::emptyEvents)) {
                *result = 0;
            }
        }
        {
            typedef void (BoosterController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoosterController::nonEmptyEvents)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject BoosterController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BoosterController.data,
      qt_meta_data_BoosterController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BoosterController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BoosterController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BoosterController.stringdata))
        return static_cast<void*>(const_cast< BoosterController*>(this));
    return QObject::qt_metacast(_clname);
}

int BoosterController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void BoosterController::emptyEvents()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void BoosterController::nonEmptyEvents()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
