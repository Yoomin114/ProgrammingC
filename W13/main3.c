#include <stdio.h>

#define STUDENTNUM 4

struct student{
	int		ID;
	int		score;
};

void main(void){
	int i;
	double sum =0.0, avg;
	int max_score, max_score_ID;
	
	struct student s[STUDENTNUM];
	
	for(i=0; i<STUDENTNUM; i++){
		printf("Input the ID: ");
		scanf("%d", &s[i].ID);
		printf("Input the score: ");
		scanf("%d", &s[i].score);
	}
	
	for (i=0; i<STUDENTNUM; i++){
		sum += s[i].score;
	}
	
	avg = sum / STUDENTNUM;
	printf("The average of the score: %f \n", avg);
	
	max_score = s[0].score;
	max_score_ID = s[0].ID;
	
	for(i=1; i<STUDENTNUM; i++){
		
		if(s[i].score>max_score){
			
			max_score = s[i].score;
			max_score_ID = s[i].ID;
		}
	}

	printf("The highest score - ID: %d, score: %d", max_score, max_score_ID);
	
	
	return 0;
	
}
