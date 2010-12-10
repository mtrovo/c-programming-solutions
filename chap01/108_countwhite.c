#include <stdio.h>

// counts whitespace (blanks, tabs and new lines)
main (int argc, char *argv[])
{
    char c;
    int sum = 0;
    while((c = getchar()) != EOF)
    {
        if (' ' == c || '\t' == c || '\n' == c)
            sum += 1;
    }

    printf("count = %d", sum);
    return 0;
}

