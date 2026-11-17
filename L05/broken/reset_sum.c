#include <stdio.h>

/* 故意的逻辑错误：想求1+2+3，却每轮清零。行为有定义，可运行。 */
int main(void)
{
    // [loop]
    int sum = 0;
    for (int i = 1; i <= 3; i++) {
        sum = 0;
        sum += i;
    }
    printf("sum=%d\n", sum);
    // [/loop]
    return 0;
}
