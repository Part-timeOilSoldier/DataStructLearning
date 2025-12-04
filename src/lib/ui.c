#include <stdio.h>      // printf, fprintf
#include <stdlib.h>     // malloc, free
#include <string.h>     // strlen, strcpy

//ui文本框结构体
typedef struct uiText{
    char *text;
    
} uiText ;

//ui文本框初始化
uiText *uiTextCreat(char *text){

    //分配结构体内存
    uiText *p=malloc(sizeof(uiText));
    if(p==NULL){
        printf("创建对象uiText失败：内存分配错误\n");
        return NULL;
    }

    
}
