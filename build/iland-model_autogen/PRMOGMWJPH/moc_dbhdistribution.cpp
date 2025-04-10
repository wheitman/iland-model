/****************************************************************************
** Meta object code from reading C++ file 'dbhdistribution.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/core/dbhdistribution.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbhdistribution.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DBHDistribution_t {
    const uint offsetsAndSize[20];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_DBHDistribution_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_DBHDistribution_t qt_meta_stringdata_DBHDistribution = {
    {
QT_MOC_LITERAL(0, 15), // "DBHDistribution"
QT_MOC_LITERAL(16, 22), // "calculateFromLandscape"
QT_MOC_LITERAL(39, 0), // ""
QT_MOC_LITERAL(40, 9), // "calculate"
QT_MOC_LITERAL(50, 8), // "addStand"
QT_MOC_LITERAL(59, 7), // "standId"
QT_MOC_LITERAL(67, 14), // "saveToTextFile"
QT_MOC_LITERAL(82, 8), // "filename"
QT_MOC_LITERAL(91, 13), // "saveStandInfo"
QT_MOC_LITERAL(105, 6) // "parent"

    },
    "DBHDistribution\0calculateFromLandscape\0"
    "\0calculate\0addStand\0standId\0saveToTextFile\0"
    "filename\0saveStandInfo\0parent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DBHDistribution[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       2,   59, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x0a,    1 /* Public */,
       3,    0,   45,    2, 0x0a,    2 /* Public */,
       4,    1,   46,    2, 0x0a,    3 /* Public */,
       6,    1,   49,    2, 0x0a,    5 /* Public */,
       8,    1,   52,    2, 0x0a,    7 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,

 // constructors: parameters
    0x80000000 | 2, QMetaType::QObjectStar,    9,
    0x80000000 | 2,

 // constructors: name, argc, parameters, tag, flags, initial metatype offsets
       0,    1,   55,    2, 0x0e,    9 /* Public */,
       0,    0,   58,    2, 0x2e,   10 /* Public | MethodCloned */,

       0        // eod
};

void DBHDistribution::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { DBHDistribution *_r = new DBHDistribution((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        case 1: { DBHDistribution *_r = new DBHDistribution();
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    } else if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DBHDistribution *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->calculateFromLandscape(); break;
        case 1: _t->calculate(); break;
        case 2: _t->addStand((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->saveToTextFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->saveStandInfo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DBHDistribution::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DBHDistribution.offsetsAndSize,
    qt_meta_data_DBHDistribution,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_DBHDistribution_t
, QtPrivate::TypeAndForceComplete<DBHDistribution, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>

, QtPrivate::TypeAndForceComplete<QObject *, std::false_type>
>,
    nullptr
} };


const QMetaObject *DBHDistribution::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DBHDistribution::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DBHDistribution.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DBHDistribution::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
