#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void)
{
    /* 教师查询程序：结果属于本次编译目标，不是所有C实现的固定表。 */
    printf("CHAR_BIT=%d\n", CHAR_BIT);
    printf("sizeof_int=%zu\n", sizeof(int));
    printf("sizeof_long=%zu\n", sizeof(long int));
    printf("sizeof_long_long=%zu\n", sizeof(long long int));
    printf("sizeof_pointer=%zu\n", sizeof(void *));
    printf("INT_MIN=%d\n", INT_MIN);
    printf("INT_MAX=%d\n", INT_MAX);
    printf("UINT_MAX=%u\n", UINT_MAX);
    printf("LONG_MIN=%ld\n", LONG_MIN);
    printf("LONG_MAX=%ld\n", LONG_MAX);
    printf("ULONG_MAX=%lu\n", ULONG_MAX);
    printf("LLONG_MIN=%lld\n", LLONG_MIN);
    printf("LLONG_MAX=%lld\n", LLONG_MAX);
    printf("ULLONG_MAX=%llu\n", ULLONG_MAX);

    /* MAX是最大有限值；MIN是最小正规正值；TRUE_MIN是最小正值。 */
    /* *_LOWEST只是本程序的输出标签，不是C17宏名；值取负MAX。 */
    printf("FLT_RADIX=%d\n", FLT_RADIX);
    printf("FLT_LOWEST=%.6e\n", -FLT_MAX);
    printf("FLT_MAX=%.6e\n", FLT_MAX);
    printf("FLT_MIN=%.6e\n", FLT_MIN);
    printf("FLT_TRUE_MIN=%.6e\n", FLT_TRUE_MIN);
    printf("DBL_LOWEST=%.6e\n", -DBL_MAX);
    printf("DBL_MAX=%.6e\n", DBL_MAX);
    printf("DBL_MIN=%.6e\n", DBL_MIN);
    printf("DBL_TRUE_MIN=%.6e\n", DBL_TRUE_MIN);
    printf("LDBL_LOWEST=%.6Le\n", -LDBL_MAX);
    printf("LDBL_MAX=%.6Le\n", LDBL_MAX);
    printf("LDBL_MIN=%.6Le\n", LDBL_MIN);
    printf("LDBL_TRUE_MIN=%.6Le\n", LDBL_TRUE_MIN);

    /* 空间、有效数位和指数范围分别查询；不把sizeof当成精度。 */
    printf("sizeof_float=%zu\n", sizeof(float));
    printf("sizeof_double=%zu\n", sizeof(double));
    printf("sizeof_long_double=%zu\n", sizeof(long double));
    printf("FLT_DIG=%d\n", FLT_DIG);
    printf("DBL_DIG=%d\n", DBL_DIG);
    printf("LDBL_DIG=%d\n", LDBL_DIG);
    printf("FLT_MANT_DIG=%d\n", FLT_MANT_DIG);
    printf("DBL_MANT_DIG=%d\n", DBL_MANT_DIG);
    printf("LDBL_MANT_DIG=%d\n", LDBL_MANT_DIG);
    printf("FLT_MIN_EXP=%d\n", FLT_MIN_EXP);
    printf("FLT_MAX_EXP=%d\n", FLT_MAX_EXP);
    printf("DBL_MIN_EXP=%d\n", DBL_MIN_EXP);
    printf("DBL_MAX_EXP=%d\n", DBL_MAX_EXP);
    printf("LDBL_MIN_EXP=%d\n", LDBL_MIN_EXP);
    printf("LDBL_MAX_EXP=%d\n", LDBL_MAX_EXP);
    printf("FLT_HAS_SUBNORM=%d\n", FLT_HAS_SUBNORM);
    printf("DBL_HAS_SUBNORM=%d\n", DBL_HAS_SUBNORM);
    printf("LDBL_HAS_SUBNORM=%d\n", LDBL_HAS_SUBNORM);

    /* 二进制课堂平台的精确核验输出；%a/%La不列入学生必学格式。 */
    printf("FLT_MAX_HEX=%a\n", FLT_MAX);
    printf("FLT_MIN_HEX=%a\n", FLT_MIN);
    printf("FLT_TRUE_MIN_HEX=%a\n", FLT_TRUE_MIN);
    printf("DBL_MAX_HEX=%a\n", DBL_MAX);
    printf("DBL_MIN_HEX=%a\n", DBL_MIN);
    printf("DBL_TRUE_MIN_HEX=%a\n", DBL_TRUE_MIN);
    printf("LDBL_MAX_HEX=%La\n", LDBL_MAX);
    printf("LDBL_MIN_HEX=%La\n", LDBL_MIN);
    printf("LDBL_TRUE_MIN_HEX=%La\n", LDBL_TRUE_MIN);

    return 0;
}
