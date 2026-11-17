#include <stdio.h>

int main(void)
{
    // [division]
    int whole = 5 / 2;
    double late = 5 / 2;
    double after = (double)(5 / 2);
    double before = (double)5 / 2;
    double by_literal = 5 / 2.0;
    printf("5 / 2 -> int: %d\n", whole);
    printf("5 / 2 -> double: %.1f\n", late);
    printf("(double)(5 / 2): %.1f\n", after);
    printf("(double)5 / 2: %.1f\n", before);
    printf("5 / 2.0: %.1f\n", by_literal);
    // [/division]

    // [cast]
    int original = 5;
    double converted = (double)original;
    printf("original = %d; converted = %.1f\n", original, converted);
    printf("-5 / 2 = %d\n", -5 / 2);
    printf("(int)2.9 = %d; (int)-2.9 = %d\n", (int)2.9, (int)-2.9);
    // [/cast]

    // [unit]
    int distance_mm = 1250;
    double distance_m = distance_mm / 1000.0;
    printf("%d mm = %.3f m\n", distance_mm, distance_m);
    // [/unit]
    return 0;
}
