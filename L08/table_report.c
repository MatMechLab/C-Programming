#include <stdio.h>

int main(void)
{
    // [data]
    int table[3][4] = {
        {49, 52, 47, 50},
        {51, 50, 50, 49},
        {48, 54, 46, 52}
    };
    // [/data]

    puts("table:");
    // [traverse]
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 4; ++c) {
            printf("%d ", table[r][c]);
        }
        putchar('\n');
    }
    // [/traverse]

    // [row_stats]
    for (int r = 0; r < 3; ++r) {
        // [row_begin]
        int sum = 0;
        int max = table[r][0];
        int max_col = 0;
        // [/row_begin]
        // [row_scan]
        for (int c = 0; c < 4; ++c) {
            sum += table[r][c];
            if (table[r][c] > max) {
                max = table[r][c];
                max_col = c;
            }
        }
        // [/row_scan]
        // [row_result]
        double mean = (double)sum / 4;
        printf("row %d: sum=%d mean=%.2f ", r, sum, mean);
        printf("max=%d col=%d\n", max, max_col);
        // [/row_result]
    }
    // [/row_stats]

    // [column_stats]
    for (int c = 0; c < 4; ++c) {
        int sum = 0;
        for (int r = 0; r < 3; ++r) {
            sum += table[r][c];
        }
        printf("col %d: sum=%d mean=%.2f\n",
               c, sum, (double)sum / 3);
    }
    // [/column_stats]

    // [first2d]
    // [first2d_init]
    int target = 50;
    int row = -1;
    int col = -1;
    // [/first2d_init]
    // [first2d_loop]
    for (int r = 0; r < 3 && row == -1; ++r) {
        for (int c = 0; c < 4; ++c) {
            if (table[r][c] == target) {
                row = r;
                col = c;
                break;
            }
        }
    }
    // [/first2d_loop]
    // [/first2d]
    if (row != -1) {
        printf("first %d: row=%d col=%d\n", target, row, col);
    } else {
        printf("first %d: not found\n", target);
    }

    int count = 0;
    printf("all %d:", target);
    // [all2d]
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 4; ++c) {
            if (table[r][c] == target) {
                printf(" (%d,%d)", r, c);
                ++count;
            }
        }
    }
    // [/all2d]
    printf(" count=%d\n", count);

    int alert_count = 0;
    printf("alerts:");
    // [alerts]
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 4; ++c) {
            if (table[r][c] < 48 || table[r][c] > 52) {
                printf(" (%d,%d)=%d", r, c, table[r][c]);
                ++alert_count;
            }
        }
    }
    // [/alerts]
    printf(" count=%d\n", alert_count);
    return 0;
}
