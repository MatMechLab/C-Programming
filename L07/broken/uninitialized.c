#include <stdio.h>

/* 故意错误：只编译观察；不要运行。局部数组未初始化，不能读取该元素。 */
int main(void)
{
    // [wrong_read]
    int reading[4];
    printf("%d\n", reading[0]);
    // [/wrong_read]
    return 0;
}
