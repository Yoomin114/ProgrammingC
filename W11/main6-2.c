#include <stdio.h>
#include <string.h>

int main(void) {
	FILE *fp = NULL;
	
	char word[100];
		
	fp = fopen("C:\\Users\\candy\\Desktop\\������\\������\\W11\\sample.txt","r");
	
	if(fp == NULL){
		printf("������ ���� ���մϴ�.\n");
	}
	
	while((fgets(word, sizeof(word), fp)) != NULL){
		printf("%s", word);
	}
	
	fclose(fp);
	
	// return 0;
}
