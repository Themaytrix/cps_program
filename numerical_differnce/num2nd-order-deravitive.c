#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>
#include "cblass.h"

/*
  void diff(double* u, int N, double dx, double* du)

  Computes a finite difference approximation for du/dx

  Inputs:
  u: pointer for input array
  N: length of the array
  dx: the space step size
  du: pointer to output array

  Outputs:
  du: contains the forward finite difference approximation

  Usage:
  gcc -o error-calc bugless-nd.c -lm -lblas
*/
void diff(double *u, int N, double dx, double *d2u)
{

  // d2u[0] = (u[1]-u[0])/dx;
  for (int i = 1; i <= N - 1; ++i)
  {
    d2u[i - 1] = (u[i + 1] - 2 * u[i] + u[i - 1]) / (dx * dx);
  }
  // d2u[N]=(u[N]-u[N-1])/dx;
}

/*
  void init(double* u, int N, double dx)

  Initializes the data array with the sin function

  Inputs:
  u: pointer to array will values will be stored
  N: length of the array
  dx: the space step size

  Outputs:
  u: contains data for a sin function
*/
void init(double *u, int N, double dx)
{
  int i;
  for (i = 0; i < N + 1; ++i)
    u[i] = sin(i * dx);
}

/*
  int main(int argc, char* argv[])

  Function tests the timing accuracy of 4 different methods

  Inputs: argc should be 2
  argv[1] is the integer length of the data array

  Outputs: ???
*/
int main(int argc, char *argv[])
{
  int N = atoi(argv[1]);

  double *u = (double *)malloc((N + 1) * sizeof(double));
  double *d2u = (double *)malloc((N - 1) * sizeof(double));
  double *errd2u = (double *)malloc((N - 1) * sizeof(double)); // calculating error.
  double dx = (M_PI) / N;

  init(u, N, dx);
  // for (int i=0; i<N;++i)
  //     printf("sin[%d] = %f  \n",i, u[i]);
  diff(u, N, dx, d2u);
  for (int i = 0; i <= N - 1; ++i)
  {
    // printf("diff = %f - %f = %f \n",cos(i*dx) /*wrong!*/, du[i], cos(i*dx)-du[i]);
    errd2u[i] = -sin((i + 1) * dx) - d2u[i];
  }
  // bug is in the last argument; u[i] should be u'[i] i.e., cos(i).
  double error_L2 = cblas_ddot(N - 1, errd2u, 1, errd2u, 1);
  printf("L2 error = %f \n", sqrt(error_L2));
  free(u);
  free(d2u);
  free(errd2u);

  return 0;
}