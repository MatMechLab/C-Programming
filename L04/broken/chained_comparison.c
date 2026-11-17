#include <stdio.h>

/* 有定义的逻辑反例，不能用于判断48到52之间的区间。 */
int main(void)
{
    // [example]
    int value_mm = 90;
    int inside = 48 <= value_mm <= 52;
    printf("错误区间判断：%d\n", inside);
    // [/example]
    return 0;
}
