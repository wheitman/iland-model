/****************************************************************************
** Meta object code from reading C++ file 'colors.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/tools/colors.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colors.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Colors_t {
    const uint offsetsAndSize[32];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Colors_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Colors_t qt_meta_stringdata_Colors = {
    {
QT_MOC_LITERAL(0, 6), // "Colors"
QT_MOC_LITERAL(7, 13), // "colorsChanged"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 12), // "scaleChanged"
QT_MOC_LITERAL(35, 19), // "manualColorsChanged"
QT_MOC_LITERAL(55, 6), // "colors"
QT_MOC_LITERAL(62, 6), // "labels"
QT_MOC_LITERAL(69, 12), // "factorLabels"
QT_MOC_LITERAL(82, 5), // "count"
QT_MOC_LITERAL(88, 8), // "minValue"
QT_MOC_LITERAL(97, 8), // "maxValue"
QT_MOC_LITERAL(106, 9), // "autoScale"
QT_MOC_LITERAL(116, 10), // "hasFactors"
QT_MOC_LITERAL(127, 7), // "caption"
QT_MOC_LITERAL(135, 11), // "description"
QT_MOC_LITERAL(147, 13) // "meterPerPixel"

    },
    "Colors\0colorsChanged\0\0scaleChanged\0"
    "manualColorsChanged\0colors\0labels\0"
    "factorLabels\0count\0minValue\0maxValue\0"
    "autoScale\0hasFactors\0caption\0description\0"
    "meterPerPixel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Colors[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
      11,   35, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x06,   12 /* Public */,
       3,    0,   33,    2, 0x06,   13 /* Public */,
       4,    0,   34,    2, 0x06,   14 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       5, QMetaType::QStringList, 0x00015001, uint(0), 0,
       6, QMetaType::QStringList, 0x00015001, uint(0), 0,
       7, QMetaType::QStringList, 0x00015001, uint(0), 0,
       8, QMetaType::Int, 0x00015001, uint(0), 0,
       9, QMetaType::Double, 0x00015103, uint(0), 0,
      10, QMetaType::Double, 0x00015103, uint(0), 0,
      11, QMetaType::Bool, 0x00015103, uint(0), 0,
      12, QMetaType::Bool, 0x00015001, uint(0), 0,
      13, QMetaType::QString, 0x00015001, uint(0), 0,
      14, QMetaType::QString, 0x00015001, uint(0), 0,
      15, QMetaType::Double, 0x00015001, uint(1), 0,

       0        // eod
};

void Colors::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Colors *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->colorsChanged(); break;
        case 1: _t->scaleChanged(); break;
        case 2: _t->manualColorsChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Colors::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Colors::colorsChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Colors::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Colors::scaleChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Colors::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Colors::manualColorsChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Colors *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QStringList*>(_v) = _t->colors(); break;
        case 1: *reinterpret_cast< QStringList*>(_v) = _t->labels(); break;
        case 2: *reinterpret_cast< QStringList*>(_v) = _t->factorLabels(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->colorCount(); break;
        case 4: *reinterpret_cast< double*>(_v) = _t->minValue(); break;
        case 5: *reinterpret_cast< double*>(_v) = _t->maxValue(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->autoScale(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->hasFactors(); break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->caption(); break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->description(); break;
        case 10: *reinterpret_cast< double*>(_v) = _t->meterPerPixel(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Colors *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 4: _t->setMinValue(*reinterpret_cast< double*>(_v)); break;
        case 5: _t->setMaxValue(*reinterpret_cast< double*>(_v)); break;
        case 6: _t->setAutoScale(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
    (void)_a;
}

const QMetaObject Colors::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Colors.offsetsAndSize,
    qt_meta_data_Colors,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Colors_t
, QtPrivate::TypeAndForceComplete<QStringList, std::true_type>, QtPrivate::TypeAndForceComplete<QStringList, std::true_type>, QtPrivate::TypeAndForceComplete<QStringList, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<bool, std::true_type>, QtPrivate::TypeAndForceComplete<bool, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<Colors, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>



>,
    nullptr
} };


const QMetaObject *Colors::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Colors::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Colors.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Colors::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Colors::colorsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Colors::scaleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Colors::manualColorsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
