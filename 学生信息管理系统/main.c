#include "infosys.h"

int main(){
	int n,m,mm;
		stu *head,*q;
		char cs[255],filer[255]="",filew[255]="";
		FILE *read=NULL,*write=NULL;
	printf("欢迎来到学生信息管理系统！\n");
	do{
		printf("0.退出\n1.创建学生记录链表\n2.打印全部学生记录\n3.插入一条新的学生记录\n4.删除一条学生记录\n5.按学号查找学生记录\n6.统计\n7.销毁学生链表\n8.将学生信息写入磁盘文件\n");
			scanf("%d",&n);
			switch (n){
				case 1:printf("请选择：\n1）头插法\n2）尾插法\n3）创建按学号有序链表\n");
				       scanf("%d",&m);
					       printf("请选择：\n1）从键盘输入2）打开学生信息文件创建链表\n");
					       scanf("%d",&mm);
					       if (mm==1) read=stdin; else if (mm==2){
						       printf("请输入文件路径：");
							       getchar();
							       gets(filer);
							       read=fopen(filer,"r");
					       }
				       switch (m){
					       case 1:head=CreateListF(read);break;
					       case 2:head=CreateListR(read);break;
					       case 3:head=CreateListO(read);break;
					       default:break;
				       }
				       if (mm==2) fclose(read);
					       break;
				case 2:printf("      学号      姓名   性别      成绩       电话号码\n");
				       fprintList(stdout,head);
					       break;
				case 3:printf("请选择：\n1）按指定位序插入\n2）在有序链表中插入\n");
				       scanf("%d",&m);
					       q=createStu("",0,0,"","");
					       fscanStu(stdin,q);
					       if (m==1) {
						       printf("你要插入到哪一号？（第一条记录是第0条）\n");
							       scanf("%d",&mm);
							       if (NULL==ListInsert(head,q,mm)) printf("插入错误！\n");;
					       }
					       else OrderInsert(head,q);
						       break;
				case 4:printf("请选择：\n1）删除指定位置的记录\n2）删除指定学号的记录\n");
				       scanf("%d",&m);
					       if (m==1) {
						       printf("你要删除哪一号？（第一条记录是第0条）\n");
							       scanf("%d",&mm);
							       if (ListDelete(head,mm)==NULL) printf("无此记录！\n");
					       }
					       else {
						       printf("你要删除学号为多少的记录？\n");
							       getchar();
							       gets(cs);
							       if (NumDelete(head,cs)==NULL) printf("无此记录！\n");
					       }
				       break;
				case 5:printf("你要查找学号为多少的记录？\n");
				       getchar();
					       gets(cs);
					       q=Search(head,cs);
					       if (q==NULL) printf("无此记录！\n");else fprintStu(stdout,q);
						       break;
				case 6:printf("请选择：1）统计学生人数\n2）统计学生的平均成绩和最高分\n3）统计不及格人数\n");
				       scanf("%d",&m);
					       switch (m){
						       case 1:printf("人数为：%d\n",length(head));break;
						       case 2:printf("平均分为：%f 最高分为%f\n",avscore(head),maxscore(head));break;
						       case 3:printf("不及格人数为：%d\n",npnum(head,60));break;
						       default:break;
					       }
				       break;
				case 7:head=destroy(head);break;
				case 8:printf("请选择：1）重写学生文件\n2）追加学生文件\n3）清空学生文件\n");
				       scanf("%d",&m);
					       if (filew[0]=='\0') {
						       printf("检测到您还未设定文件路径，请先设置：");
							       getchar();
							       gets(filew);
					       }
				       switch (m){
					       case 1:ReWrite(head,filew);break;
					       case 2:AddWrite(head,filew);break;
					       case 3:clear(filew);break;
					       default:break;
				       }
				       break;
			}
			fflush(stdin);
	}while (n);
	head=destroy(head);
	return 0;
}
