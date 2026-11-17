#include <stdio.h>

double to_fahrenheit(double c);

int main(void)
{
    // [loop]
    for (int c = 0; c <= 20; c += 5) {
        double f = to_fahrenheit(c);
        printf("%d ℃ -> %.2f ℉\n", c, f);
    }
    // [/loop]
    return 0;
}

// 本例只传入 0、5、10、15、20 ℃。
// [conversion]
double to_fahrenheit(double c)
{
    return c * 9.0 / 5.0 + 32.0;
}
// [/conversion]
