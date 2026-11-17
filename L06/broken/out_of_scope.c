#include <stdio.h>

// 故意错误：这里只检查编译诊断，不运行。
// [snippet]
int main(void)
{
    {
        int valid = 4;
        printf("块内：%d\n", valid);
    }
    printf("块外：%d\n", valid);
    return 0;
}
// [/snippet]
