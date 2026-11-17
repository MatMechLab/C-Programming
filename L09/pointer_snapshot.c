#include <stdio.h>

int main(void)
{
    // [snapshot_initial]
    int reading = 48;
    int *p = &reading;
    int copy = *p;
    printf("before: reading=%d, *p=%d, copy=%d\n",
           reading, *p, copy);
    // [/snapshot_initial]
    // [snapshot_update]
    *p = 51;
    printf("after: reading=%d, *p=%d, copy=%d\n",
           reading, *p, copy);
    // [/snapshot_update]
    return 0;
}
