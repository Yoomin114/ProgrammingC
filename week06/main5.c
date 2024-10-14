#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int num1, num2;
	char c;
	
	printf("Enter the calculation: ");
	scanf("%i %c %i", &num1, &c, &num2);
	
	if (c == '+'){
		printf("= %i", num1+num2);
	}
	
	else if (c == '-'){
		printf("= %i", num1-num2);
	}
	
	else if (c == '*'){
		printf("= %i", num1*num2);
	}
	
	else if
	 (c == '/'){
		printf("= %i", num1/num2);
	}
	return 0;
}
