#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // [data]
    const int reading[] = {49, 52, 47, 50, 54, 48};
    size_t n = sizeof reading / sizeof reading[0];
    size_t groups = 3;
    int *counts = NULL;
    // [/data]
    if (groups > SIZE_MAX / sizeof *counts) {
        puts("size too large");
        return 1;
    }
    // [allocate]
    counts = calloc(groups, sizeof *counts);
    if (counts == NULL) {
        puts("allocation failed");
        return 1;
    }
    // [/allocate]
    // [classify]
    for (size_t i = 0; i < n; ++i) {
        size_t group = 1;
        if (reading[i] < 48) {
            group = 0;
        } else if (reading[i] > 52) {
            group = 2;
        }
        ++counts[group];
    }
    // [/classify]
    printf("below=%d inside=%d above=%d\n",
           counts[0], counts[1], counts[2]);
    free(counts);
    return 0;
}
