/* ERROR EXAMPLE: do not run. %f requires float *, but the object has type double. */
#include <stdio.h>

int main(void)
{
    double temperature_c = 0.0;
    return scanf("%f", &temperature_c) == 1 ? 0 : 1;
}
