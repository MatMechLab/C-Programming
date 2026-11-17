#include <stdio.h>

/* 受控输入：两个十进制整数，各至多四字符（含符号）。
 * 故意允许任意可读标记，以展示“0/1是否合法”的判断结果。 */
int main(void)
{
    int value_mm = 0, recorded = 0;
    if (scanf("%4d %4d", &value_mm, &recorded) != 2) {
        puts("输入错误");
        return 1;
    }
    // [named]
    int inside_core = value_mm >= 48 && value_mm <= 52;
    int completed = recorded == 1;
    int ready = completed && inside_core;
    printf("区间内：%d\n", inside_core);
    printf("记录完成：%d\n", completed);
    printf("两项都满足：%d\n", ready);
    // [/named]
    // [negate]
    int outside_core = !(value_mm >= 48 && value_mm <= 52);
    int outside_direct = value_mm < 48 || value_mm > 52;
    printf("取反与直接判断：%d %d\n", outside_core, outside_direct);
    // [/negate]
    // [flag]
    int legal = recorded == 0 || recorded == 1;
    int illegal = recorded != 0 && recorded != 1;
    printf("标记合法与非法：%d %d\n", legal, illegal);
    // [/flag]
    return 0;
}
