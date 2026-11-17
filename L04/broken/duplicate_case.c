/* 仅编译看诊断；同一个switch内case常量值不能重复。 */
int main(void)
{
    int status = 1;
    switch (status) {
    case 1: return 0;
    case 1: return 1;
    default: return 2;
    }
}
