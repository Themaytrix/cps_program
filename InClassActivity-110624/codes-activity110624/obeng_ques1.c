#include <stdio.h>
#include <stdlib.h>

int main() {

    

float fahrenheit;

 printf("Enter temperature in Fahrenheit: ");

 scanf("%f", fahrenheit);

 int celsius = (fahrenheit - 32) * 5 / 9;

 printf("Temperature in Celsius: %f\n", &celsius);

 return 0;

}