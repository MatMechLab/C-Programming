#include <math.h>
#include <stdio.h>

int main(void)
{
    // [grouping]
    double a = 8.0;
    double b = 4.0;
    double c = 3.0;
    double d = 1.0;
    printf("(a + b) / (c + d) = %.6f\n", (a + b) / (c + d));
    printf("a + b / c + d = %.6f\n", a + b / c + d);
    // [/grouping]

    // [unary]
    printf("-(a - b) = %.1f\n", -(a - b));
    // [/unary]

    // [geometry]
    int length = 5;
    int width = 3;
    int perimeter = 2 * (length + width);
    int square = length * length;
    printf("perimeter = %d; length squared = %d\n", perimeter, square);
    // [/geometry]

    // [compound]
    int count = 9;
    count /= 2.0;
    printf("after count /= 2.0: count = %d\n", count);
    // [/compound]

    // [unit]
    printf("1250 / 1000 = %d\n", 1250 / 1000);
    printf("1250 / 1000.0 = %.3f\n", 1250 / 1000.0);
    // [/unit]

    // [mixed]
    printf("2.0 + 9 / 4 = %.1f\n", 2.0 + 9 / 4);
    printf("(2.0 + 9) / 4 = %.2f\n", (2.0 + 9) / 4);
    // [/mixed]

    // [rearrange]
    printf("7 / 2 * 2.0 = %.1f\n", 7 / 2 * 2.0);
    printf("7 * 2.0 / 2 = %.1f\n", 7 * 2.0 / 2);
    // [/rearrange]

    // [cast]
    printf("(int)2.75 = %d\n", (int)2.75);
    printf("(int)-2.75 = %d\n", (int)-2.75);
    // [/cast]

    // [absolute_error]
    printf("fabs(18.5 - 20.0) = %.1f\n", fabs(18.5 - 20.0));
    printf("fabs(21.5 - 20.0) = %.1f\n", fabs(21.5 - 20.0));
    // [/absolute_error]
    return 0;
}
