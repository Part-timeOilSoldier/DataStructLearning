#include <stdio.h>
#include <string.h>

#include "ui.h"

int main(void) {  // 或者 int main(int argc, char* argv[])
    const char* msg = STYLE_BLINK FG_RED "警告：系统异常！" RESET "\n";
    fwrite(msg, 1, strlen(msg), stdout);
    fflush(stdout);  // 确保立刻输出到终端

    printf("按回车键退出程序...\n");
    getchar();  // 等待输入，窗口不会马上关
    return 0;
}
