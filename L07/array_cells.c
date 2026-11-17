#include <stdio.h>

int main(void)
{
    // [read_cell]
    int reading[4] = {48, 51, 49, 52};
    int saved = reading[1];
    printf("第一项：%d，最后一项：%d\n", reading[0], reading[3]);
    // [/read_cell]

    // [write_cell]
    reading[1] = reading[0] + 2;
    printf("修改后第2项：%d\n", reading[1]);
    printf("先前保存的值：%d\n", saved);
    // [/write_cell]

    // [show_values]
    for (int i = 0; i < 4; ++i) {
        printf("下标%d：%d\n", i, reading[i]);
    }
    // [/show_values]

    // [checked_access]
    int i = 3;
    if (i >= 0 && i < 4) {
        printf("下标%d的值：%d\n", i, reading[i]);
    } else {
        printf("下标无效\n");
    }
    // [/checked_access]
    return 0;
}
