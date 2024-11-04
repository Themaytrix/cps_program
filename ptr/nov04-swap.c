#include <stdio.h>

/*
    swap two integers using pointers
    These intergers are enteries of an array called dog. This array is of length 2
 */

// input receive poointers to dogs
int swap(int *dog1,int *dog2){
    int temp = *dog1;
    *dog1 = *dog2;
    *dog2 = temp;
    return -1;

}

int main()
{
    int *ptr2dog;

    int dog[2] = {-90, 8};

    ptr2dog = dog;

    printf("dog[0] = %d  \n\n dog[1] = %d \n", *ptr2dog, *ptr2dog+1);

    swap(ptr2dog,ptr2dog+1);


    for (int i = 0; i < 2; i++)
    {
        
        printf("array[%d] = %d \n", i, dog[i]);
    }

    return 0;
}