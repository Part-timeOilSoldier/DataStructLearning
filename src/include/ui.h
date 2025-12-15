#pragma once  // 防止头文件重复包含

// ========== 基础控制 ==========

#define CSI "\033["     // ANSI 控制序列起始（Control Sequence Introducer）
#define RESET CSI "0m"  // 重置所有属性（颜色、样式恢复默认）

// ========== 前景色 ==========

#define FG_BLACK CSI "30m"    // 前景色：黑
#define FG_RED CSI "31m"      // 前景色：红
#define FG_GREEN CSI "32m"    // 前景色：绿
#define FG_YELLOW CSI "33m"   // 前景色：黄
#define FG_BLUE CSI "34m"     // 前景色：蓝
#define FG_MAGENTA CSI "35m"  // 前景色：洋红 / 品红
#define FG_CYAN CSI "36m"     // 前景色：青
#define FG_WHITE CSI "37m"    // 前景色：白

#define FG_BRIGHT_BLACK CSI "90m"    // 前景色：亮黑（灰）
#define FG_BRIGHT_RED CSI "91m"      // 前景色：亮红
#define FG_BRIGHT_GREEN CSI "92m"    // 前景色：亮绿
#define FG_BRIGHT_YELLOW CSI "93m"   // 前景色：亮黄
#define FG_BRIGHT_BLUE CSI "94m"     // 前景色：亮蓝
#define FG_BRIGHT_MAGENTA CSI "95m"  // 前景色：亮洋红
#define FG_BRIGHT_CYAN CSI "96m"     // 前景色：亮青
#define FG_BRIGHT_WHITE CSI "97m"    // 前景色：亮白

// ========== 背景色 ==========

#define BG_BLACK CSI "40m"    // 背景色：黑
#define BG_RED CSI "41m"      // 背景色：红
#define BG_GREEN CSI "42m"    // 背景色：绿
#define BG_YELLOW CSI "43m"   // 背景色：黄
#define BG_BLUE CSI "44m"     // 背景色：蓝
#define BG_MAGENTA CSI "45m"  // 背景色：洋红
#define BG_CYAN CSI "46m"     // 背景色：青
#define BG_WHITE CSI "47m"    // 背景色：白

#define BG_BRIGHT_BLACK CSI "100m"    // 背景色：亮黑（灰）
#define BG_BRIGHT_RED CSI "101m"      // 背景色：亮红
#define BG_BRIGHT_GREEN CSI "102m"    // 背景色：亮绿
#define BG_BRIGHT_YELLOW CSI "103m"   // 背景色：亮黄
#define BG_BRIGHT_BLUE CSI "104m"     // 背景色：亮蓝
#define BG_BRIGHT_MAGENTA CSI "105m"  // 背景色：亮洋红
#define BG_BRIGHT_CYAN CSI "106m"     // 背景色：亮青
#define BG_BRIGHT_WHITE CSI "107m"    // 背景色：亮白

// ========== 文本样式 ==========

#define STYLE_RESET CSI "0m"      // 重置样式（同 RESET）
#define STYLE_BOLD CSI "1m"       // 加粗
#define STYLE_DIM CSI "2m"        // 变暗 / 低亮度
#define STYLE_ITALIC CSI "3m"     // 斜体（部分终端不支持）
#define STYLE_UNDERLINE CSI "4m"  // 下划线
#define STYLE_BLINK CSI "5m"      // 闪烁（Windows 多数终端不支持）
#define STYLE_REVERSE CSI "7m"    // 反色（前景与背景交换）
#define STYLE_HIDDEN CSI "8m"     // 隐藏文本（依然可复制，但不可见）

// ========== 函数接口（放进 namespace） ==========

// namespace ui {

// void showMainMenu();
// void showExitMenu();

//} // namespace ui

// UI 对象创建（返回堆对象，需要配套销毁）
uiText* uiTextCreat(void);

// 字符串复制（返回新堆内存，需外部 free）
char* uiTextStrCopy(const char* text);

// UI 文本输出（带颜色、样式控制）
void showUiText(const uiText* uiTextContents, const char* textColor, const char* textStyles);

// 释放uiText子内容及其指针
void uiTextFree(uiText* uitext);

// ======结构体======
// ui文本框结构体
typedef struct uiText {
    char* text;
    char* color;
    char* style;
    int   state;  // 被选中的状态，0表示未被选中，1表示选中
} uiText;
