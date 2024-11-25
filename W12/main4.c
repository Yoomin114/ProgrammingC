#include <stdio.h>

int main(void) {
	int i;
	int grade[5];
	int sum = 0;
	int avg;

	for(i=0; i<5; i++){
		printf("Input value - grade[%i] = ",i);
		scanf("%d", &grade[i]);
	}
	
	
	int *ptr = grade;
	
	for (i=0; i<5; i++){
		printf("grade[%i] = %i\n",i , grade[i]);
		sum += *(ptr + i);
	}
	
	avg = sum / 5;
	
	printf("average: %i\n", avg);
	
	
	return 0;
}
