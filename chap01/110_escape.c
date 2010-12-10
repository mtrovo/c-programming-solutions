#include <stdio.h>

/* encode tabs, backspaces and '\' on the input to their
   corresponding as a C literal string */
main (int argc, char *argv[])
{
    char c;
    while (EOF != (c = getchar()))
    {
        switch(c)
        {
        case '\t': printf("\\t");  break;
        case '\b': printf("\\b");  break;
        case '\\': printf("\\\\"); break;
        default: printf("%c", c);  break;
        }
    }
    return 0;
}

