#include <stdio.h>

/* 课堂虚构计费：前10页每页2角，超出部分每页1角；仅限0～1000页。
 * 一个十进制整数，至多四字符（含符号）；%4d不验证整行。 */
int main(void)
{
    int pages = 0;
    puts("请输入打印页数（0到1000）：");
    if (scanf("%4d", &pages) != 1) {
        puts("输入错误");
        return 1;
    }
    if (pages < 0 || pages > 1000) {
        puts("页数超出范围");
        return 1;
    }
    // [fee]
    int fee_jiao = 0;
    if (pages <= 10) {
        fee_jiao = pages * 2;
    } else {
        fee_jiao = 20 + (pages - 10);
    }
    printf("总费用：%d角\n", fee_jiao);
    // [/fee]
    return 0;
}
