#include <stdio.h>

double to_fahrenheit(double c);
int remaining_to_upper(int temp_c);
int whole_degrees(double c);

int main(void)
{
    // [parameter_conversion]
    int whole_c = 18;
    double precise_c = 18.75;
    double temp_f = to_fahrenheit(whole_c);
    int remaining = remaining_to_upper(precise_c);
    printf("18换算后：%.2f ℉\n", temp_f);
    printf("整数接口余量：%d ℃\n", remaining);
    printf("原变量：%.2f ℃\n", precise_c);
    // [/parameter_conversion]
    // [return_calls]
    int positive = whole_degrees(18.75);
    int negative = whole_degrees(-18.75);
    printf("返回int：%d %d\n", positive, negative);
    // [/return_calls]
    return 0;
}

// 本例只传入 -20～50 ℃ 的有限温度。
// [conversion]
double to_fahrenheit(double c)
{
    return c * 9.0 / 5.0 + 32.0;
}
// [/conversion]

// 接口约定按整数摄氏度计算；temp_c 在 -20～50 之间。
// [remaining]
int remaining_to_upper(int temp_c)
{
    return 50 - temp_c;
}
// [/remaining]

// 本例的有限 c 在 -20～50 之间，整数部分可由 int 表示。
// 返回值转换丢弃小数部分，不是四舍五入。
// [return_conversion]
int whole_degrees(double c)
{
    return c;
}
// [/return_conversion]
