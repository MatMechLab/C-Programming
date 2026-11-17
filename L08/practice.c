#include <stdio.h>

/* 课堂练习起始文件：可以编译，但三个任务尚未实现。 */
int main(void)
{
    int table[3][4] = {
        {49, 52, 47, 50},
        {51, 50, 50, 49},
        {48, 54, 46, 52}
    };
    int target = 50;
    int a[6] = {52, 47, 50, 47, 54, 49};

    puts("table:");
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 4; ++c) {
            printf("%d ", table[r][c]);
        }
        putchar('\n');
    }
    printf("target=%d\n", target);
    printf("before:");
    for (int i = 0; i < 6; ++i) {
        printf(" %d", a[i]);
    }
    putchar('\n');

    puts("UNFINISHED: the candidate values below are not final answers.");

    // [practice_rows]
    for (int r = 0; r < 3; ++r) {
        int max = table[r][0];
        int max_col = 0;
        for (int c = 1; c < 4; ++c) {
            /* TODO 1：若当前值更大，更新max和max_col。 */
        }
        printf("row %d candidate: max=%d col=%d\n", r, max, max_col);
    }
    // [/practice_rows]

    // [practice_matches]
    int count = 0;
    printf("unfinished matches:");
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 4; ++c) {
            /* TODO 2：若等于target，输出(r,c)并增加count。 */
        }
    }
    printf(" count=%d\n", count);
    // [/practice_matches]

    // [practice_sort]
    for (int i = 0; i < 5; ++i) {
        int min_index = i;
        for (int j = i + 1; j < 6; ++j) {
            /* TODO 3a：若找到更小值，更新min_index。 */
        }
        /* TODO 3b：两个位置不同时，用临时变量完成三步交换。 */
        printf("unfinished round %d: candidate=%d;", i + 1, min_index);
        for (int k = 0; k < 6; ++k) {
            printf(" %d", a[k]);
        }
        putchar('\n');
    }
    printf("unfinished final:");
    for (int i = 0; i < 6; ++i) {
        printf(" %d", a[i]);
    }
    putchar('\n');
    // [/practice_sort]
    return 0;
}
