#include <stdio.h>

int main(void)
{
    // [guard_null]
    int x = 0;
    int *p = NULL;
    int positive = p != NULL && *p > 0;
    printf("null: positive=%d\n", positive);
    // [/guard_null]
    // [guard_zero]
    p = &x;
    positive = p != NULL && *p > 0;
    printf("zero: positive=%d\n", positive);
    // [/guard_zero]
    // [guard_positive]
    x = 53;
    positive = p != NULL && *p > 0;
    printf("positive: positive=%d\n", positive);
    // [/guard_positive]
    // [guard_negative]
    x = -1;
    positive = p != NULL && *p > 0;
    printf("negative: positive=%d\n", positive);
    // [/guard_negative]
    return 0;
}
