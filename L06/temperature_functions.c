#include <stdio.h>

// 输入约定：一个十进制整数，最多4个字符（含可选正负号）。
// %4d 限制本次转换读取的字符数，不证明整行没有其他字符。
// 有效整数温度为 -20～50 ℃；分类只是课堂约定，不是安全阈值。
// [prototypes]
double to_fahrenheit(double c);
int is_valid_temperature(int temp_c);
int temperature_band(int temp_c);
// [/prototypes]

int main(void)
{
    // [read]
    int temp_c;
    puts("请输入一个整数温度（℃）：");
    if (scanf("%4d", &temp_c) != 1) {
        puts("输入错误");
        return 1;
    }
    // [/read]
    // [check]
    if (!is_valid_temperature(temp_c)) {
        puts("温度无效");
        return 0;
    }
    // [/check]
    // [report]
    double temp_f = to_fahrenheit(temp_c);
    int band = temperature_band(temp_c);
    printf("摄氏温度：%d ℃\n", temp_c);
    printf("华氏温度：%.2f ℉\n", temp_f);
    printf("分类代码：%d\n", band);
    // [/report]
    return 0;
}

// 前提：本课有限温度在 -20～50 ℃ 之间。
// [conversion]
double to_fahrenheit(double c)
{
    return c * 9.0 / 5.0 + 32.0;
}
// [/conversion]

// [validity]
int is_valid_temperature(int temp_c)
{
    return temp_c >= -20 && temp_c <= 50;
}
// [/validity]

// 前提：temp_c 已通过有效性判断。
// [classification]
int temperature_band(int temp_c)
{
    if (temp_c < 10) {
        return 0;
    }
    if (temp_c <= 30) {
        return 1;
    }
    return 2;
}
// [/classification]
