#include <stdio.h>

// [definition]
int next_local(void)
{
    int count = 0;
    count++;
    return count;
}
// [/definition]

int main(void)
{
    // [call]
    int first = next_local();
    int second = next_local();
    printf("两次结果：%d %d\n", first, second);
    // [/call]
    return 0;
}
