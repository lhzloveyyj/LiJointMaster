/****************************************************************************
** Meta object code from reading C++ file 'serialmanager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../serialmanager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN13SerialManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto SerialManager::qt_create_metaobjectdata<qt_meta_tag_ZN13SerialManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SerialManager",
        "portOpened",
        "",
        "portClosed",
        "dataReceived",
        "CMD_TypeDef",
        "cmd",
        "data",
        "commandParsed",
        "zeroCalibrationFinished",
        "readSerialData"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'portOpened'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'portClosed'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'dataReceived'
        QtMocHelpers::SignalData<void(CMD_TypeDef, QByteArray)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 }, { QMetaType::QByteArray, 7 },
        }}),
        // Signal 'commandParsed'
        QtMocHelpers::SignalData<void(CMD_TypeDef)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
        // Signal 'zeroCalibrationFinished'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'readSerialData'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<SerialManager, qt_meta_tag_ZN13SerialManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject SerialManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13SerialManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13SerialManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13SerialManagerE_t>.metaTypes,
    nullptr
} };

void SerialManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SerialManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->portOpened(); break;
        case 1: _t->portClosed(); break;
        case 2: _t->dataReceived((*reinterpret_cast<std::add_pointer_t<CMD_TypeDef>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 3: _t->commandParsed((*reinterpret_cast<std::add_pointer_t<CMD_TypeDef>>(_a[1]))); break;
        case 4: _t->zeroCalibrationFinished(); break;
        case 5: _t->readSerialData(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (SerialManager::*)()>(_a, &SerialManager::portOpened, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (SerialManager::*)()>(_a, &SerialManager::portClosed, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (SerialManager::*)(CMD_TypeDef , QByteArray )>(_a, &SerialManager::dataReceived, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (SerialManager::*)(CMD_TypeDef )>(_a, &SerialManager::commandParsed, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (SerialManager::*)()>(_a, &SerialManager::zeroCalibrationFinished, 4))
            return;
    }
}

const QMetaObject *SerialManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13SerialManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SerialManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SerialManager::portOpened()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SerialManager::portClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SerialManager::dataReceived(CMD_TypeDef _t1, QByteArray _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void SerialManager::commandParsed(CMD_TypeDef _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void SerialManager::zeroCalibrationFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
