#include <stdio.h>
#define IN  1 /* inside a word */
#define OUT 0 /* outside a word */
#define MAX_WORD_SIZE 20 /* maximum size for a valid word */
#define SCALE 200 /* scale the results 1:SCALE shrinking a lot the output */

/* prints a histogram with the length of words on the standard input. */
main()
{
    int i, c, wl, state, lens[MAX_WORD_SIZE + 1], tmp;

    // initialize all values to 0
    for(i = MAX_WORD_SIZE; i >= 0; i--) lens[i] = 0;

    state = OUT;
    wl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t'){
            if(state == OUT){
                if(wl > MAX_WORD_SIZE) lens[0]++;
                else lens[wl]++;
            }

            state = OUT;
        } else if (state == OUT) {
            state = IN;
            wl = 1;
        } else{
            wl++;
        }
    }

    i = MAX_WORD_SIZE + 1;
    printf("Histogram:");
    while(i--){
        if(!i) printf("\n>%03d: ", MAX_WORD_SIZE);
        else printf("\n %03d: ", i);
        tmp = lens[i] / SCALE;
        while(tmp--) printf("%c", '#');
    }


    printf("\n\n-------------------\n\n");
    i = MAX_WORD_SIZE + 1;
    printf("Histogram:\n");
    int ml = 0;
    while(i--) if(ml < lens[i]) ml = lens[i];
    ml /= SCALE;
    while(ml--){
        i = MAX_WORD_SIZE + 1;
        while(i--){
            tmp = lens[i] / SCALE;
            printf("%4c", tmp > ml ? '#' : ' ');
        }
        printf("\n");
    }
    i = MAX_WORD_SIZE + 1;
    while(i--){
        if(!i) printf(">%03d", MAX_WORD_SIZE);
        else printf(" %03d", i);
    }

    printf("\n");
}

