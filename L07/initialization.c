#include <stdio.h>

int main(void)
{
    // [declarations]
    int full[4] = {49, 52, 47, 50};
    int partial[4] = {49, 52};
    int zero[4] = {0};
    int inferred[] = {49, 52, 47};
    // [/declarations]

    // [initialized_values]
    for (int i = 0; i < 4; ++i) {
        printf("下标%d：full=%d，partial=%d，zero=%d\n",
               i, full[i], partial[i], zero[i]);
    }
    // [/initialized_values]

    // [inferred_capacity]
    printf("inferred的元素个数：%zu\n",
           sizeof inferred / sizeof inferred[0]);
    // [/inferred_capacity]

    // [capacity]
    int reading[8] = {49, 52, 47};
    int n = 3;
    printf("容量：%zu，已保存：%d\n",
           sizeof reading / sizeof reading[0], n);
    // [/capacity]
    return 0;
}
