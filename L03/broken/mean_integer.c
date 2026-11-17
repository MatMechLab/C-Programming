#include <stdio.h>

/* 逻辑错误例：运算有定义，可运行观察；不能作为正确答案。 */
int main(void)
{
    int sum_mm = 10 + 11 + 13;
    double mean_mm = sum_mm / 3;
    printf("incorrect mean = %.3f mm\n", mean_mm);
    return 0;
}
