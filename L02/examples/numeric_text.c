#include <stdio.h>

int main(void)
{
    int number = 0;

    /* %d按十进制读取；这些课堂输入都在int可表示范围内。 */
    if (scanf("%d", &number) != 1) {
        puts("input_error=number");
        return 1;
    }

    printf("number=%d\n", number);
    printf("sizeof_int=%zu\n", sizeof number);
    return 0;
}
