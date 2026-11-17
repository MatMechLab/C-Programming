#include <stdio.h>

int main(void)
{
    // [stepped_loop]
    for (int i = 1; i < 8; i += 2) {
        printf("处理编号 %d\n", i);
    }
    // [/stepped_loop]
    return 0;
}
