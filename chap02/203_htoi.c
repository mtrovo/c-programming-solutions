#include <stdio.h>
#define INVALID -1
int htoi(char s[]);
main (int argc, char *argv[])
{
    printf("htoi(a0): %d\n", htoi("a0"));
    printf("htoi(AaaB0): %d\n", htoi("AaaB0"));
    printf("htoi(DeaDBeeF): %d\n", htoi("DeaDBeeF"));
    printf("htoi(0xFFFFF0): %d\n", htoi("0xFFFFF0"));

    // should print an invalid char message
    printf("htoi(xx0xx): %d\n", htoi("xx0xx"));
    return 0;
}

int htoi(char s[]){
    int i; // index
    int ret; // value to be returned
    int cur; // current position value

    ret = i = 0;

    // ignores leading 0x or 0X
    if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) i = 2;

    for(; s[i] != '\0'; i++){
        switch(s[i]){
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':   cur = s[i] - '0'; break;

        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':   cur = s[i] - 'A' + 10; break;

        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':   cur = s[i] - 'a' + 10; break;

        default: cur = INVALID; break;
        }

        if(cur == INVALID){
            printf("%d: invalid hex value at position\n", i);
            break;
        }else {
            ret = ret * 16 + cur;
        }
    }

    return ret;
}

