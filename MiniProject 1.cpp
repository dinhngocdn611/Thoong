#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <ctype.h>
#include <conio.h>

struct Info 
{
	char ID[30];
	char name[30];
	char role[30];
	char password[10];
};


struct Info readFile(FILE *file)
{
	struct Info user;
	fscanf(file, "%s", user.ID);
	fscanf(file, "%s", user.name);
	fscanf(file, "%s", user.password);
	fscanf(file, "%s", user.role);
	return user;
}


void Writefile() 
{
	int i, n;
	struct Info user;
	const char *filePath = "student.txt";
	FILE *file = fopen(filePath, "w+");
	printf ("The number of students: ");
	scanf ("%d", &n);
	fflush(stdin);
	for (i = 1; i <= n; i++) 
	{
		printf ("\n\nAccount ID %d: ", i);
		fprintf (file, "%s\n", gets(user.ID));
		
		printf ("\nName %d: ", i);
		fprintf (file, "%s\n", gets(user.name));
		
		printf ("\nPassword %d: ", i);
		fprintf (file, "%s\n", gets(user.password));
		
		printf ("\nRole %d: ", i);
		fprintf (file, "%s\n\n", gets(user.role));
		
		printf("\n-> Check Log | ID=%s | Name=%s | Pass=%s | Role=%s | \a \n", user.ID, user.name, user.password, user.role);
	}
	printf ("\nRegister success! Sign in for QUIZ! \a \n \n \n");
	fflush(stdin);
	fclose(file);
}


struct Info Login() 
{
	int i, n;
	struct Info login;
	printf ("Enter your Account ID: ");
	fflush(stdin);
	gets(login.ID);
	printf ("Enter your Password: ");
	fflush(stdin);
	//gets(login.password);
	for(i = 0; i < 8; i++) 
	{
		login.password[i] = getch();
		printf("*");
	}
	login.password[i] = '\0';
	printf("\n\n Press Enter to continue ! \a");
	getch();
	return login;
}


int checkLogin() 
{
	FILE *file = fopen("student.txt","r+");
	struct Info user = readFile(file);
	struct Info login = Login();
	while (!feof(file)) 
	{
		if (!strcmp(user.ID, login.ID))
		{ // Check for the same ID, if not moving on to the next account !
			if (!strcmp(user.password, login.password)) 
			{
				printf ("\n Login success! \n");
				printf (" Hello %s %s! \a", user.role , user.name);
				return fclose(file); // Exit the check() function !
			}
			else
			{
				printf (" Wrong password, please try again! \a\n");
				return fclose(file); // Exit the check() function !
			}
		}
		user = readFile(file);
	}
	printf ("\n This account does not exist ! \a \nPlease register and then try again! \n");
	return fclose(file);
}


int main() 
{
	Writefile();
	checkLogin();
}

