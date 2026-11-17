#include <stdio.h>

/* 逻辑错误例：缺少需要的括号；运算有定义，可运行观察。 */
int main(void)
{
    int first_mm = 10;
    int second_mm = 11;
    int third_mm = 13;
    double mean_mm = first_mm + second_mm + third_mm / 3.0;
    printf("incorrect grouped mean = %.3f mm\n", mean_mm);
    return 0;
}
