#include <stdio.h>

int main(void)
{
    // [capacity_length]
    int reading[8] = {49, 0, 47};
    int n = 3;
    int value = 50;
    printf("追加前：容量8，已有%d项\n", n);
    // [/capacity_length]

    // [append]
    if (n < 8) {
        reading[n] = value;
        ++n;
    } else {
        printf("没有空位\n");
    }
    // [/append]

    // [show_valid]
    printf("追加后：已有%d项\n", n);
    for (int i = 0; i < n; ++i) {
        printf("下标%d：%d\n", i, reading[i]);
    }
    // [/show_valid]
    return 0;
}
