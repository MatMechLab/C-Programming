#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* 输入：数量0～12（至多2字符），随后是-100～100的整数读数
   （每项至多4字符，含符号），各项用空白分隔。 */
int main(void)
{
    // [count]
    int requested = 0;
    if (scanf("%2d", &requested) != 1 ||
        requested < 0 || requested > 12) {
        puts("invalid count");
        return 1;
    }
    size_t count = (size_t)requested;
    if (count == 0) {
        puts("count=0; no average");
        return 0;
    }
    // [/count]

    // [size]
    int *a = NULL;
    if (count > SIZE_MAX / sizeof *a) {
        puts("size too large");
        return 1;
    }
    // [/size]
    // [allocate]
    a = malloc(count * sizeof *a);
    if (a == NULL) {
        puts("allocation failed");
        return 1;
    }
    // [/allocate]

    int sum = 0;
    // [read]
    for (size_t i = 0; i < count; ++i) {
        int value = 0;
        if (scanf("%4d", &value) != 1 ||
            value < -100 || value > 100) {
            puts("invalid reading");
            free(a);
            return 1;
        }
        a[i] = value;
    }
    // [/read]
    // [report]
    for (size_t i = 0; i < count; ++i) {
        sum += a[i];
    }
    printf("count=%zu sum=%d average=%.2f\n",
           count, sum, (double)sum / count);
    // [/report]
    // [release]
    free(a);
    a = NULL;
    return 0;
    // [/release]
}
