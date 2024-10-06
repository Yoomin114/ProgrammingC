#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int year;
	int leap;
	
	printf("Input the year: ");
	scanf("%i",&year);
	leap = year%4 == 0 && year%100 != 0 || year%400==0;
	
	printf("Is the year %i the leap year? %i",year,leap);

		
		
	return 0;
}
