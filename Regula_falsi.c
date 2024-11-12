#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double func(double x)
{
    return pow(x, 2) + 2 * x - 0.9975;
}

int main()
{
    double a, b, error = 1, prev_x;
    double x = a + ((fabs(func(a)) / fabs(func(a) + func(b))) * (b - a));

    printf("Enter the lower and upper limits: ");
    scanf("%lf %lf", &a, &b);

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
        
        prev_x = x;
        x = a + ((fabs(func(a)) / fabs(func(a) + func(b))) * (b - a));
        error = fabs(x - prev_x);
    }
    printf("The Result: %lf", x);
    return 0;
}