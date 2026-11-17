#include <stdio.h>

/* 每个十进制整数最多四字符（含符号），以空白分隔。
 * %4d 不验证完整数字文本或整行；课堂阈值见 README.md。 */
int main(void)
{
    int temp_c = 0;
    // [loop]
    do {
        puts("请输入-20～50之间的整数温度（℃）：");
        // [input_check]
        if (scanf("%4d", &temp_c) != 1) {
            puts("输入错误：需要整数温度。");
            return 1;
        }
        // [/input_check]
        if (temp_c < -20 || temp_c > 50) {
            puts("超出课堂范围，请重新输入。");
        }
    } while (temp_c < -20 || temp_c > 50);
    // [/loop]
    // [report]
    printf("本次温度：%d ℃\n", temp_c);
    // [/report]
    return 0;
}
