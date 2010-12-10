#include <stdio.h>
/* alphabet of the state machine */
#define CG_SLASH 0 /* slash ('/') */
#define CG_ASTERISK 1 /* asterisk ('*') */
#define CG_OTHER 2 /* any other character */

/* states of state machine */
#define ST_OUT 0 /* outside comment */
#define ST_OUT_SLASH 1 /* outside comment, found a slash*/
#define ST_IN 2 /* inside a comment */
#define ST_IN_ASRK 3 /* inside a comment, found an asterisk */
#define ST_IN_SLINE 4 /* inside a single line comment */

#define BAL "BALANCED"
#define UNBAL "UNBALANCED"


#define DEBUG 0 /* if debug is different from 0 print debug messages. */
main (int argc, char *argv[])
{
    char c; /* current char */
    int state; /* current machine state */
    int cgroup; /* current char group */

    int bdq; /* balance of double quotes */
    int bsq; /* balance of single quotes */
    int bbraces; /* balance of braces */
    int bpar; /* balance of parenthesis */
    int bbra; /* balance of brackets */
    int bc; /* balance of comments */

    int esc; /* mark if current char is part of an escaping sequence */

    int sline; /* source line */

    sline = 1;
    bdq = bsq = bbraces = bpar = bbra = bc = 0;
    state = ST_OUT;


    while((c = getchar()) != EOF){
        esc = 0;
        // ignore start of escaping sequence
        if(c == '\\'){
            c = getchar();
            esc = 1;
        }

        // increment input line number
        if(c == '\n') sline++;

        switch(c){
        case '/': cgroup = CG_SLASH; break;
        case '*': cgroup = CG_ASTERISK; break;
        default: cgroup = CG_OTHER; break;
        }

        switch(state){
            case ST_OUT:        if(cgroup == CG_SLASH)
                                    state = ST_OUT_SLASH;
                                else {
                                    switch(c){
                                    case '"':   if(!esc && !bsq){
                                                    bdq = (bdq + 1) % 2;
                                                    if(DEBUG) printf("%3d: +bdq // %d\n", sline, bdq);
                                                } else if(DEBUG)
                                                    printf("%3d: refused bdq // %d\n", sline, bdq);
                                                break;
                                    case '\'':  if(!esc && !bdq){
                                                    bsq = (bsq + 1) % 2;
                                                    if(DEBUG) printf("%3d: +bsq // %d\n", sline, bsq);
                                                } else if (DEBUG)
                                                    printf("%3d: refused bsq // %d\n", sline, bsq);
                                                break;
                                    case '{':   bbraces++;
                                                if(DEBUG) printf("%3d: +bbraces // %d\n", sline, bbraces);
                                                break;
                                    case '}':   bbraces--;
                                                if(DEBUG) printf("%3d: -bbraces // %d\n", sline, bbraces);
                                                break;
                                    case '(':   bpar++;
                                                if(DEBUG) printf("%3d: +bpar // %d\n", sline, bpar);
                                                break;
                                    case ')':   bpar--;
                                                if(DEBUG) printf("%3d: -bpar // %d\n", sline, bpar);
                                                break;
                                    case '[':   bbra++;
                                                if(DEBUG) printf("%3d: +bbra // %d\n", sline, bbra);
                                                break;
                                    case ']':   bbra--;
                                                if(DEBUG) printf("%3d: -bbra // %d\n", sline, bbra);
                                                break;
                                    }
                                }
                                break;
            case ST_OUT_SLASH:  if(cgroup == CG_ASTERISK){
                                     state = ST_IN;
                                     bc++;
                                } else if(CG_SLASH){
                                    state = ST_IN_SLINE;
                                } else {
                                    state = ST_OUT;
                                    ungetc(c, stdin);
                                }
                                break;
            case ST_IN:         if(cgroup == CG_ASTERISK)
                                    state = ST_IN_ASRK;
                                break;
            case ST_IN_ASRK:    if(cgroup == CG_SLASH){
                                    state = ST_OUT;
                                    bc--;
                                } else
                                    state = ST_IN;
                                break;
            case ST_IN_SLINE:   if(c == '\n')
                                    state = ST_OUT;
                                break;
        }
    }

    printf("C SOURCE STATS\n"
           "==============\n\n");

    printf("%20s: %s\n", "single quote", bsq ? UNBAL : BAL);
    printf("%20s: %s\n", "double quote", bdq ? UNBAL : BAL);
    printf("%20s: %s\n", "parenthesis", bpar ? UNBAL : BAL);
    printf("%20s: %s\n", "braces", bbraces ? UNBAL : BAL);
    printf("%20s: %s\n", "brackets", bbra ? UNBAL : BAL);
    printf("%20s: %s\n", "comments", bc ? UNBAL : BAL);


    return 0;
}

