#include <stdio.h>

/* 有定义的逻辑反例：case0漏break，会顺序进入case1后的语句。 */
int main(void)
{
    // [example]
    int status = 0;
    switch (status) {
    case 0:
        puts("尚未记录");
    case 1:
        puts("已经记录");
        break;
    default:
        puts("未知状态");
        break;
    }
    // [/example]
    puts("状态说明结束");
    return 0;
}
