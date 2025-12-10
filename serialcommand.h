#ifndef SERIALCOMMAND_H
#define SERIALCOMMAND_H

#pragma once
#include <cstdint>  // for uint8_t

/// 帧头、帧尾定义
#define FRAME_HEAD   0xA5
#define FRAME_TAIL   0x49

/**
 * @brief 串口命令枚举
 *
 * 这些命令用于与电机控制器通信，
 * 包括电机连接、角度读取、零点校准、SVPWM输出、电流电压采集等。
 */
enum class CMD_TypeDef : uint8_t
{
    CMD_NONE                    = 0x00,  ///< 无效命令

    // ================= 电机连接与参数 ================= //
    CMD_CONNECT_MOTOR           = 0x01,  ///< 连接电机
    CMD_MECHANICALANGLE         = 0x02,  ///< 打开机械角度传输
    CMD_MECHANICALANGLE_CLOSE   = 0x03,  ///< 关闭机械角度传输
    CMD_SETPAIRS                = 0x04,  ///< 设置极对数
    CMD_SETDIR                  = 0x05,  ///< 设置方向
    CMD_ZEROCALIBRATIO          = 0x06,  ///< 零点校准
    CMD_ZEROCALIBRATIO_OVER     = 0x07,  ///< 零点校准完成

    // ================= 电压采集 ================= //
    CMD_UABC                    = 0x08,  ///< 打印三相电压 Ua, Ub, Uc
    CMD_UABC_CLOSE              = 0x09,  ///< 关闭打印三相电压

    CMD_SETUQ                   = 0x0A,  ///< 设置 Uq

    CMD_ADC                     = 0x0B,  ///< 打印三相ADC采样值
    CMD_ADC_CLOSE               = 0x0C,  ///< 关闭打印三相ADC采样值

    CMD_DCVBUS                  = 0x0D,  ///< 获取母线电压

    // ================= SVPWM ================= //
    CMD_TABC                    = 0x0E,  ///< 三相SVPWM输出
    CMD_TABC_CLOSE              = 0x0F,  ///< 关闭三相SVPWM输出

    // ================= 电流采集 ================= //
    CMD_IABC                    = 0x10,  ///< 打印三相电流
    CMD_IABC_CLOSE              = 0x11,  ///< 关闭打印三相电流

    // ================= αβ坐标系 ================= //
    CMD_UALPHA_BETA             = 0x12,  ///< 打印 Uα, Uβ
    CMD_UALPHA_BETA_CLOSE       = 0x13,  ///< 关闭打印 Uα, Uβ

    CMD_IALPHA_BETA             = 0x14,  ///< 打印 Iα, Iβ
    CMD_IALPHA_BETA_CLOSE       = 0x15,  ///< 关闭打印 Iα, Iβ

    // ================= dq坐标系 ================= //
    CMD_IQ_ID                   = 0x16,  ///< 打印 Iq, Id
    CMD_IQ_ID_CLOSE             = 0x17,  ///< 关闭打印 Iq, Id
    CMD_SETIQ                   = 0x18,  ///< 设置 Iq
    CMD_SETID                   = 0x19,  ///< 设置 Id

    // ================= 控制模式 ================= //
    CMD_OPEN_LOOP               = 0x20,  ///< 开环模式
    CMD_CURRENT_LOOP            = 0x21,  ///< 电流环模式
    CMD_SPEED_LOOP              = 0x22,  ///< 速度-电流环模式
    CMD_POSITION_LOOP           = 0x23,  ///< 位置-速度-电流环模式

    // ================= 温度 ================= //
    CMD_MOSTEMP                 = 0x24,  ///< 获取 MOSFET 温度
    CMD_SETUD                   = 0x25,  ///< 设置Ud
    CMD_SETIQPIDKP              = 0x26,  ///< 设置电流环KP
    CMD_SETIQPIDKI              = 0x27,  ///< 设置电流环KI、

    CMD_SPEED                   = 0x28,  ///< 开启速度打印
    CMD_SPEED_CLODE             = 0x29,  ///< 关闭速度打印
};

#endif // SERIALCOMMAND_H
