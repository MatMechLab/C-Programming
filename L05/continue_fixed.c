#include <stdio.h>

/* 跳过编号2，for 的更新仍会在 continue 之后执行。 */
int main(void)
{
    // [loop]
    for (int i = 0; i < 4; i++) {
        if (i == 2) {
            continue;
        }
        printf("处理编号：%d\n", i);
    }
    // [/loop]
    return 0;
}
