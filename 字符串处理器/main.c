#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

extern N;
char s[MAX][100000];
int p=0;

int main(){
    int n=0,m,i,t,j,pos,tn;
    char a[100000],b[100000];
    printf("��ӭʹ���ַ�����������\n");
    Config();
    do{
        printf("0. �˳�\n1. �����ַ���\n2. ��ʾ�ַ���\n3. �󴮳�\n4. ������\n5. ���Ƚ�\n6. ������\n7. ������\n8. ���Ӵ�\n9. ������\n10. ���û�\n");
        scanf("%d",&n);
        fflush(stdin);
        switch (n){
            case 1:printf("��Ҫ���뼸���ַ�����");
                   scanf("%d",&m);
                   fflush(stdin);
                   for (i=0;i<m;i++) gets(s[i+p]);
                   p+=m;
                   break;
            case 2:for (i=0;i<N;i++) printf("%3d: %s\n",i,s[i]);
                   getchar();
                   break;
            case 3:printf("��Ҫ��ڼ���Ԫ�صĳ��ȣ�");
                   scanf("%d",&m);
                   printf("%d\n",length(s[m]));
                   getchar();
                   getchar();
                   break;
            case 4:printf("��Ҫ�����������ַ��������������ڵ�һ���ַ����У�");
                   scanf("%d%d",&m,&t);
                   combine(s[m],s[t]);
                   break;
            case 5:printf("��Ҫ�Ƚ��������ַ�����");
                   scanf("%d%d",&m,&t);
                   if (strcomp(s[m],s[t])) printf("��ǰ�治ͬ��һλ��ASCII���ֵ��%d\n",strcomp(s[m],s[t])); else printf("��ȫ��ͬ��\n");
                   getchar();
                   getchar();
                   break;
            case 6:printf("��Ҫ����һλ���Ƶ���һλ�������棺�縴�Ƶ���λ�������ַ���ʱ�Ḳ�ǣ�");
                   scanf("%d%d",&m,&t);
                   strcp(s[t],s[m]);
                   break;
            case 7:printf("��Ҫ����һλ���뵽��һλ�ĵڼ���λ�ã������棺����뵽��λ�������ַ���ʱ�Ḳ�ǣ�");
                   scanf("%d%d%d",&m,&t,&pos);
                   Insert(s[t],pos-1,s[m]);
                   break;
            case 8:printf("��Ҫ��ڼ���Ԫ�ش��ĸ�λ�ÿ�ʼ�ĳ��ȶ��ٵ��Ӵ���");
                   scanf("%d%d%d",&m,&pos,&tn);
                   SubString(s[m],pos-1,tn,a);
                   puts(a);
                   getchar();
                   break;
            case 9:printf("��Ҫ���ҵڼ���Ԫ��?");
                   scanf("%d",&m);
                   getchar();
                   printf("�����ĸ��ַ�����\n");
                   gets(a);
                   if ((t=Search(s[m],a))!=-1) printf("���ִ����ȳ����ڵ�%d��λ��",t+1); else printf("�Ҳ������ִ���\n");
                   getchar();
                   break;
            case 10:printf("��Ҫ�滻�ڼ���Ԫ��?");
                   scanf("%d",&m);
                   getchar();
                   printf("�����ĸ��ַ�����\n");
                   gets(a);
                   printf("�滻Ϊ�ĸ��ַ�����\n");
                   gets(b);
                   Replace(s[m],a,b);
                   break;
        }
    }while (n);
    return 0;
}
