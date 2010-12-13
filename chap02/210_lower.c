#include <stdio.h>
#define dprint(expr) printf(#expr " = '%c'\n", expr)


int
main (int argc, char *argv[])
{
    dprint(lower('A'));
    dprint(lower('z'));
    dprint(lower('0'));
    dprint(lower('-'));
    return 0;
}
/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

