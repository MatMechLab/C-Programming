#include <stdio.h>

/* Return 1 on success, 0 on a detected argument error.
   On success a must provide n readable, initialized int elements.
   low_out and high_out must designate two distinct live writable int objects,
   neither overlapping the input elements. All pointer values must already
   be valid pointer values (or NULL); null checks cannot verify arbitrary
   pointer validity or the actual array extent. A detected failure performs
   no output writes. The caller must test the return value before using
   the outputs as results of this call. */
// [guard]
int minmax(const int a[], int n,
           int *low_out, int *high_out)
{
    if (n <= 0 || a == NULL ||
        low_out == NULL || high_out == NULL ||
        low_out == high_out) {
        return 0;
    }
// [/guard]
    // [scan]
    int low = a[0];
    int high = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] < low) {
            low = a[i];
        }
        if (a[i] > high) {
            high = a[i];
        }
    }
    // [/scan]
    // [commit]
    *low_out = low;
    *high_out = high;
    return 1;
}
// [/commit]

int main(void)
{
    // [call]
    int ranges[4] = {420, 390, 450, 410};
    int low = -1, high = -1;
    int ok = minmax(ranges, 4, &low, &high);
    if (ok == 1) {
        printf("normal: min=%d, max=%d\n", low, high);
    }
    // [/call]
    low = -1;
    high = -1;
    ok = minmax(ranges, 0, &low, &high);
    printf("empty: ok=%d, kept=%d,%d\n", ok, low, high);
    int same = -1;
    ok = minmax(ranges, 4, &same, &same);
    printf("same output: ok=%d, kept=%d\n", ok, same);
    // [subrange]
    ok = minmax(&ranges[1], 2, &low, &high);
    if (ok == 1) {
        printf("middle: min=%d, max=%d\n", low, high);
    }
    // [/subrange]
    return 0;
}
