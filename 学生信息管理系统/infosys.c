#include "infosys.h"

stu* GetStu(stu *head,int num){
	int i;
		stu *p=head;
		if (head==NULL) return NULL;
	for (i=0;i<num;i++) {p=p->next;if (p==NULL) return NULL;}
	return p;
}

stu *copy(stu *src){
	stu *p;
	if (NULL==(p=(stu*)malloc(sizeof(stu)))) return NULL;
	strcpy(p->name,src->name);
	strcpy(p->num,src->num);
	strcpy(p->telnum,src->telnum);
	p->gender=src->gender;
	p->score=src->score;
	p->next=NULL;
	return p;
}

stu* createStu(char *name,int gender,float score,char *num,char *telnum){
	stu *p;
	if (NULL==(p=(stu*)malloc(sizeof(stu)))) return NULL;
	strcpy(p->name,name);
	strcpy(p->num,num);
	strcpy(p->telnum,telnum);
	p->gender=gender;
	p->score=score;
	p->next=NULL;
	return p;
}

int fscanStu(FILE *f,stu *s){
	printf("请输入学生的学号，姓名，性别（1代表男，0代表女），成绩，手机号码，以空格分隔：\n");
	char t[25];
	fscanf(f,"%s",s->num);
	if (s->num[0]=='0') {fflush(f);return -1;}
	fscanf(f,"%s%s%f%s",s->name,t,&(s->score),s->telnum);
	if (!strcmp(t,"男")) s->gender=1;else s->gender=0;
	return 0;
}

void fprintStu(FILE *f,stu *s){
	char t[25];
		//if (s->gender) strcpy(t,"男");else strcpy(t,"女");
	fprintf(f,"%10s%10s%7s%10.2f%15s\n",s->num,s->name,(s->gender)?"男":"女",s->score,s->telnum);
}

stu *ListInsert(stu *head,stu *ps,int num){
	int i;
	stu *p=head,*q=copy(ps);
	if (num==0) {head=q;head->next=p;}
	else {
		for (i=0;i<num-1;i++) {p=p->next;if (p==NULL) return NULL;}
		q->next=p->next;
		p->next=q;
	}
	if (head==NULL) head=p;
	return head;
}

stu *OrderInsert(stu *head,stu *ps){
	stu *p=head,*q=copy(ps);
	int order;
	if (p==NULL) {p=q;return p;}
	if (p->next==NULL) {p->next=q;return p;}
	order=(strcmp(p->num,p->next->num)>=0);
	if (order^(strcmp(p->num,q->num)>=0)) {q->next=p;return q;}
	while (!(order^(strcmp(p->next->num,q->num)>=0)))
	{p=p->next;if (p->next==NULL) break;}
	return head;
}

stu* CreateListF(FILE *f){
	stu *head=NULL,*p=NULL;
	char c;
	do{
		p=createStu("",0,0,"","");
		if (fscanStu(f,p)==-1) return head;
		if (strcmp(p->num,"")==0) return head;
		head=ListInsert(head,p,0);
	}while ((c=getc(f))!=EOF);
	return head;
}

stu* CreateListR(FILE *f){
	stu *head=NULL,*q=NULL;
	stu *p=head;
	char c;
	do{
		q=createStu("",0,0,"","");
		if (fscanStu(f,q)==-1) return head;
		if (strcmp(q->num,"")==0) return head;
		if (head==NULL) {head=q;p=q;}else {p=ListInsert(p,q,1);p=p->next;}
	}while ((c=getc(f))!=EOF);
	if (p!=NULL) p->next=NULL;
		return head;
}

stu* CreateListO(FILE *f){
	stu *head=NULL,*p=NULL;
	char c;
	do{
		p=createStu("",0,0,"","");
		if (fscanStu(f,p)==-1) return head;
		if (strcmp(p->num,"")==0) return head;
		head=OrderInsert(head,p);
	}while ((c=getc(f))!=EOF);
	return head;
}

void fprintList(FILE *f,stu *head){
	stu *p=head;
	if (head==NULL){fprintf(f,"链表为空！\n");return;}
	do fprintStu(f,p);while ((p=p->next)!=NULL);
}

stu* ListDelete(stu *head,int num){
	stu *p,*q;
	if (head==NULL) return NULL;
	if (num==0) {p=head;p=p->next;free(head);return p;}
	p=GetStu(head,num-1);
	if (p==NULL) return NULL;
	if (p->next==NULL) return NULL;
	q=p->next;
	p->next=q->next;
	free(q);
	return head;
}

stu* NumDelete(stu *head,char *num){
	stu *p=head,*q;
		if (head==NULL) return NULL;
	if (strcmp(num,p->num)==0) return ListDelete(head,0);
	while (strcmp(p->next->num,num)!=0) {p=p->next;if (p->next==NULL) return NULL;}
	q=p->next;
	p->next=q->next;
	free(q);
	return head;
}

stu* Search(stu *head,char *num){
	stu *p=head;
		if (head==NULL) return NULL;
	while (strcmp(p->num,num)!=0) {p=p->next;if (p==NULL) return NULL;}
	return p;
}

int length(stu *head){
	if (head==NULL) return 0;
	stu *p=head;
	int i=1;
	while (p->next!=NULL) {p=p->next;i++;}
	return i;
}

float avscore(stu *head){
	stu *p=head;
	float s=0;
	int i=1;
		if (head==NULL) return 0;
	while (p->next!=NULL) {i++;s+=p->score;p=p->next;}
	return s/i;
}

float maxscore(stu *head){
	stu *p=head;
		if (head==NULL) return 0;
	float s=p->score;
	while (p->next!=NULL) {if (p->score>=s) s=p->score;p=p->next;}
	return s;
}

int npnum(stu *head,float passed_score){
	stu *p=head;
		if (head==NULL) return 0;
	int n=1;
	while (p->next!=NULL) {if (p->score<passed_score) n++;p=p->next;}
	return n;
}

stu* destroy(stu *head){
	int i;
	for (i=0;i<=length(head);i++) head=ListDelete(head,0);
	return NULL;
}

void clear(char *file){
	FILE *read;
	if (NULL==(read=fopen(file,"w"))) printf("Error!");
	else fclose(read);
}

void ReWrite(stu *head,char *file){
	FILE *read;
	if (NULL==(read=fopen(file,"w"))) printf("Error!");
	else {
		fprintList(read,head);
		//fprintf(read,"0\n");
		fclose(read);
	}
}

void AddWrite(stu *head,char *file){
	FILE *read;
	if (NULL==(read=fopen(file,"a"))) printf("Error!");
	else {
		fprintList(read,head);
		//fprintf(read,"0\n");
		fclose(read);
	}
}
