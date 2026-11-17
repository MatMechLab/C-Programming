#include <stdio.h>

// 固定读取6个整数，每项最多4字符（含符号），以空白分隔。
// %4d 不检查整行是否恰好只含整数；输入须遵守本例约定。
// 有效范围 -20～50 ℃ 是课堂练习约定，不是设备安全阈值。
// [prototypes]
int is_valid_temperature(int temp_c);
double mean_temperature(int sum_c, int count);
double to_fahrenheit(double c);
// [/prototypes]

int main(void)
{
    // [init]
    int valid_count = 0;
    int invalid_count = 0;
    int sum_c = 0;
    int min_c = 0;
    int max_c = 0;
    // [/init]
    puts("请输入6个整数温度（℃）：");
    for (int i = 0; i < 6; i++) {
        // [read]
        int temp_c;
        if (scanf("%4d", &temp_c) != 1) {
            puts("输入错误：需要整数温度。");
            return 1;
        }
        if (!is_valid_temperature(temp_c)) {
            invalid_count++;
            continue;
        }
        // [/read]
        // [first_valid]
        if (valid_count == 0) {
            min_c = temp_c;
            max_c = temp_c;
        }
        // [/first_valid]
        // [update]
        if (temp_c < min_c) {
            min_c = temp_c;
        }
        if (temp_c > max_c) {
            max_c = temp_c;
        }
        sum_c += temp_c;
        valid_count++;
        // [/update]
    }
    // [counts]
    printf("有效：%d，无效：%d\n", valid_count, invalid_count);
    printf("总和：%d ℃\n", sum_c);
    if (valid_count == 0) {
        puts("没有有效温度，平均值和极值不计算。");
    } else {
        // [/counts]
        // [mean_report]
        double mean_c = mean_temperature(sum_c, valid_count);
        double mean_f = to_fahrenheit(mean_c);
        printf("最低值：%d ℃\n", min_c);
        printf("最高值：%d ℃\n", max_c);
        printf("平均值：%.2f ℃\n", mean_c);
        printf("华氏平均值：%.2f ℉\n", mean_f);
    }
    // [/mean_report]
    return 0;
}

// [validity]
int is_valid_temperature(int temp_c)
{
    return temp_c >= -20 && temp_c <= 50;
}
// [/validity]

// count 为 1～6；sum_c 为这些有效整数温度的总和。
// [mean]
double mean_temperature(int sum_c, int count)
{
    return (double)sum_c / count;
}
// [/mean]

// c 为 -20～50 ℃ 范围内的有限温度。
// [conversion]
double to_fahrenheit(double c)
{
    return c * 9.0 / 5.0 + 32.0;
}
// [/conversion]
