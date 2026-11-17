#include <stdio.h>

int main(void)
{
    double length_mm = 12.3125;

    puts("[field_width_and_precision]");
    printf("width_8=|%8.2f|\n", length_mm);
    printf("width_4=|%4.2f|\n", length_mm);
    printf("four_decimals=%.4f\n", length_mm);
    printf("stored_value_after_print=%.4f\n", length_mm);

    puts("[same_double_different_output_precision]");
    double fraction = 0.1;
    printf("one_decimal=%.1f\n", fraction);
    printf("seventeen_decimals=%.17f\n", fraction);

    puts("[escape_sequences]");
    printf("Material: \"Steel\"\n");
    printf("Folder: C:\\lab\\sample\n");
    printf("Load: 40%%\n");

    return 0;
}
