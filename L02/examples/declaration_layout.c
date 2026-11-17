#include <stdio.h>

int main(void)
{
    int run_id = 0, sample_count = 0;
    char grade = 'B';

    /* 声明变量时，可以同时给出初值。 */
    int count = 6; // 从这里到行尾都是注释
    double length_mm = 8.5;

    printf("run_id=%d\n", run_id);
    printf("sample_count=%d\n", sample_count);
    printf("grade=%c\n", grade);
    printf("count=%d\n", count);
    printf("length_mm=%.1f\n", length_mm);
    return 0;
}
