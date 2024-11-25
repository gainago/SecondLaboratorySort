/****************************************************************************
** Meta object code from reading C++ file 'realtimeplot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Declaration/realtimeplot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'realtimeplot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RealTimePlot_t {
    QByteArrayData data[9];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RealTimePlot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RealTimePlot_t qt_meta_stringdata_RealTimePlot = {
    {
QT_MOC_LITERAL(0, 0, 12), // "RealTimePlot"
QT_MOC_LITERAL(1, 13, 10), // "timeHandle"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "setData"
QT_MOC_LITERAL(4, 33, 1), // "i"
QT_MOC_LITERAL(5, 35, 8), // "testSize"
QT_MOC_LITERAL(6, 44, 10), // "timeBubble"
QT_MOC_LITERAL(7, 55, 9), // "timeQuick"
QT_MOC_LITERAL(8, 65, 11) // "timePiramid"

    },
    "RealTimePlot\0timeHandle\0\0setData\0i\0"
    "testSize\0timeBubble\0timeQuick\0timePiramid"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RealTimePlot[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    5,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    4,    5,    6,    7,    8,

       0        // eod
};

void RealTimePlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RealTimePlot *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->timeHandle(); break;
        case 1: _t->setData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RealTimePlot::staticMetaObject = { {
    QMetaObject::SuperData::link<QwtPlot::staticMetaObject>(),
    qt_meta_stringdata_RealTimePlot.data,
    qt_meta_data_RealTimePlot,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RealTimePlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RealTimePlot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RealTimePlot.stringdata0))
        return static_cast<void*>(this);
    return QwtPlot::qt_metacast(_clname);
}

int RealTimePlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPlot::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
