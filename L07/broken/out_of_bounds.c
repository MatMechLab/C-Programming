#include <stdio.h>

/* 故意错误：只编译观察；不要运行。最后一次会访问不存在的 reading[4]。 */
int main(void)
{
    // [wrong_bound]
    int reading[4] = {49, 52, 47, 50};
    for (int i = 0; i <= 4; ++i) {
        printf("%d\n", reading[i]);
    }
    // [/wrong_bound]
    return 0;
}
