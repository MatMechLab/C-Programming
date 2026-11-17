#include <stdio.h>

int main(void)
{
    // [view]
    int calibration = 50;
    const int *view = &calibration;
    printf("initial view=%d\n", *view);
    // [/view]
    // [update]
    calibration = 51;
    printf("after direct write: view=%d\n", *view);
    // [/update]
    // [readonly]
    const int baseline = 48;
    view = &baseline;
    printf("baseline view=%d\n", *view);
    // [/readonly]
    return 0;
}
