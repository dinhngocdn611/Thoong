#include <stdio.h>
#include <stdlib.h>


void main()
{
	char s[1000],deadline[1000];
	int i,quizid,a[100],n;
	FILE *p4,*quiz;
	p4 = fopen("C:\\Users\\votha\\Desktop\\Project 4\\P4.txt","r");
	quiz = fopen("C:\\Users\\votha\\Desktop\\Project 4\\quiz.txt","a+");
	i=0;
	while (!feof(p4))
	{
		i++;
		fgets(s,1000,p4);
		printf("%d %s",i,s);
	}
	printf("\n");
	printf("Input QuizID: ");scanf("%d",&quizid);fprintf(quiz,"%d\n",quizid);
	printf("Input the number of question: ");scanf("%d",&n);
	printf("Input QuestionID: ");
	for (i=0;i<n-1;i++)
	{
	scanf("%d",&a[i]);
	fprintf(quiz,"%d, ",a[i]);
	}
	scanf("%d",&a[i]);
	fprintf(quiz,"%d ",a[i]);
	fprintf(quiz,"\n");
	fflush;
	printf("Input Deadline: ");scanf("%s",&deadline);fprintf(quiz,"%s\n",deadline);
	fclose(p4);
}
