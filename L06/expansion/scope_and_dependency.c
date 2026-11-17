#include <stdio.h>

int allowed_with_limit(int c, int upper);

int main(void)
{
    // [shadow]
    int temp_c = 18;
    {
        int temp_c = 25;
        printf("内层温度：%d ℃\n", temp_c);
    }
    printf("外层温度：%d ℃\n", temp_c);
    // [/shadow]
    // [dependency_calls]
    int first = allowed_with_limit(40, 50);
    int second = allowed_with_limit(40, 30);
    printf("上限50：%d\n", first);
    printf("上限30：%d\n", second);
    // [/dependency_calls]
    return 0;
}

// 这里只判断上限，不是完整的温度有效性检查。
// [explicit_dependency]
int allowed_with_limit(int c, int upper)
{
    return c <= upper;
}
// [/explicit_dependency]
