#include <stdio.h>

int main(void)
{
    // [clear_declare]
    int *p = NULL;
    int *q = NULL;
    // [/clear_declare]
    // [clear_block]
    // [clear_share]
    {
        int temporary = 53;
        p = &temporary;
        q = p;
        printf("shared: *p=%d, *q=%d\n", *p, *q);
        // [/clear_share]
        // [clear_one]
        p = NULL;
        *q = 54;
        printf("clear p: p is null=%d, *q=%d\n",
               p == NULL, *q);
        // [/clear_one]
        // [clear_last]
        q = NULL;
    }
    printf("after block: p is null=%d, q is null=%d\n",
           p == NULL, q == NULL);
    // [/clear_last]
    // [/clear_block]
    return 0;
}
