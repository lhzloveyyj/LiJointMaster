#ifndef SERIALCOMMAND_H
#define SERIALCOMMAND_H

#pragma once
#include <cstdint>  // for uint8_t

#define FRAME_HEAD   0xA5
#define FRAME_TAIL   0x49

// ======================= 命令字定义 ======================= //
enum class CMD_TypeDef : uint8_t
{
    CMD_NONE          = 0x00,  // 无效命令
    CMD_CONNECT_MOTOR = 0x01,  // 连接电机
    // 未来可以继续扩展
    // DISCONNECT_MOTOR = 0x02,
};


#endif // SERIALCOMMAND_H
