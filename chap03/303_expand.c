#include <stdio.h>

#define INVALID_CHAR '\0'
#define SEPARATOR '-'

int expand(char s1[], char s2[]);
int expand_seq(char s[], int offset, char a, char b);
int is_valid_char(char c);
main (int argc, char *argv[])
{
    char s1[100], *s2;

    s2 = "abcdefg";
    expand(s1,s2);
    printf("orig: %s\n new: %s\n====================\n", s2, s1);

    s2 = "-abcdefg";
    expand(s1,s2);
    printf("orig: %s\n new: %s\n====================\n", s2, s1);

    s2 = "a#-zbcdefg";
    expand(s1,s2);
    printf("orig: %s\n new: %s\n====================\n", s2, s1);

    s2 = "[a-z]bcdefg";
    expand(s1,s2);
    printf("orig: %s\n new: %s\n====================\n", s2, s1);

    s2 = "-a-z0-9";
    expand(s1,s2);
    printf("orig: %s\n new: %s\n====================\n", s2, s1);

    s2 = "-a-b-c-";
    expand(s1,s2);
    printf("orig: %s\n new: %s\n====================\n", s2, s1);

    s2 = "A-z";
    expand(s1,s2);
    printf("orig: %s\n new: %s\n====================\n", s2, s1);

    return 0;
}


int expand(char s1[], char s2[]){
    int i, j; // indexes
    char a,s; // first char and separator exists flag
    char c; // current char on s2
    a = s = INVALID_CHAR;

    for(i = j = 0; s2[j] != '\0'; j++){
        c = s2[j];
        if(a != INVALID_CHAR && c == SEPARATOR){
            s = 1; // set separator
        }else if(is_valid_char(c)){
            if(s){
                if(c < a){
                    s1[i++] = a;
                    s1[i++] = SEPARATOR;
                    s1[i++] = c;
                } else {
                    i = expand_seq(s1, i, a, c);
                    a = s = INVALID_CHAR;
                }
            } else {
                if(a) s1[i++] = a;
                a = c;
            }
        }else {
            if(a) s1[i++] = a;
            a = INVALID_CHAR;
            s1[i++] = c;
        }
    }

    if(a) s1[i++] = a;
    if(s) s1[i++] = SEPARATOR;

    s1[i] = '\0';
    return i;
}

int expand_seq(char s[], int offset, char a, char b){
    for(; a<=b; a++){
        if(is_valid_char(a)) {
            s[offset] = a;
            offset++;
        }
    }
    return offset;
}

int is_valid_char(char c){
    if(c>='A' && c<='Z') return 1;
    if(c>='a' && c<='z') return 1;
    if(c>='0' && c<='9') return 1;
    return 0;
}

