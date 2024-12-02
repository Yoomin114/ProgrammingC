#include <stdio.h>

int main(void){
	
	char c;
	char changed;
	
	printf("enter a character: ");
	scanf("%c", &c);
	changed = c + 1;
	
	printf("The next character of %c (%i) is %c (%i)\n", c, c, changed, changed);
	
	return 0;
}
