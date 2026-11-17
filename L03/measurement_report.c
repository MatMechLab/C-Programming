#include <math.h>
#include <stdio.h>

int main(void)
{
    // [input]
    int first_mm;
    int second_mm;
    int third_mm;
    int reference_mm;

    puts("Enter three measurements and one reference (mm):");
    if (scanf("%4d %4d %4d %4d", &first_mm, &second_mm,
              &third_mm, &reference_mm) != 4) {
        puts("Input error: four integers are required.");
        return 1;
    }
    // [/input]

    // [calculate]
    int sum_mm = first_mm + second_mm + third_mm;
    double mean_mm = sum_mm / 3.0;
    double absolute_error_mm = fabs(mean_mm - reference_mm);
    // [/calculate]

    // [report]
    printf("sum = %d mm\n", sum_mm);
    printf("mean = %.3f mm\n", mean_mm);
    printf("absolute error = %.3f mm\n", absolute_error_mm);
    // [/report]
    return 0;
}
