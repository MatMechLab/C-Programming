#include <stdio.h>

/* 故意错误：i未更新，程序不能正常结束；只阅读和编译，不运行。 */
int main(void)
{
    // [loop]
    int i = 0;
    while (i < 3) {
        printf("第%d次记录\n", i + 1);
    }
    // [/loop]
    return 0;
}
