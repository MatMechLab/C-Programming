#include <stdio.h>

int main(void)
{
    // [fixed]
    int x = 48;
    int * const p = &x;
    *p = 51;
    printf("x=%d, *p=%d\n", x, *p);
    // [/fixed]
    return 0;
}
