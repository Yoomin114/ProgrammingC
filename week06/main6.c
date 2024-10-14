#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int answer= 50;
	int num, trial =0;
	
	do {
		num =0;
		
		printf("Guess a number: ");
		scanf("%i", &num);
		
		trial ++;
		
		if (num < answer) {
			printf("Low!\n");
		}
		
		else if (num> answer){
			printf("High!\n");
		}

	} while(num != answer);
	
	printf("Congratulation! Trials: %i", trial);
	return 0;
}
