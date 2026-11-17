#include <stdio.h>

int main(void)
{
    // [input]
    int seconds;
    puts("Enter elapsed time in seconds (1 to 9999):");
    if (scanf("%4d", &seconds) != 1) {
        puts("Input error: one integer is required.");
        return 1;
    }
    // [/input]

    // [guard]
    if (seconds == 0) {
        puts("Calculation stopped: elapsed time must not be zero.");
        return 1;
    }
    if (seconds < 0) {
        puts("Calculation stopped: elapsed time must be positive.");
        return 1;
    }
    // [/guard]

    // [calculate]
    double distance_m = 6.0;
    double speed_m_s = distance_m / seconds;
    printf("speed = %.3f m/s\n", speed_m_s);
    // [/calculate]
    return 0;
}
