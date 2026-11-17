#include <math.h>
#include <stdio.h>

/* 有定义的逻辑错误：固定小整数，允许运行对照；不是正确解答。 */
int main(void)
{
    // [calculate]
    int first_mm = 17;
    int second_mm = 18;
    int third_mm = 20;
    int reference_mm = 20;
    int sum_mm = first_mm + second_mm + third_mm;
    double mean_mm = sum_mm / 3;
    double absolute_error_mm = fabs(mean_mm - reference_mm);
    // [/calculate]

    // [report]
    printf("sum = %d mm\n", sum_mm);
    printf("mean = %.3f mm\n", mean_mm);
    printf("absolute error = %.3f mm\n", absolute_error_mm);
    // [/report]
    return 0;
}
