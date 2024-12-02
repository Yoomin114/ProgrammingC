#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int sec;
	int min, sec2;
	
	printf("Input the second: ");
	scanf("%i",&sec);
	
	min = sec/60;
	sec2 = sec%60;
	
	printf("The time is %i : %i\n",min,sec2);
	
	return 0;
}
