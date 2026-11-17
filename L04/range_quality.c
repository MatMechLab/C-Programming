#include <stdio.h>

/* 教学约定：输入一个十进制整数，至多四字符（含符号）。
 * %4d 限制单次转换宽度，不验证完整数字文本或整行。
 * 以下毫米范围是课堂虚构规则，不是实际测量标准。 */
int main(void)
{
    // [input]
    int value_mm = 0;
    puts("请输入整数毫米读数：");
    if (scanf("%4d", &value_mm) != 1) {
        puts("输入错误：未读到整数。");
        return 1;
    }
    // [/input]

    // [classify]
    if (value_mm < 40 || value_mm > 60) {
        puts("质量：无效");
    } else if (value_mm >= 48 && value_mm <= 52) {
        puts("质量：有效");
    } else {
        puts("质量：需复查");
    }
    // [/classify]
    return 0;
}
