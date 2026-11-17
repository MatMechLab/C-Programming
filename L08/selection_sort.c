#include <stdio.h>

int main(void)
{
    int a[8];
    int n;
    // [input]
    // [input_count]
    if (scanf("%2d", &n) != 1 || n < 0 || n > 8) {
        puts("ERROR: count");
        return 1;
    }
    // [/input_count]
    // [input_values]
    for (int i = 0; i < n; ++i) {
        int value;
        if (scanf("%4d", &value) != 1 ||
            value < -100 || value > 100) {
            printf("ERROR: value %d\n", i);
            return 1;
        }
        a[i] = value;
    }
    // [/input_values]
    // [/input]

    printf("before:");
    for (int i = 0; i < n; ++i) {
        printf(" %d", a[i]);
    }
    putchar('\n');

    // [outer_start]
    for (int i = 0; i < n - 1; ++i) {
        // [/outer_start]
        // [find_min]
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        // [/find_min]
        // [swap]
        if (min_index != i) {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
        // [/swap]
        // [trace]
        printf("round %d:", i + 1);
        for (int k = 0; k < n; ++k) {
            printf(" %d", a[k]);
        }
        putchar('\n');
        // [/trace]
    }

    // [result]
    printf("sorted:");
    for (int i = 0; i < n; ++i) {
        printf(" %d", a[i]);
    }
    putchar('\n');
    // [/result]
    return 0;
}
