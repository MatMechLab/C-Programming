#include <stdio.h>

/* 有定义的逻辑反例：宽范围抢先，内部有效分支永远到不了。 */
int main(void)
{
    int value_mm = 0;
    if (scanf("%4d", &value_mm) != 1) {
        puts("输入错误：未读到整数。");
        return 1;
    }
    // [example]
    if (value_mm >= 40 && value_mm <= 60) {
        puts("质量：需复查");
    } else if (value_mm >= 48 && value_mm <= 52) {
        puts("质量：有效");
    } else {
        puts("质量：无效");
    }
    // [/example]
    return 0;
}
