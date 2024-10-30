#include <stdio.h>
#include <math.h>
/*
write a c program that computes the product of two integers (provided by the user) by calling a function mult
*/

int mult(int a, int b)
{
    return a * b;
}

int swap(int *ptr2a, int *ptr2b)
{
    int temp;
    temp = *ptr2b;
    *ptr2b = *ptr2a;
    *ptr2a = temp;

    printf("After swap, a = %d, b = %d \n \n", *ptr2a, *ptr2b);

    return 1;
}

int main()
{
    int cat1, cat2;
    printf("enter two integers: \n");
    scanf(" %d  %d", &cat1, &cat2);

    int *ptr2cat1, *ptr2cat2; // * stands for a unary operator
    printf("value of pointer to cat1 = %d \n", *ptr2cat1);
    ptr2cat1 = &cat1;
    ptr2cat2 = &cat2;

    // printf("ptr2cat1 value : %d \n", )

    
    
    swap(ptr2cat1, ptr2cat2);
    printf("Prod is %d \n", mult(cat1, cat2));
    printf("values after integers are swapped %d %d", *ptr2cat1, *ptr2cat2);
}