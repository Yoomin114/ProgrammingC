#include <stdio.h>

struct student{
	int		ID;
	char	name[10];
	double	grade;
};

int main(void){
	struct student s1 = {2213432, "Yoomin", 3.39};
	
	printf("Original information\n\n");
	printf("ID: %d\n", s1.ID);
	printf("name: %s\n", s1.name);
	printf("grade: %f\n\n", s1.grade);
	
	printf("\nInput the ID: ");
	scanf("%d", &s1.ID);
	
	printf("Input the name: ");
	scanf("%s", &s1.name);
	
	printf("Input the grade: ");
	scanf("%f", &s1.grade);
	
	printf("\nNew information\n\n");
	printf("ID: %d\n", s1.ID);
	printf("name: %s\n", s1.name);
	printf("grade: %f\n", s1.grade);
	
}
