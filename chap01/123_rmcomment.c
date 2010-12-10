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

main (int argc, char *argv[])
{
    char c; /* current char */
    int state; /* current machine state */
    int cgroup; /* current char group */

    state = ST_OUT;
    while((c = getchar()) != EOF){
        switch(c){
        case '/': cgroup = CG_SLASH; break;
        case '*': cgroup = CG_ASTERISK; break;
        default: cgroup = CG_OTHER; break;
        }

        switch(state){
            case ST_OUT:        if(cgroup == CG_SLASH)
                                    state = ST_OUT_SLASH;
                                else printf("%c", c);
                                break;
            case ST_OUT_SLASH:  if(cgroup == CG_ASTERISK)
                                     state = ST_IN;
                                else if(CG_SLASH){
                                    state = ST_IN_SLINE;
                                } else {
                                    printf("/%c", c);
                                    state = ST_OUT;
                                }
                                break;
            case ST_IN:         if(cgroup == CG_ASTERISK)
                                    state = ST_IN_ASRK;
                                break;
            case ST_IN_ASRK:    if(cgroup == CG_SLASH)
                                    state = ST_OUT;
                                else
                                    state = ST_IN;
                                break;
            case ST_IN_SLINE:   if(c == '\n')
                                    state = ST_OUT;
                                break;
        }
    }
    return 0;
}

