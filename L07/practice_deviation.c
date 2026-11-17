#include <stdio.h>

int main(void)
{
    // [read_count]
    int requested;
    printf("请输入数据个数（0~8）：\n");
    if (scanf("%2d", &requested) != 1) {
        printf("个数输入错误\n");
        return 1;
    }
    // [/read_count]

    // [check_count]
    if (requested < 0 || requested > 8) {
        printf("数据个数须在0~8之间\n");
        return 1;
    }
    // [/check_count]

    // [storage]
    int reading[8];
    int n = 0;
    printf("请输入%d个整数读数（-100~100）：\n", requested);
    // [/storage]

    // [read_value]
    for (int i = 0; i < requested; ++i) {
        int value;
        if (scanf("%4d", &value) != 1) {
            printf("第%d项输入错误，本批次停止\n", i + 1);
            return 1;
        }
    // [/read_value]
        // [check_store]
        if (value < -100 || value > 100) {
            printf("第%d项超出-100~100，本批次停止\n", i + 1);
            return 1;
        }
        reading[n] = value;
        ++n;
    }
    // [/check_store]

    // [empty]
    if (n == 0) {
        printf("没有数据\n");
        return 0;
    }
    // [/empty]

    // [mean]
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += reading[i];
    }
    double mean = (double)sum / n;
    // [/mean]

    // [deviations]
    double deviation[8];
    for (int i = 0; i < n; ++i) {
        deviation[i] = reading[i] - mean;
    }
    // [/deviations]

    // [show_deviations]
    printf("平均值：%.2f\n", mean);
    for (int i = 0; i < n; ++i) {
        printf("下标%d：原值%d，偏差%+.2f\n",
               i, reading[i], deviation[i]);
    }
    // [/show_deviations]
    return 0;
}
