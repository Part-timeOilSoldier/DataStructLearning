#pragma once

// ========== 基础控制 ==========

#define CSI         "\033["       // 控制序列前缀
#define RESET       CSI "0m"      // 重置所有样式

// ========== 前景色 ==========

#define FG_BLACK    CSI "30m"
#define FG_RED      CSI "31m"
#define FG_GREEN    CSI "32m"
#define FG_YELLOW   CSI "33m"
#define FG_BLUE     CSI "34m"
#define FG_MAGENTA  CSI "35m"
#define FG_CYAN     CSI "36m"
#define FG_WHITE    CSI "37m"

#define FG_BRIGHT_BLACK    CSI "90m"
#define FG_BRIGHT_RED      CSI "91m"
#define FG_BRIGHT_GREEN    CSI "92m"
#define FG_BRIGHT_YELLOW   CSI "93m"
#define FG_BRIGHT_BLUE     CSI "94m"
#define FG_BRIGHT_MAGENTA  CSI "95m"
#define FG_BRIGHT_CYAN     CSI "96m"
#define FG_BRIGHT_WHITE    CSI "97m"

// ========== 背景色 ==========

#define BG_BLACK    CSI "40m"
#define BG_RED      CSI "41m"
#define BG_GREEN    CSI "42m"
#define BG_YELLOW   CSI "43m"
#define BG_BLUE     CSI "44m"
#define BG_MAGENTA  CSI "45m"
#define BG_CYAN     CSI "46m"
#define BG_WHITE    CSI "47m"

#define BG_BRIGHT_BLACK    CSI "100m"
#define BG_BRIGHT_RED      CSI "101m"
#define BG_BRIGHT_GREEN    CSI "102m"
#define BG_BRIGHT_YELLOW   CSI "103m"
#define BG_BRIGHT_BLUE     CSI "104m"
#define BG_BRIGHT_MAGENTA  CSI "105m"
#define BG_BRIGHT_CYAN     CSI "106m"
#define BG_BRIGHT_WHITE    CSI "107m"

// ========== 文本样式 ==========

#define STYLE_RESET     CSI "0m"
#define STYLE_BOLD      CSI "1m"
#define STYLE_DIM       CSI "2m"
#define STYLE_ITALIC    CSI "3m"
#define STYLE_UNDERLINE CSI "4m"
#define STYLE_BLINK     CSI "5m"
#define STYLE_REVERSE   CSI "7m"
#define STYLE_HIDDEN    CSI "8m"

// ========== 函数接口（放进 namespace） ==========

namespace ui {

void showMainMenu();
void showExitMenu();

} // namespace ui
