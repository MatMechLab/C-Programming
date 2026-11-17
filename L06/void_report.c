#include <stdio.h>

// [heading]
void print_heading(void)
{
    puts("温度报告");
}
// [/heading]

// [report]
void print_temperature(int temp_c)
{
    if (temp_c < -20 || temp_c > 50) {
        puts("温度无效");
        return;
    }
    printf("温度：%d ℃\n", temp_c);
}
// [/report]

int main(void)
{
    // [call]
    print_heading();
    print_temperature(18);
    print_temperature(80);
    puts("main继续执行");
    // [/call]
    return 0;
}
