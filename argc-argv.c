#include <stdio.h>

int main(int argc, char *argv[])
{
	#argc is the argument counts
	printf("Number of arguments: %d \n", argc);
	
	for (int i =0; i<argc; i++){

		printf("Argument %d: %s \n",i, argv[i]);
}
	return 0;

}
