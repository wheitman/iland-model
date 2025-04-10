/****************************************************************************
** Meta object code from reading C++ file 'modelcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/core/modelcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modelcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModelController_t {
    const uint offsetsAndSize[44];
    char stringdata0[204];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ModelController_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ModelController_t qt_meta_stringdata_ModelController = {
    {
QT_MOC_LITERAL(0, 15), // "ModelController"
QT_MOC_LITERAL(16, 8), // "finished"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 12), // "errorMessage"
QT_MOC_LITERAL(39, 4), // "year"
QT_MOC_LITERAL(44, 10), // "bufferLogs"
QT_MOC_LITERAL(55, 9), // "do_buffer"
QT_MOC_LITERAL(65, 12), // "stateChanged"
QT_MOC_LITERAL(78, 11), // "setFileName"
QT_MOC_LITERAL(90, 12), // "initFileName"
QT_MOC_LITERAL(103, 6), // "create"
QT_MOC_LITERAL(110, 7), // "destroy"
QT_MOC_LITERAL(118, 3), // "run"
QT_MOC_LITERAL(122, 5), // "years"
QT_MOC_LITERAL(128, 7), // "runYear"
QT_MOC_LITERAL(136, 5), // "pause"
QT_MOC_LITERAL(142, 11), // "continueRun"
QT_MOC_LITERAL(154, 6), // "cancel"
QT_MOC_LITERAL(161, 7), // "repaint"
QT_MOC_LITERAL(169, 17), // "saveDebugOutputJs"
QT_MOC_LITERAL(187, 8), // "do_clear"
QT_MOC_LITERAL(196, 7) // "runloop"

    },
    "ModelController\0finished\0\0errorMessage\0"
    "year\0bufferLogs\0do_buffer\0stateChanged\0"
    "setFileName\0initFileName\0create\0destroy\0"
    "run\0years\0runYear\0pause\0continueRun\0"
    "cancel\0repaint\0saveDebugOutputJs\0"
    "do_clear\0runloop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModelController[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x06,    1 /* Public */,
       4,    1,  107,    2, 0x06,    3 /* Public */,
       5,    1,  110,    2, 0x06,    5 /* Public */,
       7,    0,  113,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,  114,    2, 0x0a,    8 /* Public */,
      10,    0,  117,    2, 0x0a,   10 /* Public */,
      11,    0,  118,    2, 0x0a,   11 /* Public */,
      12,    1,  119,    2, 0x0a,   12 /* Public */,
      14,    0,  122,    2, 0x0a,   14 /* Public */,
      15,    0,  123,    2, 0x0a,   15 /* Public */,
      16,    0,  124,    2, 0x0a,   16 /* Public */,
      17,    0,  125,    2, 0x0a,   17 /* Public */,
      18,    0,  126,    2, 0x0a,   18 /* Public */,
      19,    1,  127,    2, 0x0a,   19 /* Public */,
      21,    0,  130,    2, 0x08,   21 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void,

       0        // eod
};

void ModelController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ModelController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->finished((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->year((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->bufferLogs((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->stateChanged(); break;
        case 4: { bool _r = _t->setFileName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->create(); break;
        case 6: _t->destroy(); break;
        case 7: _t->run((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: { bool _r = _t->runYear();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->pause();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->continueRun();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->cancel(); break;
        case 12: _t->repaint(); break;
        case 13: _t->saveDebugOutputJs((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: _t->runloop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ModelController::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelController::finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ModelController::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelController::year)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ModelController::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelController::bufferLogs)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ModelController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelController::stateChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject ModelController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ModelController.offsetsAndSize,
    qt_meta_data_ModelController,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ModelController_t
, QtPrivate::TypeAndForceComplete<ModelController, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ModelController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModelController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModelController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ModelController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void ModelController::finished(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ModelController::year(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ModelController::bufferLogs(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ModelController::stateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
