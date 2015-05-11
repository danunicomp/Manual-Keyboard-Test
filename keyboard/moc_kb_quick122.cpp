/****************************************************************************
** Meta object code from reading C++ file 'kb_quick122.h'
**
** Created: Mon May 11 10:38:27 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "kb_quick122.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kb_quick122.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_kb_Quick122[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   34,   34,   34, 0x08,
      35,   34,   34,   34, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_kb_Quick122[] = {
    "kb_Quick122\0on_btnClose_clicked()\0\0"
    "on_btnStartTest_clicked()\0"
};

void kb_Quick122::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        kb_Quick122 *_t = static_cast<kb_Quick122 *>(_o);
        switch (_id) {
        case 0: _t->on_btnClose_clicked(); break;
        case 1: _t->on_btnStartTest_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData kb_Quick122::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject kb_Quick122::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_kb_Quick122,
      qt_meta_data_kb_Quick122, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &kb_Quick122::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *kb_Quick122::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *kb_Quick122::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_kb_Quick122))
        return static_cast<void*>(const_cast< kb_Quick122*>(this));
    return QDialog::qt_metacast(_clname);
}

int kb_Quick122::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
