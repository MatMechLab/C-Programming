#include <stdio.h>

/* 每个花括号块是独立示例。完整文件可直接编译运行。
 * 课件按标记摘取同一份源码；各例之间没有变量依赖。 */
int main(void)
{
    {
        // [one_if]
        int value_mm = 47;
        if (value_mm < 48) {
            puts("低于下限");
        }
        puts("本次判断结束");
        // [/one_if]
    }
    {
        // [two_way]
        int value_mm = 50;
        if (value_mm < 48) {
            puts("低于下限");
        } else {
            puts("达到下限");
        }
        // [/two_way]
    }
    {
        // [chain]
        int value_mm = 50;
        if (value_mm < 48) {
            puts("偏低");
        } else if (value_mm <= 52) {
            puts("范围内");
        } else {
            puts("偏高");
        }
        // [/chain]
    }
    {
        // [nested]
        int recorded = 0;
        int value_mm = 50;
        if (recorded == 1) {
            if (value_mm >= 48) {
                puts("达到下限");
            }
        } else {
            puts("记录未完成");
        }
        // [/nested]
    }
    {
        // [grouping]
        int recorded = 0;
        int value_mm = 53;
        int outside_core = recorded == 1 &&
                          (value_mm < 48 || value_mm > 52);
        printf("已记录且超出内部范围：%d\n", outside_core);
        // [/grouping]
    }
    {
        // [truth]
        printf("非零判断：%d %d %d\n", -3 != 0, 0 != 0, 5 != 0);
        int a = 2, b = -3, zero = 0, c = 7, d = 5;
        printf("逻辑结果：%d %d %d\n", a && b, zero || c, !d);
        // [/truth]
    }
    return 0;
}
