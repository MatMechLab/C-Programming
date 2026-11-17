#include <float.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    /* 教师观察程序：volatile 仅用于要求这里实际读写对象，不是本课新语法。 */
    puts("Local floating-point observation; not a universal C17 output.");
    printf("FLT_RADIX = %d; DBL_MANT_DIG = %d; FLT_EVAL_METHOD = %d\n",
           FLT_RADIX, DBL_MANT_DIG, FLT_EVAL_METHOD);
    // [observation]
    volatile double first = 0.1;
    volatile double second = 0.2;
    volatile double sum = first + second;
    volatile double reference = 0.3;
    printf("0.1 + 0.2 stored as double = %.17g\n", sum);
    printf("0.3 stored as double = %.17g\n", reference);
    printf("difference = %.17g\n", fabs(sum - reference));
    printf("equal in this run = %d\n", sum == reference);
    // [/observation]

    // [tolerance]
    double measured_mm = 10.03;
    double reference_mm = 10.0;
    double tolerance_mm = 0.05;
    double absolute_error_mm = fabs(measured_mm - reference_mm);
    printf("measurement absolute error = %.3f mm\n", absolute_error_mm);
    printf("exercise tolerance = %.3f mm\n", tolerance_mm);
    printf("within exercise tolerance = %d\n", absolute_error_mm <= tolerance_mm);
    // [/tolerance]
    return 0;
}
