/* ERROR EXAMPLE: do not run. scanf requires int *, not the int value itself. */
#include <stdio.h>

int main(void)
{
    int experiment_id = 0;
    return scanf("%d", experiment_id) == 1 ? 0 : 1;
}
