#include <stdio.h>

int main(void)
{
    // [target]
    int x;
    int *p = &x;
    *p = 50;
    printf("x=%d, *p=%d\n", x, *p);
    // [/target]
    return 0;
}
