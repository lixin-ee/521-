/****************************************************************************
** Meta object code from reading C++ file 'maze.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../maze/maze.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maze.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_maze_t {
    QByteArrayData data[11];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_maze_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_maze_t qt_meta_stringdata_maze = {
    {
QT_MOC_LITERAL(0, 0, 4), // "maze"
QT_MOC_LITERAL(1, 5, 10), // "startgame1"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 10), // "startgame2"
QT_MOC_LITERAL(4, 28, 10), // "startgame3"
QT_MOC_LITERAL(5, 39, 6), // "replay"
QT_MOC_LITERAL(6, 46, 10), // "returnhome"
QT_MOC_LITERAL(7, 57, 8), // "initgame"
QT_MOC_LITERAL(8, 66, 11), // "settingslot"
QT_MOC_LITERAL(9, 78, 11), // "updatetimer"
QT_MOC_LITERAL(10, 90, 9) // "movemouse"

    },
    "maze\0startgame1\0\0startgame2\0startgame3\0"
    "replay\0returnhome\0initgame\0settingslot\0"
    "updatetimer\0movemouse"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_maze[] = {

 // content:
       8,       // revision
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

void maze::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<maze *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startgame1(); break;
        case 1: _t->startgame2(); break;
        case 2: _t->startgame3(); break;
        case 3: _t->replay(); break;
        case 4: _t->returnhome(); break;
        case 5: _t->initgame(); break;
        case 6: _t->settingslot(); break;
        case 7: _t->updatetimer(); break;
        case 8: _t->movemouse(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject maze::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_maze.data,
    qt_meta_data_maze,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *maze::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *maze::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_maze.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int maze::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
