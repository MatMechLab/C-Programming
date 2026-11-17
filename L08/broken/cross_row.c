#include <stdio.h>

/* 错误示例：第二个下标越过当前行；只分析和检查编译诊断，不运行。 */
int main(void)
{
    int table[2][3] = {{1, 2, 3}, {4, 5, 6}};
    // [wrong_access]
    printf("%d\n", table[0][3]);
    // [/wrong_access]
    return 0;
}
