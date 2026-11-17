#include <stdio.h>

/* a、b 是两个传感器的虚构读数；加 2 只是本题约定。 */

int main(void)
{
    int a = 49;
    int b = 52;
    // [input]
    int choice;
    if (scanf("%2d", &choice) != 1) {
        puts("input error");
        return 1;
    }
    if (choice < 0 || choice > 2) {
        puts("choice out of range");
        return 1;
    }
    // [/input]
    // [choose]
    int *p = NULL;
    if (choice == 1) {
        p = &a;
    } else if (choice == 2) {
        p = &b;
    }
    // [/choose]
    // [update]
    if (p != NULL) {
        *p += 2;
        printf("selected=%d\n", *p);
    } else {
        puts("no selection");
    }
    printf("a=%d, b=%d\n", a, b);
    // [/update]
    return 0;
}
