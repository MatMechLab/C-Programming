#include <stdio.h>

/* 受控十进制整数输入，至多四字符（含符号）；只检查[48,52]外的提醒。 */
int main(void)
{
    int value_mm = 0;
    if (scanf("%4d", &value_mm) != 1) {
        puts("输入错误");
        return 1;
    }
    // [state]
    int needs_review = 0;
    if (value_mm < 48 || value_mm > 52) {
        needs_review = 1;
    }
    printf("需要复查：%d\n", needs_review);
    // [/state]
    return 0;
}
