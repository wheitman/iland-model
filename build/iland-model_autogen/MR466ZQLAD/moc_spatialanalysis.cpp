/****************************************************************************
** Meta object code from reading C++ file 'spatialanalysis.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/tools/spatialanalysis.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spatialanalysis.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SpatialAnalysis_t {
    const uint offsetsAndSize[26];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SpatialAnalysis_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SpatialAnalysis_t qt_meta_stringdata_SpatialAnalysis = {
    {
QT_MOC_LITERAL(0, 15), // "SpatialAnalysis"
QT_MOC_LITERAL(16, 14), // "saveRumpleGrid"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 8), // "fileName"
QT_MOC_LITERAL(41, 18), // "saveCrownCoverGrid"
QT_MOC_LITERAL(60, 8), // "QJSValue"
QT_MOC_LITERAL(69, 4), // "grid"
QT_MOC_LITERAL(74, 7), // "patches"
QT_MOC_LITERAL(82, 8), // "min_size"
QT_MOC_LITERAL(91, 6), // "parent"
QT_MOC_LITERAL(98, 11), // "rumpleIndex"
QT_MOC_LITERAL(110, 10), // "patchsizes"
QT_MOC_LITERAL(121, 10) // "QList<int>"

    },
    "SpatialAnalysis\0saveRumpleGrid\0\0"
    "fileName\0saveCrownCoverGrid\0QJSValue\0"
    "grid\0patches\0min_size\0parent\0rumpleIndex\0"
    "patchsizes\0QList<int>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpatialAnalysis[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       2,   58, // properties
       0,    0, // enums/sets
       2,   68, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x0a,    3 /* Public */,
       4,    1,   41,    2, 0x0a,    5 /* Public */,
       4,    2,   44,    2, 0x0a,    7 /* Public */,
       7,    2,   49,    2, 0x0a,   10 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5,    3,    6,
    0x80000000 | 5, 0x80000000 | 5, QMetaType::Int,    6,    8,

 // constructors: parameters
    0x80000000 | 2, QMetaType::QObjectStar,    9,
    0x80000000 | 2,

 // properties: name, type, flags
      10, QMetaType::Double, 0x00015001, uint(-1), 0,
      11, 0x80000000 | 12, 0x00015009, uint(-1), 0,

 // constructors: name, argc, parameters, tag, flags, initial metatype offsets
       0,    1,   54,    2, 0x0e,   13 /* Public */,
       0,    0,   57,    2, 0x2e,   14 /* Public | MethodCloned */,

       0        // eod
};

void SpatialAnalysis::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { SpatialAnalysis *_r = new SpatialAnalysis((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        case 1: { SpatialAnalysis *_r = new SpatialAnalysis();
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    } else if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpatialAnalysis *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->saveRumpleGrid((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->saveCrownCoverGrid((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->saveCrownCoverGrid((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJSValue>>(_a[2]))); break;
        case 3: { QJSValue _r = _t->patches((*reinterpret_cast< std::add_pointer_t<QJSValue>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QJSValue*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QJSValue >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QJSValue >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SpatialAnalysis *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->rumpleIndexFullArea(); break;
        case 1: *reinterpret_cast< QList<int>*>(_v) = _t->patchsizes(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject SpatialAnalysis::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SpatialAnalysis.offsetsAndSize,
    qt_meta_data_SpatialAnalysis,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SpatialAnalysis_t
, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<QList<int>, std::true_type>, QtPrivate::TypeAndForceComplete<SpatialAnalysis, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QJSValue, std::false_type>, QtPrivate::TypeAndForceComplete<QJSValue, std::false_type>, QtPrivate::TypeAndForceComplete<QJSValue, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>

, QtPrivate::TypeAndForceComplete<QObject *, std::false_type>
>,
    nullptr
} };


const QMetaObject *SpatialAnalysis::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpatialAnalysis::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SpatialAnalysis.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SpatialAnalysis::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
