#include <stdio.h>
#include <string.h>

int main(void) {
	FILE *fp = NULL;
	
	char ch;
		
	fp = fopen("C:\\Users\\candy\\Desktop\\숙명여대\\전프기\\W11\\sample.txt","r");
	
	if(fp == NULL){
		printf("파일을 열지 못합니다.\n");
	}
	
	while((ch = fgetc(fp)) != EOF){
		putchar(ch);
	}
	
	fclose(fp);
	
	// return 0;
}
