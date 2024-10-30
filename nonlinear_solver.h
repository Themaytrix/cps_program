#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//  defining global variables of
#define MAX_ITER 50
#define TOL 0.000001

double function(double x)
{

    return pow(x, 6) - x - 1;
}
// differential funtion
double d_function(double x)
{
    return 12 * pow(x, 5) / (x + 1);
}
// approximated differential function
double dd_function(double x)
{
    return 6 * pow(x, 5) - 1;
}

double bisection(double a, double b)
{

    double c;
    double e;
    double root;

    // compare signs of a and b at funtions

    if ((function(a) * function(b)) > 0)
    {
        printf("there");
    }

    for (int i = 0; i <= MAX_ITER; i++)
    {

        c = (a + b) / 2;
        printf("%f", c);
        // e = (b - a) / 2;
        if (fabs(function(c)) < TOL)
        {
            root = c;
            return root;
        }

        if ((function(a) * function(c)) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }

    return root;
}

double newton(double x0)
{

    double root;

    for (int i = 0; i < MAX_ITER; i++)
    {
        double xn = x0 - (function(x0) / dd_function(x0));
        if (fabs(xn - x0) < TOL)
        {
            // printf("ehllo");
            root = xn;
            return root;
        }

        x0 = xn;
    }

    return -5.0;
}

double secant(double x0, double x1)
{
    double root;

    for (int i = 0; i < MAX_ITER; i++)
    {
        double x2 = (x0 * function(x1) - x1 * function(x0)) / (function(x1) - function(x0));

        if (fabs(x2 - x1) < TOL)
        {
            root = x2;
            return root;
        }

        x0 = x1;
        x1 = x2;
    }
    return -5.00;
}

