/* 未定义行为反例：仅编译检查诊断，禁止执行。 */
int main(void)
{
    int count = 3;
    int total = count++ + count;
    return total;
}
