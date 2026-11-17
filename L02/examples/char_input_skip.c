#include <stdio.h>

static void print_marker(char marker)
{
    printf("marker_is_newline=%d\n", marker == '\n');
    printf("marker_code_observed=%u\n", (unsigned int)(unsigned char)marker);
    printf("marker=%c\n", marker);
}

int main(void)
{
    int id = 0;
    char marker = '\0';

    /* 格式串开头的空白表示：先跳过任意数量的空白字符。 */
    if (scanf("%d", &id) != 1) {
        puts("input_error=id");
        return 1;
    }
    if (scanf(" %c", &marker) != 1) {
        puts("input_error=marker");
        return 1;
    }

    printf("id=%d\n", id);
    print_marker(marker);
    return 0;
}
