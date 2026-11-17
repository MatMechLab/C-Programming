#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    puts("[integer_literals]");
    printf("decimal_27=%d\n", 27);
    printf("octal_027=%d\n", 027);
    printf("hexadecimal_0x1B=%d\n", 0x1B);

    puts("[floating_literals]");
    /* F后缀得到float，无后缀得到double，L后缀得到long double。 */
    float single_value = 25.0F;
    double double_value = 25.0;
    long double extended_value = 2.5e1L; /* 2.5 × 10^1 */
    printf("float_value=%.1f\n", (double)single_value);
    printf("double_value=%.1f\n", double_value);
    printf("long_double_value=%.1Lf\n", extended_value);
    printf("float_bytes=%zu\n", sizeof single_value);
    printf("double_bytes=%zu\n", sizeof double_value);
    printf("long_double_bytes=%zu\n", sizeof extended_value);

    puts("[number_and_character]");
    int number_value = 3;
    char digit_character = '3';
    printf("number_value=%d\n", number_value);
    printf("digit_character=%c\n", digit_character);
    printf("character_code_observed=%d\n", (int)digit_character);

    puts("[boolean_normalization]");
    bool flag_from_zero = 0;
    bool flag_from_seven = 7;
    printf("flag_from_zero=%d\n", (int)flag_from_zero);
    printf("flag_from_seven=%d\n", (int)flag_from_seven);

    puts("[assignment_copies_value]");
    int sample_count = 4;
    int saved_count = sample_count;
    sample_count = 7;
    printf("sample_count_after_change=%d\n", sample_count);
    printf("saved_count_after_change=%d\n", saved_count);

    return 0;
}
