#include <stdio.h>

// Test if getchar() != EOF always equals 0 or 1.
// It must print various 1 followed by a 0 just before EOF.
main (int argc, char *argv[])
{
    char c;
    while (1)
    {
        c = getchar();

        // must never show this
        if(0 != c && 1 != c) printf("\n*** found something weird ***\n");

        printf("%d", c != EOF);
        if(c == EOF) return 0;
    }
    return 0;
}

