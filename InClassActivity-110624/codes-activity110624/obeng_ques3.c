#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
int main()
{
   int number[SIZE];
   int num;
   int count = 0;
   int i = 0;
   FILE *in_file = fopen("scores-data.txt", "r"); // only open a pre-exisiting file in read mode.

   if (!in_file) // equivalent to saying if ( in_file == NULL )
   {
      printf("oops, file can't be read\n");
      exit(-1);
   }
   // attempt to read the next line and store
   // the value in the "number" variable
   while (fscanf(in_file, "%d", &num) == 1)
   {
      printf("We just read %d\n", num);
      i++;
      if (count < 100)
      {
         number[count] = num;
         count++;
      }
   }
   // close the file
   fclose(in_file);

   // calculating the mean = sum / number of elements(count)
   double sum = 0.0;

   for (int i = 0; i < count; i++)
   {
      sum += number[i];
   }
   double mean = sum / count;

   // calculate the mode
   // instatiate the mode using the first element and setting a count of 1
   double mode = number[0];
   int mode_count = 1;

   for (int i = 0; i < count; i++)
   {
      int acc_count = 0; // count he actuall mode of each item
      // inneficient 0(n^2) time. can use a sort algorithm. mergesort algorithm (nlogn and pointers. total runtime 0(nlogn))
      for (int j = 0; j < count; j++)
      {
         if (number[j] == number[i])
         {

            acc_count++;
         }
      }
      if (acc_count > mode_count)
      {
         mode_count = acc_count;
         mode = number[i];
      }
   }

   printf("The mean is %lf \n", mean);
   printf("The mode is %lf \n", mode);
   return 0;
}
