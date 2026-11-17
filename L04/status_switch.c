#include <stdio.h>

/* 只把一个整数状态码解释为文字，不操作任何设备。
 * 受控课堂输入：一个十进制整数，至多四字符（含符号）。 */
int main(void)
{
    int status = 0;
    puts("请输入状态码（0或1）：");
    if (scanf("%4d", &status) != 1) {
        puts("输入错误：未读到整数。");
        return 1;
    }

    // [switch]
    switch (status) {
    case 0:
        puts("尚未记录");
        break;
    case 1:
        puts("已经记录");
        break;
    default:
        puts("未知状态");
        break;
    }
    // [/switch]
    // [after]
    puts("状态说明结束");
    // [/after]
    return 0;
}
