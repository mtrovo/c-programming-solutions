#include <stdio.h>
#define BYTE_TO_BITS 8

#define DEBUG 1
#define dprint(expr) { printf(#expr ":");\
printb(expr); \
printf("\n"); }
int setbits(int x, int p, int n, int y);

void printb(int);
void reverse(char s[]);

int
main (int argc, char *argv[])
{
    int ret;
    unsigned tmp = ~0;
    tmp >>= 1;
    ret = setbits(tmp, 4, 4, 0x05);
    printb(ret);
    printf("\n");
    return 0;
}


int setbits(int x, int p, int n, int y){
    int ret;

    if(DEBUG){
        dprint(x);
        dprint(y);
    }

    // set the range [0 : p[
    ret = x & ~(~0 << p);
    // set the range [p:p+n[
    ret |= x & ((y & ~(~0 << n)) << p);
    // set the range [p+n:]
    ret |= x & (~0 << (p + n));

    if(DEBUG) dprint(ret);

    return ret;
}

// prints the binary representation of a number separated by 4bits
void printb(int n){
    char buff[100];
    int i; // index
    unsigned ref;
    ref = sizeof ref * BYTE_TO_BITS;
    i = 0;


    while(ref--){
        buff[i] = (n & 1) + '0';
        ++i;
        if(i % 5 == 4) buff[i++] = ' ';

        // next binary digit
        n >>= 1;
    }
    buff[i] = '\0';

    reverse(buff);
    printf("%s", buff);
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

