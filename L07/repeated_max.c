#include <stdio.h>

int main(void)
{
    int reading[8] = {49, 54, 47, 54, 50, 54, 48, 51};
    int n = 8;

    // [first_max]
    int first = 0;
    for (int i = 1; i < n; ++i) {
        if (reading[i] > reading[first]) {
            first = i;
        }
    }
    // [/first_max]

    // [last_max]
    int last = 0;
    for (int i = 1; i < n; ++i) {
        if (reading[i] >= reading[last]) {
            last = i;
        }
    }
    // [/last_max]

    printf("最大值：%d\n", reading[first]);
    printf("首次下标：%d\n", first);
    printf("末次下标：%d\n", last);
    // [all_max]
    printf("全部最大值下标：");
    for (int i = 0; i < n; ++i) {
        if (reading[i] == reading[first]) {
            printf(" %d", i);
        }
    }
    printf("\n");
    // [/all_max]
    return 0;
}
