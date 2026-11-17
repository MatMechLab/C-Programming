#include <stdio.h>

int main(void)
{
    // [identity_initial]
    int a = 50;
    int b = 50;
    int *p = &b;
    int *q = &a;
    printf("equal values=%d, same object=%d\n", *p == *q, p == q);
    // [/identity_initial]
    // [identity_update]
    *p = 51;
    printf("after: a=%d, b=%d\n", a, b);
    // [/identity_update]
    return 0;
}
