#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef MAIN_H
#define MAIN_H
#define N 100
struct books{
	int booknum;
	char bookname[20];
	char auther[20];
	char publisher[20];
	char publishtime[20];
	char price[10];
}book[N];

int input;
int flag;
int fileexist;
int sum;
char keywords[30];

void showmain();
void clearscreen();
void bookinput();
void bookbrowse();
void booksearch();
void bookchange();
void bookdelete();
void inputerror();
void exitsystem();
void yesorno();
void firsttime();
void INIT();
void WRITE();
void READ();
void RM();
void showbook(int a);

#endif