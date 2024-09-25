#include <stdio.h>

int main(void){
	
	float a;
	float b;
	
	printf("enter two integers (use ,) : ");
	scanf("%f,%f", &a, &b);
	
	printf("%f / %f = %f", a, b, a/b);
	
	return 0;
	
}
