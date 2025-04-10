/****************************************************************************
** Meta object code from reading C++ file 'management.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/core/management.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'management.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Management_t {
    const uint offsetsAndSize[126];
    char stringdata0[656];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Management_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Management_t qt_meta_stringdata_Management = {
    {
QT_MOC_LITERAL(0, 10), // "Management"
QT_MOC_LITERAL(11, 4), // "tree"
QT_MOC_LITERAL(16, 8), // "QJSValue"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 5), // "index"
QT_MOC_LITERAL(32, 10), // "treeObject"
QT_MOC_LITERAL(43, 4), // "mean"
QT_MOC_LITERAL(48, 10), // "expression"
QT_MOC_LITERAL(59, 6), // "filter"
QT_MOC_LITERAL(66, 3), // "sum"
QT_MOC_LITERAL(70, 6), // "remain"
QT_MOC_LITERAL(77, 6), // "number"
QT_MOC_LITERAL(84, 7), // "killPct"
QT_MOC_LITERAL(92, 7), // "pctfrom"
QT_MOC_LITERAL(100, 5), // "pctto"
QT_MOC_LITERAL(106, 7), // "killAll"
QT_MOC_LITERAL(114, 15), // "disturbanceKill"
QT_MOC_LITERAL(130, 21), // "stem_to_soil_fraction"
QT_MOC_LITERAL(152, 21), // "stem_to_snag_fraction"
QT_MOC_LITERAL(174, 23), // "branch_to_soil_fraction"
QT_MOC_LITERAL(198, 23), // "branch_to_snag_fraction"
QT_MOC_LITERAL(222, 5), // "agent"
QT_MOC_LITERAL(228, 4), // "kill"
QT_MOC_LITERAL(233, 8), // "fraction"
QT_MOC_LITERAL(242, 9), // "managePct"
QT_MOC_LITERAL(252, 9), // "manageAll"
QT_MOC_LITERAL(262, 6), // "manage"
QT_MOC_LITERAL(269, 10), // "cutAndDrop"
QT_MOC_LITERAL(280, 10), // "percentile"
QT_MOC_LITERAL(291, 3), // "pct"
QT_MOC_LITERAL(295, 5), // "clear"
QT_MOC_LITERAL(301, 7), // "loadAll"
QT_MOC_LITERAL(309, 4), // "load"
QT_MOC_LITERAL(314, 16), // "loadResourceUnit"
QT_MOC_LITERAL(331, 7), // "ruindex"
QT_MOC_LITERAL(339, 16), // "loadFromTreeList"
QT_MOC_LITERAL(356, 12), // "QList<Tree*>"
QT_MOC_LITERAL(369, 9), // "tree_list"
QT_MOC_LITERAL(379, 9), // "do_append"
QT_MOC_LITERAL(389, 11), // "loadFromMap"
QT_MOC_LITERAL(401, 14), // "const MapGrid*"
QT_MOC_LITERAL(416, 8), // "map_grid"
QT_MOC_LITERAL(425, 3), // "key"
QT_MOC_LITERAL(429, 15), // "MapGridWrapper*"
QT_MOC_LITERAL(445, 4), // "wrap"
QT_MOC_LITERAL(450, 12), // "killSaplings"
QT_MOC_LITERAL(463, 24), // "killSaplingsResourceUnit"
QT_MOC_LITERAL(488, 16), // "removeSoilCarbon"
QT_MOC_LITERAL(505, 7), // "SWDfrac"
QT_MOC_LITERAL(513, 7), // "DWDfrac"
QT_MOC_LITERAL(521, 10), // "litterFrac"
QT_MOC_LITERAL(532, 8), // "soilFrac"
QT_MOC_LITERAL(541, 10), // "slashSnags"
QT_MOC_LITERAL(552, 14), // "slash_fraction"
QT_MOC_LITERAL(567, 4), // "sort"
QT_MOC_LITERAL(572, 9), // "statement"
QT_MOC_LITERAL(582, 12), // "filterIdList"
QT_MOC_LITERAL(595, 6), // "idList"
QT_MOC_LITERAL(602, 9), // "randomize"
QT_MOC_LITERAL(612, 5), // "count"
QT_MOC_LITERAL(618, 13), // "removeFoliage"
QT_MOC_LITERAL(632, 12), // "removeBranch"
QT_MOC_LITERAL(645, 10) // "removeStem"

    },
    "Management\0tree\0QJSValue\0\0index\0"
    "treeObject\0mean\0expression\0filter\0sum\0"
    "remain\0number\0killPct\0pctfrom\0pctto\0"
    "killAll\0disturbanceKill\0stem_to_soil_fraction\0"
    "stem_to_snag_fraction\0branch_to_soil_fraction\0"
    "branch_to_snag_fraction\0agent\0kill\0"
    "fraction\0managePct\0manageAll\0manage\0"
    "cutAndDrop\0percentile\0pct\0clear\0loadAll\0"
    "load\0loadResourceUnit\0ruindex\0"
    "loadFromTreeList\0QList<Tree*>\0tree_list\0"
    "do_append\0loadFromMap\0const MapGrid*\0"
    "map_grid\0key\0MapGridWrapper*\0wrap\0"
    "killSaplings\0killSaplingsResourceUnit\0"
    "removeSoilCarbon\0SWDfrac\0DWDfrac\0"
    "litterFrac\0soilFrac\0slashSnags\0"
    "slash_fraction\0sort\0statement\0"
    "filterIdList\0idList\0randomize\0count\0"
    "removeFoliage\0removeBranch\0removeStem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Management[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       4,  375, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  224,    3, 0x0a,    5 /* Public */,
       5,    1,  227,    3, 0x0a,    7 /* Public */,
       6,    2,  230,    3, 0x0a,    9 /* Public */,
       6,    1,  235,    3, 0x2a,   12 /* Public | MethodCloned */,
       9,    2,  238,    3, 0x0a,   14 /* Public */,
       9,    1,  243,    3, 0x2a,   17 /* Public | MethodCloned */,
      10,    1,  246,    3, 0x0a,   19 /* Public */,
      12,    3,  249,    3, 0x0a,   21 /* Public */,
      15,    0,  256,    3, 0x0a,   25 /* Public */,
      16,    5,  257,    3, 0x0a,   26 /* Public */,
      22,    2,  268,    3, 0x0a,   32 /* Public */,
      24,    3,  273,    3, 0x0a,   35 /* Public */,
      25,    0,  280,    3, 0x0a,   39 /* Public */,
      26,    2,  281,    3, 0x0a,   40 /* Public */,
      27,    0,  286,    3, 0x0a,   43 /* Public */,
      28,    1,  287,    3, 0x0a,   44 /* Public */,
      30,    0,  290,    3, 0x0a,   46 /* Public */,
      31,    0,  291,    3, 0x0a,   47 /* Public */,
      32,    1,  292,    3, 0x0a,   48 /* Public */,
      33,    1,  295,    3, 0x0a,   50 /* Public */,
      35,    2,  298,    3, 0x0a,   52 /* Public */,
      35,    1,  303,    3, 0x2a,   55 /* Public | MethodCloned */,
      39,    3,  306,    3, 0x0a,   57 /* Public */,
      39,    2,  313,    3, 0x2a,   61 /* Public | MethodCloned */,
      39,    3,  318,    3, 0x0a,   64 /* Public */,
      39,    2,  325,    3, 0x2a,   68 /* Public | MethodCloned */,
      45,    3,  330,    3, 0x0a,   71 /* Public */,
      45,    2,  337,    3, 0x2a,   75 /* Public | MethodCloned */,
      46,    1,  342,    3, 0x0a,   78 /* Public */,
      47,    6,  345,    3, 0x0a,   80 /* Public */,
      52,    3,  358,    3, 0x0a,   87 /* Public */,
      54,    1,  365,    3, 0x0a,   91 /* Public */,
       8,    1,  368,    3, 0x0a,   93 /* Public */,
      56,    1,  371,    3, 0x0a,   95 /* Public */,
      58,    0,  374,    3, 0x0a,   97 /* Public */,

 // slots: parameters
    0x80000000 | 2, QMetaType::Int,    4,
    0x80000000 | 2, QMetaType::Int,    4,
    QMetaType::Double, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::Double, QMetaType::QString,    7,
    QMetaType::Double, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::Double, QMetaType::QString,    7,
    QMetaType::Int, QMetaType::Int,   11,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   13,   14,   11,
    QMetaType::Int,
    QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QString,   17,   18,   19,   20,   21,
    QMetaType::Int, QMetaType::QString, QMetaType::Double,    8,   23,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   13,   14,   11,
    QMetaType::Int,
    QMetaType::Int, QMetaType::QString, QMetaType::Double,    8,   23,
    QMetaType::Void,
    QMetaType::Double, QMetaType::Int,   29,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Int, QMetaType::QString,    8,
    QMetaType::Int, QMetaType::Int,   34,
    QMetaType::Void, 0x80000000 | 36, QMetaType::Bool,   37,   38,
    QMetaType::Void, 0x80000000 | 36,   37,
    QMetaType::Void, 0x80000000 | 40, QMetaType::Int, QMetaType::Bool,   41,   42,   38,
    QMetaType::Void, 0x80000000 | 40, QMetaType::Int,   41,   42,
    QMetaType::Int, 0x80000000 | 43, QMetaType::Int, QMetaType::Bool,   44,   42,   38,
    QMetaType::Int, 0x80000000 | 43, QMetaType::Int,   44,   42,
    QMetaType::Void, 0x80000000 | 43, QMetaType::Int, QMetaType::QString,   44,   42,    8,
    QMetaType::Void, 0x80000000 | 43, QMetaType::Int,   44,   42,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void, 0x80000000 | 43, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,   44,   42,   48,   49,   50,   51,
    QMetaType::Void, 0x80000000 | 43, QMetaType::Int, QMetaType::Double,   44,   42,   53,
    QMetaType::Void, QMetaType::QString,   55,
    QMetaType::Int, QMetaType::QString,    8,
    QMetaType::Int, QMetaType::QVariantList,   57,
    QMetaType::Void,

 // properties: name, type, flags
      59, QMetaType::Int, 0x00015001, uint(-1), 0,
      60, QMetaType::Double, 0x00015103, uint(-1), 0,
      61, QMetaType::Double, 0x00015103, uint(-1), 0,
      62, QMetaType::Double, 0x00015103, uint(-1), 0,

       0        // eod
};

void Management::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Management *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QJSValue _r = _t->tree((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJSValue*>(_a[0]) = std::move(_r); }  break;
        case 1: { QJSValue _r = _t->treeObject((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJSValue*>(_a[0]) = std::move(_r); }  break;
        case 2: { double _r = _t->mean((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 3: { double _r = _t->mean((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 4: { double _r = _t->sum((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 5: { double _r = _t->sum((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->remain((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->killPct((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->killAll();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->disturbanceKill((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->kill((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->managePct((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: { int _r = _t->manageAll();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: { int _r = _t->manage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->cutAndDrop(); break;
        case 15: { double _r = _t->percentile((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->clear(); break;
        case 17: { int _r = _t->loadAll();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 18: { int _r = _t->load((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 19: { int _r = _t->loadResourceUnit((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 20: _t->loadFromTreeList((*reinterpret_cast< std::add_pointer_t<QList<Tree*>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 21: _t->loadFromTreeList((*reinterpret_cast< std::add_pointer_t<QList<Tree*>>>(_a[1]))); break;
        case 22: _t->loadFromMap((*reinterpret_cast< std::add_pointer_t<const MapGrid*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 23: _t->loadFromMap((*reinterpret_cast< std::add_pointer_t<const MapGrid*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 24: { int _r = _t->loadFromMap((*reinterpret_cast< std::add_pointer_t<MapGridWrapper*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 25: { int _r = _t->loadFromMap((*reinterpret_cast< std::add_pointer_t<MapGridWrapper*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 26: _t->killSaplings((*reinterpret_cast< std::add_pointer_t<MapGridWrapper*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 27: _t->killSaplings((*reinterpret_cast< std::add_pointer_t<MapGridWrapper*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 28: _t->killSaplingsResourceUnit((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 29: _t->removeSoilCarbon((*reinterpret_cast< std::add_pointer_t<MapGridWrapper*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[6]))); break;
        case 30: _t->slashSnags((*reinterpret_cast< std::add_pointer_t<MapGridWrapper*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3]))); break;
        case 31: _t->sort((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 32: { int _r = _t->filter((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 33: { int _r = _t->filterIdList((*reinterpret_cast< std::add_pointer_t<QVariantList>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 34: _t->randomize(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 24:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< MapGridWrapper* >(); break;
            }
            break;
        case 25:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< MapGridWrapper* >(); break;
            }
            break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< MapGridWrapper* >(); break;
            }
            break;
        case 27:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< MapGridWrapper* >(); break;
            }
            break;
        case 29:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< MapGridWrapper* >(); break;
            }
            break;
        case 30:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< MapGridWrapper* >(); break;
            }
            break;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Management *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->count(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->removeFoliage(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->removeBranch(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->removeStem(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Management *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setRemoveFoliage(*reinterpret_cast< double*>(_v)); break;
        case 2: _t->setRemoveBranch(*reinterpret_cast< double*>(_v)); break;
        case 3: _t->setRemoveStem(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Management::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Management.offsetsAndSize,
    qt_meta_data_Management,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Management_t
, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<double, std::true_type>, QtPrivate::TypeAndForceComplete<Management, std::true_type>
, QtPrivate::TypeAndForceComplete<QJSValue, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QJSValue, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<Tree*>, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<Tree*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const MapGrid *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const MapGrid *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<MapGridWrapper *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<MapGridWrapper *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<MapGridWrapper *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<MapGridWrapper *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<MapGridWrapper *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<MapGridWrapper *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantList, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Management::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Management::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Management.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Management::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
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
