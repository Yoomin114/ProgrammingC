#include <stdio.h>

char *proverb = "All the glisters is not gold.";

void setPointer(char **q){
	*q = proverb;
}

int main(void){
	char *p = "zzz";
	setPointer(&p);
	printf("%s\n",p);
	
	return 0;
	
}

//All the glisters is not gold.
