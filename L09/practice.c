#include <stdio.h>

int main(void)
{
    // [practice]
    int a = 49;
    int b = 52;
    int *p = &a;

    // TODO 1: 通过 p 把 a 改为 50。

    // TODO 2: 让 p 指向 b。

    // TODO 3: 通过 p 把 b 减少 2。

    printf("a=%d, b=%d, *p=%d\n", a, b, *p);
    // [/practice]
    return 0;
}
