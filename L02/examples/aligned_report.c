#include <stdio.h>

int main(void)
{
    int run_id = 7;
    double length_mm = 3.5;

    printf("%4d | %7.2f\n", run_id, length_mm);

    run_id = 128;
    length_mm = 27.25;
    printf("%4d | %7.2f\n", run_id, length_mm);
    return 0;
}
