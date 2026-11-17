#include <stdio.h>

/* 有定义的语法误读反例：else属于内层if，缩进不改变归属。
 * recorded为0时整段不输出，不是输出“记录未完成”。 */
int main(void)
{
    // [example]
    int recorded = 0;
    int value_mm = 50;
    if (recorded == 1)
        if (value_mm >= 48)
            puts("达到下限");
    else
        puts("记录未完成");
    // [/example]
    return 0;
}
