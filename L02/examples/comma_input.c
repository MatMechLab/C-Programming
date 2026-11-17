#include <stdio.h>

int main(void)
{
    int id = -1;
    double value = -999.0;
    int assigned = scanf("%d,%lf", &id, &value);

    if (assigned == EOF) {
        puts("assigned=EOF");
    } else {
        printf("assigned=%d\n", assigned);
    }
    /* 仅观察哪些对象被赋值；失败后的值不参与计算。 */
    printf("id=%d\n", id);
    printf("value=%.2f\n", value);

    if (assigned != 2) {
        puts("ready=no");
        return 1;
    }
    puts("ready=yes");
    return 0;
}
