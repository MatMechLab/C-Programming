#include <stdio.h>

int main(void)
{
    // [setup]
    int reading = 420;
    int *p = &reading;
    // [/setup]

    // [read]
    int snapshot = *p;
    // [/read]

    // [before]
    printf("before: reading=%d, snapshot=%d, same_target=%d\n",
           reading, snapshot, p == &reading);
    // [/before]

    // [write]
    *p = 400;
    // [/write]

    // [after]
    printf("after: reading=%d, snapshot=%d, same_target=%d\n",
           reading, snapshot, p == &reading);
    // [/after]

    // [zero]
    int zero = 0;
    int *zero_ptr = &zero;
    int *empty = NULL;
    printf("zero: nonnull=%d, value=%d\n", zero_ptr != NULL, *zero_ptr);
    printf("empty: is_null=%d\n", empty == NULL);
    // [/zero]

    return 0;
}
