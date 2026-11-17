#include <stdio.h>

int main(void)
{
    // [comparison]
    int i = 3;
    while (i < 3) {
        i++;
    }
    int j = 3;
    do {
        j++;
    } while (j < 3);
    // [/comparison]
    // [report]
    printf("while结束：i = %d\n", i);
    printf("do...while结束：j = %d\n", j);
    // [/report]
    return 0;
}
