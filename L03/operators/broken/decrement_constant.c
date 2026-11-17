/* 错误例：常量不是可修改对象。只编译诊断，不执行。 */
int main(void)
{
    int result = 5--;
    return result;
}
