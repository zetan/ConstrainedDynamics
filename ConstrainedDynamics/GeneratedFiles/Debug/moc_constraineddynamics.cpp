/****************************************************************************
** Meta object code from reading C++ file 'constraineddynamics.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../constraineddynamics.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'constraineddynamics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ConstrainedDynamics_t {
    QByteArrayData data[6];
    char stringdata[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ConstrainedDynamics_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ConstrainedDynamics_t qt_meta_stringdata_ConstrainedDynamics = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 13),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 12),
QT_MOC_LITERAL(4, 48, 17),
QT_MOC_LITERAL(5, 66, 16)
    },
    "ConstrainedDynamics\0BeadStartPlay\0\0"
    "BeadStopPlay\0PendulumStartPlay\0"
    "PendulumStopPlay\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConstrainedDynamics[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a,
       3,    0,   35,    2, 0x0a,
       4,    0,   36,    2, 0x0a,
       5,    0,   37,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ConstrainedDynamics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConstrainedDynamics *_t = static_cast<ConstrainedDynamics *>(_o);
        switch (_id) {
        case 0: _t->BeadStartPlay(); break;
        case 1: _t->BeadStopPlay(); break;
        case 2: _t->PendulumStartPlay(); break;
        case 3: _t->PendulumStopPlay(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ConstrainedDynamics::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ConstrainedDynamics.data,
      qt_meta_data_ConstrainedDynamics,  qt_static_metacall, 0, 0}
};


const QMetaObject *ConstrainedDynamics::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConstrainedDynamics::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConstrainedDynamics.stringdata))
        return static_cast<void*>(const_cast< ConstrainedDynamics*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ConstrainedDynamics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
