#include <stdio.h>
#include <string.h>

int main(void) {
	FILE *fp = NULL;
	
	char ch;
		
	fp = fopen("C:\\Users\\candy\\Desktop\\������\\������\\W11\\sample.txt","r");
	
	if(fp == NULL){
		printf("������ ���� ���մϴ�.\n");
	}
	
	while((ch = fgetc(fp)) != EOF){
		putchar(ch);
	}
	
	fclose(fp);
	
	// return 0;
}
