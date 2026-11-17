#include <stddef.h>
/* Deliberately misleading: this measures a pointer, not array capacity.
   Compile for diagnostics only; never run this example. */
size_t wrong_length(int a[])
{
    return sizeof a / sizeof a[0];
}
