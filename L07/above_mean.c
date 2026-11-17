#include <stdio.h>

int main(void)
{
    int reading[8] = {49, 52, 47, 50, 54, 48, 51, 53};
    int n = 8;

    // [mean]
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += reading[i];
    }
    double mean = (double)sum / n;
    // [/mean]

    // [above_mean]
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (reading[i] > mean) {
            ++count;
        }
    }
    // [/above_mean]
    printf("平均值：%.2f\n", mean);
    printf("大于平均值：%d项\n", count);
    return 0;
}
