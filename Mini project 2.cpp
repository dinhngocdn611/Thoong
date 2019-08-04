#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 1000 

struct addquestion
{
	int questionID;
	char question[size];
	char sol1[size];
	char sol2[size];
	char sol3[size];
	char sol4[size];
	char correct[size];
};

int main()
{
	int i=0;
	struct addquestion aq;
	FILE*add;
	char listquestions[size];
	add=fopen("E:\\New folder\\questions.txt","a+");
	
	while(!feof(add))
	{
		fgets(listquestions,size,add);
		i++;
		printf("%s",listquestions);
	}
	
	aq.questionID =(i/7)+1;
	fflush(stdin);
	printf("\n\n");
	printf("ADD NEW QUESTION\n");
	printf("Enter new question: ");
	gets(aq.question);
	printf("Enter solution 1: ");
	gets(aq.sol1);
	printf("Enter solution 2: ");
	gets(aq.sol2);
	printf("Enter solution 3: ");
	gets(aq.sol3);
	printf("Enter solution 4: ");
	gets(aq.sol4);
	printf("Enter correct solution: ");
	gets(aq.correct);
	
	fprintf(add,"\nQuestionID: %d\n",aq.questionID);
	fprintf(add,"Desc: %s\n",aq.question);
	fprintf(add,"Sol1: %s\n",aq.sol1);
	fprintf(add,"Sol2: %s\n",aq.sol2);
	fprintf(add,"Sol3: %s\n",aq.sol3);
	fprintf(add,"Sol4: %s\n",aq.sol4);
	fprintf(add,"Correct: %s",aq.correct);
		
	fclose(add);
	
	return 0;
	
}


