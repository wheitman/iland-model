/****************************************************************************
** Meta object code from reading C++ file 'csvfile.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/tools/csvfile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'csvfile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CSVFile_t {
    const uint offsetsAndSize[44];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CSVFile_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CSVFile_t qt_meta_stringdata_CSVFile = {
    {
QT_MOC_LITERAL(0, 7), // "CSVFile"
QT_MOC_LITERAL(8, 8), // "loadFile"
QT_MOC_LITERAL(17, 0), // ""
QT_MOC_LITERAL(18, 8), // "fileName"
QT_MOC_LITERAL(27, 14), // "loadFromString"
QT_MOC_LITERAL(42, 7), // "content"
QT_MOC_LITERAL(50, 18), // "loadFromStringList"
QT_MOC_LITERAL(69, 10), // "columnName"
QT_MOC_LITERAL(80, 3), // "col"
QT_MOC_LITERAL(84, 11), // "columnIndex"
QT_MOC_LITERAL(96, 5), // "value"
QT_MOC_LITERAL(102, 3), // "row"
QT_MOC_LITERAL(106, 11), // "column_name"
QT_MOC_LITERAL(118, 7), // "jsValue"
QT_MOC_LITERAL(126, 8), // "QJSValue"
QT_MOC_LITERAL(135, 8), // "setValue"
QT_MOC_LITERAL(144, 8), // "saveFile"
QT_MOC_LITERAL(153, 6), // "parent"
QT_MOC_LITERAL(160, 8), // "captions"
QT_MOC_LITERAL(169, 4), // "flat"
QT_MOC_LITERAL(174, 8), // "colCount"
QT_MOC_LITERAL(183, 8) // "rowCount"

    },
    "CSVFile\0loadFile\0\0fileName\0loadFromString\0"
    "content\0loadFromStringList\0columnName\0"
    "col\0columnIndex\0value\0row\0column_name\0"
    "jsValue\0QJSValue\0setValue\0saveFile\0"
    "parent\0captions\0flat\0colCount\0rowCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSVFile[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       4,  141, // properties
       0,    0, // enums/sets
       3,  161, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x0a,    5 /* Public */,
       4,    1,   89,    2, 0x0a,    7 /* Public */,
       6,    1,   92,    2, 0x0a,    9 /* Public */,
       7,    1,   95,    2, 0x0a,   11 /* Public */,
       9,    1,   98,    2, 0x10a,   13 /* Public | MethodIsConst  */,
      10,    2,  101,    2, 0x10a,   15 /* Public | MethodIsConst  */,
      10,    2,  106,    2, 0x10a,   18 /* Public | MethodIsConst  */,
      11,    1,  111,    2, 0x0a,   21 /* Public */,
      13,    2,  114,    2, 0x10a,   23 /* Public | MethodIsConst  */,
      13,    2,  119,    2, 0x10a,   26 /* Public | MethodIsConst  */,
      15,    3,  124,    2, 0x0a,   29 /* Public */,
      16,    1,  131,    2, 0x0a,   33 /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Bool, QMetaType::QString,    5,
    QMetaType::Bool, QMetaType::QStringList,    5,
    QMetaType::QString, QMetaType::Int,    8,
    QMetaType::Int, QMetaType::QString,    7,
    QMetaType::QVariant, QMetaType::Int, QMetaType::QString,   11,   12,
    QMetaType::QVariant, QMetaType::Int, QMetaType::Int,   11,    8,
    QMetaType::QVariant, QMetaType::Int,   11,
    0x80000000 | 14, QMetaType::Int, QMetaType::Int,   11,    8,
    0x80000000 | 14, QMetaType::Int, QMetaType::QString,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QVariant,   11,    8,   10,
    QMetaType::Void, QMetaType::QString,    3,

 // constructors: parameters
    0x80000000 | 2, QMetaType::QObjectStar,   17,
    0x80000000 | 2,
    0x80000000 | 2, QMetaType::QString,    3,

 // properties: name, type, flags
      18, QMetaType::Bool, 0x00015003, uint(-1), 0,
      19, QMetaType::Bool, 0x00015103, uint(-1), 0,
      20, QMetaType::Int, 0x00015001, uint(-1), 0,
      21, QMetaType::Int, 0x00015001, uint(-1), 0,

 // constructors: name, argc, parameters, tag, flags, initial metatype offsets
       0,    1,  134,    2, 0x0e,   35 /* Public */,
       0,    0,  137,    2, 0x2e,   36 /* Public | MethodCloned */,
       0,    1,  138,    2, 0x0e,   36 /* Public */,

       0        // eod
};

void CSVFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { CSVFile *_r = new CSVFile((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        case 1: { CSVFile *_r = new CSVFile();
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        case 2: { CSVFile *_r = new CSVFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    } else if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CSVFile *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->loadFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->loadFromString((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->loadFromStringList((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->columnName((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->columnIndex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { QVariant _r = _t->value((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 6: { QVariant _r = _t->value((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 7: { QVariant _r = _t->row((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 8: { QJSValue _r = _t->jsValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QJSValue*>(_a[0]) = std::move(_r); }  break;
        case 9: { QJSValue _r = _t->jsValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QJSValue*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->setValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[3]))); break;
        case 11: _t->saveFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CSVFile *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->hasCaptions(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->flat(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->colCount(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->rowCount(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CSVFile *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setHasCaptions(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setFlat(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject CSVFile::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CSVFile.offsetsAndSize,
    qt_meta_data_CSVFile,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CSVFile_t
, QtPrivate::TypeAndForceComplete<bool, std::true_type>, QtPrivate::TypeAndForceComplete<bool, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<CSVFile, std::true_type>
, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<QVariant, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>, QtPrivate::TypeAndForceComplete<QVariant, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<QVariant, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<QJSValue, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<QJSValue, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<QVariant, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>

, QtPrivate::TypeAndForceComplete<QObject *, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
>,
    nullptr
} };


const QMetaObject *CSVFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSVFile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CSVFile.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CSVFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
