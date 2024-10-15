/****************************************************************************
** Meta object code from reading C++ file 'sortedanalyzer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Downloads/SortedAnalyzer/sortedanalyzer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sortedanalyzer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Graphic_t {
    QByteArrayData data[1];
    char stringdata0[8];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Graphic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Graphic_t qt_meta_stringdata_Graphic = {
    {
QT_MOC_LITERAL(0, 0, 7) // "Graphic"

    },
    "Graphic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Graphic[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Graphic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject Graphic::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Graphic.data,
    qt_meta_data_Graphic,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Graphic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Graphic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Graphic.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Graphic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_SortedWidget_t {
    QByteArrayData data[13];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SortedWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SortedWidget_t qt_meta_stringdata_SortedWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SortedWidget"
QT_MOC_LITERAL(1, 13, 18), // "slotGenerateValues"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 13), // "slotWriteFile"
QT_MOC_LITERAL(4, 47, 12), // "slotReadFile"
QT_MOC_LITERAL(5, 60, 13), // "slotQuickSort"
QT_MOC_LITERAL(6, 74, 14), // "slotChoiceSort"
QT_MOC_LITERAL(7, 89, 13), // "slotShowTable"
QT_MOC_LITERAL(8, 103, 15), // "slotShowGraphic"
QT_MOC_LITERAL(9, 119, 8), // "slotHelp"
QT_MOC_LITERAL(10, 128, 15), // "slotMakeEnabled"
QT_MOC_LITERAL(11, 144, 8), // "QWidget*"
QT_MOC_LITERAL(12, 153, 4) // "pwgt"

    },
    "SortedWidget\0slotGenerateValues\0\0"
    "slotWriteFile\0slotReadFile\0slotQuickSort\0"
    "slotChoiceSort\0slotShowTable\0"
    "slotShowGraphic\0slotHelp\0slotMakeEnabled\0"
    "QWidget*\0pwgt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SortedWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    1,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void SortedWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SortedWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotGenerateValues(); break;
        case 1: _t->slotWriteFile(); break;
        case 2: _t->slotReadFile(); break;
        case 3: _t->slotQuickSort(); break;
        case 4: _t->slotChoiceSort(); break;
        case 5: _t->slotShowTable(); break;
        case 6: _t->slotShowGraphic(); break;
        case 7: _t->slotHelp(); break;
        case 8: _t->slotMakeEnabled((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SortedWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_SortedWidget.data,
    qt_meta_data_SortedWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SortedWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SortedWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SortedWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SortedWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
