#include <stdio.h>

/* 受控输入：毫米读数和0/1记录标记，每项至多四字符（含符号）。
 * 两项用空白分隔；%4d 不验证完整文本。这里只给独立提醒，不作质量分类。 */
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
    // [checks]
    if (value_mm > 52) {
        puts("读数高于52毫米");
    }
    if (recorded == 0) {
        puts("记录尚未完成");
    }
    // [/checks]
    return 0;
}
