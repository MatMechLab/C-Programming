#include <stdio.h>

int main(void)
{
    // [swap_initial]
    int a = 49;
    int b = 52;
    int *p = &a;
    int *q = &b;
    printf("before: a=%d, b=%d\n", a, b);
    // [/swap_initial]
    // [swap_steps]
    int temp = *p;
    *p = *q;
    *q = temp;
    printf("after: a=%d, b=%d\n", a, b);
    // [/swap_steps]
    return 0;
}
