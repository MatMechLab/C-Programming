// 故意错误：这里只检查编译诊断，不运行。
// 无效温度走到函数末尾，调用者若使用该返回值，行为未定义。
// [snippet]
int is_valid_temperature(int temp_c)
{
    if (temp_c >= -20 && temp_c <= 50) {
        return 1;
    }
}
// [/snippet]

int main(void)
{
    return is_valid_temperature(80);
}
