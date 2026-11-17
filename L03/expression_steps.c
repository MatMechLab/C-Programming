#include <stdio.h>

int main(void)
{
    // [arithmetic]
    printf("17 + 5 = %d\n", 17 + 5);
    printf("17 - 5 = %d\n", 17 - 5);
    printf("17 * 5 = %d\n", 17 * 5);
    printf("17 / 5 = %d\n", 17 / 5);
    printf("17 %% 5 = %d\n", 17 % 5);
    printf("-17 / 5 = %d; -17 %% 5 = %d\n", -17 / 5, -17 % 5);
    printf("17 / -5 = %d; 17 %% -5 = %d\n", 17 / -5, 17 % -5);
    printf("-17 / -5 = %d; -17 %% -5 = %d\n", -17 / -5, -17 % -5);
    // [/arithmetic]

    // [grouping]
    printf("8 + 6 / 2 = %d\n", 8 + 6 / 2);
    printf("(8 + 6) / 2 = %d\n", (8 + 6) / 2);
    printf("20 / 3 / 2 = %d\n", 20 / 3 / 2);
    printf("20 / (3 / 2) = %d\n", 20 / (3 / 2));
    // [/grouping]

    // [compound]
    int total_mm = 17;
    total_mm += 5;
    total_mm *= 2;
    total_mm -= 1;
    total_mm /= 2;
    printf("after +=, *=, -=, /=: total_mm = %d\n", total_mm);
    // [/compound]

    // [increment]
    int count = 3;
    count++;
    printf("after count++: count = %d\n", count);
    ++count;
    printf("after ++count: count = %d\n", count);
    // [/increment]
    return 0;
}
