/* 故意错误：只阅读和编译观察诊断，不运行。 */
#include <stdio.h>

int main(void)
{
    // [bad]
    int *p;
    printf("%d\n", *p);
    // [/bad]
    return 0;
}
