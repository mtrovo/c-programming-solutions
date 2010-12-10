#include <stdio.h>
/* print Celsius-Fahrenheit table
for celsius = -40, -20, ..., 260; floating-point version */
main()
{
float fahr, celsius;
float lower, upper, step;
lower = -40;/* lower limit of temperatuire scale */
upper = 260;/* upper limit */
step = 20;/* step size */

// header
printf("%s %s\n", "Celsius", "Fahrenheit");
printf("%s %s\n", "=======", "==========");

celsius = lower;
while (celsius <= upper) {
fahr = celsius / (5.0 / 9.0) + 32.0;
printf("%7.0f %10.1f\n", celsius, fahr);
celsius = celsius + step;
}
}

