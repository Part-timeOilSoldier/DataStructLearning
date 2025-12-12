#include "common_operations.h"

#include <stdio.h>
#include <string.h>

#include "ui.h"

// 字符串检查
// 检查内容：1.指针是否为空；2.内容是否为空，即仅包含换行；3.字符串长度是否超限（999）
int checkUiText(const char* str) {
    const char* msg = NULL;

    // ====== 检查过程 ======
    if (str == NULL) {
        msg = "错误：指针为NULL\n";
    } else if (str[0] == '\0') {
        msg = "错误：内容为空\n";
    } else if (strlen(str) > UI_TEXT_MAX) {
        msg = "错误：内容超限（999字符）\n";
    } else {
        return 0;  // 正常：不输出、不返回任何状态，直接结束
    }

    // ====== 出错打印 ======
    fwrite(STYLE_BOLD, 1, strlen(STYLE_BOLD), stdout);  // 加粗
    fwrite(FG_RED, 1, strlen(FG_RED), stdout);          // 红色
    fwrite(msg, 1, strlen(msg), stdout);                // 错误内容
    fwrite(RESET, 1, strlen(RESET), stdout);            // 恢复样式
    fflush(stdout);                                     // 立即输出
    return 1;
}

// 字符串复制函数：负责分配新内存并拷贝内容（可以为 NULL）（需外部 free）
void contentsCopy(const char* original, char* waiting) {
    // 允许返回 NULL，表示空文本
    if (original == NULL) {
        return NULL;
    }

    // 复制字符串内容到新空间
    strcpy(waiting, original);
}
