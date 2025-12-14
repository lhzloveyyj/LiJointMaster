/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../widget.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN6WidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto Widget::qt_create_metaobjectdata<qt_meta_tag_ZN6WidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Widget",
        "on_openserial_bt_clicked",
        "",
        "on_connectMotor_bt_clicked",
        "refreshSerialPortList",
        "handleParsedCommand",
        "CMD_TypeDef",
        "cmd",
        "on_mechanicalAngle_bt_clicked",
        "checked",
        "on_setPairs_bt_clicked",
        "on_setDir_bt_clicked",
        "on_zeroOffset_bt_clicked",
        "onZeroCalibrationFinished",
        "on_Uabc_bt_clicked",
        "on_setUq_bt_clicked",
        "on_adc_bt_clicked",
        "on_dcBus_bt_clicked",
        "on_SVPWM_bt_clicked",
        "on_Iabc_bt_clicked",
        "on_UAlpha_Beta_bt_clicked",
        "on_IAlpha_Beta_bt_clicked",
        "on_iq_id_bt_clicked",
        "on_setIQ_tb_clicked",
        "on_setID_tb_clicked",
        "on_ctrolMode_ComboBox_currentIndexChanged",
        "index",
        "on_DevMsg_bt_clicked",
        "updateMosTempUI",
        "appendLogToUI",
        "msg",
        "onNewLog",
        "on_setUd_bt_clicked",
        "on_iqPID_kp_tb_clicked",
        "on_speed_bt_clicked",
        "on_setSpeedDir_bt_clicked",
        "on_speedOut_bt_clicked",
        "on_setSpeedTar_tb_clicked",
        "on_speedPID_kp_tb_clicked",
        "on_speedPID_ki_tb_clicked",
        "on_iqPID_ki_tb_clicked",
        "on_setLocalTar_tb_clicked",
        "on_local_bt_clicked",
        "on_localOut_bt_clicked",
        "on_localPID_kp_tb_clicked",
        "on_localPID_kd_tb_clicked",
        "on_iqPID_out_tb_clicked",
        "on_speedPID_out_tb_clicked",
        "on_localPID_out_tb_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_openserial_bt_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_connectMotor_bt_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'refreshSerialPortList'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'handleParsedCommand'
        QtMocHelpers::SlotData<void(CMD_TypeDef)>(5, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Slot 'on_mechanicalAngle_bt_clicked'
        QtMocHelpers::SlotData<void(bool)>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 9 },
        }}),
        // Slot 'on_setPairs_bt_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_setDir_bt_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_zeroOffset_bt_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onZeroCalibrationFinished'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_Uabc_bt_clicked'
        QtMocHelpers::SlotData<void(bool)>(14, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 9 },
        }}),
        // Slot 'on_setUq_bt_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_adc_bt_clicked'
        QtMocHelpers::SlotData<void(bool)>(16, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 9 },
        }}),
        // Slot 'on_dcBus_bt_clicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_SVPWM_bt_clicked'
        QtMocHelpers::SlotData<void(bool)>(18, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 9 },
        }}),
        // Slot 'on_Iabc_bt_clicked'
        QtMocHelpers::SlotData<void(bool)>(19, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 9 },
        }}),
        // Slot 'on_UAlpha_Beta_bt_clicked'
        QtMocHelpers::SlotData<void(bool)>(20, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 9 },
        }}),
        // Slot 'on_IAlpha_Beta_bt_clicked'
        QtMocHelpers::SlotData<void(bool)>(21, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 9 },
        }}),
        // Slot 'on_iq_id_bt_clicked'
        QtMocHelpers::SlotData<void(bool)>(22, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 9 },
        }}),
        // Slot 'on_setIQ_tb_clicked'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_setID_tb_clicked'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_ctrolMode_ComboBox_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(25, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 26 },
        }}),
        // Slot 'on_DevMsg_bt_clicked'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updateMosTempUI'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'appendLogToUI'
        QtMocHelpers::SlotData<void(const QString &)>(29, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'onNewLog'
        QtMocHelpers::SlotData<void(const QString &)>(31, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'on_setUd_bt_clicked'
        QtMocHelpers::SlotData<void()>(32, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_iqPID_kp_tb_clicked'
        QtMocHelpers::SlotData<void()>(33, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_speed_bt_clicked'
        QtMocHelpers::SlotData<void(bool)>(34, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 9 },
        }}),
        // Slot 'on_setSpeedDir_bt_clicked'
        QtMocHelpers::SlotData<void()>(35, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_speedOut_bt_clicked'
        QtMocHelpers::SlotData<void(bool)>(36, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 9 },
        }}),
        // Slot 'on_setSpeedTar_tb_clicked'
        QtMocHelpers::SlotData<void()>(37, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_speedPID_kp_tb_clicked'
        QtMocHelpers::SlotData<void()>(38, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_speedPID_ki_tb_clicked'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_iqPID_ki_tb_clicked'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_setLocalTar_tb_clicked'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_local_bt_clicked'
        QtMocHelpers::SlotData<void(bool)>(42, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 9 },
        }}),
        // Slot 'on_localOut_bt_clicked'
        QtMocHelpers::SlotData<void(bool)>(43, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 9 },
        }}),
        // Slot 'on_localPID_kp_tb_clicked'
        QtMocHelpers::SlotData<void()>(44, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_localPID_kd_tb_clicked'
        QtMocHelpers::SlotData<void()>(45, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_iqPID_out_tb_clicked'
        QtMocHelpers::SlotData<void()>(46, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_speedPID_out_tb_clicked'
        QtMocHelpers::SlotData<void()>(47, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_localPID_out_tb_clicked'
        QtMocHelpers::SlotData<void()>(48, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Widget, qt_meta_tag_ZN6WidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6WidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6WidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN6WidgetE_t>.metaTypes,
    nullptr
} };

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Widget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_openserial_bt_clicked(); break;
        case 1: _t->on_connectMotor_bt_clicked(); break;
        case 2: _t->refreshSerialPortList(); break;
        case 3: _t->handleParsedCommand((*reinterpret_cast<std::add_pointer_t<CMD_TypeDef>>(_a[1]))); break;
        case 4: _t->on_mechanicalAngle_bt_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->on_setPairs_bt_clicked(); break;
        case 6: _t->on_setDir_bt_clicked(); break;
        case 7: _t->on_zeroOffset_bt_clicked(); break;
        case 8: _t->onZeroCalibrationFinished(); break;
        case 9: _t->on_Uabc_bt_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->on_setUq_bt_clicked(); break;
        case 11: _t->on_adc_bt_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->on_dcBus_bt_clicked(); break;
        case 13: _t->on_SVPWM_bt_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: _t->on_Iabc_bt_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 15: _t->on_UAlpha_Beta_bt_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 16: _t->on_IAlpha_Beta_bt_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 17: _t->on_iq_id_bt_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 18: _t->on_setIQ_tb_clicked(); break;
        case 19: _t->on_setID_tb_clicked(); break;
        case 20: _t->on_ctrolMode_ComboBox_currentIndexChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->on_DevMsg_bt_clicked(); break;
        case 22: _t->updateMosTempUI(); break;
        case 23: _t->appendLogToUI((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 24: _t->onNewLog((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 25: _t->on_setUd_bt_clicked(); break;
        case 26: _t->on_iqPID_kp_tb_clicked(); break;
        case 27: _t->on_speed_bt_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 28: _t->on_setSpeedDir_bt_clicked(); break;
        case 29: _t->on_speedOut_bt_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 30: _t->on_setSpeedTar_tb_clicked(); break;
        case 31: _t->on_speedPID_kp_tb_clicked(); break;
        case 32: _t->on_speedPID_ki_tb_clicked(); break;
        case 33: _t->on_iqPID_ki_tb_clicked(); break;
        case 34: _t->on_setLocalTar_tb_clicked(); break;
        case 35: _t->on_local_bt_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 36: _t->on_localOut_bt_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 37: _t->on_localPID_kp_tb_clicked(); break;
        case 38: _t->on_localPID_kd_tb_clicked(); break;
        case 39: _t->on_iqPID_out_tb_clicked(); break;
        case 40: _t->on_speedPID_out_tb_clicked(); break;
        case 41: _t->on_localPID_out_tb_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6WidgetE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 42)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 42;
    }
    return _id;
}
QT_WARNING_POP
