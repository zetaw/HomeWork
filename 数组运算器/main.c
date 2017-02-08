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
		printf("0、退出\n1、配置系统参数\n2、生成样本数据\n3、显示数组\n4、删除\n5、插入\n6、统计\n7、查找\n8、判断升降序\n9、排列数组元素\n10、数组的其他应用\n");
		scanf("%d",&n);
		fflush(stdin);
		switch(n){
		case 1:Config();break;
		case 2:FillArray(a,N);break;
		case 3:printarr(a,N);break;
		case 4:{
			printf("请选择：\n");
			printf("1） 删除指定下标的元素\n2） 删除指定值的元素\n3） 删除按指定下标区间的一组元素\n");
			scanf("%d",&m);
			switch (m){
				case 1:printf("请输入要删除的元素的下标：");
				       scanf("%d",&pos);
				       Delete(a,N,pos);
				       break;
				case 2:printf("请输入要删除的元素的大小：");
				       scanf("%d",&val);
				       Delete(a,N,Search(a,N,val)+1);
				       break;
				case 3:printf("请输入左边界和右边界：");
				       scanf("%d%d",&s,&t);
				       DeleteRange(a,N,s,t);
				       break;
			}
			break;
		       }

		case 5:{
			printf("请选择：\n");
		        printf("1）按指定下标位置插入新元素\n2）在有序数组中插入新元素\n");
			scanf("%d",&m);
			switch(m){
				case 1:printf("请输入要插入的元素的下标和大小：");
				       scanf("%d%d",&pos,&val);
				       insert(a,N,pos,val);
				       break;
				case 2:printf("请输入要插入的元素的大小：");
				       scanf("%d",&val);
				       OrderInsert(a,N,val);
				       break;
			}
			break;
		}
		case 6:{
			printf("请选择：\n");
			printf("1）求最大值\n2）求最小值\n3）求平均值\n4）求方差和均方差\n");
			scanf("%d",&m);
			switch (m){
				case 1:printf("最大值下标是%d，值为%d\n",max(a,N)+1,a[max(a,N)]);break;
				case 2:printf("最小值下标是%d，值为%d\n",min(a,N)+1,a[min(a,N)]);break;
				case 3:printf("平均值为：%f\n",average(a,N));break;
				case 4:printf("方差为：%f\n均方差为：%f\n",variance(a,N),sqrt(variance(a,N)));break;
			}
			break;
		}
		case 7:{
		    printf("请选择：\n");
			printf("1）普通查找\n2）二分查找\n");
			printf("警告：二分查找必须保证数组有序！\n");
			scanf("%d",&m);
			switch (m){
				case 1:printf("请输入你需要查找的元素的大小：");
                       scanf("%d",&val);
                       temp=Search(a,N,val);
                       if (temp==-1) printf("查无此数！\n"); else printf("此元素是第%d号\n",temp+1);
                       break;
				case 2:printf("请输入你需要查找的元素的大小：");
                       scanf("%d",&val);
                       if (a[0]<=a[1]) temp=BiSearch(a,N,val,comp3); else temp=BiSearch(a,N,val,comp4);
                       if (temp==-1) printf("查无此数！\n"); else printf("此元素是第%d号\n",temp+1);
                       break;
			}
            break;
		}
		case 8:{
		    if (isEqual(a,N)) printf("全部相等！\n");
		    else if (isAsc(a,N)) printf("全部升序！\n");
		    else if (isDesc(a,N)) printf("全部降序！\n");
		    else printf("既不升序也不降序\n");
            break;
		}
		case 9:{
			printf("请选择：\n");
			printf("1）排序\n2）逆置数组\n3）左旋数组\n4）右旋数组\n");
			scanf("%d",&m);
			switch (m){
				case 1:printf("请选择：\n");
                       printf("1）升序排列\n2）降序排列\n");
                       scanf("%d",&mm);
                       if (mm==1) p=comp1; else if (mm==2) p=comp2; else break;
                       printf("1）冒泡法\n2）选择法\n3）交换法\n");
                       scanf("%d",&mm);
                       switch (mm){
                           case 1:BubbleSort(a,N,p);break;
                           case 2:SelectSort(a,N,p);break;
                           case 3:ExchangeSort(a,N,p);break;
                       }
                       break;
				case 2:Reverse(a,N);break;
				case 3:printf("请输入左旋的位数：");
                       scanf("%d",&mm);
                       LeftRotate(a,N,mm);
                       break;
				case 4:printf("请输入右旋的位数：");
                       scanf("%d",&mm);
                       RightRotate(a,N,mm);
                       break;
			}
			break;
		}
		case 10:{
            printf("请选择：\n");
			printf("1）约瑟夫环\n2）筛法求素数\n");
			scanf("%d",&m);
			switch (m){
                case 1:printf("有多少人？");scanf("%d",&mn);
                       printf("从1至多少报数？");scanf("%d",&mm);
                       joseph(mn,mm);
                       break;
                case 2:printf("输出1至多少之间的素数？");scanf("%d",&mm);
                       prime(mm);
                       break;
			}
            break;
		}
		}
	}while(n);
	return 0;
}
