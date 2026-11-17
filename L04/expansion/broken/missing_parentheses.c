#include <stdio.h>

/* 有定义的错误对照：漏括号使“读数偏高”绕过了记录完成检查。
 * 不可作为正确程序；两个十进制整数，各至多四字符。 */
int main(void)
{
    int value_mm = 0, recorded = 0;
    if (scanf("%4d %4d", &value_mm, &recorded) != 2) {
        puts("输入错误");
        return 1;
    }
    if (recorded != 0 && recorded != 1) {
        puts("标记错误");
        return 1;
    }
    // [wrong]
    if (recorded == 1 && value_mm < 48 || value_mm > 52) {
        puts("已记录且超出内部范围");
    }
    // [/wrong]
    return 0;
}
