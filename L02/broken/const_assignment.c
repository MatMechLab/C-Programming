/* ERROR EXAMPLE: do not copy. A const-qualified object is not assignable. */
int main(void)
{
    const double scale = 1.8;
    scale = 2.0;
    return 0;
}
