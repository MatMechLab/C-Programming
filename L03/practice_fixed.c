#include <stdio.h>

int main(void)
{
    // [mean]
    int first_mm = 10;
    int second_mm = 11;
    int third_mm = 13;
    int sum_mm = first_mm + second_mm + third_mm;
    double mean_mm = sum_mm / 3.0;
    printf("correct mean = %.3f mm\n", mean_mm);
    // [/mean]

    // [grouping]
    double grouped_mean_mm = (first_mm + second_mm + third_mm) / 3.0;
    printf("correct grouped mean = %.3f mm\n", grouped_mean_mm);
    // [/grouping]
    return 0;
}
