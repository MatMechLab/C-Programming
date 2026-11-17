#include <stdio.h>

static void print_marker(char marker)
{
    printf("marker_is_newline=%d\n", marker == '\n');
    printf("marker_code_observed=%u\n", (unsigned int)(unsigned char)marker);

    if (marker == '\n') {
        puts("marker=<newline>");
    } else if (marker == ' ') {
        puts("marker=<space>");
    } else if (marker == '\t') {
        puts("marker=<tab>");
    } else {
        printf("marker=%c\n", marker);
    }
}

int main(void)
{
    int id = 0;
    char marker = '\0';

    /* 这些课堂测试只输入int可表示的数；返回1并不检查数值是否越界。 */
    if (scanf("%d", &id) != 1) {
        puts("input_error=id");
        return 1;
    }
    if (scanf("%c", &marker) != 1) {
        puts("input_error=marker");
        return 1;
    }

    printf("id=%d\n", id);
    print_marker(marker);
    return 0;
}
