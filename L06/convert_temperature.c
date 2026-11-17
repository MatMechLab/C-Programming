#include <stdio.h>

// 本课约定：输入为 -20～50 ℃ 的有限温度。
// [prototype]
double to_fahrenheit(double c);
// [/prototype]

int main(void)
{
    // [call]
    double temp_c = 18.0;
    double temp_f = to_fahrenheit(temp_c);
    printf("华氏温度：%.2f ℉\n", temp_f);
    // [/call]
    return 0;
}

// [definition]
double to_fahrenheit(double c)
{
    return c * 9.0 / 5.0 + 32.0;
}
// [/definition]
