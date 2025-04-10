/****************************************************************************
** Meta object code from reading C++ file 'devstageout.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/output/devstageout.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'devstageout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DevStageCell_t {
    const uint offsetsAndSize[48];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_DevStageCell_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_DevStageCell_t qt_meta_stringdata_DevStageCell = {
    {
QT_MOC_LITERAL(0, 12), // "DevStageCell"
QT_MOC_LITERAL(13, 4), // "grid"
QT_MOC_LITERAL(18, 8), // "QJSValue"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 9), // "paintGrid"
QT_MOC_LITERAL(38, 13), // "Grid<double>*"
QT_MOC_LITERAL(52, 4), // "what"
QT_MOC_LITERAL(57, 12), // "QStringList&"
QT_MOC_LITERAL(70, 5), // "names"
QT_MOC_LITERAL(76, 6), // "colors"
QT_MOC_LITERAL(83, 1), // "x"
QT_MOC_LITERAL(85, 1), // "y"
QT_MOC_LITERAL(87, 6), // "DBHMax"
QT_MOC_LITERAL(94, 6), // "DBHMin"
QT_MOC_LITERAL(101, 7), // "DBHMean"
QT_MOC_LITERAL(109, 9), // "DBHMedian"
QT_MOC_LITERAL(119, 4), // "HMax"
QT_MOC_LITERAL(124, 5), // "HMean"
QT_MOC_LITERAL(130, 7), // "HMedian"
QT_MOC_LITERAL(138, 3), // "NQD"
QT_MOC_LITERAL(142, 13), // "deadwoodShare"
QT_MOC_LITERAL(156, 3), // "CPA"
QT_MOC_LITERAL(160, 4), // "N_ha"
QT_MOC_LITERAL(165, 9) // "Pct_PMugo"

    },
    "DevStageCell\0grid\0QJSValue\0\0paintGrid\0"
    "Grid<double>*\0what\0QStringList&\0names\0"
    "colors\0x\0y\0DBHMax\0DBHMin\0DBHMean\0"
    "DBHMedian\0HMax\0HMean\0HMedian\0NQD\0"
    "deadwoodShare\0CPA\0N_ha\0Pct_PMugo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DevStageCell[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
      14,   34, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    3, 0x0a,   15 /* Public */,
       4,    3,   27,    3, 0x0a,   16 /* Public */,

 // slots: parameters
    0x80000000 | 2,
    0x80000000 | 5, QMetaType::QString, 0x80000000 | 7, 0x80000000 | 7,    6,    8,    9,

 // properties: name, type, flags
      10, QMetaType::Int, 0x00015001, uint(-1), 0,
      11, QMetaType::Int, 0x00015001, uint(-1), 0,
      12, QMetaType::Double, 0x00015001, uint(-1), 0,
      13, QMetaType::Double, 0x00015001, uint(-1), 0,
      14, QMetaType::Double, 0x00015001, uint(-1), 0,
      15, QMetaType::Double, 0x00015001, uint(-1), 0,
      16, QMetaType::Double, 0x00015001, uint(-1), 0,
      17, QMetaType::Double, 0x00015001, uint(-1), 0,
      18, QMetaType::Double, 0x00015001, uint(-1), 0,
      19, QMetaType::Double, 0x00015001, uint(-1), 0,
      20, QMetaType::Double, 0x00015001, uint(-1), 0,
      21, QMetaType::Double, 0x00015001, uint(-1), 0,
      22, QMetaType::Double, 0x00015001, uint(-1), 0,
      23, QMetaType::Double, 0x00015001, uint(-1), 0,

       0        // eod
};

void DevStageCell::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DevStageCell *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QJSValue _r = _t->grid();
            if (_a[0]) *reinterpret_cast< QJSValue*>(_a[0]) = std::move(_r); }  break;
        case 1: { Grid<double>* _r = _t->paintGrid((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList&>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList&>>(_a[3])));
            if (_a[0]) *reinterpret_cast< Grid<double>**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DevStageCell *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->x(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->y(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->DBHMax(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->DBHMin(); break;
        case 4: *reinterpret_cast< double*>(_v) = _t->DBHMean(); break;
        case 5: *reinterpret_cast< double*>(_v) = _t->DBHMedian(); break;
        case 6: *reinterpret_cast< double*>(_v) = _t->HMax(); break;
        case 7: *reinterpret_cast< double*>(_v) = _t->HMean(); break;
        case 8: *reinterpret_cast< double*>(_v) = _t->HMedian(); break;
        case 9: *reinterpret_cast< double*>(_v) = _t->NQD(); break;
        case 10: *reinterpret_cast< double*>(_v) = _t->deadwoodShare(); break;
        case 11: *reinterpret_cast< double*>(_v) = _t->CPA(); break;
        case 12: *reinterpret_cast< double*>(_v) = _t->N_ha(); break;
        case 13: *reinterpret_cast< double*>(_v) = _t->Pct_PMugo(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject DevStageCell::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DevStageCell.offsetsAndSize,
    qt_meta_data_DevStageCell,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_DevStageCell_t
, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<DevStageCell, std::true_type>
, QtPrivate::TypeAndForceComplete<QJSValue, std::false_type>, QtPrivate::TypeAndForceComplete<Grid<double> *, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList &, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList &, std::false_type>


>,
    nullptr
} };


const QMetaObject *DevStageCell::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DevStageCell::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DevStageCell.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DevStageCell::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
