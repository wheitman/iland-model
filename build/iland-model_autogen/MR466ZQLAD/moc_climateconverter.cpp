/****************************************************************************
** Meta object code from reading C++ file 'climateconverter.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/tools/climateconverter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'climateconverter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClimateConverter_t {
    const uint offsetsAndSize[32];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ClimateConverter_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ClimateConverter_t qt_meta_stringdata_ClimateConverter = {
    {
QT_MOC_LITERAL(0, 16), // "ClimateConverter"
QT_MOC_LITERAL(17, 3), // "run"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 6), // "parent"
QT_MOC_LITERAL(29, 8), // "fileName"
QT_MOC_LITERAL(38, 9), // "tableName"
QT_MOC_LITERAL(48, 8), // "database"
QT_MOC_LITERAL(57, 8), // "captions"
QT_MOC_LITERAL(66, 4), // "year"
QT_MOC_LITERAL(71, 5), // "month"
QT_MOC_LITERAL(77, 3), // "day"
QT_MOC_LITERAL(81, 4), // "temp"
QT_MOC_LITERAL(86, 7), // "minTemp"
QT_MOC_LITERAL(94, 4), // "prec"
QT_MOC_LITERAL(99, 3), // "rad"
QT_MOC_LITERAL(103, 3) // "vpd"

    },
    "ClimateConverter\0run\0\0parent\0fileName\0"
    "tableName\0database\0captions\0year\0month\0"
    "day\0temp\0minTemp\0prec\0rad\0vpd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClimateConverter[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
      12,   25, // properties
       0,    0, // enums/sets
       2,   85, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x0a,   13 /* Public */,

 // slots: parameters
    QMetaType::Void,

 // constructors: parameters
    0x80000000 | 2, QMetaType::QObjectStar,    3,
    0x80000000 | 2,

 // properties: name, type, flags
       4, QMetaType::QString, 0x00015103, uint(-1), 0,
       5, QMetaType::QString, 0x00015103, uint(-1), 0,
       6, QMetaType::QString, 0x00015103, uint(-1), 0,
       7, QMetaType::Bool, 0x00015103, uint(-1), 0,
       8, QMetaType::QString, 0x00015103, uint(-1), 0,
       9, QMetaType::QString, 0x00015103, uint(-1), 0,
      10, QMetaType::QString, 0x00015103, uint(-1), 0,
      11, QMetaType::QString, 0x00015103, uint(-1), 0,
      12, QMetaType::QString, 0x00015103, uint(-1), 0,
      13, QMetaType::QString, 0x00015103, uint(-1), 0,
      14, QMetaType::QString, 0x00015103, uint(-1), 0,
      15, QMetaType::QString, 0x00015103, uint(-1), 0,

 // constructors: name, argc, parameters, tag, flags, initial metatype offsets
       0,    1,   21,    2, 0x0e,   14 /* Public */,
       0,    0,   24,    2, 0x2e,   15 /* Public | MethodCloned */,

       0        // eod
};

void ClimateConverter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { ClimateConverter *_r = new ClimateConverter((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        case 1: { ClimateConverter *_r = new ClimateConverter();
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    } else if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClimateConverter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->run(); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ClimateConverter *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->fileName(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->tableName(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->database(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->captions(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->year(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->month(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->day(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->temp(); break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->minTemp(); break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->prec(); break;
        case 10: *reinterpret_cast< QString*>(_v) = _t->rad(); break;
        case 11: *reinterpret_cast< QString*>(_v) = _t->vpd(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ClimateConverter *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFileName(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setTableName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setDatabase(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setCaptions(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setYear(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setMonth(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setDay(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->setTemp(*reinterpret_cast< QString*>(_v)); break;
        case 8: _t->setMinTemp(*reinterpret_cast< QString*>(_v)); break;
        case 9: _t->setPrec(*reinterpret_cast< QString*>(_v)); break;
        case 10: _t->setRad(*reinterpret_cast< QString*>(_v)); break;
        case 11: _t->setVpd(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ClimateConverter::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ClimateConverter.offsetsAndSize,
    qt_meta_data_ClimateConverter,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ClimateConverter_t
, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<bool, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<ClimateConverter, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>

, QtPrivate::TypeAndForceComplete<QObject *, std::false_type>
>,
    nullptr
} };


const QMetaObject *ClimateConverter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClimateConverter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClimateConverter.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ClimateConverter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
