#include <stdio.h>

/* 两个独立变量使用相同初值，比较一次选择与循环重复。 */
int main(void)
{
    // [comparison]
    int i = 0;
    if (i < 3) {
        i++;
    }
    int j = 0;
    while (j < 3) {
        j++;
    }
    // [/comparison]
    printf("i=%d, j=%d\n", i, j);
    return 0;
}
