#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>
int main()
{
	FILE*sol;
	FILE*f1;
	sol=fopen("D:\\solutions.txt","w");
	f1=fopen("D:\\hours.txt","r");
	int hours;
	fscanf(f1,"%d",&hours);
time_t seconds;
seconds = time(NULL);
seconds = seconds/3600;
if (hours>seconds)
printf("good luck with your quiz!!");
else printf("You missed the deadline, see you next semester :> ");
  FILE *f=fopen("D:\\f.txt","r"); // phan nay f.txt thay the bang file question nha ^^
if(!f){
printf("Error!\n");
getch();
exit(0);
}
int z,p=0;
char c;
char line[255];
int i,j=1;
while(!feof(f))
{
c=fgetc(f);
i=0;


while(c!='\n'&&c!=EOF)
{
line[i]=c;
i++;
c=fgetc(f);
}
line[i]='\0';
printf("\n ",j);
printf(line);


if ((j)!=0&&((j)%6)==0)
{p++;
	printf("\nplease input your answer: ");
	scanf("%d", &z);
	printf("\n");
	fprintf(sol,"%d-%d\n",p,z);
	fseek(f,9,SEEK_CUR);
	
}
j++;


getch();

}
}
