#include <stdio.h>

/* Classroom distance data only: 0 <= n <= 8 and each value in [0,3000].
   When n > 0, a provides n readable initialized int elements.
   sum_out points to a live writable int outside the input region.
   n == 0 succeeds with sum 0, and a may then be NULL.
   Returns 0 on a detected error without modifying *sum_out. */
// [sum_guard]
int range_sum(const int a[], int n, int *sum_out)
{
    if (n < 0 || n > 8 || sum_out == NULL ||
        (n > 0 && a == NULL)) {
        return 0;
    }
// [/sum_guard]
    // [sum_loop]
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0 || a[i] > 3000) {
            return 0;
        }
        sum += a[i];
    }
    *sum_out = sum;
    return 1;
}
// [/sum_loop]

int main(void)
{
    int ranges[4] = {420, 390, 450, 410};
    int sum = -1;
    int ok = range_sum(ranges, 4, &sum);
    if (ok == 1) {
        printf("normal: sum=%d\n", sum);
    }
    ok = range_sum(NULL, 0, &sum);
    printf("empty: ok=%d, sum=%d\n", ok, sum);
    int bad[3] = {420, 3001, 410};
    sum = -1;
    ok = range_sum(bad, 3, &sum);
    printf("invalid: ok=%d, kept=%d\n", ok, sum);
    return 0;
}
