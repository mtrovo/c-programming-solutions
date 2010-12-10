#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 300, 280, ..., 0; floating-point version */
main()
{
float fahr, celsius;
float lower, upper, step;
lower = 0;/* lower limit of temperatuire scale */
upper = 300;/* upper limit */
step = 20;/* step size */

// header
printf("%s %s\n", "Fahrenheit", "Celsius");
printf("%s %s\n", "==========", "=======");

fahr = upper;
while (fahr >= lower) {
celsius = (5.0/9.0) * (fahr-32.0);
printf("%10.0f %7.1f\n", fahr, celsius);
fahr = fahr - step;
}
}

