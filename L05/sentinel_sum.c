#include <stdio.h>

/* 最多读取6项，-999表示提前结束；结束标记不参与统计。
 * 每个十进制整数最多四字符（含符号），以空白分隔。
 * %4d 不验证完整数字文本或整行；课堂阈值见 README.md。 */
int main(void)
{
    int sum_c = 0;
    int valid_count = 0;
    puts("最多输入6个整数温度，-999表示结束：");
    for (int i = 0; i < 6; i++) {
        // [input]
        int temp_c = 0;
        if (scanf("%4d", &temp_c) != 1) {
            puts("输入错误：需要整数温度。");
            return 1;
        }
        // [/input]
        // [control]
        // [stop]
        if (temp_c == -999) {
            break;
        }
        // [/stop]
        // [filter_sum]
        if (temp_c < -20 || temp_c > 50) {
            continue;
        }
        sum_c += temp_c;
        valid_count++;
        // [/filter_sum]
        // [/control]
    }
    // [report]
    printf("有效数：%d\n", valid_count);
    printf("总和：%d ℃\n", sum_c);
    // [/report]
    return 0;
}
