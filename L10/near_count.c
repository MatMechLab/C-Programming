#include <stdio.h>

/* Count offline samples whose distance is <= limit.
   This is a classroom review threshold, not a collision-safety rule.
   Classroom limits: 0 <= n <= 8, 0 <= limit <= 3000, every value in [0,3000].
   When n > 0, a provides n readable, initialized int elements.
   count_out designates a live writable int outside the input elements.
   All pointer values must be valid pointer values or NULL. n == 0 permits
   a == NULL and succeeds with count 0 when the other arguments are valid.
   Return 1 on success, 0 on a detected error; failure preserves the output. */
// [count_guard]
int count_near(const int a[], int n, int limit, int *count_out)
{
    if (n < 0 || n > 8 || limit < 0 || limit > 3000 ||
        count_out == NULL || (n > 0 && a == NULL)) {
        return 0;
    }
// [/count_guard]
    // [count_loop]
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0 || a[i] > 3000) {
            return 0;
        }
        if (a[i] <= limit) {
            ++count;
        }
    }
    // [/count_loop]
    // [count_commit]
    *count_out = count;
    return 1;
}
// [/count_commit]

int main(void)
{
    // [count_call]
    int ranges[4] = {420, 390, 450, 400};
    int count = -1;
    int ok = count_near(ranges, 4, 400, &count);
    if (ok == 1) {
        printf("limit=400: count=%d\n", count);
    }
    // [/count_call]
    ok = count_near(ranges, 4, 399, &count);
    if (ok == 1) {
        printf("limit=399: count=%d\n", count);
    }
    ok = count_near(NULL, 0, 400, &count);
    printf("empty: ok=%d, count=%d\n", ok, count);
    count = -1;
    ok = count_near(ranges, 4, 3001, &count);
    printf("invalid limit: ok=%d, kept=%d\n", ok, count);
    int bad[3] = {390, 3001, 400};
    ok = count_near(bad, 3, 400, &count);
    printf("invalid reading: ok=%d, kept=%d\n", ok, count);
    return 0;
}
