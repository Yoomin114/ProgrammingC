#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a, b, n, x, y;

int SumTwo(a,b){

	return (a+b);
}

int Square(n){	

	return(n*n);	
}
	
int get_max(x,y){

	
	if (x-y>0){
		return x;
	}	
	else {
		return y;
	}
}

int main(int argc, char *argv[]) {
	int num1, num2, sum, square, max;
	
	printf("Enter the integers: ");
	scanf("%i %i",&num1,&num2);
	
	sum = SumTwo(num1,num2);
	square = Square(num1);
	max = get_max(num1, num2);
	
	printf("Result - Sum: %i, Square: %i, Max: %i",sum,square,max);
	
	
	return 0;
}
