#include <stdio.h>
#define IN  1 /* inside a word */
#define OUT 0 /* outside a word */


/* print each word of input on a new line */
main()
{
    int c, state;
    state = OUT;
    while ((c = getchar()) != EOF) {
        printf("%c", c);
        if (c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
            // print a newline avoiding two newlines in a row
            if(c != '\n') printf("\n");
        } else if (state == OUT) {
            state = IN;
        }
    }
}

