#include <stdio.h>

/* 故意错误：需要6次，却把终止边界写成了 <= 6。 */
int main(void)
{
    // [loop]
    for (int i = 0; i <= 6; i++) {
        printf("第%d次记录\n", i + 1);
    }
    // [/loop]
    return 0;
}
