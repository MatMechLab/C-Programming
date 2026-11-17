#include <stdio.h>

/* 故意错误：i到2时，continue反复跳过更新；只阅读和编译，不运行。 */
int main(void)
{
    // [loop]
    int i = 0;
    while (i < 6) {
        if (i == 2) {
            continue;
        }
        printf("第%d次记录\n", i + 1);
        i++;
    }
    // [/loop]
    return 0;
}
