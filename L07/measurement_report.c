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

    // [start_statistics]
    int sum = 0;
    int minimum = reading[0];
    int maximum = reading[0];
    int min_index = 0;
    int max_index = 0;
    // [/start_statistics]

    // [sum_min]
    for (int i = 0; i < n; ++i) {
        sum += reading[i];
        if (reading[i] < minimum) {
            minimum = reading[i];
            min_index = i;
        }
    // [/sum_min]
        // [max]
        if (reading[i] > maximum) {
            maximum = reading[i];
            max_index = i;
        }
    }
    // [/max]

    // [mean_summary]
    double mean = (double)sum / n;
    printf("数据个数：%d\n", n);
    printf("总和：%d\n", sum);
    printf("平均值：%.2f\n", mean);
    printf("最小值：%d，下标%d，第%d项\n",
           minimum, min_index, min_index + 1);
    printf("最大值：%d，下标%d，第%d项\n",
           maximum, max_index, max_index + 1);
    // [/mean_summary]

    // [review_values]
    int review_count = 0;
    for (int i = 0; i < n; ++i) {
        if (reading[i] < 48 || reading[i] > 52) {
            printf("待复查：下标%d，第%d项，数值%d\n",
                   i, i + 1, reading[i]);
            ++review_count;
        }
    }
    printf("待复查项数：%d\n", review_count);
    // [/review_values]

    // [reverse]
    printf("反向序列：");
    for (int i = n - 1; i >= 0; --i) {
        printf(" %d", reading[i]);
    }
    printf("\n");
    // [/reverse]
    return 0;
}
