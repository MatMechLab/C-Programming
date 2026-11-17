#include <stdio.h>

/* n >= 0; a provides n readable int elements when n > 0. */
// [show]
void show(const int a[], int n)
{
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
// [/show]

/* When n > 0, a must provide n writable int elements. */
// [change]
void reset_first(int a[], int n)
{
    if (n > 0) {
        a[0] = 400;
    }
}
// [/change]

int main(void)
{
    // [array]
    int readings[6] = {420, 390, 450, 410};
    int n = 4;
    // [/array]
    // [call]
    show(readings, n);
    reset_first(readings, n);
    show(readings, n);
    // [/call]
    // [capacity]
    printf("capacity=%zu, n=%d\n",
           sizeof readings / sizeof readings[0], n);
    // [/capacity]
    return 0;
}
