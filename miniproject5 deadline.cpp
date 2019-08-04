#include<stdio.h>
#include<time.h>
int calhours(int, int ,int);
int main()
{
	FILE*f1;
	f1=fopen("D:\\deadline.txt","a");//phan nay deadline.txt thay bang cái file question nha
	FILE*f2;
int d,m,y;
printf("please input deadline\n");
printf("date:\t");
scanf("%d",&d);
printf("month:\t");
scanf("%d",&m);
printf("year:\t");
scanf("%d",&y);
fprintf(f1,"deadline: %d/%d/%d\n", d,m,y);
	int a[]={31,28,31,30,31,30,31,31,30,31,30,31},i;
int days = 0;
for (int i=0;i<m-1;i++)
{
	days = days + a[i];
}
days = days + d +(y-1970)*365+(y-1970)/4;
int hours = days*24;
f2=fopen("D:\\hours.txt","w");//phan nay la tui ghi vo file khac tg tinh tu nam 1970 toi deadline = ...h de lay ra ss o mini project6
fprintf(f2,"%d",hours);

}
