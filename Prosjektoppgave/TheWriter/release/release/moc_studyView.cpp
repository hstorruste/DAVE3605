/****************************************************************************
** Meta object code from reading C++ file 'studyView.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../view/studyView.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'studyView.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StudyView_t {
    QByteArrayData data[21];
    char stringdata[380];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StudyView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StudyView_t qt_meta_stringdata_StudyView = {
    {
QT_MOC_LITERAL(0, 0, 9), // "StudyView"
QT_MOC_LITERAL(1, 10, 18), // "NotifyAppleClicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 19), // "NotifyCoffeeClicked"
QT_MOC_LITERAL(4, 50, 19), // "NotifyWindowClicked"
QT_MOC_LITERAL(5, 70, 17), // "NotifyWineClicked"
QT_MOC_LITERAL(6, 88, 17), // "NotifySofaClicked"
QT_MOC_LITERAL(7, 106, 18), // "NotifyBooksClicked"
QT_MOC_LITERAL(8, 125, 19), // "NotifyWriterClicked"
QT_MOC_LITERAL(9, 145, 9), // "AnimWrite"
QT_MOC_LITERAL(10, 155, 11), // "AnimWeather"
QT_MOC_LITERAL(11, 167, 24), // "AnimSuperSecretEasterEgg"
QT_MOC_LITERAL(12, 192, 13), // "changeWeather"
QT_MOC_LITERAL(13, 206, 4), // "type"
QT_MOC_LITERAL(14, 211, 24), // "on_clk_lb_writer_clicked"
QT_MOC_LITERAL(15, 236, 23), // "on_clk_lb_apple_clicked"
QT_MOC_LITERAL(16, 260, 24), // "on_clk_lb_coffee_clicked"
QT_MOC_LITERAL(17, 285, 24), // "on_clk_lb_window_clicked"
QT_MOC_LITERAL(18, 310, 22), // "on_clk_lb_wine_clicked"
QT_MOC_LITERAL(19, 333, 22), // "on_clk_lb_sofa_clicked"
QT_MOC_LITERAL(20, 356, 23) // "on_clk_lb_books_clicked"

    },
    "StudyView\0NotifyAppleClicked\0\0"
    "NotifyCoffeeClicked\0NotifyWindowClicked\0"
    "NotifyWineClicked\0NotifySofaClicked\0"
    "NotifyBooksClicked\0NotifyWriterClicked\0"
    "AnimWrite\0AnimWeather\0AnimSuperSecretEasterEgg\0"
    "changeWeather\0type\0on_clk_lb_writer_clicked\0"
    "on_clk_lb_apple_clicked\0"
    "on_clk_lb_coffee_clicked\0"
    "on_clk_lb_window_clicked\0"
    "on_clk_lb_wine_clicked\0on_clk_lb_sofa_clicked\0"
    "on_clk_lb_books_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StudyView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    0,  105,    2, 0x06 /* Public */,
       4,    0,  106,    2, 0x06 /* Public */,
       5,    0,  107,    2, 0x06 /* Public */,
       6,    0,  108,    2, 0x06 /* Public */,
       7,    0,  109,    2, 0x06 /* Public */,
       8,    0,  110,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  111,    2, 0x0a /* Public */,
      10,    0,  112,    2, 0x0a /* Public */,
      11,    0,  113,    2, 0x0a /* Public */,
      12,    1,  114,    2, 0x0a /* Public */,
      14,    0,  117,    2, 0x08 /* Private */,
      15,    0,  118,    2, 0x08 /* Private */,
      16,    0,  119,    2, 0x08 /* Private */,
      17,    0,  120,    2, 0x08 /* Private */,
      18,    0,  121,    2, 0x08 /* Private */,
      19,    0,  122,    2, 0x08 /* Private */,
      20,    0,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StudyView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StudyView *_t = static_cast<StudyView *>(_o);
        switch (_id) {
        case 0: _t->NotifyAppleClicked(); break;
        case 1: _t->NotifyCoffeeClicked(); break;
        case 2: _t->NotifyWindowClicked(); break;
        case 3: _t->NotifyWineClicked(); break;
        case 4: _t->NotifySofaClicked(); break;
        case 5: _t->NotifyBooksClicked(); break;
        case 6: _t->NotifyWriterClicked(); break;
        case 7: _t->AnimWrite(); break;
        case 8: _t->AnimWeather(); break;
        case 9: _t->AnimSuperSecretEasterEgg(); break;
        case 10: _t->changeWeather((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_clk_lb_writer_clicked(); break;
        case 12: _t->on_clk_lb_apple_clicked(); break;
        case 13: _t->on_clk_lb_coffee_clicked(); break;
        case 14: _t->on_clk_lb_window_clicked(); break;
        case 15: _t->on_clk_lb_wine_clicked(); break;
        case 16: _t->on_clk_lb_sofa_clicked(); break;
        case 17: _t->on_clk_lb_books_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StudyView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StudyView::NotifyAppleClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (StudyView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StudyView::NotifyCoffeeClicked)) {
                *result = 1;
            }
        }
        {
            typedef void (StudyView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StudyView::NotifyWindowClicked)) {
                *result = 2;
            }
        }
        {
            typedef void (StudyView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StudyView::NotifyWineClicked)) {
                *result = 3;
            }
        }
        {
            typedef void (StudyView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StudyView::NotifySofaClicked)) {
                *result = 4;
            }
        }
        {
            typedef void (StudyView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StudyView::NotifyBooksClicked)) {
                *result = 5;
            }
        }
        {
            typedef void (StudyView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StudyView::NotifyWriterClicked)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject StudyView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StudyView.data,
      qt_meta_data_StudyView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StudyView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StudyView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StudyView.stringdata))
        return static_cast<void*>(const_cast< StudyView*>(this));
    return QWidget::qt_metacast(_clname);
}

int StudyView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void StudyView::NotifyAppleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void StudyView::NotifyCoffeeClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void StudyView::NotifyWindowClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void StudyView::NotifyWineClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void StudyView::NotifySofaClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void StudyView::NotifyBooksClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void StudyView::NotifyWriterClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
