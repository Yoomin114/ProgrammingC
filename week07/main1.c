#include <stdio.h>
#include <stdlib.h>


/* int main(int argc, char *argv[]) {
	
	int i;
	
	for(i=0; i<10; i++)
		printf("*");
	
	for(i=0; i<10; i++)
		printf("*");
	
	for(i= 0; i<10; i++)
		printf("*");
		
		
	return 0;
}
*/

void print_star()
{
	int i;
	for(i=0; i<10; i++)
		printf("*");
}

int main (void){
	print_star();
	print_star();
	print_star();
	
	return 0;
}
