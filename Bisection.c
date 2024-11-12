#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double func(double x)
{
    return (pow(x, 2) - 2.85 * x + 1.75);
}

int main()
{
    double a, b, error = 1;

    printf("Enter the lower and upper limits: ");
    scanf("%lf %lf", &a, &b);

    double next_x, x = fabs((a + b)/2);
    int can = func(a)*func(b) < 0 ? 1 : 0; 
    if (!can)
    {
        printf("No root in this interval");
        return 1;
    }

    while(fabs(error) > 5e-5)
    {
        if (func(a) * func(x) > 0)
        a = x;
        else
        b = x;

        next_x = fabs((a + b)/2);
        error = next_x - x;
        x = next_x;
    }
    printf("Root: %lf", x);
    return 0;
}