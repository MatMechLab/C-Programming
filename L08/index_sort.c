#include <stdio.h>

int main(void)
{
    // [data]
    int reading[4] = {54, 48, 54, 50};
    int order[4] = {0, 1, 2, 3};
    // [/data]

    for (int i = 0; i < 3; ++i) {
        int min_index = i;
        for (int j = i + 1; j < 4; ++j) {
            // [compare_indices]
            int left = order[j];
            int right = order[min_index];
            if (reading[left] < reading[right] ||
                (reading[left] == reading[right] && left < right)) {
                min_index = j;
            }
            // [/compare_indices]
        }
        // [swap_indices]
        if (min_index != i) {
            int temp = order[i];
            order[i] = order[min_index];
            order[min_index] = temp;
        }
        // [/swap_indices]
    }

    // [display]
    for (int k = 0; k < 4; ++k) {
        int original_index = order[k];
        printf("rank %d: index=%d value=%d\n",
               k + 1, original_index, reading[original_index]);
    }
    // [/display]
    printf("original:");
    for (int i = 0; i < 4; ++i) {
        printf(" %d", reading[i]);
    }
    putchar('\n');
    return 0;
}
