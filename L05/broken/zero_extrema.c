#include <stdio.h>

/* 故意错误：正温度18、21、20的最小值应为18，不能用0冒充数据。 */
int main(void)
{
    // [example]
    int min_c = 0;
    int first_c = 18, second_c = 21, third_c = 20;
    if (first_c < min_c) { min_c = first_c; }
    if (second_c < min_c) { min_c = second_c; }
    if (third_c < min_c) { min_c = third_c; }
    printf("错误的最低值：%d ℃\n", min_c);
    // [/example]
    return 0;
}
