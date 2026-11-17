#include <stdio.h>

int main(void)
{
    int original[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int transposed[3][2];
    // [transpose]
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 3; ++c) {
            transposed[c][r] = original[r][c];
        }
    }
    // [/transpose]

    puts("transposed:");
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 2; ++c) {
            printf("%d ", transposed[r][c]);
        }
        putchar('\n');
    }
    puts("original:");
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 3; ++c) {
            printf("%d ", original[r][c]);
        }
        putchar('\n');
    }
    return 0;
}
