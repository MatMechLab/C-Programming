#include <stdio.h>

/* Offline samples from one distance sensor, in time order.
   The returned index identifies a sample, not an obstacle direction.
   Classroom limits: 1 <= n <= 8 and each distance in [0,3000] mm.
   Whenever 1 <= n <= 8 and a is non-NULL, the caller supplies n live,
   readable, initialized int elements.
   index_out and range_out designate two distinct live writable int objects,
   neither overlapping the input elements. All pointer values must be valid
   pointer values or NULL. Return 1 on success, 0 on a detected error.
   A detected failure leaves both output objects unchanged. */
// [closest_guard]
int closest(const int a[], int n,
            int *index_out, int *range_out)
{
    if (n < 1 || n > 8 || a == NULL ||
        index_out == NULL || range_out == NULL ||
        index_out == range_out) {
        return 0;
    }
// [/closest_guard]
    // [closest_loop]
    int best = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0 || a[i] > 3000) {
            return 0;
        }
        if (a[i] < a[best]) {
            best = i;
        }
    }
    // [/closest_loop]
    // [closest_commit]
    *index_out = best;
    *range_out = a[best];
    return 1;
}
// [/closest_commit]

int main(void)
{
    // [closest_call]
    int ranges[4] = {420, 390, 450, 390};
    int index = -1, range = -1;
    int ok = closest(ranges, 4, &index, &range);
    if (ok == 1) {
        printf("closest: index=%d, range=%d\n", index, range);
    }
    // [/closest_call]
    int bad[3] = {420, 3001, 390};
    index = -1;
    range = -1;
    ok = closest(bad, 3, &index, &range);
    printf("invalid: ok=%d, kept=%d,%d\n", ok, index, range);
    int same = -1;
    ok = closest(ranges, 4, &same, &same);
    printf("same output: ok=%d, kept=%d\n", ok, same);
    return 0;
}
