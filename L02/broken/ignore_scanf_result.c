/* LOGIC ERROR EXAMPLE: initialized, but failed input is silently used as 0.0. */
#include <stdio.h>

int main(void)
{
    double temperature_c = 0.0;
    (void)scanf("%lf", &temperature_c);
    printf("%.1f\n", temperature_c * 1.8 + 32.0);
    return 0;
}
