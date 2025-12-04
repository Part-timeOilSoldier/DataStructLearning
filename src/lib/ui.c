#include <stdio.h>   // printf, fprintf
#include <stdlib.h>  // malloc, free
#include <string.h>  // strlen, strcpy

// ui文本框结构体
typedef struct uiText {
    char* text;
} uiText;

// ui文本框初始化
uiText* uiTextCreat() {
    // 分配结构体内存
    uiText* p = malloc(sizeof(uiText));
    if (p == NULL) {
        printf("创建对象uiText失败：内存分配错误\n");
        return NULL;
    }

    // 初始化指针，防止出现野指针
    p->text = NULL;

    return p;
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
// void showUiText(uiText){

//}
