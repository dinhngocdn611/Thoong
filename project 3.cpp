#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

// do dai mang
int lenght(char a[100])
{
	int count = 0;
	while (a[count] != NULL)
	{
		count++;
	}
	return count;
}
// doc file cau hoi
// đặt file câu hỏi cần thay thế vào chung với source mới chạy đc. tên file cần nhập phải ghi namefile+ .txt 
void read_file(char *filename, char c[200])
{

	
	ifstream fin;
	fin.open(filename);
	int count = 0;
	while (!fin.eof())
	{
		fin.get(c[count]);
		count++;
	}
	c[count] = '\0';
	cout << "\n";
	fin.close();

}
// Liet ke cau hoi va sua doi cau hoi//

//đọc tất cả các câu hoi xong hết rồi và lưu vào mang list-question 
int modifythequestion(char list_question[100][200], int Number_of_current_questions)
{
	//liệt kê tất cả câu hỏi.
	printf("\nAll question:\n");
	int n = Number_of_current_questions;
	for (int i = 0; i < n; i++)
	{
		printf("\nQuestion %d:\n", i+1);
		printf("%s\n", list_question[i]);
		
	}
	
	printf("\nThe question the teacher wants to correct:");
	int replace;
	scanf("%d", &replace);
	replace = replace - 1;
	//nhap tuừ console.
	int type;
	cout << "\n1. Console\n2. File\n";
	scanf("%d", &type);
	if (type == 1)
	{
		char a[100];
		printf("\nThe content of the question wants to be changed: \n");
		fflush(stdin);
		gets(a);
		for (int i = 0; i < lenght(a); i++)
		{
			list_question[replace][i] = a[i];
		}
		list_question[replace][lenght(a)] = '\0';
	}
	//Thay doi cau hoi tu file.
	if (type == 2)
	{
		printf("Input name file:");
		char namechange[10];
		fflush(stdin);
		gets(namechange);
		char savequestion[100];
		read_file(namechange, savequestion);
		for (int i = 0; i < lenght(savequestion); i++)
		{
			list_question[replace][i] = savequestion[i];
		}
		list_question[replace][lenght(savequestion)] = '\0';
	}
	return 0;
}
//test
void main()
{
	
	char a[100][200];
	gets(a[0]);
	modifythequestion(a, 1);
	cout <<endl;	
	system("pause");
}