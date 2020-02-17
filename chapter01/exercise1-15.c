#include <stdio.h>

/* print Fahrenheit-Celsius table
        for fahr = 0, 20, ..., 300 */
float conversion(int fahr);
main()
{
        float  fahr, celsius;
        float  lower, upper, step;

        lower = 0; /*lower limit of temperature table */
        upper = 300; /* upper limit */
        step = 20; /* step size */

        fahr = lower;
  printf("%10s %7s\n", "Fahrenheit", "Celsius");
        while (fahr <= upper) {
                celsius = conversion(fahr);
                printf("%10.0f %7.1f\n", fahr, celsius);

                fahr = fahr + step;
        }
}

float conversion(int fahr)
{
  return (5.0/9.0) * (fahr-32.0);
}

