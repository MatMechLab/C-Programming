#include <stdio.h>

// [prototypes]
double mean_temperature(int sum_c, int count);
double to_fahrenheit(double c);
double mean_fahrenheit(int sum_c, int count);
// [/prototypes]

int main(void)
{
    // [main_call]
    double mean_f = mean_fahrenheit(87, 5);
    printf("分步调用：%.2f ℉\n", mean_f);
    // [/main_call]
    // [nested_call]
    double nested_f = to_fahrenheit(mean_temperature(87, 5));
    printf("嵌套调用：%.2f ℉\n", nested_f);
    // [/nested_call]
    return 0;
}

// count 为 1～6；sum_c 是同一批有效整数温度的总和。
// 每个有效温度在 -20～50 ℃ 之间。
// [mean]
double mean_temperature(int sum_c, int count)
{
    return (double)sum_c / count;
}
// [/mean]

// [conversion]
double to_fahrenheit(double c)
{
    return c * 9.0 / 5.0 + 32.0;
}
// [/conversion]

// count 与 sum_c 的前提同 mean_temperature。
// [mean_fahrenheit]
double mean_fahrenheit(int sum_c, int count)
{
    double mean_c = mean_temperature(sum_c, count);
    double mean_f = to_fahrenheit(mean_c);
    return mean_f;
}
// [/mean_fahrenheit]
