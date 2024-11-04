#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

int main(){

    int dog[SIZE];
    // int *ptr2dog = dog;

    // populate dog array
    for(int i = 0; i< SIZE ; i++){
        dog[i] = rand() % 40;
    }


    int *ptr2max = dog;

    for(int i=0; i<SIZE; i++){
        if(dog[i] > *ptr2max){
            *ptr2max = dog[i];
        }

    }

    printf("max = %d \n", *ptr2max);
    
    return 0;
}