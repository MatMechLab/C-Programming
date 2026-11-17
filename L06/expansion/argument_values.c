#include <stdio.h>

// 本例传给换算函数的温度均在 -20～50 ℃ 之间。
// 原型中的形参名与定义中的形参名可以不同。
// [prototype]
double to_fahrenheit(double input_c);
// [/prototype]

int main(void)
{
    // [names_call]
    double temp_c = 18.0;
    double temp_f = to_fahrenheit(temp_c);
    printf("直接换算：%.2f ℉\n", temp_f);
    // [/names_call]
    // [expression]
    double warmer_f = to_fahrenheit(temp_c + 2.0);
    printf("加2后换算：%.2f ℉\n", warmer_f);
    printf("原变量：%.2f ℃\n", temp_c);
    // [/expression]
    // [result_expression]
    double difference_f = to_fahrenheit(temp_c) - 32.0;
    printf("与32 ℉的差：%.2f ℉\n", difference_f);
    // [/result_expression]
    return 0;
}

// [definition]
double to_fahrenheit(double c)
{
    return c * 9.0 / 5.0 + 32.0;
}
// [/definition]
