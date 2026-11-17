#include <stdio.h>

/* 有定义的逻辑反例：if后的分号是空语句；后面的块总会执行。 */
int main(void)
{
    // [example]
    int value_mm = 50;
    if (value_mm < 48);
    {
        puts("低于下限");
    }
    // [/example]
    return 0;
}
