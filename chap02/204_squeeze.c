#include <stdio.h>
#define dprint(expr) printf(#expr " = %d\n", expr)


int squeeze(char s[], char rm[]);
int find(char s[], char c);
main (int argc, char *argv[])
{
    char s[] = "01234567890123456789";
    char rm[] = "01";

    printf("removing \"%s\" from \"%s\"...\n", rm, s);
    squeeze(s, rm);
    printf("squeezed version: \"%s\"\n", s);
    return 0;
}

int squeeze(char s[], char rm[]){
    int ri; // reading position
    int wi; // writing position
    for(ri = wi = 0; s[ri] != '\0'; ri++){
        if(-1 == find(rm, s[ri])){
            if(wi != ri) s[wi] = s[ri];
            wi++;
        }
    }
    s[wi] = '\0';

    return wi;
}

int find(char s[], char c){
    int i;
    i = 0;

    // linear search for char c
    while(s[i] != '\0' && s[i] != c) i++;

    return (s[i] == '\0') ? -1 : i;
}

