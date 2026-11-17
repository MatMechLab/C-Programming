#include <stdio.h>

// [prototypes]
double mean_temperature(int sum_c, int count);
int in_closed_range(int value, int low, int high);
// [/prototypes]

int main(void)
{
    // [call]
    double mean_c = mean_temperature(87, 5);
    printf("平均温度：%.2f ℃\n", mean_c);
    int below = in_closed_range(47, 48, 52);
    int low = in_closed_range(48, 48, 52);
    int high = in_closed_range(52, 48, 52);
    int above = in_closed_range(53, 48, 52);
    printf("范围判断：%d %d %d %d\n", below, low, high, above);
    // [/call]
    return 0;
}

// 前提：1 <= count <= 6；sum_c 是这些有效整数温度的总和。
// 每个有效温度在 -20～50 ℃ 之间，故 -20*count <= sum_c <= 50*count。
// [mean]
double mean_temperature(int sum_c, int count)
{
    return (double)sum_c / count;
}
// [/mean]

// 前提：low <= high。闭区间包含左右端点。
// [range]
int in_closed_range(int value, int low, int high)
{
    return value >= low && value <= high;
}
// [/range]
