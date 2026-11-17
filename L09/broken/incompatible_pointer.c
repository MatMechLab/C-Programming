/* 故意错误：只阅读和编译观察诊断，不运行。 */

int main(void)
{
    // [bad]
    double value = 48.0;
    int *p = &value;
    // [/bad]
    (void)p;
    return 0;
}
