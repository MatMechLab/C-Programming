#include <stdio.h>

int main(void)
{
    int a[6] = {52, 47, 50, 47, 54, 49};
    int n = 6;
    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        // [count_comparisons]
        for (int j = i + 1; j < n; ++j) {
            ++comparisons;
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        // [/count_comparisons]
        // [count_swaps]
        if (min_index != i) {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
            ++swaps;
        }
        // [/count_swaps]
    }
    printf("comparisons=%d swaps=%d\n", comparisons, swaps);
    printf("sorted:");
    for (int i = 0; i < n; ++i) {
        printf(" %d", a[i]);
    }
    putchar('\n');
    return 0;
}
