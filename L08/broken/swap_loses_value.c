#include <stdio.h>

/* 错误示例：逻辑错误，行为有定义，可以观察值如何丢失。 */
int main(void)
{
    int a[2] = {52, 47};
    // [wrong_swap]
    a[0] = a[1];
    a[1] = a[0];
    // [/wrong_swap]
    printf("after wrong swap: %d %d\n", a[0], a[1]);
    return 0;
}
