// main_menu_ui.c
#include <stdio.h>   // printf（如果需要额外输出）
#include <stdlib.h>  // malloc, free
#include <string.h>  // strlen（备用）

#include "ui.h"

// 初始化主菜单
void initMainMenu() {}

// 主菜单显示函数
void showMainMenu(void) {
    // ==== 创建 uiText 对象 ====
    uiText* title    = uiTextCreat();
    uiText* subtitle = uiTextCreat();
    uiText* menu     = uiTextCreat();
    uiText* tip      = uiTextCreat();

    // ==== 准备文本内容 ====
    // 标题
    if (setUiText(title,
                  "=======================================\n"
                  "        数据结构与算法演示系统         \n"
                  "=======================================\n") != 0)
        goto cleanup;

    // 子标题
    if (setUiText(subtitle, "请选择要学习 / 操作的模块：\n\n") != 0)
        goto cleanup;

    // 菜单内容
    if (setUiText(menu,
                  "  1. 线性表\n"
                  "  2. 栈（Stack）\n"
                  "  3. 队列（Queue）\n"
                  "  4. 树（Tree）\n"
                  "  5. 图（Graph）\n"
                  "  6. 查找（Searching）\n"
                  "  7. 排序（Sorting）\n"
                  "  0. 退出系统\n\n") != 0)
        goto cleanup;

    // 输入提示
    if (setUiText(tip, "请输入你的选择（0-7）：") != 0)
        goto cleanup;

    // ==== 实际输出 ====
    // 标题：亮青 + 加粗
    showUiText(title, FG_BRIGHT_CYAN, STYLE_BOLD);

    // 子标题：亮白
    showUiText(subtitle, FG_BRIGHT_WHITE, STYLE_RESET);

    // 菜单列表：亮绿
    showUiText(menu, FG_BRIGHT_GREEN, STYLE_RESET);

    // 输入提示：亮黄 + 加粗
    showUiText(tip, FG_BRIGHT_YELLOW, STYLE_BOLD);

cleanup:
    // ==== 释放资源 ====
    if (title) {
        free(title->text);
        free(title);
    }
    if (subtitle) {
        free(subtitle->text);
        free(subtitle);
    }
    if (menu) {
        free(menu->text);
        free(menu);
    }
    if (tip) {
        free(tip->text);
        free(tip);
    }
}

// 退出界面
void showExitMenu(void) {
    uiText* bye = uiTextCreat();
    if (!bye) {
        printf("创建 uiText 对象失败，无法显示退出信息\n");
        return;
    }

    if (setUiText(bye,
                  "\n=======================================\n"
                  "  感谢使用本数据结构与算法演示系统！  \n"
                  "            再见，再会~               \n"
                  "=======================================\n") != 0) {
        free(bye);
        return;
    }

    // 使用亮洋红 + 加粗显示退出信息
    showUiText(bye, FG_BRIGHT_MAGENTA, STYLE_BOLD);

    free(bye->text);
    free(bye);
}
