#include <stdio.h>

int main(void)
{
    // [input]
    int start_s;
    int end_s;
    puts("Enter start and end times (s):");
    if (scanf("%4d %4d", &start_s, &end_s) != 2) {
        puts("Input error: two integers are required.");
        return 1;
    }
    // [/input]

    // [denominator]
    int elapsed_s = end_s - start_s;
    // [/denominator]

    // [zero_guard]
    if (elapsed_s == 0) {
        puts("Calculation stopped: elapsed time must not be zero.");
        return 1;
    }
    // [/zero_guard]

    // [negative_guard]
    if (elapsed_s < 0) {
        puts("Calculation stopped: elapsed time must be positive.");
        return 1;
    }
    // [/negative_guard]

    // [calculation]
    double distance_mm = 18.0;
    double average_rate_mm_s = distance_mm / elapsed_s;
    printf("elapsed = %d s\n", elapsed_s);
    printf("average rate = %.3f mm/s\n", average_rate_mm_s);
    // [/calculation]
    return 0;
}
