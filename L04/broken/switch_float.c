/* 仅编译看诊断；违反switch控制表达式须为整数类型的约束。 */
int main(void)
{
    double value = 1.0;
    switch (value) {
    case 1: return 0;
    default: return 1;
    }
}
