#include <stdio.h>

int main(void)
{
    // [zero_initial]
    int x = 0;
    int *p = &x;
    int *q = NULL;
    printf("*p=%d, p is nonnull=%d, q is null=%d\n",
           *p, p != NULL, q == NULL);
    // [/zero_initial]
    // [zero_alias]
    q = p;
    *q = 2;
    p = NULL;
    printf("x=%d, *q=%d, p is null=%d\n", x, *q, p == NULL);
    // [/zero_alias]
    return 0;
}
