# LiJointMaster

`LiJointMaster` 是一个基于 **Qt6 + C++17** 的上位机调试工具，用于通过串口与电机控制器通信，实现 FOC 参数设置、状态监控与实时曲线显示。

项目当前重点能力：
- 串口连接与设备参数读取
- 多种控制命令下发（电流环 / 速度环 / 位置环）
- 多路实时波形显示（机械角、电压、电流、ADC、速度、位置等）
- MOS 温度可视化
- 应用内日志捕获与展示

---

## 1. 技术栈

- C++17
- Qt 6（Widgets / SerialPort / PrintSupport）
- QCustomPlot（内置源码）
- CMake >= 3.16

核心构建配置见 `CMakeLists.txt`。

---

## 2. 项目结构

```text
LiJointMaster/
├─ main.cpp                  # 程序入口
├─ widget.h/.cpp/.ui         # 主界面与交互逻辑
├─ serialmanager.h/.cpp      # 串口收发与协议解析
├─ serialcommand.h           # 串口命令枚举与帧定义
├─ plotmanager.h/.cpp        # 实时绘图管理
├─ qcustomplot.h/.cpp        # 绘图库源码
├─ loghelper.h/.cpp          # Qt 日志重定向
├─ dialog.h/.cpp/.ui         # 设备信息对话框
├─ ResourceFiles.qrc         # 资源文件（图标）
└─ picture/                  # 图标资源
```

---

## 3. 功能概览

### 3.1 串口功能

- 自动刷新可用串口列表（2 秒）
- 打开 / 关闭串口
- 串口连接状态图标联动
- 接收帧解析与命令分发

### 3.2 参数与控制

支持：
- 电机连接与基础参数读取（极对数、方向、零偏、PID 等）
- 零点校准
- 控制模式切换：开环 / 电流环 / 速度环 / 位置环
- 目标与参数设置：Uq、Ud、Iq、Id、速度目标、位置目标、各环 PID 与输出限幅

### 3.3 实时观测与波形

支持实时打印并绘图：
- 机械角
- Uabc / Iabc
- ADC1/2/3
- Ta/Tb/Tc（SVPWM）
- Uαβ / Iαβ
- Iq/Id
- 速度 / 速度环输出
- 位置 / 位置环输出

绘图支持：
- 鼠标缩放与拖拽
- 滑条控制 X 轴显示时长
- 鼠标吸附最近点并显示 `Y` 值

### 3.4 温度与日志

- MOS 温度 100ms 刷新
- 温度条按区间变色（绿/黄/红）
- 捕获 `qDebug/qWarning/...` 并输出到 UI 日志窗口

---

## 4. 串口协议（按现有代码）

### 4.1 帧标记

- 帧头：`0xA5`
- 帧尾：`0x49`

定义位于 `serialcommand.h`：

```cpp
#define FRAME_HEAD 0xA5
#define FRAME_TAIL 0x49
```

### 4.2 上位机发送（PC -> 控制器）

由 `SerialManager::sendFloatCommand` 组帧：

```text
[HEAD][CMD][DATA0][DATA1][DATA2][DATA3][CHECKSUM][TAIL]
```

- `DATA`：1 个 `float`（4 字节）
- `CHECKSUM`：`HEAD + CMD + DATA0 + DATA1 + DATA2 + DATA3`（uint8 累加）

### 4.3 上位机接收（控制器 -> PC）

由 `SerialManager::readSerialData` 解析：

```text
[HEAD][CMD][LEN][PAYLOAD...][CHECKSUM][TAIL]
```

- `LEN`：payload 字节数
- `LEN` 必须：`>0`、`<=128`、且 `LEN % 4 == 0`
- `PAYLOAD`：按 4 字节切分为 float 数组
- `CHECKSUM`：从 `HEAD` 累加到 `PAYLOAD` 末尾（不含 `CHECKSUM` 和 `TAIL`）

---

## 5. 命令列表（`serialcommand.h`）

> 以下为代码中的命令分组，十六进制值以源码为准。

### 5.1 电机与基础参数
- `CMD_CONNECT_MOTOR` `0x01`
- `CMD_MECHANICALANGLE` / `_CLOSE` `0x02/0x03`
- `CMD_SETPAIRS` `0x04`
- `CMD_SETDIR` `0x05`
- `CMD_ZEROCALIBRATIO` / `_OVER` `0x06/0x07`

### 5.2 电压 / ADC / SVPWM / 电流
- `CMD_UABC` / `_CLOSE` `0x08/0x09`
- `CMD_SETUQ` `0x0A`
- `CMD_ADC` / `_CLOSE` `0x0B/0x0C`
- `CMD_DCVBUS` `0x0D`
- `CMD_TABC` / `_CLOSE` `0x0E/0x0F`
- `CMD_IABC` / `_CLOSE` `0x10/0x11`

### 5.3 αβ / dq
- `CMD_UALPHA_BETA` / `_CLOSE` `0x12/0x13`
- `CMD_IALPHA_BETA` / `_CLOSE` `0x14/0x15`
- `CMD_IQ_ID` / `_CLOSE` `0x16/0x17`
- `CMD_SETIQ` `0x18`
- `CMD_SETID` `0x19`

### 5.4 控制模式
- `CMD_OPEN_LOOP` `0x20`
- `CMD_CURRENT_LOOP` `0x21`
- `CMD_SPEED_LOOP` `0x22`
- `CMD_POSITION_LOOP` `0x23`

### 5.5 高级参数
- `CMD_MOSTEMP` `0x24`
- `CMD_SETUD` `0x25`
- `CMD_SETIQPIDKP` / `CMD_SETIQPIDKI` `0x26/0x27`
- `CMD_SPEED` / `_CLODE` `0x28/0x29`
- `CMD_SETSPEEDDIR` `0x30`
- `CMD_SPEEDOUT` / `_CLOSE` `0x31/0x32`
- `CMD_SETSPEEDTAR` `0x33`
- `CMD_SETSPEEDPIDKP` / `CMD_SETSPEEDPIDKI` `0x34/0x35`
- `CMD_SETLOCALTAR` `0x36`
- `CMD_LOCAL` / `_CLOSE` `0x37/0x38`
- `CMD_LOCALOUT` / `_CLOSE` `0x39/0x40`
- `CMD_SETLOCALPIDKP` / `CMD_SETLOCALPIDKD` `0x41/0x42`
- `CMD_SETIQPIDOUT` / `CMD_SETSPEEDPIDOUT` / `CMD_SETLOCALPIDOUT` `0x43/0x44/0x45`

---

## 6. 构建与运行

## 6.1 Windows + Qt Creator（推荐）

1. 安装 Qt 6（包含 `Qt SerialPort` 与 MinGW）
2. 用 Qt Creator 打开项目根目录 `CMakeLists.txt`
3. 选择 Kit（例如 `Desktop Qt 6.x MinGW 64-bit`）
4. Configure -> Build -> Run

> 项目内已有 `MINGW` 的 `-Wa,-mbig-obj` 编译选项，处理 `qcustomplot.cpp` 大对象文件。

## 6.2 命令行（示例）

```bash
cmake -S . -B build -DCMAKE_PREFIX_PATH="<Qt6_DIR>"
cmake --build build -j
```

---

## 7. 使用流程

1. 启动软件
2. 选择串口与波特率，点击“打开串口”
3. 点击“连接电机”读取基础参数
4. 根据需要：
   - 切换控制模式
   - 设置 Uq/Ud/Iq/Id/速度/位置目标
   - 调整 PID 参数与输出限幅
5. 打开对应打印开关，观察实时曲线
6. 通过日志窗口查看运行信息

---

## 8. 主要类说明

- `Widget`：主 UI 交互层，负责按钮槽函数、界面刷新、命令下发
- `SerialManager`：串口收发与协议解析中心
- `PlotManager`：曲线注册、数据追加、坐标范围管理、鼠标提示
- `LogHelper`：Qt 日志重定向到 UI

---

## 9. 已知注意事项

- 串口接收端要求数据帧 `LEN` 必须为 4 的倍数（float 对齐）
- 部分参数更新采用 `QTimer::singleShot` 延时读取，依赖设备响应时序
- 当前工程内包含 `build/` 产物目录，建议后续加入 `.gitignore` 统一管理

---

## 10. 许可证

当前仓库未显式提供 LICENSE 文件。若用于开源分发，建议补充许可证声明（如 MIT / Apache-2.0）。

---

## 11. 致谢

- Qt
- QCustomPlot
