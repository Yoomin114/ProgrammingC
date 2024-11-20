#include <stdio.h>
#include <string.h>

int main(void) {
	char word1[100];
	char word2[100];	
	char word3[100];
	int i = 0;
	FILE *fp;
	
	printf("input a word:");
	scanf("%s", word1);
	
	printf("input a word:");
	scanf("%s", word2);
	
	printf("input a word:");
	scanf("%s", word3);
	
	fp = fopen("C:\\Users\\candy\\Desktop\\숙명여대\\전프기\\W11\\sample.txt","w");
	
	if(fp==NULL){
		printf("파일을 열지 못합니다.\n");
	}
	
	fprintf(fp, "%s\n%s\n%s\n", word1, word2, word3) ;
	
	fclose(fp);
	
	//return 0;
}
