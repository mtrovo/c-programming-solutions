#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getl(char line[], int maxline);
/* print the longest input line */
main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    int i; /* current position within line*/

    while ((len = getl(line, MAXLINE)) >= 0){
        i = len - 1;
        while(i >= 0 && (line[i] == ' ' || line[i] == '\t')) --i;

        if(i < 0) ; // blank line, do nothing
        else {
            line[i + 1] = '\0';
            printf("%s\n", line);
        }
    }

    return 0;
}

/* getline: read a line into s, return length or -1 if EOF */
int getl(char s[],int lim){
    int c, i;

    for (i=0; i < lim && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    s[i] = '\0';

    // differentiate blank lines from EOF
    return i == 0 && c == EOF ? -1 : i;
}

