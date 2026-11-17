#include <stdio.h>

/* 有定义的逻辑反例：要求只给一个结论，却把互斥分类写成两个if。 */
int main(void)
{
    // [example]
    int value_mm = 47;
    if (value_mm < 48) {
        puts("偏低");
    }
    if (value_mm <= 52) {
        puts("范围内");
    } else {
        puts("偏高");
    }
    // [/example]
    return 0;
}
