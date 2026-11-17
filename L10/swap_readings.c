#include <stdio.h>

/* Both pointers must designate live, initialized, writable int objects.
   They may designate the same object. No sensor-channel labels are swapped. */
// [swap]
void swap_values(int *left, int *right)
{
    int temp = *left;
    *left = *right;
    *right = temp;
}
// [/swap]

int main(void)
{
    // [call]
    int first = 420;
    int second = 390;
    swap_values(&first, &second);
    printf("first=%d, second=%d\n", first, second);
    // [/call]
    swap_values(&first, &first);
    printf("same object: first=%d\n", first);
    return 0;
}
