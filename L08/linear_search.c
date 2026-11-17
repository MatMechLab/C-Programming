#include <stdio.h>

int main(void)
{
    int a[8];
    int n;
    int target;

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
        if (scanf("%4d", &value) != 1 || value < -100 || value > 100) {
            printf("ERROR: value %d\n", i);
            return 1;
        }
        a[i] = value;
    }
    // [/input_values]
    // [input_target]
    if (scanf("%4d", &target) != 1 || target < -100 || target > 100) {
        puts("ERROR: target");
        return 1;
    }
    // [/input_target]
    // [/input]

    // [first]
    int first = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == target) {
            first = i;
            break;
        }
    }
    // [/first]

    // [find_guard]
    if (first != -1) {
        printf("first=%d value=%d\n", first, a[first]);
    } else {
        puts("first=-1");
    }
    // [/find_guard]

    // [last]
    int last = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == target) {
            last = i;
        }
    }
    // [/last]
    printf("last=%d\n", last);

    // [all]
    int count = 0;
    printf("matches:");
    for (int i = 0; i < n; ++i) {
        if (a[i] == target) {
            printf(" %d", i);
            ++count;
        }
    }
    printf(" count=%d\n", count);
    // [/all]
    return 0;
}
