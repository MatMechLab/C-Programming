#include <stdio.h>

int main(void)
{
    // [pointer]
    int reading = 49;
    int *p = &reading;
    *p = 52;
    printf("reading=%d, *p=%d\n", reading, *p);
    // [/pointer]
    return 0;
}
