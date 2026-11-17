#include <stdio.h>

int main(void)
{
    // [stable_copy]
    int stable = 0;
    int *p = &stable;
    {
        int local = 53;
        stable = local;
    }
    printf("after block: *p=%d\n", *p);
    // [/stable_copy]

    // [borrow]
    int *borrowed = NULL;
    {
        int temporary = 47;
        borrowed = &temporary;
        printf("inside block: *borrowed=%d\n", *borrowed);
        // [clear]
        borrowed = NULL;
    }
    printf("after block: borrowed is null=%d\n",
           borrowed == NULL);
    // [/clear]
    // [/borrow]
    return 0;
}
