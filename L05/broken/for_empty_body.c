#include <stdio.h>

/* 故意错误：for后多写了分号，后面的块不是循环体。
 * 此例行为有定义，可以运行；保留编译器的实际警告。 */
int main(void)
{
    // [empty_body]
    int i;
    for (i = 0; i < 6; i++);
    {
        printf("第%d次记录\n", i + 1);
    }
    // [/empty_body]
    return 0;
}
