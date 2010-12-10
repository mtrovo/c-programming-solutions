#include <stdio.h>
#define MAXLINE 81 /* maximum input line length */

int getl(char line[], int maxline);
/* print lines greater than MAXLINE */
main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    char c; /* current input char */

    while ((len = getl(line, MAXLINE)) > 0)
        if (len + 1 > MAXLINE) {
            printf("%s", line);
            while((c=getchar())!=EOF && c!='\n') printf("%c", c);

            printf("\n");
        }

    return 0;
}

/* getline: read a line into s, return length */
int getl(char s[],int lim)
{
    int c, i;

    for (i=0; i < lim && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    s[i] = '\0';

    return i;
}

