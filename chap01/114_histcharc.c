#include <stdio.h>
#define SCALE 500 /* scale the results 1:SCALE shrinking a lot the output */
#define MIN 'A'
#define MAX 'z'
/* prints a histogram of the number of each char on the range ['A' : 'z'] found on the standard input. */
main()
{
    int SIZE = MAX - MIN + 1;
    int i, c, cs[SIZE], tmp, mc = 0;

    // initialize all values to 0
    for(i = SIZE; i; i--) cs[i] = 0;

    while ((c = getchar()) != EOF) {
        if(c >= MIN && c <= MAX) cs[c - MIN]++;
    }

    i = SIZE;
    printf("Histogram:");
    while(i--){
        printf("\n %3c: ", i + MIN);
        tmp = cs[i] / SCALE;
        while(tmp--) printf("%c", '#');
    }


    printf("\n\n-------------------\n\n");
    i = SIZE;
    printf("Histogram:\n");

    while(i--) if(mc < cs[i]) mc = cs[i];
    mc /= SCALE;
    while(mc--){
        i = SIZE;
        while(i--){
            tmp = cs[i] / SCALE;
            printf("%c", tmp > mc ? '#' : ' ');
        }
        printf("\n");
    }
    i = SIZE;
    while(i--){
        printf("%c", i + MIN);
    }

    printf("\n");
}

