#include<stdio.h>
//This program calculates the average of the scores of 5 students.

// double mean(int arr[]){
// 	double sum = 0;
// 	int size_of_arr = sizeof(arr) / sizeof(arr[0]);
// 	for (int i = 0; i<size_of_arr; i++){
// 		sum += arr[i];
// 	}

// 	return sum / size_of_arr;
// }


int main(){
	//int n = 5;
	//int max_student_size = 1000;
	int x[5];//array of variable length. 
	//x[1]= x[2]= wrong because 
	// indexing begins at 0. x[0] and x[1].
	double avg=-5.0;
	x[0]= 10;
	x[1]= 7;
	x[2]= 5;
	x[3]= 9;
	x[4]= 10;
	// double sum = 0.0;//sum 41
	// for (int i = 0 ;i < 5; ++i)
	// 	{
	// 	sum +=x[i];
	// 	printf("for i = %d, sum = %lf \n ", i, sum );
	// 		//more for checking if the right sum is being 
	// 		//computed.
	// 	} // for-loop
	// int mean = sum/5;

	double mode = x[0];
   int mode_count = 1;

   for (int i = 0; i < 5; i++)
   {
      int acc_count = 0; // count he actuall mode of each item
      // inneficient 0(n^2) time. can use a sort algorithm. mergesort algorithm (nlogn and pointers. total runtime 0(nlogn))
      for (int j = 0; j < 5; j++)
      {
         if (x[j] == x[i])
         {

            acc_count++;
         }
      }
      if (acc_count > mode_count)
      {
        mode_count = acc_count;
        mode = x[i];
      }
   }
   printf("The mode is %lf \n", mode);




}
