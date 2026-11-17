#include <stdio.h>

int main(void)
{
    // [scope]
    int total = 6;
    {
        int valid = 4;
        printf("块内：total=%d，valid=%d\n", total, valid);
    }
    printf("块外：total=%d\n", total);
    // [/scope]
    return 0;
}
