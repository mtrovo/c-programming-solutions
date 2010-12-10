#include <stdio.h>

// replace one or more blanks by only one
main (int argc, char *argv[])
{
    char c;
    while((c = getchar()) != EOF)
    {
        if (' ' == c)
        {
            // print first blank
            printf("%c", c);
            // while blank don't do nothing
            while((c = getchar()) == ' ');
            // unget the char different from blank
            // sorry, a little bored to not use ungetc
            ungetc(c, stdin);
        } else printf("%c", c);
    }
    return 0;
}

