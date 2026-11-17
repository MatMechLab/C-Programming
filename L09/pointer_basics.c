#include <stdio.h>

/* 虚构机器人距离传感器读数，单位 mm；仅用于离线指针练习。 */

int main(void)
{
    // [declare]
    int reading = 48;
    int *p = &reading;
    // [/declare]
    // [read]
    printf("reading=%d, *p=%d\n", reading, *p);
    printf("p == &reading: %d\n", p == &reading);
    // [/read]
    // [write]
    *p = 51;
    printf("reading=%d, *p=%d\n", reading, *p);
    // [/write]
    return 0;
}
