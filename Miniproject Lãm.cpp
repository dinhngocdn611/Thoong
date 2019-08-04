#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <ctype.h>
#include <conio.h>
void Writefile (int Data);
void Login (int enter);
void check (int a, int b);
void readfile (FILE *file);


struct Info
{
	char name [30];
	char role [30];
	char ID[30];
	char password [8];
};


int main ()
{
	int i, n, info, enter, ID, password;
	struct Info user;
	struct Info login;
	Writefile (info);
	Login (enter);
	check (ID, password);
	return 0;
 }
 
 
 void Writefile (int Data)
 {
 	int i, n;
 	struct Info user;
 	const char *filePath = "C:\\Users\\Lãm\\student.txt";
	FILE *file;
	file = fopen(filePath,"w+");
 	printf ("The number of students: ");
	scanf ("%d", &n);
 	for (i=1;i<=n;i++)
 	{
 		printf ("\n\nAccount ID %d: ", i);
 		scanf("%s", &user.ID);
			fprintf (file,"Account ID %d: %s \n", i, user.ID);
 		printf ("\nName %d: ",i);
 		fflush(stdin);
 		gets (user.name);
 			fprintf (file,"Name %d: %s \n", i, user.name);
 		printf ("\nPassword %d: ",i);
 		scanf("%s", &user.password);
 			fprintf (file,"Password %d: %s \n", i, user.password);
 		printf ("\nRole %d: ",i);
 		scanf ("%s", &user.role);
 			fprintf (file,"Role %d: %s \n", i, user.role);
 	}
 	fclose(file);
 }
 
 
 void Login (int enter)
 {
 	int i, n;
	struct Info login;
 	printf ("Enter your Account ID: ");
 	fflush(stdin);
 	gets (login.ID);
 	printf ("Enter your Password: ");
 	for(i=1;i<=8;i++)
	{
	login.password[i]=getch();
	printf("*");   	
	}
	login.password[i]='\0';
	printf("\n\nPress Enter to continue");
	getch();
	if (strcmpi ())
 }
 
 
 void check (int a, int b)
 {
 	int i;
 	struct Info user;
	struct Info login;
	FILE *file;
	file = fopen("C:\\Users\\Lãm\\student.txt","w+");
	while (!feof(file))
	{
		readfile (file);
    	a = strcmp( user.ID , login.ID );
    	b = strcmp( user.password , login.password );
	}
	if (a == 0 && b == 0)
	{
		printf ("Login success! \a \n ");
		printf ("Hello %s %s !", user.name , user.role );
	}
	else if (a != 0)
	{
		printf ("This account does not exist! \a \nPlease register and then try again!");
	}
	else if (b != 0)
	{
		printf ("Wrong password, please try again! \a");
	}
	fclose(file);
 }
 
 
void readfile (FILE *file)
 {
 	struct Info user;
	file = fopen("C:\\Users\\Lãm\\student.txt","w+");
 	fscanf (file, "%s", user.ID);
 	fscanf (file, "%s", user.password);
 	fscanf (file, "%[^\n]", user.name);
 	fscanf (file, "%s", user.role);
 	fclose(file);
 }
