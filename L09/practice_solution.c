#include <stdio.h>

int main(void)
{
    // [practice]
    int a = 49;
    int b = 52;
    int *p = &a;

    *p = 50;
    p = &b;
    *p -= 2;

    printf("a=%d, b=%d, *p=%d\n", a, b, *p);
    // [/practice]
    return 0;
}
