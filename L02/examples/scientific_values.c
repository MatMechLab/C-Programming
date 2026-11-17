#include <stdio.h>

int main(void)
{
    double pulse_us = 2.5e3;
    double delay_s = 2.5e-3;
    double offset_mm = -2.5e-3;

    printf("pulse_us=%.0f\n", pulse_us);
    printf("delay_s=%.4f\n", delay_s);
    printf("offset_mm=%.4f\n", offset_mm);

    double displacement_m = 0.000125;
    printf("displacement_fixed_6=%.6f\n", displacement_m);
    printf("displacement_scientific=%.2e\n", displacement_m);
    printf("displacement_fixed_2=%.2f\n", displacement_m);
    return 0;
}
