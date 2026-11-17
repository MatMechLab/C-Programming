// 故意错误：这里只检查编译诊断，不运行。
// [snippet]
double to_fahrenheit(double c);

int main(void)
{
    double result = to_fahrenheit(18.0, 20.0);
    return result > 0.0;
}
// [/snippet]

double to_fahrenheit(double c)
{
    return c * 9.0 / 5.0 + 32.0;
}
