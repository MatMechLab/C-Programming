#include <stdio.h>

int main(void)
{
    int run_id = 0;
    double length_mm = 0.0;

    puts("Enter run ID (integer):");
    if (scanf("%d", &run_id) != 1) {
        puts("Input error: expected an integer run ID.");
        return 1;
    }

    puts("Enter length in millimeters:");
    if (scanf("%lf", &length_mm) != 1) {
        puts("Input error: expected a numeric length.");
        return 1;
    }

    printf("Run %d: %.2f mm\n", run_id, length_mm);
    return 0;
}
