#include <stdio.h>
#include <stdlib.h>
#include"zhibo.h"

FILE *fp;

void printHead( )
{
printf("%8s%8s%8d%10s%8d%8d%6s\n","����","�Ա�","�����","ֱ��ʱ��","������","��ʱ��","��Ϸ");
}

void menu( )
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ������Ϣ���� ********\n");
		printf("******** 3. ������Ϣ���� ********\n");
		printf("******** 4. ���Գɼ�ͳ�� ********\n");
     printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )
{
		printf("%%%%%%%% 2. ɾ��������¼ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸�������¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuScore( )
{
		printf("@@@@@@@@ 1. ����ֱ��ʱ�� @@@@@@@@\n");
		printf("@@@@@@@@ 2. ����ʱ������ @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}

void menuCount( )
{
    	printf("&&&&&&&& 1. ��ֱ��� &&&&&&&&\n");
		printf("&&&&&&&& 2. ��������� &&&&&&&&\n");
		printf("&&&&&&&& 3. ��ֱ��ƽ�� &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
}

void menuSearch()
{
		printf("######## 1. ��������ѯ   ########\n");
		printf("######## 2. �������ѯ   ########\n");
		printf("######## 3. ����Ϸ��ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
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
		    switch(choice)
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

void scoreManage(zhubo zhu[],int n)
{

    int choice;
	do
	{
		menuScore( );
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:   calcuTotal(zhu,n);
					  break;
			case 2:   calcuRank(zhu,n);
				      break;
			case 0:   break;
		}
	}while(choice);
}



void countManage(zhubo zhu[],int n)               /*�ú�����ɿ��Գɼ�ͳ�ƹ���*/
{
		int choice;
		int max,pj,most;
		do
		{
			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/

			int calcumost(most, zhu , n) ;                 /*���ô˺�����������ʱ�����ߡ�������ߡ�ֱ��ƽ��ֵ*/
			int calcupj(pj, zhu  , n);  /*��ֱ��ƽ��ʱ��*/
			int calcumax(max,  zhu , n) ; /*��ֱ��ʱ���*/
			printf("choose one operation you want to do:\n");

			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("ֱ��ʱ�������:\n",max,0);  /*���ֱ��ʱ���*/
				      break;
				case 2:   printMarkCourse("ֱ��������ߵ���:\n",most,1);  /*����������*/
				      break;
				case 3:   printMarkCourse("ֱ����ƽ��ʱ����:\n",pj,2);  /*���ƽ��ʱ��*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(zhubo zhu[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
    zhubo z;
	   do
{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a zhubo\'s num will be searched:\n");
				      scanf("%ld",&z.num);         /*�������ѯ�����ķ����*/
					  break;
				case 2:   printf("Input a zhubo\'s name will be searched:\n");
				      scanf("%s",z.name);	          /*�������ѯ����������*/
				      break;
				case 3:   printf("Input a game will be searched:\n");
				      scanf("%d",&z.game);          /*�������������Ϸ*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{
				findnum=searchzhu(zhu,n,z,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printzhu(&zhu[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }
	    }while (choice);
}

int runMain(zhubo zhu[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				 sortzhu(zhu,n,1);         /*��ѧ����С�����˳�������¼*/
          	 printzhu(zhu,n);          /*��ѧ����С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(zhu,n);    /* 2. ������Ϣ����*/
			   	     break;
			case 3: scoreManage(zhu,n);     /* 3. ������Ϣ����*/
					break;
			case 4: countManage(zhu,n);     /* 4. ֱ����Ϣͳ��*/
					break;
			case 5: searchManage(zhu,n);     /* 5. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		zhubo zhu[NUM];                /*����ʵ��һά����洢������¼*/
      int choice,n;
	 n=readFile(zhu);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(zhu);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(zhu,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortzhu(zhu,n,1);                   /*�����ļ�ǰ��ѧ����С��������*/
	     saveFile(zhu,n);                   /*����������ļ�*/
      return 0;
}
