#include <stdio.h>
#define dprint(expr) printf(#expr " = \"%s\"\n", expr)


int escape(char s[], char t[]);
int unescape(char s[], char t[]);
main (int argc, char *argv[])
{
    char s[20];
    char * t;
    t = "0\n1\t2\r3\\4";

    escape(s, t);
    printf("\"%s\" escaped to \"%s\"\n", t, s);

    t = "0\\n1\\t2\\r3\\\\4";
    unescape(s, t);
    printf("\"%s\" unescaped to \"%s\"\n", t, s);

    return 0;
}

/* escapes any of '\n', '\t' '\\' or '\r' characters on string t to their literal
 * string values on string s. Returns the new length of the string s.
 */
int escape(char s[], char t[]){
    int i,j; // indexes within s and t
    for(i = j = 0; t[j] != '\0'; j++){
        switch(t[j]){
        case '\n':  s[i++] = '\\';
                    s[i++] = 'n';
                    break;
        case '\t':  s[i++] = '\\';
                    s[i++] = 't';
                    break;
        case '\r':  s[i++] = '\\';
                    s[i++] = 'r';
                    break;
        case '\\':  s[i++] = '\\';
                    s[i++] = '\\';
                    break;
        default:    s[i++] = t[j];
                    break;
        }
    }
    s[i] = '\0';
    return i;
}

/* unescapes any of the character sequence "\\n" "\\t" "\\\\" and "\\r" on string t
 * to their real character value on string s and returns the new length of the
 * string s.
 */
int unescape(char s[], char t[]){
    int escaping; // if is a escaping sequence
    int i,j; // indexes within s and t
    escaping = 0;
    for(i = j = 0; t[j] != '\0'; j++){
        if(escaping){
            switch(t[j]){
            case 'n':   s[i++] = '\n'; break;
            case 't':   s[i++] = '\t'; break;
            case 'r':   s[i++] = '\r'; break;
            case '\\':  s[i++] = '\\'; break;
            }
            escaping = 0;
        } else {
            if(t[j] == '\\'){
                escaping = 1;
            } else {
                s[i++] = t[j];
            }
        }
    }
    s[i] = '\0';
    return i;
}

