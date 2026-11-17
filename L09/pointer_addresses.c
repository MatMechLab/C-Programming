#include <stdio.h>

int main(void)
{
    // [addresses]
    int reading = 48;
    int *p = &reading;
    printf("&reading=%p\n", (void *)&reading);
    printf("p=%p\n", (void *)p);
    printf("&p=%p\n", (void *)&p);
    printf("p == &reading: %d\n", p == &reading);
    // [/addresses]
    return 0;
}
