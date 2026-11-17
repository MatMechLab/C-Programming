#include <stdio.h>

/* 与 range_quality.c 的输入约定及虚构分类规则完全相同。
 * 这次按数轴从左到右判断，用前面条件的否定限定下一段范围。 */
int main(void)
{
    int value_mm = 0;
    puts("请输入整数毫米读数：");
    if (scanf("%4d", &value_mm) != 1) {
        puts("输入错误：未读到整数。");
        return 1;
    }
    // [ascending]
    if (value_mm < 40) {
        puts("质量：无效");
    } else if (value_mm < 48) {
        puts("质量：需复查");
    } else if (value_mm <= 52) {
        puts("质量：有效");
    } else if (value_mm <= 60) {
        puts("质量：需复查");
    } else {
        puts("质量：无效");
    }
    // [/ascending]
    return 0;
}
