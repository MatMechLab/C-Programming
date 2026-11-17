#include <stdio.h>

// [copy]
void set_copy(int value)
{
    value = 400;
    printf("inside copy: value=%d\n", value);
}
// [/copy]

/* out must point to a live, writable int object. */
// [write]
void set_reading(int *out)
{
    *out = 400;
}
// [/write]

int main(void)
{
    // [calls]
    int reading = 420;
    set_copy(reading);
    printf("after copy: reading=%d\n", reading);
    set_reading(&reading);
    printf("after pointer: reading=%d\n", reading);
    // [/calls]
    return 0;
}
