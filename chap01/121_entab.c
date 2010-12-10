#include <stdio.h>
#define COLS 4
#define RM_CHAR -42 /* char to be removed from final str representation */
#define MAXLINE 1000 /* maximum input line length */

void mark_tab_to_spaces(char s[], int ini, int end);
/* Replaces all spaces by tabs characters to fit on fixed columns of COLS size.  */
main (int argc, char *argv[])
{
    int len; /* current line length */
    int ncols; /* number of cols on current input line */
    char line[MAXLINE]; /* current input line */
    int i; /* current output char index */
    int ini, end; /* positions within line*/
    while ((len = getl(line, MAXLINE)) >= 0){
        ncols = len / COLS;
        ini = ncols * COLS;
        end = len;
        // incomplete col
        while(ncols-- >= 0){
            mark_tab_to_spaces(line, ini, end);
            end = ini;
            ini -= COLS;
        }

        // print current line with tabs
        for(i = 0; i < len; i++){
            if(line[i] == RM_CHAR) ; // do nothing
            else printf("%c", line[i]);
        }
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

void mark_tab_to_spaces(char s[], int ini, int end){
    int tmp = end;
    while(--tmp >= ini && s[tmp] == ' '){
        if(tmp + 1 < end && s[tmp + 1] == '\t'){
            s[tmp + 1] = RM_CHAR;
        }
        s[tmp] = '\t';
    }
}

