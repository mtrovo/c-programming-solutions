#include <stdio.h>

int any(char s1[], char s2[]);
int find(char s[], char c);

main (int argc, char *argv[])
{
    char s1[11] = "0123456789";
    char * s2;

    printf("s1: \"%s\"\n", s1);

    s2 = "0123";
    printf("found any char of \"%s\" on position: %d\n", s2, any(s1,s2));

    s2 = "1234";
    printf("found any char of \"%s\" on position: %d\n", s2, any(s1,s2));

    s2 = "abc9";
    printf("found any char of \"%s\" on position: %d\n", s2, any(s1,s2));

    s2 = "ZYXW";
    printf("found any char of \"%s\" on position: %d\n", s2, any(s1,s2));
    return 0;
}

int any(char s1[], char s2[]){
    char c; // current char inside s1
    int i;
    int ret;
    i = 0;

    // loop while not '\0'
    while(c = s1[i]){
        /* search for the current char inside s2 and if exists return
           the current position */
        if(find(s2, c) != -1){
            return i;
        }

        ++i;
    }

    return -1;
}

int find(char s[], char c){
    int i;
    i = 0;

    // linear search for char c
    while(s[i] != '\0' && s[i] != c) i++;

    return (s[i] == '\0') ? -1 : i;
}

