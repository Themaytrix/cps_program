#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

/*
Calculates the inner product withous any blas function and returns the expected answer and time taken to compute tje inner product of 2 vectors of length N.


*/

int main(int argc, char *argv[])
{
    clock_t begin, end;
    double time_taken;

    begin = clock();

    int n = atoi(argv[1]);

    // insert code
    // generate random x values
    double *x = malloc(sizeof(double)*n);
    double *y = malloc(sizeof(double) * n);

    for (int i = 0; i < n; i++)
    {
        if (i%2 == 0){
            x[i] = 1;
            y[i] = 1;
        }
        else{
            x[i] = -1;
            y[i] = -1;
        }
    }
    // generate random y values

    double dot_product;

    for (int i = 0; i < n; i++)
    {
        dot_product += x[i] * y[i];
    }

    printf("dot product = %lf \n", dot_product);

    end = clock();
    time_taken = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time taken for this code = %f seconds \n", time_taken);

    return 0;
}