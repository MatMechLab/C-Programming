#include <limits.h>
#include <stdio.h>

int main(void)
{
    int sample_count = 9;

    printf("value_before=%d\n", sample_count);
    printf("sizeof_sample_count_before=%zu\n", sizeof sample_count);
    printf("sizeof_int=%zu\n", sizeof(int));
    printf("CHAR_BIT=%d\n", CHAR_BIT);

    sample_count = 12000;
    printf("value_after=%d\n", sample_count);
    printf("sizeof_sample_count_after=%zu\n", sizeof sample_count);
    return 0;
}
