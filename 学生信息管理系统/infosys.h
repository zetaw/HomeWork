#ifndef INFOSYS_H
#define INFOSYS_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct student{
	char name[255];
	int gender;
	float score;
	char num[10];
	char telnum[20];
	struct student *next;
} stu;

stu* CreateListF(FILE *f);
stu* CreateListR(FILE *f);
stu* CreateListO(FILE *f);
stu* copy(stu *src);
stu* createStu(char *name,int gender,float score,char *num,char *telnum);
int fscanStu(FILE *f,stu *s);
void fprintStu(FILE *f,stu *s);
void fprintList(FILE *f,stu *head);
stu* GetStu(stu *head,int num);
stu* ListInsert(stu *head,stu *ps,int num);
stu* OrderInsert(stu *head,stu *ps);
stu* ListDelete(stu *head,int num);
stu* NumDelete(stu *head,char *num);
stu* Search(stu *head,char *num);
int length(stu *head);
float avscore(stu *head);
float maxscore(stu *head);
int npnum(stu *head,float passed_score);
stu* destroy(stu *head);
void ReWrite(stu *head,char *file);
void AddWrite(stu *head,char *file);
void clear(char *file);


#endif //INFOSYS_H
