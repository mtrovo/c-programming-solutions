#include <stdio.h>
#define MAXSIZE 1000

/* Print the first line using a loop equivalent to the for loop
   i < lim-1 && (c=getchar()) != '\n' && c != EOF
   without using && or ||.

   The solution assumes that a true boolean operation returns 1
   and a false one returns 0 */
main (int argc, char *argv[])
{
    char c, line[MAXSIZE];
    int i;
    for (i=0; ((i < MAXSIZE-1) + ((c=getchar()) != '\n') + (c != EOF)) == 3; ++i)
        line[i] = c;
    line[i] = '\0';

    printf("read line: %s\n", line);

    return 0;
}

