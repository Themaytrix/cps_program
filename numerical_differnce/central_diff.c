#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>

void central_diff(double *u, int N, double h, double *du)
{
    int i;
    // forward difference for central difference due to unavailable prev values
    du[0] = (u[1] - u[0]) / h;
    for (i = 1; i < N - 1; ++i)
    {
        du[i] = (u[i+1] - u[i - 1]) / 2*h;
    }
    // backward difference for central difference due to unavailable prev values
    du[N] = (u[N] - u[N - 1]) / h;
}

void init(double *u, int N, double h)
{
    int i;
    for (i = 0; i < N; ++i)
        u[i] = sin(i * h);
}

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    

    double *u = (double*)malloc((N+1)*sizeof(double));
    double *du = (double*)malloc((N+1)*sizeof(double));

    double h = 2*M_PI / N;
    init(u, N, h);
    central_diff(u, N, h, du);
    for (int i = 0; i < N+1; ++i){
        printf("diff = %f - %f = %f \n", cos(i*h), du[i], cos(i*h) - du[i]);
    }
        
    free(u);
    free(du);


}