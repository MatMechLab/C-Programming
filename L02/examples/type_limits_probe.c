#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    /* 范围由实现决定；这里把当前课堂平台的实际宏值打印出来。 */
    puts("[integer_limits]");
    printf("UCHAR_MAX=%u\n", (unsigned int)UCHAR_MAX);
    printf("CHAR_MIN=%jd\n", (intmax_t)CHAR_MIN);
    /* plain char也可能是unsigned；其上界未必能由int表示。 */
    printf("CHAR_MAX=%ju\n", (uintmax_t)CHAR_MAX);
    printf("SHRT_MIN=%d\n", SHRT_MIN);
    printf("SHRT_MAX=%d\n", SHRT_MAX);
    printf("INT_MIN=%d\n", INT_MIN);
    printf("INT_MAX=%d\n", INT_MAX);
    printf("UINT_MAX=%u\n", UINT_MAX);
    printf("LONG_MIN=%ld\n", LONG_MIN);
    printf("LONG_MAX=%ld\n", LONG_MAX);
    printf("LLONG_MIN=%lld\n", LLONG_MIN);
    printf("LLONG_MAX=%lld\n", LLONG_MAX);

    /* MANT_DIG、DIG描述有效精度，不是对象占用的字节数。 */
    puts("[floating_precision]");
    printf("FLT_RADIX=%d\n", FLT_RADIX);
    printf("FLT_MANT_DIG=%d\n", FLT_MANT_DIG);
    printf("DBL_MANT_DIG=%d\n", DBL_MANT_DIG);
    printf("LDBL_MANT_DIG=%d\n", LDBL_MANT_DIG);
    printf("FLT_DIG=%d\n", FLT_DIG);
    printf("DBL_DIG=%d\n", DBL_DIG);
    printf("LDBL_DIG=%d\n", LDBL_DIG);

    /* sizeof给出存储空间，单位永远是字节；1字节有CHAR_BIT位。 */
    puts("[storage_bytes]");
    printf("CHAR_BIT=%d\n", CHAR_BIT);
    printf("sizeof_char=%zu\n", sizeof(char));
    printf("sizeof_short=%zu\n", sizeof(short));
    printf("sizeof_int=%zu\n", sizeof(int));
    printf("sizeof_unsigned_int=%zu\n", sizeof(unsigned int));
    printf("sizeof_long=%zu\n", sizeof(long));
    printf("sizeof_long_long=%zu\n", sizeof(long long));
    printf("sizeof_float=%zu\n", sizeof(float));
    printf("sizeof_double=%zu\n", sizeof(double));
    printf("sizeof_long_double=%zu\n", sizeof(long double));
    printf("sizeof_bool=%zu\n", sizeof(bool));

    return 0;
}
