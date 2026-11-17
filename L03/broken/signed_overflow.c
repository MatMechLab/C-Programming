#include <limits.h>

/* 未定义行为反例：仅编译检查诊断，禁止执行。 */
int main(void)
{
    int too_large = INT_MAX + 1;
    return too_large;
}
