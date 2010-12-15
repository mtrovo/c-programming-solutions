#include <stdio.h>
#define abs(x) (((x) < 0) ? -(x) : x)
#define dprint(x,s,m) itoa(x,s,m);\
                    printf("converted %d using min size %d to \"%s\"\n", x, m, s)
#define MAX_SIZE 40
int itoa(int n, char s[], int m);
void reverse(char s[]);

main (int argc, char *argv[])
{
    char s[MAX_SIZE];
    int i;

    for(i = 0; i < MAX_SIZE - 1; i++){
        dprint(12345678, s, i);
        dprint(-1234567, s, i);
    }


    return 0;
}

int itoa(int n, char s[], int m){
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

    while(i < m) s[i++] = ' ';

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

