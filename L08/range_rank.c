#include <stdio.h>

int main(void)
{
    // [data]
    int table[3][5] = {
        {49, 52, 47, 50, 52},
        {50, 50, 51, 49, 50},
        {48, 54, 46, 53, 49}
    };
    int ranges[3];
    int order[3] = {0, 1, 2};
    // [/data]

    // [range_stats]
    for (int r = 0; r < 3; ++r) {
        // [row_range]
        int min = table[r][0];
        int max = table[r][0];
        for (int c = 1; c < 5; ++c) {
            if (table[r][c] < min) {
                min = table[r][c];
            }
            if (table[r][c] > max) {
                max = table[r][c];
            }
        }
        ranges[r] = max - min;
        // [/row_range]
        printf("row %d: min=%d max=%d range=%d\n",
               r, min, max, ranges[r]);
    }
    // [/range_stats]

    for (int i = 0; i < 2; ++i) {
        int min_index = i;
        for (int j = i + 1; j < 3; ++j) {
            // [compare_ranges]
            int left = order[j];
            int right = order[min_index];
            if (ranges[left] < ranges[right] ||
                (ranges[left] == ranges[right] && left < right)) {
                min_index = j;
            }
            // [/compare_ranges]
        }
        // [swap_indices]
        if (min_index != i) {
            int temp = order[i];
            order[i] = order[min_index];
            order[min_index] = temp;
        }
        // [/swap_indices]
    }

    // [ranked_rows]
    for (int k = 0; k < 3; ++k) {
        int row = order[k];
        printf("rank %d: row=%d range=%d\n", k + 1, row, ranges[row]);
    }
    // [/ranked_rows]
    puts("original rows:");
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 5; ++c) {
            printf("%d ", table[r][c]);
        }
        putchar('\n');
    }
    return 0;
}
