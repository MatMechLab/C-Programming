#include <stdio.h>

int main(void)
{
    int experiment_id = 0;
    double temperature_c = 0.0;
    double temperature_f = 0.0;
    const double scale = 1.8;
    const double offset_f = 32.0;
    const char input_unit = 'C';

    puts("Enter experiment ID (integer):");
    if (scanf("%d", &experiment_id) != 1) {
        puts("Input error: expected an integer experiment ID.");
        return 1;
    }

    puts("Enter temperature in Celsius:");
    if (scanf("%lf", &temperature_c) != 1) {
        puts("Input error: expected a numeric temperature.");
        return 1;
    }

    temperature_f = temperature_c * scale + offset_f;
    printf("Experiment %d: %.1f %c = %.1f F\n",
           experiment_id, temperature_c, input_unit, temperature_f);

    return 0;
}
