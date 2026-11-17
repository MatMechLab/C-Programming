#include <stdio.h>

int main(void)
{
    int reading[4] = {49, 52, 47, 50};
    int n = 4;

    // [forward]
    printf("正向：");
    for (int i = 0; i < n; ++i) {
        printf(" %d", reading[i]);
    }
    printf("\n");
    // [/forward]

    // [reverse]
    printf("反向：");
    for (int i = n - 1; i >= 0; --i) {
        printf(" %d", reading[i]);
    }
    printf("\n");
    // [/reverse]
    return 0;
}
