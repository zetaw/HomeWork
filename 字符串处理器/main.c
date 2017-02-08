#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

extern N;
char s[MAX][100000];
int p=0;

int main(){
    int n=0,m,i,t,j,pos,tn;
    char a[100000],b[100000];
    printf("欢迎使用字符串运算器！\n");
    Config();
    do{
        printf("0. 退出\n1. 输入字符串\n2. 显示字符串\n3. 求串长\n4. 串连接\n5. 串比较\n6. 串复制\n7. 串插入\n8. 求子串\n9. 串查找\n10. 串置换\n");
        scanf("%d",&n);
        fflush(stdin);
        switch (n){
            case 1:printf("您要输入几个字符串？");
                   scanf("%d",&m);
                   fflush(stdin);
                   for (i=0;i<m;i++) gets(s[i+p]);
                   p+=m;
                   break;
            case 2:for (i=0;i<N;i++) printf("%3d: %s\n",i,s[i]);
                   getchar();
                   break;
            case 3:printf("您要求第几号元素的长度？");
                   scanf("%d",&m);
                   printf("%d\n",length(s[m]));
                   getchar();
                   getchar();
                   break;
            case 4:printf("您要链接哪两个字符串？（结果会放在第一个字符串中）");
                   scanf("%d%d",&m,&t);
                   combine(s[m],s[t]);
                   break;
            case 5:printf("您要比较哪两个字符串？");
                   scanf("%d%d",&m,&t);
                   if (strcomp(s[m],s[t])) printf("最前面不同的一位的ASCII码差值是%d\n",strcomp(s[m],s[t])); else printf("完全相同！\n");
                   getchar();
                   getchar();
                   break;
            case 6:printf("您要把哪一位复制到哪一位？（警告：如复制到空位，输入字符串时会覆盖）");
                   scanf("%d%d",&m,&t);
                   strcp(s[t],s[m]);
                   break;
            case 7:printf("您要把哪一位插入到哪一位的第几号位置？（警告：如插入到空位，输入字符串时会覆盖）");
                   scanf("%d%d%d",&m,&t,&pos);
                   Insert(s[t],pos-1,s[m]);
                   break;
            case 8:printf("您要求第几号元素从哪个位置开始的长度多少的子串？");
                   scanf("%d%d%d",&m,&pos,&tn);
                   SubString(s[m],pos-1,tn,a);
                   puts(a);
                   getchar();
                   break;
            case 9:printf("您要查找第几号元素?");
                   scanf("%d",&m);
                   getchar();
                   printf("查找哪个字符串？\n");
                   gets(a);
                   if ((t=Search(s[m],a))!=-1) printf("此字串最先出现在第%d号位置",t+1); else printf("找不到此字串！\n");
                   getchar();
                   break;
            case 10:printf("您要替换第几号元素?");
                   scanf("%d",&m);
                   getchar();
                   printf("查找哪个字符串？\n");
                   gets(a);
                   printf("替换为哪个字符串？\n");
                   gets(b);
                   Replace(s[m],a,b);
                   break;
        }
    }while (n);
    return 0;
}
