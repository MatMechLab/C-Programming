#include <stdio.h>

/* 两个离散状态可以共用一段处理。输入约定同 status_switch.c。 */
int main(void)
{
    int status = 0;
    if (scanf("%4d", &status) != 1) {
        puts("输入错误：未读到整数。");
        return 1;
    }
    // [switch]
    switch (status) {
    case 0:
    case 2:
        puts("请补充记录");
        break;
    case 1:
        puts("可以查看记录");
        break;
    default:
        puts("未知状态");
        break;
    }
    // [/switch]
    return 0;
}
