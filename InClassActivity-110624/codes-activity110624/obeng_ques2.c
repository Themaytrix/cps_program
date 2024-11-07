#include <stdio.h>
#include <math.h>
// This program calculates the average of the scores of 5 students.

double mean(int arr[], int n)
{
	// initialize sum of array
	double sum = 0;
	// get length of array
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	return sum / n;
}

int mode(int arr[])
{

	int mode = arr[0];
	int mode_count = 1;

	for (int i = 0; i < 5; i++)
	{
		int acc_count = 0; // count he actuall mode of each item
		// inneficient 0(n^2) time. can use a sort algorithm. mergesort algorithm (nlogn and pointers. total runtime 0(nlogn))
		for (int j = 0; j < 5; j++)
		{
			if (arr[j] == arr[i])
			{

				acc_count++;
			}
		}
		if (acc_count > mode_count)
		{
			mode_count = acc_count;
			mode = arr[i];
		}
	}

	return mode;
}

double standard_deviaiton(int arr[], int mean, int n)
{

	double squared_difference = 0;

	for (int i = 0; i < n; i++)
	{
		squared_difference += pow((arr[i] - mean), 2);
	}

	double stdv = sqrt(squared_difference / n);

	return stdv;
}

int main()
{
	// int n = 5;
	// int max_student_size = 1000;
	int x[5]; // array of variable length.
	// x[1]= x[2]= wrong because
	//  indexing begins at 0. x[0] and x[1].
	double avg = -5.0;
	x[0] = 10;
	x[1] = 7;
	x[2] = 5;
	x[3] = 9;
	x[4] = 10;
	int n = sizeof(x) / sizeof(x[0]);
	printf("length = %d \n", n);

	int mean_o_x = mean(x, n);
	printf("The mode is %d \n", mode(x));
	printf("The mean of the function = %lf \n", mean(x, n));
	printf("The standard deviation of the function = %lf \n", standard_deviaiton(x, mean_o_x, n));
}
