#include <stdio.h>

int main(void)
{
    // [unary]
    int x = -6;
    printf("+x = %d\n", +x);
    printf("-x = %d\n", -x);
    printf("x - 2 = %d\n", x - 2);
    printf("x remains %d\n", x);
    // [/unary]

    // [value_and_update]
    int plain = 8;
    int result = plain + 3;
    int updated = 8;
    updated += 3;
    printf("plain = %d; result = %d\n", plain, result);
    printf("updated = %d\n", updated);
    // [/value_and_update]

    // [compound]
    int add_value = 17;
    int subtract_value = 17;
    int multiply_value = 17;
    int divide_value = 17;
    int remainder_value = 17;
    add_value += 5;
    subtract_value -= 5;
    multiply_value *= 5;
    divide_value /= 5;
    remainder_value %= 5;
    printf("add_value after += 5: %d\n", add_value);
    printf("subtract_value after -= 5: %d\n", subtract_value);
    printf("multiply_value after *= 5: %d\n", multiply_value);
    printf("divide_value after /= 5: %d\n", divide_value);
    printf("remainder_value after %%= 5: %d\n", remainder_value);
    // [/compound]

    // [compound_grouping]
    int grouped_n = 4;
    int expanded_n = 4;
    int a = 2;
    int b = 3;
    grouped_n *= a + b;
    expanded_n = expanded_n * (a + b);
    printf("grouped n = %d\n", grouped_n);
    printf("expanded n = %d\n", expanded_n);
    // [/compound_grouping]

    // [remainder]
    int number = 247;
    printf("247 %% 10 = %d\n", number % 10);
    printf("247 / 10 = %d\n", number / 10);
    printf("247 %% 2 = %d\n", number % 2);
    // [/remainder]

    // [decrement]
    int prefix_remaining = 5;
    int prefix_value = --prefix_remaining;
    int postfix_remaining = 5;
    int postfix_value = postfix_remaining--;
    printf("prefix: value = %d; remaining = %d\n", prefix_value, prefix_remaining);
    printf("postfix: value = %d; remaining = %d\n", postfix_value, postfix_remaining);
    // [/decrement]

    // [assign_compare]
    int assigned = 3;
    assigned = 5;
    int compared = 3;
    int same = (compared == 5);
    printf("assigned = %d\n", assigned);
    printf("same = %d; compared = %d\n", same, compared);
    // [/assign_compare]

    // [comparison]
    int n = 5;
    int limit = 8;
    printf("n < limit: %d\n", n < limit);
    printf("n <= limit: %d\n", n <= limit);
    printf("n > limit: %d\n", n > limit);
    printf("n >= limit: %d\n", n >= limit);
    printf("n == limit: %d\n", n == limit);
    printf("n != limit: %d\n", n != limit);
    // [/comparison]

    // [logical]
    int ready = 2;
    int fault = 0;
    int flag_two = 2;
    int flag_one = 1;
    printf("!ready = %d\n", !ready);
    printf("!fault = %d\n", !fault);
    printf("ready && fault = %d\n", ready && fault);
    printf("fault && ready = %d\n", fault && ready);
    printf("ready || fault = %d\n", ready || fault);
    printf("ready && !fault = %d\n", ready && !fault);
    printf("flag_two && flag_one = %d\n", flag_two && flag_one);
    // [/logical]
    return 0;
}
