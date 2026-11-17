#include <stdio.h>

int main(void)
{
    // [loop]
    int i = 1;
    int sum = 0;
    while (i <= 3) {
        sum += i;
        i++;
    }
    // [/loop]
    // [report]
    printf("sum = %d\n", sum);
    // [/report]
    return 0;
}
