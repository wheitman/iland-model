/****************************************************************************
** Meta object code from reading C++ file 'microclimate.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/core/microclimate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'microclimate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MicroclimateVisualizer_t {
    const uint offsetsAndSize[20];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MicroclimateVisualizer_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MicroclimateVisualizer_t qt_meta_stringdata_MicroclimateVisualizer = {
    {
QT_MOC_LITERAL(0, 22), // "MicroclimateVisualizer"
QT_MOC_LITERAL(23, 9), // "paintGrid"
QT_MOC_LITERAL(33, 13), // "Grid<double>*"
QT_MOC_LITERAL(47, 0), // ""
QT_MOC_LITERAL(48, 4), // "what"
QT_MOC_LITERAL(53, 12), // "QStringList&"
QT_MOC_LITERAL(66, 5), // "names"
QT_MOC_LITERAL(72, 6), // "colors"
QT_MOC_LITERAL(79, 4), // "grid"
QT_MOC_LITERAL(84, 5) // "month"

    },
    "MicroclimateVisualizer\0paintGrid\0"
    "Grid<double>*\0\0what\0QStringList&\0names\0"
    "colors\0grid\0month"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MicroclimateVisualizer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   26,    3, 0x0a,    1 /* Public */,
       8,    2,   33,    3, 0x0a,    5 /* Public */,

 // slots: parameters
    0x80000000 | 2, QMetaType::QString, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,
    0x80000000 | 2, QMetaType::QString, QMetaType::Int,    4,    9,

       0        // eod
};

void MicroclimateVisualizer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MicroclimateVisualizer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { Grid<double>* _r = _t->paintGrid((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList&>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList&>>(_a[3])));
            if (_a[0]) *reinterpret_cast< Grid<double>**>(_a[0]) = std::move(_r); }  break;
        case 1: { Grid<double>* _r = _t->grid((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< Grid<double>**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject MicroclimateVisualizer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MicroclimateVisualizer.offsetsAndSize,
    qt_meta_data_MicroclimateVisualizer,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MicroclimateVisualizer_t
, QtPrivate::TypeAndForceComplete<MicroclimateVisualizer, std::true_type>
, QtPrivate::TypeAndForceComplete<Grid<double> *, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList &, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList &, std::false_type>, QtPrivate::TypeAndForceComplete<Grid<double> *, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *MicroclimateVisualizer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MicroclimateVisualizer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MicroclimateVisualizer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MicroclimateVisualizer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
