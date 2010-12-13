#include <stdio.h>
#include <limits.h>
#include <float.h>

main (int argc, char *argv[])
{
    printf("LIMITS\n"
           "======\n");
    printf("char size (bytes): %d\n", CHAR_BIT);
    printf("char signed min: %d\n", SCHAR_MIN);
    printf("char signed max: %d\n", SCHAR_MAX);
    printf("char unsigned max: %d\n\n", UCHAR_MAX);

    printf("short signed min: %d\n", SHRT_MIN);
    printf("short signed max: %d\n", SHRT_MAX);
    printf("short unsigned max: %d\n\n", USHRT_MAX);

    printf("int signed min: %d\n", INT_MIN);
    printf("int signed max: %d\n", INT_MAX);
    printf("int unsigned max: %u\n\n", UINT_MAX);

    printf("long signed min: %ld\n", LONG_MIN);
    printf("long signed max: %ld\n", LONG_MAX);
    printf("long unsigned max: %lu\n\n", ULONG_MAX);

    printf("long long signed min: %lld\n", LLONG_MIN);
    printf("long long signed max: %lld\n", LLONG_MAX);
    printf("long long unsigned max: %llu\n\n", ULLONG_MAX);

    printf("float min: %.100f\n", FLT_MIN);
    printf("float max: %f\n", FLT_MAX);

    printf("double min: %le\n", DBL_MIN);
    printf("double max: %lf\n", DBL_MAX);

    printf("long double min: %lle\n", LDBL_MIN);
    printf("long double max: %llf\n", LDBL_MAX);



    // lazy of calculating all values
    // if you really want to know how to get it please read the following link:
    // http://homepages.cwi.nl/~steven/enquire.html


    return 0;
}

