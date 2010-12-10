#include <stdio.h>
#define COLS 10

int getl(char s[], int lim);

/* Replaces all tabs by space characters to fit on fixed columns of COLS size.  */
main (int argc, char *argv[])
{
    int count;
    char c;
    count = COLS + 1;
    while((c = getchar()) != EOF){
        if(c == '\t') {
            while(count--) printf(" ");
            count = COLS;
        }
        else {
            printf("%c", c);
            count -= 1;
            if (count == 0) count = COLS;
        }
    }

    return 0;
}

