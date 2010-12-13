#include <stdio.h>
#define dprint(expr) printf(#expr " = %d\n", expr)

int bitcount(unsigned x);

/* If the numbers n and n - 1 are both positive or both negative you can easily
 * verify that n - 1 removes the least significant bit and all bits following it
 * are changed to 0 as can be seen on the following example:
 *   16    : 0001 0000
 *   16 - 1: 0000 1111
 * Every bit greater then the least bit will not change but those that are
 * smaller or equal will change, in consequence if we execute an AND operator
 * the only bits maintened will be those greater then the least bit and so the
 * number of bits on the number will be decremented by one.
 *
 * When the numbers n and n - 1 are negative and positive or vice-versa we need
 * to look at the definition of negative numbers representation. C uses the two
 * complement system which is as following:
 *   twos(n) = ~n + 1
 *   negative(x) = twos(x)
 * For example if one needs to know what number is 1111 0000 and
 * simplifying supose we are using a 8bit variable (a byte).
 * Calculating the two complement (0001 0000) we found that this is the number
 * -16. Analyzing the results you will discover that a negative number needs
 * at least one empty high significant bit to work properly, this way any number
 * greater then 0111 1111 is the negative correspondent of its two complement.
 *
 * This is important to know because by this definition you can handle positive
 * and negative numbers equally on arithmetic operations.
 * For example on positive numbers decrementing a number has the following
 * representation:
 *   0000 0100(4d) - 0000 0001(1d) = 0000 0011(3d)
 * The same as negative numbers as following:
 *   1111 1100(-4d) - 0000 0001(1d) = 1111 1011(-5d)
 *
 * As the arithmetic operations are still the same for positive and negative
 * numbers for the two complement system we can conclude that there is no
 * distinction while working with both negative or both positive numbers or when
 * they are mixed.
 *
 *
 * Finished the long long explanation let's code.
 */
main (int argc, char *argv[])
{
    dprint(bitcount(0xFFFF));     // positive
    dprint(bitcount(0x80000000)); // negative
    dprint(bitcount(~0)); // INT_MIN
    return 0;
}

int bitcount(unsigned x){
    int ret = 0;
    while(x){
        ++ret;
        x &= x - 1;
    }

    return ret;
}

