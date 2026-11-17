#include <stdio.h>

/* 受控整数秒数；只有正秒数才进行整数除法。
 * 分子固定为12；在 seconds>0 前提下商可表示。 */
int main(void)
{
    int seconds = 0;
    if (scanf("%4d", &seconds) != 1) {
        puts("输入错误：未读到整数。");
        return 1;
    }
    // [guard]
    if (seconds > 0 && 12 / seconds >= 3) {
        puts("条件成立");
    } else {
        puts("条件不成立");
    }
    // [/guard]
    return 0;
}
