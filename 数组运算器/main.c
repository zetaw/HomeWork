#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAXINT 2147483646
#include "array.h"
extern N;
int comp1(int a,int b){return a<=b;}
int comp2(int a,int b){return a>=b;}
int comp3(int a,int b){return a<b;}
int comp4(int a,int b){return a>b;}
int main(){
	int n,m,s,t,val,pos,temp,mm,mn;
	int (*p)(int a,int b);
	int a[100000];
	srand((unsigned int)(time(0)));
	Config();
	do{
		printf("0���˳�\n1������ϵͳ����\n2��������������\n3����ʾ����\n4��ɾ��\n5������\n6��ͳ��\n7������\n8���ж�������\n9����������Ԫ��\n10�����������Ӧ��\n");
		scanf("%d",&n);
		fflush(stdin);
		switch(n){
		case 1:Config();break;
		case 2:FillArray(a,N);break;
		case 3:printarr(a,N);break;
		case 4:{
			printf("��ѡ��\n");
			printf("1�� ɾ��ָ���±��Ԫ��\n2�� ɾ��ָ��ֵ��Ԫ��\n3�� ɾ����ָ���±������һ��Ԫ��\n");
			scanf("%d",&m);
			switch (m){
				case 1:printf("������Ҫɾ����Ԫ�ص��±꣺");
				       scanf("%d",&pos);
				       Delete(a,N,pos);
				       break;
				case 2:printf("������Ҫɾ����Ԫ�صĴ�С��");
				       scanf("%d",&val);
				       Delete(a,N,Search(a,N,val)+1);
				       break;
				case 3:printf("��������߽���ұ߽磺");
				       scanf("%d%d",&s,&t);
				       DeleteRange(a,N,s,t);
				       break;
			}
			break;
		       }

		case 5:{
			printf("��ѡ��\n");
		        printf("1����ָ���±�λ�ò�����Ԫ��\n2�������������в�����Ԫ��\n");
			scanf("%d",&m);
			switch(m){
				case 1:printf("������Ҫ�����Ԫ�ص��±�ʹ�С��");
				       scanf("%d%d",&pos,&val);
				       insert(a,N,pos,val);
				       break;
				case 2:printf("������Ҫ�����Ԫ�صĴ�С��");
				       scanf("%d",&val);
				       OrderInsert(a,N,val);
				       break;
			}
			break;
		}
		case 6:{
			printf("��ѡ��\n");
			printf("1�������ֵ\n2������Сֵ\n3����ƽ��ֵ\n4���󷽲�;�����\n");
			scanf("%d",&m);
			switch (m){
				case 1:printf("���ֵ�±���%d��ֵΪ%d\n",max(a,N)+1,a[max(a,N)]);break;
				case 2:printf("��Сֵ�±���%d��ֵΪ%d\n",min(a,N)+1,a[min(a,N)]);break;
				case 3:printf("ƽ��ֵΪ��%f\n",average(a,N));break;
				case 4:printf("����Ϊ��%f\n������Ϊ��%f\n",variance(a,N),sqrt(variance(a,N)));break;
			}
			break;
		}
		case 7:{
		    printf("��ѡ��\n");
			printf("1����ͨ����\n2�����ֲ���\n");
			printf("���棺���ֲ��ұ��뱣֤��������\n");
			scanf("%d",&m);
			switch (m){
				case 1:printf("����������Ҫ���ҵ�Ԫ�صĴ�С��");
                       scanf("%d",&val);
                       temp=Search(a,N,val);
                       if (temp==-1) printf("���޴�����\n"); else printf("��Ԫ���ǵ�%d��\n",temp+1);
                       break;
				case 2:printf("����������Ҫ���ҵ�Ԫ�صĴ�С��");
                       scanf("%d",&val);
                       if (a[0]<=a[1]) temp=BiSearch(a,N,val,comp3); else temp=BiSearch(a,N,val,comp4);
                       if (temp==-1) printf("���޴�����\n"); else printf("��Ԫ���ǵ�%d��\n",temp+1);
                       break;
			}
            break;
		}
		case 8:{
		    if (isEqual(a,N)) printf("ȫ����ȣ�\n");
		    else if (isAsc(a,N)) printf("ȫ������\n");
		    else if (isDesc(a,N)) printf("ȫ������\n");
		    else printf("�Ȳ�����Ҳ������\n");
            break;
		}
		case 9:{
			printf("��ѡ��\n");
			printf("1������\n2����������\n3����������\n4����������\n");
			scanf("%d",&m);
			switch (m){
				case 1:printf("��ѡ��\n");
                       printf("1����������\n2����������\n");
                       scanf("%d",&mm);
                       if (mm==1) p=comp1; else if (mm==2) p=comp2; else break;
                       printf("1��ð�ݷ�\n2��ѡ��\n3��������\n");
                       scanf("%d",&mm);
                       switch (mm){
                           case 1:BubbleSort(a,N,p);break;
                           case 2:SelectSort(a,N,p);break;
                           case 3:ExchangeSort(a,N,p);break;
                       }
                       break;
				case 2:Reverse(a,N);break;
				case 3:printf("������������λ����");
                       scanf("%d",&mm);
                       LeftRotate(a,N,mm);
                       break;
				case 4:printf("������������λ����");
                       scanf("%d",&mm);
                       RightRotate(a,N,mm);
                       break;
			}
			break;
		}
		case 10:{
            printf("��ѡ��\n");
			printf("1��Լɪ��\n2��ɸ��������\n");
			scanf("%d",&m);
			switch (m){
                case 1:printf("�ж����ˣ�");scanf("%d",&mn);
                       printf("��1�����ٱ�����");scanf("%d",&mm);
                       joseph(mn,mm);
                       break;
                case 2:printf("���1������֮���������");scanf("%d",&mm);
                       prime(mm);
                       break;
			}
            break;
		}
		}
	}while(n);
	return 0;
}
