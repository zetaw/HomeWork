#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAXINT 2147483646

int N,ln,w;

void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}

void printarr(int*a,int n){
	int i;
	for (i=0;i<n;i++) {printf("%*d",w,a[i]);if (!((i+1)%ln))printf("\n");}
	printf("\n");
}


void FillArray(int a[],int n){
	int m,i;
	printf("��ѡ��\n");
	printf("1�� ��ָ����Χ��������������\n2�� ��������\n3�� ����������ͬһ��ֵ\n4�� �õȲ�����������飨ע���������е���ʼֵ��ÿ��Ĳ�ֵ��\n");
	printf("��ѡ����ţ�");
	scanf("%d",&m);
	switch (m){
		case 1:{
		int l,r;
	 	printf("��������߽���ұ߽磬�Կո�ָ���");
		scanf("%d%d",&l,&r);
		for (i=0;i<n;i++) a[i]=rand()%(r-l)+l;
		break;
		}
		case 2:{
			printf("������n�������Կո��س��ָ���\n");
		 	for (i=0;i<n;i++) scanf("%d",&a[i]);
			break;
		}
		case 3:{
		int t;
		printf("������һ������");
		scanf("%d",&t);
		for (i=0;i<n;i++) a[i]=t;
		break;
		}
		case 4:{
		int a0,d;
		printf("����������͹���:");
		scanf("%d%d",&a0,&d);
		for (i=0;i<n;i++) a[i]=a0+i*d;
		break;
		}
	}
}

void Config(){
	printf("�������µĲ�����������Ԫ�ظ�����ÿ�д�ӡ��������ӡ��ȣ�");
	scanf("%d%d%d",&N,&ln,&w);
}

void Reverse(int a[],int n){
	int i;
	for (i=0;i<n/2;i++) swap(&a[i],&a[n-i-1]);
}

void insert(int a[],int n,int pos,int val){
	int i;
	for (i=n;i>=pos;i--) a[i]=a[i-1];
	a[pos-1]=val;
	N++;
}

void Delete(int a[],int n,int id){
	int i;
	if (id==-1) {printf("û�д�Ԫ�أ�\n");return;}
	for (i=id-1;i<n-1;i++) a[i]=a[i+1];
	N--;
}

void DeleteRange(int a[],int n,int s,int t){
	int i;
	for (i=s-1;i<n-(t-s+1);i++) a[i]=a[i+(t-s+1)];
	N-=(t-s+1);
}

int Search(int a[],int n,int val){
	int i;
	for (i=0;i<n;i++) if (a[i]==val) return i;
	return -1;
}

int isAsc(int a[],int n){
	int i;
	for (i=0;i<n-1;i++) if (a[i+1]<a[i]) return 0;
	return 1;
}

int isDesc(int a[],int n){
	int i;
	for (i=0;i<n-1;i++) if (a[i+1]>a[i]) return 0;
	return 1;
}

int isEqual(int a[],int n){
	return (isAsc(a,n)&&isDesc(a,n));
}

int max(int a[],int n){
	int i,m=0;
	for (i=1;i<n;i++) if (a[m]<a[i]) m=i;
	return m;
}

int min(int a[],int n){
	int i,m=0;
	for (i=1;i<n;i++) if (a[m]>a[i]) m=i;
	return m;
}

float average(int a[],int n){
	int i;
	float s=0;
	for (i=0;i<n;i++) s+=a[i];
	return s/n;
}

float variance(int a[],int n){
	int i;
	float p=average(a,n),s=0;
	for (i=0;i<n;i++) s+=(a[i]-p)*(a[i]-p);
	return s/n;
}
void OrderInsert(int a[],int n,int val){
	int i,p;
	if (a[0]>a[1]) p=1; else p=0;
	if (p^(a[0]>val)) {insert(a,n,1,val);return;}
	if (p^(a[n-1]<val)) {insert(a,n,n+1,val);return;}
	for (i=0;i<n-1;i++)
		if ((p^(a[i]<=val))&&(p^(a[i+1]>val))) {insert(a,n,i+2,val);return;}
}

void BubbleSort(int a[],int n,int (*comp)(int a,int b)){
	int i,j;
	for (i=0;i<n-1;i++) for (j=0;j<n-i-1;j++) if ((*comp)(a[j+1],a[j])) swap(&a[j],&a[j+1]);
}

void SelectSort(int a[],int n,int (*comp)(int a,int b)){
	int i,j,m;
	for (i=0;i<n-1;i++){
		m=i;
		for (j=i+1;j<n;j++) if ((*comp)(a[j],a[m])) m=j;
		swap(&a[i],&a[m]);
	}
}

void ExchangeSort(int a[],int n,int (*comp)(int a,int b)){
	int i,j;
	for (i=0;i<n-1;i++)
		for (j=i+1;j<n;j++) if (!((*comp)(a[i],a[j]))) swap(&a[i],&a[j]);
}
void qsm(int a[],int l,int r,int (*comp)(int a,int b)){
	int i=l,j=r,m=a[l];
	if (i>=j) return;
	while (i<j){
		while ((*comp)(m,a[j])&&i<j) j--;
		while ((*comp)(a[i],m)&&i<j) i++;
		swap(&a[i],&a[j]);
	}
	swap(&a[l],&a[i]);
	qsm(a,l,i-1,comp);
	qsm(a,i+1,r,comp);
}

int BiSearch(int a[],int n,int val,int (*comp)(int a,int b)){
	int l=0,m,r=n-1;
	while (l<=r){
		m=(l+r)/2;
		if ((*comp)(a[m],val)) l=m+1;
		if ((*comp)(val,a[m])) r=m-1;
		if (a[m]==val) return m;
	}
	return -1;
}

void LeftRotate(int a[],int n,int m){
	int i;
	for (i=0;i<m;i++){
		insert(a,n,n+1,a[0]);
		Delete(a,n+1,1);
	}
}


void RightRotate(int a[],int n,int m){
	int i;
	for (i=0;i<m;i++){
		insert(a,n,1,a[n-1]);
		Delete(a,n+1,n+1);
	}
}

void joseph(int n,int m){
    int i,a[100000],p,t;
	for (i=0;i<=n;i++) a[i]=0;
	i=0;p=0;t=0;
	do{
		i++;if (i>n) i=1;
		if (!a[i]) t++;
		if (t==m){
			t=0;
			p++;
			a[i]=1;
			printf("%d\n",i);
		}
	}while (p!=n);
}

void prime(int n){
    int i,j;
	int a[100000];
	for (i=0;i<=n;i++) a[i]=0;
	for (i=2;i<=n;i++){
		if (a[i]==0){
			printf("%d ",i);
			for (j=i;j<=n;j+=i) a[j]=1;
		}
	}
	printf("\n");
}
