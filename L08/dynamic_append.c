#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* 输入约定与dynamic_batch.c相同。按到达次序保存；满了才扩容。
   此例仍限制最多12项，便于手算；动态分配不表示资源无限。 */
int main(void)
{
    int requested = 0;
    if (scanf("%2d", &requested) != 1 ||
        requested < 0 || requested > 12) {
        puts("invalid count");
        return 1;
    }
    // [state]
    int *a = NULL;
    size_t n = 0;
    size_t capacity = 0;
    // [/state]
    for (int k = 0; k < requested; ++k) {
        int value = 0;
        if (scanf("%4d", &value) != 1 ||
            value < -100 || value > 100) {
            puts("invalid reading");
            free(a);
            return 1;
        }
        // [growth_size]
        if (n == capacity) {
            if (capacity > SIZE_MAX / 2) {
                puts("size too large");
                free(a);
                return 1;
            }
            size_t new_capacity = 2;
            if (capacity != 0) {
                new_capacity = capacity * 2;
            }
            // [/growth_size]
            // [byte_size]
            if (new_capacity > SIZE_MAX / sizeof *a) {
                puts("size too large");
                free(a);
                return 1;
            }
            // [/byte_size]
            // [grow]
            int *tmp = realloc(a, new_capacity * sizeof *a);
            if (tmp == NULL) {
                puts("allocation failed");
                free(a);
                return 1;
            }
            a = tmp;
            capacity = new_capacity;
            // [/grow]
            printf("capacity=%zu\n", capacity);
        }
        // [append]
        a[n] = value;
        ++n;
        // [/append]
    }
    // [report]
    printf("count=%zu capacity=%zu\n", n, capacity);
    printf("values:");
    for (size_t i = 0; i < n; ++i) {
        printf(" %d", a[i]);
    }
    putchar('\n');
    free(a);
    a = NULL;
    // [/report]
    return 0;
}
