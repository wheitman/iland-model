/****************************************************************************
** Meta object code from reading C++ file 'scripttree.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/tools/scripttree.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scripttree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScriptTree_t {
    const uint offsetsAndSize[54];
    char stringdata0[286];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ScriptTree_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ScriptTree_t qt_meta_stringdata_ScriptTree = {
    {
QT_MOC_LITERAL(0, 10), // "ScriptTree"
QT_MOC_LITERAL(11, 4), // "info"
QT_MOC_LITERAL(16, 0), // ""
QT_MOC_LITERAL(17, 4), // "expr"
QT_MOC_LITERAL(22, 8), // "expr_str"
QT_MOC_LITERAL(31, 5), // "valid"
QT_MOC_LITERAL(37, 1), // "x"
QT_MOC_LITERAL(39, 1), // "y"
QT_MOC_LITERAL(41, 3), // "dbh"
QT_MOC_LITERAL(45, 6), // "height"
QT_MOC_LITERAL(52, 7), // "species"
QT_MOC_LITERAL(60, 5), // "flags"
QT_MOC_LITERAL(66, 15), // "TreeRemovalType"
QT_MOC_LITERAL(82, 12), // "RemovedDeath"
QT_MOC_LITERAL(95, 14), // "RemovedHarvest"
QT_MOC_LITERAL(110, 18), // "RemovedDisturbance"
QT_MOC_LITERAL(129, 16), // "RemovedSalavaged"
QT_MOC_LITERAL(146, 13), // "RemovedKilled"
QT_MOC_LITERAL(160, 14), // "RemovedCutDown"
QT_MOC_LITERAL(175, 5), // "Flags"
QT_MOC_LITERAL(181, 8), // "TreeDead"
QT_MOC_LITERAL(190, 18), // "TreeDeadBarkBeetle"
QT_MOC_LITERAL(209, 12), // "TreeDeadWind"
QT_MOC_LITERAL(222, 12), // "TreeDeadFire"
QT_MOC_LITERAL(235, 19), // "TreeDeadKillAndDrop"
QT_MOC_LITERAL(255, 13), // "TreeHarvested"
QT_MOC_LITERAL(269, 16) // "TreeAffectedBite"

    },
    "ScriptTree\0info\0\0expr\0expr_str\0valid\0"
    "x\0y\0dbh\0height\0species\0flags\0"
    "TreeRemovalType\0RemovedDeath\0"
    "RemovedHarvest\0RemovedDisturbance\0"
    "RemovedSalavaged\0RemovedKilled\0"
    "RemovedCutDown\0Flags\0TreeDead\0"
    "TreeDeadBarkBeetle\0TreeDeadWind\0"
    "TreeDeadFire\0TreeDeadKillAndDrop\0"
    "TreeHarvested\0TreeAffectedBite"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptTree[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       7,   30, // properties
       2,   65, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x0a,    8 /* Public */,
       3,    1,   27,    2, 0x0a,    9 /* Public */,

 // slots: parameters
    QMetaType::QString,
    QMetaType::Double, QMetaType::QString,    4,

 // properties: name, type, flags
       5, QMetaType::Bool, 0x00015001, uint(-1), 0,
       6, QMetaType::Double, 0x00015001, uint(-1), 0,
       7, QMetaType::Double, 0x00015001, uint(-1), 0,
       8, QMetaType::Double, 0x00015001, uint(-1), 0,
       9, QMetaType::Double, 0x00015001, uint(-1), 0,
      10, QMetaType::QString, 0x00015001, uint(-1), 0,
      11, QMetaType::Int, 0x00015001, uint(-1), 0,

 // enums: name, alias, flags, count, data
      12,   12, 0x0,    6,   75,
      19,   19, 0x0,    7,   87,

 // enum data: key, value
      13, uint(ScriptTree::RemovedDeath),
      14, uint(ScriptTree::RemovedHarvest),
      15, uint(ScriptTree::RemovedDisturbance),
      16, uint(ScriptTree::RemovedSalavaged),
      17, uint(ScriptTree::RemovedKilled),
      18, uint(ScriptTree::RemovedCutDown),
      20, uint(ScriptTree::TreeDead),
      21, uint(ScriptTree::TreeDeadBarkBeetle),
      22, uint(ScriptTree::TreeDeadWind),
      23, uint(ScriptTree::TreeDeadFire),
      24, uint(ScriptTree::TreeDeadKillAndDrop),
      25, uint(ScriptTree::TreeHarvested),
      26, uint(ScriptTree::TreeAffectedBite),

       0        // eod
};

void ScriptTree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScriptTree *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QString _r = _t->info();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { double _r = _t->expr((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ScriptTree *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->valid(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->x(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->y(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->dbh(); break;
        case 4: *reinterpret_cast< double*>(_v) = _t->height(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->species(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->flags(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ScriptTree::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ScriptTree.offsetsAndSize,
    qt_meta_data_ScriptTree,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ScriptTree_t
, QtPrivate::TypeAndForceComplete<bool, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<ScriptTree, std::true_type>
, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *ScriptTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScriptTree::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScriptTree.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ScriptTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_ScriptTreeExpr_t {
    const uint offsetsAndSize[16];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ScriptTreeExpr_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ScriptTreeExpr_t qt_meta_stringdata_ScriptTreeExpr = {
    {
QT_MOC_LITERAL(0, 14), // "ScriptTreeExpr"
QT_MOC_LITERAL(15, 10), // "expression"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 13), // "setExpression"
QT_MOC_LITERAL(41, 4), // "expr"
QT_MOC_LITERAL(46, 5), // "value"
QT_MOC_LITERAL(52, 11), // "ScriptTree*"
QT_MOC_LITERAL(64, 11) // "script_tree"

    },
    "ScriptTreeExpr\0expression\0\0setExpression\0"
    "expr\0value\0ScriptTree*\0script_tree"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptTreeExpr[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   42, // properties
       0,    0, // enums/sets
       1,   47, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x0a,    2 /* Public */,
       3,    1,   33,    2, 0x0a,    3 /* Public */,
       5,    1,   36,    2, 0x0a,    5 /* Public */,

 // slots: parameters
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Double, 0x80000000 | 6,    7,

 // constructors: parameters
    0x80000000 | 2, QMetaType::QString,    4,

 // properties: name, type, flags
       1, QMetaType::QString, 0x00015103, uint(-1), 0,

 // constructors: name, argc, parameters, tag, flags, initial metatype offsets
       0,    1,   39,    2, 0x0e,    7 /* Public */,

       0        // eod
};

void ScriptTreeExpr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { ScriptTreeExpr *_r = new ScriptTreeExpr((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    } else if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScriptTreeExpr *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QString _r = _t->expression();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->setExpression((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: { double _r = _t->value((*reinterpret_cast< std::add_pointer_t<ScriptTree*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ScriptTree* >(); break;
            }
            break;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ScriptTreeExpr *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->expression(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ScriptTreeExpr *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setExpression(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ScriptTreeExpr::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ScriptTreeExpr.offsetsAndSize,
    qt_meta_data_ScriptTreeExpr,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ScriptTreeExpr_t
, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<ScriptTreeExpr, std::true_type>
, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<ScriptTree *, std::false_type>

, QtPrivate::TypeAndForceComplete<QString, std::false_type>
>,
    nullptr
} };


const QMetaObject *ScriptTreeExpr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScriptTreeExpr::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScriptTreeExpr.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ScriptTreeExpr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
