/* 错误例：% 的操作数必须是整数类型。只编译诊断，不执行。 */
int main(void)
{
    double remainder = 5.0 % 2.0;
    return (int)remainder;
}
