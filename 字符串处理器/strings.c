#include <stdio.h>
#include <stdlib.h>
#define MAX (100000)

int N=10;
void Config(){
    printf("请输入字符串数组的个数：");
    scanf("%d",&N);
}

void printarr(char *s[MAX],int n){
    int i;
    for (i=0;i<n;i++) puts(s[i]);
}

int length(char *s){
    int m=0;
    while (s[m]!=0) m++;
    return m;
}

char *combine(char *a,char *b){
    char *p;
	p=a;
	p+=length(a);
    while (*(p++)=*(b++));
    return a;
}

int strcomp(char *a,char *b){
	int i,l1,l2,l,t;
	l1=length(a);
	l2=length(b);
	l=(l1>l2?l1:l2);
	for (i=0;i<l;i++){
		t=a[i]-b[i];
		if (t) return t;
	}
	return 0;
}

void strcp(char *dest,char *str){
    while (*(dest++)=*(str++));
}

void strncp(char *dest,char *str,int n){
    int i=0;
    while ((*(dest++)=*(str++))&&++i<n);
	dest[n]=0;
}


void Insert(char s[],int pos,char t[]){
    char c[100000];
    strncp(c,s,pos);
	c[pos]=0;
    combine(c,t);
    combine(c,s+pos);
    strcp(s,c);
}

void SubString(char s[],int pos,int n,char sub[]){
    strncpy(sub,s+pos,n);
}

int Search(char s[], char t[]){
    int i;
    char p[100000]="";
    for (i=0;i<=length(s)-length(t);i++){
        SubString(s,i,length(t),p);
        if (strcmp(t,p)==0) return i;
    }
    return -1;
}

void Replace(char s[],char v[], char t[]){
    int m=0;
	char *p=s;
    while ((m=Search(p,v))!=-1){
		p+=m;
        strcp(p,p+length(v));
        Insert(p,0,t);
		p+=length(t);
    }
}
