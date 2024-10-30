#include <stdio.h>
#include <math.h>
#include "nonlinear_solver.h"

int main()
{

    int input;
    // double tol = 0.0000001;
    // int max_iter = 50;
    double bisection_ans;
    printf("CHOOSE YOUR NON-LINEAR SOLVER \n");
    printf("1. bisection\n");
    printf("2. Newton Method\n");
    printf("3. Secant\n");
    printf("Selection: ");
    scanf("%d", &input);

    switch (input)
    {
    case 1:

        printf("Our root is %lf", bisection(1, 1.5));
        break;

    case 2:
        printf("Our root is %lf", newton(1.12));
        break;

    case 3:
        printf("Our root is %lf", secant(0, 1.5));
        break;

    default:
        printf("nothing matched");
        break;
    }
}