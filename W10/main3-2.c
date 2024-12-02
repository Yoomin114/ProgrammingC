#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	
	int i =0;
	int a[SIZE] = {1, 2, 3, 4, 5};
	int b[SIZE] = {1, 2, 3, 7, 10};

	for(i=0; i<SIZE; i++){
		if(a[i] != b[i]){
			printf("a[%d] and b[%d] have different values\n", i, i);
			printf("a[%d] = %d b[%d] = %d\n\n", i, a[i], i, b[i]);
		}
	}

	return 0;
}
