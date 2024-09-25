#include <stdio.h>

int main(void){
	
	char c;
	int i;
	
	printf("input a number : ");
	scanf("%c", &c);
	
	i = c - '0';
	printf("The input number is %i\n", i);
	
	return 0;
}
