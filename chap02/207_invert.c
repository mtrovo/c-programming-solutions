#include <stdio.h>
#define dprint(expr) printf(#expr " = %X\n", expr)

int invert(int x, int p, int n);
main (int argc, char *argv[])
{
    dprint(invert(0xFFFF, 4, 8));
    dprint(invert(0xFFFF, 2, 4));
    dprint(invert(0xFF3F, 4, 4));
    dprint(invert(0xDeadBeef, 4, 4));

    return 0;
}

int invert(int x, int p, int n){
    return x ^ (~(~0 << n) << p);
}

