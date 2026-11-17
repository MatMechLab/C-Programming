// 故意错误：这里只检查编译诊断，不运行。
// [snippet]
double to_fahrenheit(double c);

int to_fahrenheit(double c)
{
    return c * 9.0 / 5.0 + 32.0;
}
// [/snippet]

int main(void)
{
    return 0;
}
