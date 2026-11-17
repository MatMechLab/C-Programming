#include <stdio.h>

int main(void)
{
    // [copy_initial]
    int a = 49;
    int b = 52;
    int *p = &a;
    int *q = &b;
    printf("initial: a=%d, b=%d, *p=%d, *q=%d, same=%d\n",
           a, b, *p, *q, p == q);
    // [/copy_initial]
    // [copy_value]
    *p = *q;
    printf("copy value: a=%d, b=%d, *p=%d, *q=%d, same=%d\n",
           a, b, *p, *q, p == q);
    // [/copy_value]
    // [copy_address]
    p = q;
    printf("copy address: a=%d, b=%d, *p=%d, *q=%d, same=%d\n",
           a, b, *p, *q, p == q);
    // [/copy_address]
    // [copy_update]
    *p = 54;
    printf("update: a=%d, b=%d, *p=%d, *q=%d, same=%d\n",
           a, b, *p, *q, p == q);
    // [/copy_update]
    return 0;
}
