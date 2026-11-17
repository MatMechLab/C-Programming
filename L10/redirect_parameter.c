#include <stdio.h>

/* p and other point to live, initialized, writable int objects. */
// [redirect]
void choose_locally(int *p, int *other)
{
    p = other;
    *p = 410;
}
// [/redirect]

int main(void)
{
    // [call]
    int first = 420, second = 390;
    int *selected = &first;
    choose_locally(selected, &second);
    printf("first=%d, second=%d\n", first, second);
    printf("selected still points to first: %d\n",
           selected == &first);
    // [/call]
    return 0;
}
