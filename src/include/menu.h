#pragma once

#include "ui.h"

// ========== 菜单 UI 结构体 ==========
// 约定：所有 uiText* 都在初始化函数中分配，在释放函数中统一释放
typedef struct menuUi {
    char*    title;          // 标题
    uiText** options;        // 选项数组（多个 uiText*）
    int      optionCount;    // 选项数量
    uiText*  previousLevel;  // 上一级菜单
} menuUi;

// ========== 菜单相关函数接口 ==========

// 菜单初始化：
// 为 menu 结构体中的各 uiText* 分配内存
menuUi* menuInit();

// 菜单创建：
// 为菜单填入内容
void menuCreate(char* menuContents);

// 菜单显示：
// 按一定格式（例如标题高亮、选项绿色、提示黄色等）输出到控制台
// 具体颜色样式由实现函数内部决定
void menuShow(const menuUi* menu);

// 菜单刷新：
// 当菜单内容（选项、状态提示等）发生变化时重新输出，或者重绘界面
// 一般可以简单地清屏 + 再调用 menuShow，具体实现由你决定
int menuRefresh(menuUi* menu);

// 菜单释放：
// 释放 menu 结构体中所有 uiText* 及其内部 text 字符串
// 注意：如果 menuUi 本身是动态分配的（malloc），需要在外部再 free(menu)
void menuFree(menuUi* menu);

// 设置菜单标题内容
void menuSetTitleContents(menuUi* menu, char* content);