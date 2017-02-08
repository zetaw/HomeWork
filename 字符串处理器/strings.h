#ifndef STRINGS_H
#define STRINGS_H
#include <stdio.h>
#define MAX (1000)

void Config();
void printarr(char *s[MAX],int n);
int length(char *s);
char *combine(char *a,char *b);
int strcomp(char *a,char *b);
void strcp(char *dest,char *str);
void strncp(char *dest,char *str,int n);
void Insert(char s[],int pos,char t[]);
void SubString(char s[],int pos,int n,char sub[]);
int Search(char s[], char t[]);
void Replace(char s[],char v[], char t[]);

#endif // STRINGS_H
