#include <stdio.h>

int main(void)
{
    // [copy]
    int original[4] = {49, 52, 47, 50};
    int copied[4];
    for (int i = 0; i < 4; ++i) {
        copied[i] = original[i];
    }
    // [/copy]

    // [independent_change]
    copied[1] = 60;
    printf("original[1]=%d\n", original[1]);
    printf("copied[1]=%d\n", copied[1]);
    // [/independent_change]
    return 0;
}
