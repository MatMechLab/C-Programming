#include <stdio.h>

int main(void)
{
    // [loop]
    int i = 0;
    while (i < 3) {
        printf("第%d次记录\n", i + 1);
        i++;
    }
    // [/loop]
    // [after]
    printf("循环后 i = %d\n", i);
    // [/after]
    return 0;
}
