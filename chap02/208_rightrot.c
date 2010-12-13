#include <stdio.h>
#define BYTE_TO_BITS 8

#define DEBUG 0
#define dprint(expr) { printf("%10s:", #expr);\
printb(expr); \
printf("\n"); }

int rightrot(unsigned x, int n);

void printb(int);
void reverse(char s[]);
main (int argc, char *argv[])
{
    rightrot(0xF000000F, 4);
    return 0;
}

int rightrot(unsigned x, int n){
    unsigned carry, ret;

    if(DEBUG) dprint(x);

    ret = (x >> n);
    carry = ((x & ~(~0 << n)) << (sizeof x * BYTE_TO_BITS - n));

    if(DEBUG){
        dprint(ret);
        dprint(carry);
    }

    ret = ret | carry;
    if(DEBUG) dprint(ret);
    return  ret;
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

