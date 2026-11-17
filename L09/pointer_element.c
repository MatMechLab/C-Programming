#include <stdio.h>

int main(void)
{
    // [element]
    int a[3] = {49, 52, 47};
    int *p = &a[1];
    *p = 51;
    printf("a: %d %d %d; *p=%d\n", a[0], a[1], a[2], *p);
    // [/element]
    return 0;
}
