#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){

    int N = atoi(argv[1]);

    // allocate memories
    int pi = 3.14159;
    int h = pi/N;


    // array containing the exact derivatives

    double *dfx = malloc(sizeof(double) * N);
    double *dfh = malloc(sizeof(double) * N); 



    return 0;
}