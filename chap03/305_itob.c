#include <stdio.h>

#define abs(x) (((x) < 0) ? -(x) : x)
#define to_char(d) (((d) < 10) ? (d) + '0' : (d) - 10 + 'A')

/* debug macros */
#define dprint(x,s,b) itob(x,s,b);\
                    printf("converted %d using base %d to \"%s\"\n", x, b, s)
#define cdebug(d) printf("\nto_char(%d): %c", d, to_char(d));


int itob(int n, char s[], int b);
void reverse(char s[]);
/*
 * Convert a number n to the base b, based on the code of itoa on 304_itoa.c
 */
main (int argc, char *argv[])
{
    char s[30];
    //positive
    dprint(31,s,10);
    dprint(31,s,16);
    dprint(31,s,8);
    dprint(31,s,2);
    //negative
    dprint(-31,s,10);
    dprint(-31,s,16);
    dprint(-31,s,8);
    dprint(-31,s,2);
    //and finally
    dprint(0xDEAD, s, 16);
    dprint(0xBEEF, s, 16);

    return 0;
}

int itob(int n, char s[], int b){
    int i, sign, tmp;
    sign = n;
    i = 0;

    do {
        /* get next digit, it needs 'abs' because n could be negative */
        s[i++] = to_char(abs(n % b));
    } while (n /= b);

    /* delete it */
    if (sign < 0)
    s[i++] = '-';
    s[i] = '\0';

    /* generated digits in reverse order, so reverse back to the right
     * orientation */
    reverse(s);

    return i;
}

void reverse(char s[]){
    int tmp;
    int ini;
    int end;

    // string len
    tmp = 0;
    while(s[tmp] != '\0') tmp++;

    // reverse string
    for(ini = 0,end = tmp - 1; ini < end; ++ini,--end){
        tmp = s[ini];
        s[ini] = s[end];
        s[end] = tmp;
    }
}

