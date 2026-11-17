#include <stdio.h>

int main(void)
{
    unsigned int batch_code = 58;

    printf("decimal=%u\n", batch_code);
    printf("octal=%o\n", batch_code);
    printf("hex_lower=%x\n", batch_code);
    printf("hex_upper=%X\n", batch_code);
    printf("decimal_after=%u\n", batch_code);
    return 0;
}
