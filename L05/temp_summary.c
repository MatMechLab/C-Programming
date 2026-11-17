#include <stdio.h>

/* 学生增量练习参考解答：增加无效项数量和有效项平均值。
 * 固定读取6个整数温度，每项最多四字符（含符号），以空白分隔。
 * %4d 不验证完整数字文本或整行；课堂阈值见 README.md。 */
int main(void)
{
    // [state]
    int valid_count = 0;
    int invalid_count = 0;
    int sum_c = 0;
    int min_c = 0;
    int max_c = 0;
    // [/state]
    puts("请输入6个整数温度（℃）：");
    for (int i = 0; i < 6; i++) {
        // [input]
        int temp_c = 0;
        if (scanf("%4d", &temp_c) != 1) {
            puts("输入错误：需要整数温度。");
            return 1;
        }
        // [/input]
        // [filter]
        if (temp_c < -20 || temp_c > 50) {
            invalid_count++;
            continue;
        }
        // [/filter]
        // [extrema]
        if (valid_count == 0) {
            min_c = temp_c;
            max_c = temp_c;
        }
        if (temp_c < min_c) {
            min_c = temp_c;
        }
        if (temp_c > max_c) {
            max_c = temp_c;
        }
        // [/extrema]
        // [accumulate]
        sum_c += temp_c;
        valid_count++;
        // [/accumulate]
    }
    // [report]
    printf("有效数：%d\n", valid_count);
    printf("无效数：%d\n", invalid_count);
    printf("总和：%d ℃\n", sum_c);
    if (valid_count == 0) {
        puts("没有有效温度，平均值和极值不计算。");
    } else {
        // [mean]
        double mean_c = (double)sum_c / valid_count;
        printf("平均值：%.2f ℃\n", mean_c);
        // [/mean]
        printf("最低值：%d ℃\n", min_c);
        printf("最高值：%d ℃\n", max_c);
    }
    // [/report]
    return 0;
}
