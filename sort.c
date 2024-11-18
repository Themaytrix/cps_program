#include <stdio.h>
#include <stdlib.h>


// merge sort. 

#define MAX_LEN 10

void left_slice_array(int arr[], int n){
    int left_arr[n];
    for(int i =0; i<n,i++ ){
        left_arr[i] = arr[i];
    }

    return left_arr;
}

int main(){

    int x[MAX_LEN];

    // check if array is empty
    if (MAX_LEN < 0){
        return -1;
    }

    // split array
    int midpoint = MAX_LEN / 2;
   

    return 0;
}