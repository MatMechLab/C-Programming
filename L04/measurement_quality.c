#include <stdio.h>

/* 学生练习的参考解答。
 * 输入：空白分隔的两个十进制整数，每项至多四字符（含符号）。
 * 顺序：毫米读数、记录标记；标记0=未完成，1=已完成。
 * %4d 不验证完整数字文本、分隔符或整行；见 README.md。 */
int main(void)
{
    // [input]
    int value_mm = 0;
    int recorded = 0;
    puts("请输入整数毫米读数和记录标记（0或1）：");
    if (scanf("%4d %4d", &value_mm, &recorded) != 2) {
        puts("输入错误：需要两个整数。");
        return 1;
    }
    // [/input]

    // [flag_check]
    if (recorded != 0 && recorded != 1) {
        puts("标记错误：只能是0或1。");
        return 1;
    }
    // [/flag_check]

    // [classify]
    if (recorded == 0 || value_mm < 40 || value_mm > 60) {
        puts("质量：无效");
    } else if (value_mm >= 48 && value_mm <= 52) {
        puts("质量：有效");
    } else {
        puts("质量：需复查");
    }
    // [/classify]
    return 0;
}
