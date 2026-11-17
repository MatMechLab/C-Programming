#include <stdio.h>

/* 有定义的逻辑反例：赋值为0，条件为假，且改掉了status。 */
int main(void)
{
    int status = 1;
    if (status = 0) {
        puts("尚未记录");
    }
    printf("status=%d\n", status);
    return 0;
}
