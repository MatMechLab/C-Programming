#include <stdio.h>

int main(void)
{
    // [declarations]
    int a[2][3] = {{1, 2}, {3}};
    int b[2][3] = {{1, 2, 3}};
    int z[2][3] = {0};
    int inferred[][3] = {{1, 2, 3}, {4, 5, 6}};
    // [/declarations]

    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 3; ++c) {
            printf("a[%d][%d]=%d b=%d z=%d\n",
                   r, c, a[r][c], b[r][c], z[r][c]);
        }
    }
    // [dimensions]
    printf("rows=%zu\n",
           sizeof inferred / sizeof inferred[0]);
    printf("cols=%zu\n",
           sizeof inferred[0] / sizeof inferred[0][0]);
    printf("elements=%zu\n",
           sizeof inferred / sizeof inferred[0][0]);
    // [/dimensions]
    return 0;
}
