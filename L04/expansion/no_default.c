#include <stdio.h>

/* 教学对照：刻意没有 default，未知整数状态也会继续到 switch 之后。
 * 输入为受控十进制整数，至多四字符（含符号）。 */
int main(void)
{
    int status = 0;
    if (scanf("%4d", &status) != 1) {
        puts("输入错误");
        return 1;
    }
    // [switch]
    switch (status) {
    case 0:
        puts("尚未记录");
        break;
    case 1:
        puts("已经记录");
        break;
    }
    puts("状态说明结束");
    // [/switch]
    return 0;
}
