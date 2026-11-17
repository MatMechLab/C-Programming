#include <stdio.h>

/* 有定义的逻辑错误：本式不是 n *= a + b 的等价改写，可运行作对照。 */
int main(void)
{
    // [calculate]
    int n = 4;
    int a = 2;
    int b = 3;
    n = n * a + b;
    // [/calculate]

    // [report]
    printf("mistaken n = %d\n", n);
    // [/report]
    return 0;
}
