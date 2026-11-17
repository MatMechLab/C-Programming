#include <stdio.h>

/* 比较三种有定义的计算；只有c在除法前把操作数转成double。 */
int main(void)
{
    // [comparison]
    int sum_c = 87;
    int valid_count = 5;
    double a = sum_c / valid_count;
    double b = (double)(sum_c / valid_count);
    double c = (double)sum_c / valid_count;
    // [/comparison]
    printf("a=%.2f\n", a);
    printf("b=%.2f\n", b);
    printf("c=%.2f\n", c);
    return 0;
}
