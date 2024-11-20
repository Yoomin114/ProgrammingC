#include <stdio.h>
#include <string.h>

int main(void) {
	FILE *fp = NULL;
	
	char word[100];
		
	fp = fopen("C:\\Users\\candy\\Desktop\\숙명여대\\전프기\\W11\\sample.txt","r");
	
	if(fp == NULL){
		printf("파일을 열지 못합니다.\n");
	}
	
	while((fgets(word, sizeof(word), fp)) != NULL){
		printf("%s", word);
	}
	
	fclose(fp);
	
	// return 0;
}
