/* 仅编译看诊断；C17中的const int对象不是整数常量表达式。 */
int main(void)
{
    const int limit = 1;
    int status = 1;
    switch (status) {
    case limit: return 0;
    default: return 1;
    }
}
