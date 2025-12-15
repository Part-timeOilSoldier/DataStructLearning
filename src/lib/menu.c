#include "menu.h"

#include <stdio.h>
#include <string.h>

#include "common_operations.h"
#include "ui.h"

// 初始化一个菜单，返回操作菜单的指针
menuUi* menuInit(void) {
    menuUi* menu = malloc(sizeof(menuUi));
    if (!menu) {
        printf("[menuInit] menuUi 结构体分配失败！\n");
        return NULL;
    }

    // 先全部置空，防止释放时出错
    menu->title         = NULL;
    menu->options       = NULL;
    menu->optionCount   = 0;
    menu->previousLevel = NULL;

    // 若任何一个失败 → 统一释放并返回 NULL
    if (!menu->title || !menu->options || !menu->previousLevel) {
        printf("[menuInit] 菜单文本框创建失败，初始化中止\n");
        menuFree(menu);  // 创建失败释放内存
        return NULL;
    }

    // 返回课操作的指针
    return menu;
}

// 释放菜单
void menuFree(menuUi* menu) {
    if (menu == NULL)
        return;  // 如果传入空指针直接返回

    if (menu->title)
        free(menu->title);

    for (int i = 0; i < menu->optionCount; i++) {
        if (menu->options[i]) {
            free(menu->options[i]->text);
            free(menu->options[i]);
        }
    }
    free(menu->options);

    if (menu->previousLevel) {
        free(menu->previousLevel->text);
        free(menu->previousLevel);
    }

    // 释放菜单结构体
    free(menu);
}

// 设置菜单标题内容
void menuSetTitleContents(menuUi* menu, char* content) {
    if (content == NULL) {
        return;
    }
    contentsCopy(content, menu->title);
}

// 设置菜单选项
void menuSetOptionsContents(menuUi* menu, char* content) {
    // 如果无内容则返回
    if (content == NULL) {
        return;
    }

    uiText* uiitem = uiTextCreat();        // 创建一个新text文本框
    contentsCopy(content, &uiitem->text);  // 复制文本到菜单选项中

    // c语言规定：ptr + i  ≡  (char*)ptr + i * sizeof(*ptr)
    uiText** tmp = realloc(menu->options, sizeof(uiText*) * (menu->optionCount + 1));

    // 如果获取失败则释放初始化的uiText*指针及其子内容
    // 因此这里引入中间指针tmp是为了安全考量
    if (!tmp) {
        uiTextFree(uiitem);
        return;
    }

    menu->options                    = tmp;
    menu->options[menu->optionCount] = uiitem;
    menu->optionCount++;
}
