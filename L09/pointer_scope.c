#include <stdio.h>

int main(void)
{
    // [scope]
    int x = 48;
    {
        int *p = &x;
        *p = 51;
    }
    printf("after block: x=%d\n", x);
    // [/scope]
    return 0;
}
