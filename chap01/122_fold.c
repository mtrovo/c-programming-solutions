#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define COLS 50 /* fold line on COLS characters */

int getl(char s[], int lim);
int find(char s[], char c, int offset);
int rfind(char s[], char c, int ini, int offset);
void print_range(char s[], int ini, int end);

main (int argc, char *argv[])
{
    int len; /* current line length */
    int ncols; /* number of cols on current input line */
    char line[MAXLINE]; /* current input line */

    int offset, ini; /* positions within line */
    int fp; // position to fold within line */
    while ((len = getl(line, MAXLINE)) >= 0){
        offset = 0;
        ini = COLS;

        // if line is shorter then COLS just print it
        if(len <= COLS) {
            printf("%s\n", line);
            continue;
        }

        while(ini < len){
            fp = rfind(line, ' ', ini, offset);
            // if did not find, try searching the next one
            if(fp == -1){
                fp = find(line, ' ', ini);
            }

            // line does not have spaces, just print the line
            if(fp == -1) {
              break;
            } else {
                print_range(line, offset, fp);
                printf("\n");
                offset = fp + 1;
                ini = offset + COLS;
            }
        }

        print_range(line, offset, len);
        printf("\n");
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

int find(char s[], char c, int offset){
    int i;
    i = offset;
    while(s[i] != '\0' && s[i] != c) i++;

    return (s[i] == '\0') ? -1 : i;
}

int rfind(char s[], char c, int ini, int offset){
    int i;
    i = ini;
    while(s[i] >= offset && s[i] != c) i--;

    return (i < offset) ? -1 : i;
}

/* print the characters within the range ini inclusive and end exclusive. */
void print_range(char s[], int ini, int end){
    for(; ini < end; ini++) printf("%c", s[ini]);
}

