#include <stdio.h>

// [value_function]
void change_copy(int value)
{
    value = 51;
    printf("inside: value=%d\n", value);
}
// [/value_function]

int main(void)
{
    // [value_call]
    int reading = 48;
    change_copy(reading);
    printf("after call: reading=%d\n", reading);
    // [/value_call]
    return 0;
}
