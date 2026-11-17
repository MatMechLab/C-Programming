#include <stdio.h>

int main(void)
{
    // [initial]
    int a = 49;
    int b = 52;
    int *p = &a;
    int *q = p;
    printf("initial: a=%d, b=%d, *p=%d, *q=%d\n",
           a, b, *p, *q);
    // [/initial]
    // [shared_write]
    *p = 50;
    printf("write through p: a=%d, b=%d, *q=%d\n",
           a, b, *q);
    // [/shared_write]
    // [redirect]
    p = &b;
    printf("redirect p: *p=%d, *q=%d\n", *p, *q);
    // [/redirect]
    // [write_b]
    *p = 53;
    printf("write b: a=%d, b=%d, *q=%d\n", a, b, *q);
    // [/write_b]
    // [write_a]
    *q = 48;
    printf("write through q: a=%d, b=%d\n", a, b);
    // [/write_a]
    return 0;
}
