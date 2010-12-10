#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getl(char s[], int lim);
void swap(char s[], int a, int b);
/* reverses the input a line at a time */
main (int argc, char *argv[])
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    int ini, end; /* positions within line*/
    while ((len = getl(line, MAXLINE)) >= 0){
        for(ini = 0, end = len - 1;ini < end; ++ini,--end)
            swap(line, ini, end);

        printf("%s\n", line);
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

/* swap characters on positions a and b */
void swap(char s[], int a, int b){
    int tmp;
    tmp = s[a];
    s[a] = s[b];
    s[b] = tmp;
}

