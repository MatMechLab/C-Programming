/* ERROR EXAMPLE: do not copy. An automatic local int is read before initialization. */
#include <stdio.h>

int main(void)
{
    int sample_count;
    printf("%d\n", sample_count);
    return 0;
}
