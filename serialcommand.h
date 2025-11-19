#ifndef SERIALCOMMAND_H
#define SERIALCOMMAND_H

#pragma once
#include <cstdint>  // for uint8_t

#define FRAME_HEAD   0xA5
#define FRAME_TAIL   0x49

// ======================= 命令字定义 ======================= //
enum class CMD_TypeDef : uint8_t
{
    CMD_NONE                    = 0x00,  // 无效命令
    CMD_CONNECT_MOTOR           = 0x01,  // 连接电机
    CMD_MECHANICALANGLE         = 0x02,  // 打开机械角度传输
    CMD_MECHANICALANGLE_CLOSE   = 0x03,  //关闭机械角度传输
    CMD_SETPAIRS                = 0x04,  //设置极对数
    CMD_SETDIR                  = 0x05,  //设置方向
    CMD_ZEROCALIBRATIO          = 0x06,  // 零点校准
    CMD_ZEROCALIBRATIO_OVER     = 0x07,  // 零点校准结束
    CMD_UABC                    = 0x08,  // 打印三项电压ua,ub,uc
    CMD_UABC_CLOSE              = 0x09,  // 关闭打印三项电压ua,ub,uc
};


#endif // SERIALCOMMAND_H
