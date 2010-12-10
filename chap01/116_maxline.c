#include <stdio.h>
#define MAXLINE 100 /* maximum input line length */

int getl(char line[], int maxline);
void copy(char to[], char from[]);
/* print the longest input line */
main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = getl(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }

    if (max > 0) /* there was a line */
        printf("length: %d\n%s%s\n", max, longest, max > MAXLINE ? "[...]" : "");
    return 0;
}

/* getline: read a line into s, return length */
int getl(char s[],int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    // if it was not at the end of a line or of the input increment
    // variable i so we return the correct value
    if(c!=EOF && c!='\n'){
        while((c=getchar())!=EOF && c!='\n') ++i;
        if(c == '\n') i++;
    }

    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') ++i;
}

