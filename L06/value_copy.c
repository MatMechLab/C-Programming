#include <stdio.h>

// 本例只使用很小的整数，避免 value + 2 超出 int 范围。
// [definition]
int add_two(int value)
{
    value += 2;
    return value;
}
// [/definition]

int main(void)
{
    // [call]
    int temp_c = 18;
    add_two(temp_c);
    printf("未接收返回值：%d\n", temp_c);
    temp_c = add_two(temp_c);
    printf("接收并赋值后：%d\n", temp_c);
    // [/call]
    return 0;
}
