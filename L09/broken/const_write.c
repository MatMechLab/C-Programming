/* 故意错误：只阅读和编译观察诊断，不运行。 */

int main(void)
{
    // [bad]
    int calibration = 50;
    const int *view = &calibration;
    *view = 51;
    // [/bad]
    return 0;
}
