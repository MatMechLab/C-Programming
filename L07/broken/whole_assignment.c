#include <stdio.h>

/* 故意错误：只编译观察。数组不能用赋值运算符整体赋值。 */
int main(void)
{
    // [wrong_assignment]
    int original[4] = {49, 52, 47, 50};
    int copied[4];
    copied = original;
    printf("%d\n", copied[0]);
    // [/wrong_assignment]
    return 0;
}
