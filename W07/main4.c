#include <stdio.h>
#include <stdlib.h>



int combination(int n, int r){

	return (factorial(n)/(factorial(n-r)*factorial(r)));
}

int factorial(int x){
	int i;
	int res = 1;
		
	for(i=1; i<=x; i++){
		res= res*i;	
	}	
	
	return (res);
}

int get_integer(int num){
	
	printf("Enter the value of: ");
	scanf("%i",&num);
	return(num);
	
}

int main(int argc, char *argv[]) {
	int n, r, result;
	
	n= get_integer(n);
	r= get_integer(r);
	result = combination(n,r);
	
	printf("The result of C(%i, %i) is %i",n,r,result);
	
	return 0;
}
