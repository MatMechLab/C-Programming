#include <stdio.h>

/* 与 independent_checks.c 相同的受控输入约定。
 * 本例只检查是否达到48毫米下限，不是完整质量分类。 */
int main(void)
{
    int value_mm = 0, recorded = 0;
    if (scanf("%4d %4d", &value_mm, &recorded) != 2) {
        puts("输入错误");
        return 1;
    }
    if (recorded != 0 && recorded != 1) {
        puts("标记错误");
        return 1;
    }
    // [nested]
    if (recorded == 1) {
        if (value_mm >= 48) {
            puts("达到下限");
        } else {
            puts("低于下限");
        }
    } else {
        puts("记录未完成");
    }
    // [/nested]
    return 0;
}
