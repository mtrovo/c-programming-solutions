#include <stdio.h>

main (int argc, char *argv[])
{
    int num, i, tmp;
    if(argc <= 1) {
        printf("Usage: %s num_lines\n", argv[0]);
        return 1;
    }

    num = atoi(argv[1]);

    for(i = 1;i <= num; i++){
        tmp = i;
        while(tmp--) printf("#");
        printf("\n");
    }
    return 0;
}

