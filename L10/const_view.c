#include <stdio.h>

/* The caller deliberately modifies a non-const array between two reads. */
int main(void)
{
    // [view]
    int ranges[2] = {420, 390};
    const int *view = ranges;
    printf("before: %d\n", view[0]);
    ranges[0] = 400;
    printf("after direct write: %d\n", view[0]);
    view = &ranges[1];
    printf("after redirect: %d\n", *view);
    // [/view]
    return 0;
}
