#include "ui.h"

#include <stdio.h>   // printf, fprintf
#include <stdlib.h>  // malloc, free
#include <string.h>  // strlen, strcpy

#include "common_operations.h"

// ui文本框初始化
uiText* uiTextCreat() {
    // 分配结构体内存
    uiText* p = malloc(sizeof(uiText));
    if (p == NULL) {
        printf("创建对象uiText失败：内存分配错误\n");
        return NULL;
    }

    // 初始化指针，防止出现野指针
    p->text  = NULL;
    p->color = NULL;
    p->style = NULL;
    p->state = 0;

    return p;
}

// 释放uiText子内容及其指针
void uiTextFree(uiText* uitext) {
    // 释放子内容
    free(uitext->text);
    free(uitext->color);
    free(uitext->style);
    free(uitext->state);

    // 释放uiText指针
    free(uitext);
}

// 字符串复制函数：负责分配新内存并拷贝内容（可以为 NULL）（需外部 free）
char* uiTextStrCopy(const char* text) {
    // 允许返回 NULL，表示空文本
    if (text == NULL) {
        return NULL;
    }

    // 分配新字符串内存
    char* buf = malloc(strlen(text) + 1);
    if (buf == NULL) {
        return NULL;
    }

    // 复制字符串内容到新空间
    strcpy(buf, text);

    // 返回字符串指针
    return buf;
}

// uitext输出到控制台
// 文本，颜色，样式
void showUiText(const uiText* uiTextContents, const char* textColor, const char* textStyles) {
    // 检查文本情况
    if (!checkUiText(uiTextContents->text))
        return;

    fwrite(textColor, 1, strlen(textColor), stdout);                        // 颜色
    fwrite(textStyles, 1, strlen(textStyles), stdout);                      // 样式
    fwrite(uiTextContents->text, 1, strlen(uiTextContents->text), stdout);  // 内容
    fwrite(RESET, 1, strlen(RESET), stdout);                                // 恢复样式
    fflush(stdout);                                                         // 立即输出
}
