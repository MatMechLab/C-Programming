#include <stdio.h>

/* 剩余次数逐次减少；在本轮开始时输出，因此输出3、2、1。 */
int main(void)
{
    // [loop]
    int remaining = 3;
    while (remaining > 0) {
        printf("本轮开始还剩：%d\n", remaining);
        remaining--;
    }
    printf("结束时还剩：%d\n", remaining);
    // [/loop]
    return 0;
}
