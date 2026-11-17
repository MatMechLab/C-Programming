#include <float.h>
#include <stdio.h>

int main(void)
{
    // [environment]
    puts("Local rounding observation; not a universal C17 result.");
    printf("FLT_RADIX = %d; DBL_MANT_DIG = %d; FLT_EVAL_METHOD = %d; FLT_ROUNDS = %d\n",
           FLT_RADIX, DBL_MANT_DIG, FLT_EVAL_METHOD, FLT_ROUNDS);
    // [/environment]

    /* 教师观察装置：volatile 保留这些对象的读写，不是本课必学语法。 */
    // [conversion]
    volatile long long original = 9007199254740993LL;
    volatile double converted = (double)original;
    printf("original long long = %lld\n", original);
    printf("stored double = %.0f\n", converted);
    // [/conversion]

    // [grouping]
    volatile double large = 1e16;
    volatile double cancel = -1e16;
    volatile double small = 1.0;
    volatile double left_partial = large + cancel;
    volatile double left_result = left_partial + small;
    volatile double right_partial = cancel + small;
    volatile double right_result = large + right_partial;
    printf("(large + cancel) + small = %.1f\n", left_result);
    printf("large + (cancel + small) = %.1f\n", right_result);
    // [/grouping]
    return 0;
}
