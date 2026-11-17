// 故意错误：这里只检查编译诊断，不运行。
// [snippet]
void print_heading(void);

int main(void)
{
    int result = print_heading();
    return result;
}
// [/snippet]

void print_heading(void)
{
    return;
}
