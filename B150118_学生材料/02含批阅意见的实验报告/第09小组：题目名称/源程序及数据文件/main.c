#include <stdio.h>
#include <stdlib.h>
#include"zhubo.h"
#include"duqu.h"
int main()
{
welcome();
return 0;
}


void welcome() /*��ӭ������*/
{
system("CLS");
printf("\n\n\n\n\n\n\t\t\t���������������������\n");
printf("\t\t\t�� ��                              �� ��\n");
printf("\t\t\t�� ��                              �� ��\n");
printf("\t\t\t�� �� ��ӭʹ��ֱ��ƽ̨��������ϵͳ �� ��\n");
printf("\t\t\t�� ��                              �� ��\n");
printf("\t\t\t�� ��                              �� ��\n");
printf("\t\t\t���������������������\n");
printf("\n\t\t\t�����������...");
getch();
login();
}
void login() /*��¼����*/
{
int select;
system("CLS");
system("CLS");
printf("\n\n\n\n\n\t\t\t��������������������\n");
printf("\t\t\t�� ��          �� ��\n");
printf("\t\t\t�� ��1.ע���û��� ��\n");
printf("\t\t\t��----------------��\n");
printf("\t\t\t�� ��2.��¼ϵͳ�� ��\n");
printf("\t\t\t��----------------��\n");
printf("\t\t\t�� ��3.�˳�ϵͳ�� ��\n");
printf("\t\t\t�� ��          �� ��\n");
printf("\t\t\t��������������������\n");
label:
printf("\n\t\t\t��ѡ��1-3��:");
scanf("%d",&select);
switch(select)
{
case 1:
regist();
break;
case 2:
loginsystem();
break;
case 3:
exitsystem();
break;
default:
{
printf("\t\t\t�޴��������ѡ��\n");
goto label;
}
}
}
void regist()
{
char cleck[30],ctemp;
int count=0;
while(1)
{
printf("\t\t\t����Ա����:");
int i=0;
while((ctemp=getch())!='\r')
{

cleck[i++]=ctemp;
putchar('*');
}
cleck[i]='\0';
if(strcmp(cleck,"123456")==0)
{
printf("\n\t\t\t������ȷ\n");
break;
}
else
{
printf("\n\t\t\t�������\n");
exit(0);
}
}
printf("ע���û�\n");
printf("ע��ɹ�!\n");
printf("�����ⷵ�ص�¼����...");
getch();
login();
system("CLS");
}
void loginsystem()
{
printf("��¼ϵͳ\n");
}
void exitsystem()
{
printf("��ȫ�˳�ϵͳ\n");
}


int baseManage(zhubo zhu[],int n)
{
		int choice,t,find[NUM];
     zhubo z;
do
	    {
menuBase( );
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);
		     {
			   case 1:	 readzhu(&z,1);
					 n=insertzhu(zhu,n,z);
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&z.num);
					 n=deletezhu(zhu,n,z);
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&z.num);
				      t=searchStu(zhu,n,z,1,find) ;
				      if (t)
					 {
						  readzhu(&z,1);
					      zhu[find[0]]=z;
					  }
					 else
 printf("this zhubo is not in,can not be modified.\n");
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;
}
