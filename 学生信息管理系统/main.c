#include "infosys.h"

int main(){
	int n,m,mm;
		stu *head,*q;
		char cs[255],filer[255]="",filew[255]="";
		FILE *read=NULL,*write=NULL;
	printf("��ӭ����ѧ����Ϣ����ϵͳ��\n");
	do{
		printf("0.�˳�\n1.����ѧ����¼����\n2.��ӡȫ��ѧ����¼\n3.����һ���µ�ѧ����¼\n4.ɾ��һ��ѧ����¼\n5.��ѧ�Ų���ѧ����¼\n6.ͳ��\n7.����ѧ������\n8.��ѧ����Ϣд������ļ�\n");
			scanf("%d",&n);
			switch (n){
				case 1:printf("��ѡ��\n1��ͷ�巨\n2��β�巨\n3��������ѧ����������\n");
				       scanf("%d",&m);
					       printf("��ѡ��\n1���Ӽ�������2����ѧ����Ϣ�ļ���������\n");
					       scanf("%d",&mm);
					       if (mm==1) read=stdin; else if (mm==2){
						       printf("�������ļ�·����");
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
				case 2:printf("      ѧ��      ����   �Ա�      �ɼ�       �绰����\n");
				       fprintList(stdout,head);
					       break;
				case 3:printf("��ѡ��\n1����ָ��λ�����\n2�������������в���\n");
				       scanf("%d",&m);
					       q=createStu("",0,0,"","");
					       fscanStu(stdin,q);
					       if (m==1) {
						       printf("��Ҫ���뵽��һ�ţ�����һ����¼�ǵ�0����\n");
							       scanf("%d",&mm);
							       if (NULL==ListInsert(head,q,mm)) printf("�������\n");;
					       }
					       else OrderInsert(head,q);
						       break;
				case 4:printf("��ѡ��\n1��ɾ��ָ��λ�õļ�¼\n2��ɾ��ָ��ѧ�ŵļ�¼\n");
				       scanf("%d",&m);
					       if (m==1) {
						       printf("��Ҫɾ����һ�ţ�����һ����¼�ǵ�0����\n");
							       scanf("%d",&mm);
							       if (ListDelete(head,mm)==NULL) printf("�޴˼�¼��\n");
					       }
					       else {
						       printf("��Ҫɾ��ѧ��Ϊ���ٵļ�¼��\n");
							       getchar();
							       gets(cs);
							       if (NumDelete(head,cs)==NULL) printf("�޴˼�¼��\n");
					       }
				       break;
				case 5:printf("��Ҫ����ѧ��Ϊ���ٵļ�¼��\n");
				       getchar();
					       gets(cs);
					       q=Search(head,cs);
					       if (q==NULL) printf("�޴˼�¼��\n");else fprintStu(stdout,q);
						       break;
				case 6:printf("��ѡ��1��ͳ��ѧ������\n2��ͳ��ѧ����ƽ���ɼ�����߷�\n3��ͳ�Ʋ���������\n");
				       scanf("%d",&m);
					       switch (m){
						       case 1:printf("����Ϊ��%d\n",length(head));break;
						       case 2:printf("ƽ����Ϊ��%f ��߷�Ϊ%f\n",avscore(head),maxscore(head));break;
						       case 3:printf("����������Ϊ��%d\n",npnum(head,60));break;
						       default:break;
					       }
				       break;
				case 7:head=destroy(head);break;
				case 8:printf("��ѡ��1����дѧ���ļ�\n2��׷��ѧ���ļ�\n3�����ѧ���ļ�\n");
				       scanf("%d",&m);
					       if (filew[0]=='\0') {
						       printf("��⵽����δ�趨�ļ�·�����������ã�");
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
