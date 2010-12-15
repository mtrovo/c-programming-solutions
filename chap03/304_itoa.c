#include <stdio.h>

#define abs(x) (((x) < 0) ? -(x) : x)
#define dprint(x,s) itoa(x,s);\
                    printf("converted %d to \"%s\"\n", x, s)

int itoa(int n, char s[]);
void reverse(char s[]);

/*
 * On a two complement system the largest negative number is represented as
 * -(2^wordsize-1), for example for a wordsize = 8 we have the largest negative
 * as:
 *   1000 0000 (-128)
 * This number cannot be represented as a positive number because its two
 * complement number is itself as shown below:
 *   twos(1000 0000)
 *   ~(1000 0000) + 0001
 *   0111 1111 + 0001
 *   1000 0000
 *
 * To workaround this issue we need to drop the inversion of sign (unary '-'
 * operator) and take care of the side effects of this change.
 */
main (int argc, char *argv[])
{
    char s[20];
    dprint(20, s);
    dprint(-20, s);
    dprint(40, s);
    dprint(1 << (sizeof 0) * 8 - 1, s);
    dprint(20, s);

    return 0;
}

int itoa(int n, char s[]){
    int i, sign;
    sign = n;
    i = 0;

    do {
        /* get next digit, it needs 'abs' because n could be negative */
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);

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

