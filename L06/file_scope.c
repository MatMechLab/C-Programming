#include <stdio.h>

// 本例故意使用可变的文件作用域对象，观察函数对外部状态的依赖。
// [global]
int upper_c = 50;

int allowed(int c)
{
    return c <= upper_c;
}
// [/global]

int main(void)
{
    // [call]
    printf("上限50，allowed(40)=%d\n", allowed(40));
    upper_c = 30;
    printf("上限30，allowed(40)=%d\n", allowed(40));
    // [/call]
    return 0;
}
