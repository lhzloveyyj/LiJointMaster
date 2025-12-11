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
        "newmechanicalAngle",
        "mechanicalAngle",
        "newADC",
        "ADC1",
        "ADC2",
        "ADC3",
        "newUABC",
        "Ua",
        "Ub",
        "Uc",
        "newTABC",
        "Ta",
        "Tb",
        "Tc",
        "newIABC",
        "Ia",
        "Ib",
        "Ic",
        "newUalpha_Ubeta",
        "Ualpha",
        "Ubeta",
        "newIalpha_Ibeta",
        "Ialpha",
        "Ibeta",
        "newIqId",
        "Iq",
        "Id",
        "newSpeed",
        "speed",
        "newSpeedOut",
        "speedOut",
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
        // Signal 'newmechanicalAngle'
        QtMocHelpers::SignalData<void(float)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 11 },
        }}),
        // Signal 'newADC'
        QtMocHelpers::SignalData<void(int, int, int)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 13 }, { QMetaType::Int, 14 }, { QMetaType::Int, 15 },
        }}),
        // Signal 'newUABC'
        QtMocHelpers::SignalData<void(float, float, float)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 17 }, { QMetaType::Float, 18 }, { QMetaType::Float, 19 },
        }}),
        // Signal 'newTABC'
        QtMocHelpers::SignalData<void(float, float, float)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 21 }, { QMetaType::Float, 22 }, { QMetaType::Float, 23 },
        }}),
        // Signal 'newIABC'
        QtMocHelpers::SignalData<void(float, float, float)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 25 }, { QMetaType::Float, 26 }, { QMetaType::Float, 27 },
        }}),
        // Signal 'newUalpha_Ubeta'
        QtMocHelpers::SignalData<void(float, float)>(28, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 29 }, { QMetaType::Float, 30 },
        }}),
        // Signal 'newIalpha_Ibeta'
        QtMocHelpers::SignalData<void(float, float)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 32 }, { QMetaType::Float, 33 },
        }}),
        // Signal 'newIqId'
        QtMocHelpers::SignalData<void(float, float)>(34, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 35 }, { QMetaType::Float, 36 },
        }}),
        // Signal 'newSpeed'
        QtMocHelpers::SignalData<void(float)>(37, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 38 },
        }}),
        // Signal 'newSpeedOut'
        QtMocHelpers::SignalData<void(float)>(39, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 40 },
        }}),
        // Slot 'readSerialData'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPrivate, QMetaType::Void),
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
        case 5: _t->newmechanicalAngle((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 6: _t->newADC((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[3]))); break;
        case 7: _t->newUABC((*reinterpret_cast<std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[3]))); break;
        case 8: _t->newTABC((*reinterpret_cast<std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[3]))); break;
        case 9: _t->newIABC((*reinterpret_cast<std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[3]))); break;
        case 10: _t->newUalpha_Ubeta((*reinterpret_cast<std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[2]))); break;
        case 11: _t->newIalpha_Ibeta((*reinterpret_cast<std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[2]))); break;
        case 12: _t->newIqId((*reinterpret_cast<std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[2]))); break;
        case 13: _t->newSpeed((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 14: _t->newSpeedOut((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 15: _t->readSerialData(); break;
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
        if (QtMocHelpers::indexOfMethod<void (SerialManager::*)(float )>(_a, &SerialManager::newmechanicalAngle, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (SerialManager::*)(int , int , int )>(_a, &SerialManager::newADC, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (SerialManager::*)(float , float , float )>(_a, &SerialManager::newUABC, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (SerialManager::*)(float , float , float )>(_a, &SerialManager::newTABC, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (SerialManager::*)(float , float , float )>(_a, &SerialManager::newIABC, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (SerialManager::*)(float , float )>(_a, &SerialManager::newUalpha_Ubeta, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (SerialManager::*)(float , float )>(_a, &SerialManager::newIalpha_Ibeta, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (SerialManager::*)(float , float )>(_a, &SerialManager::newIqId, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (SerialManager::*)(float )>(_a, &SerialManager::newSpeed, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (SerialManager::*)(float )>(_a, &SerialManager::newSpeedOut, 14))
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
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

// SIGNAL 5
void SerialManager::newmechanicalAngle(float _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void SerialManager::newADC(int _t1, int _t2, int _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2, _t3);
}

// SIGNAL 7
void SerialManager::newUABC(float _t1, float _t2, float _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1, _t2, _t3);
}

// SIGNAL 8
void SerialManager::newTABC(float _t1, float _t2, float _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1, _t2, _t3);
}

// SIGNAL 9
void SerialManager::newIABC(float _t1, float _t2, float _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1, _t2, _t3);
}

// SIGNAL 10
void SerialManager::newUalpha_Ubeta(float _t1, float _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1, _t2);
}

// SIGNAL 11
void SerialManager::newIalpha_Ibeta(float _t1, float _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1, _t2);
}

// SIGNAL 12
void SerialManager::newIqId(float _t1, float _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1, _t2);
}

// SIGNAL 13
void SerialManager::newSpeed(float _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1);
}

// SIGNAL 14
void SerialManager::newSpeedOut(float _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 14, nullptr, _t1);
}
QT_WARNING_POP
