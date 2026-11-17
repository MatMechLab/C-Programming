#include <stdio.h>

/* 变量在循环体内改变后，while 在下一次进入前才重新判断。 */
int main(void)
{
    // [loop]
    int i = 0;
    while (i < 3) {
        i += 2;
        printf("循环体：i=%d\n", i);
    }
    printf("循环后：i=%d\n", i);
    // [/loop]
    return 0;
}
