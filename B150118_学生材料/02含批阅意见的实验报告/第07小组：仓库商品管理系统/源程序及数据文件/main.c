#include <stdio.h>
#include <stdlib.h>


#include"file.h" 
#include"goods.h"
void printHead()     /*��ӡ��Ʒ��Ϣ�ı�ͷ*/
{
	printf("%8s%10s%8s%10s%10s%6s%6s\n","���","����","Ʒ��","�����","������","���","����");
}
void menu( )     /*һ���˵�����*/   
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ��Ʒ��Ϣ���� ********\n");
		printf("******** 3. ��Ʒ������ ********\n");
		printf("******** 4. ��Ʒ���ͳ�� ********\n");
        printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     /*������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ������Ʒ��Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ����Ʒ��Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸���Ʒ��Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuScore( )    /*��Ʒ������˵�����*/ 
{
		printf("@@@@@@@@ 1. ������Ʒ��� @@@@@@@@\n");
		printf("@@@@@@@@ 2. ���ݿ������ @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}
 
void menuCount( )   /*��Ʒ���ͳ�Ʋ˵�����*/
{		printf("&&&&&&&& 1. ����������������������Ʒ &&&&&&&&\n");
		printf("&&&&&&&& 2. ���������С���������С����Ʒ &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵�       &&&&&&&&\n");
}

void menuSearch()    /*����������ѯ�˵�����*/
{
		printf("######## 1. ����Ʒ��Ų�ѯ   ########\n");
		printf("######## 2. ����Ʒ���Ʋ�ѯ   ########\n");
		printf("######## 3. �����������ѯ   ########\n");
		printf("######## 0. �����ϲ�˵�     ########\n");
}

int baseManage(Goods good[],int n)    	     

{  
		int choice,t,find[NUM];
		Goods g;
     
do
	    {   
         menuBase( );                  
         printf("ѡ����Ҫʹ�õ�ѡ��:\n ");
		 scanf("%d",&choice);	          
		 switch(choice)
		     {
			   case 1: readGood(&g,1);
				       n=insertGood(good,n,g);
				       break;
			   case 2:  printf("��������Ʒ���\n");
				   scanf("%ld",&g.num);
				   n=deleteGood(good,n,g);
					    break;
			   case 3:  printf("��������Ʒ���\n");
				   scanf("%ld",&g.num);
				   t=searchGood(good,n,g,1,find);
if (t)                 
					 {
						  readGood(&g,1);  
					      good[find[0]]=g;     					 
					  }					 
					 else                 
 printf("�����Ʒ�����ڲ��ܱ��޸�.\n"); 
					    break;
			   case 0: break;
		    }
		}
		while(choice);
return n;                             
}
void scoreManage(Goods good[],int n)          
{  
	int choice;
	do
	{
		menuScore( );                        
		printf("ѡ����Ҫʹ�õ�ѡ��:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:   calcuStock(good,n);
				      break;
			case 2:   calcuRank(good,n); 
				      break;		
			case 0:   break;
		}
	}while(choice);
}
void printMarkCourse(char *s,double m[2][2],int k)   
{                 
int i;
    printf(s);                                  
    for (i=0;i<2;i++)                           
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}
void countManage(Goods good[],int n)               
{
		int choice;
		double mark[2][2];
		do
		{
			menuCount( );  
			calcuMark(mark,good,n);
			printf("ѡ����Ҫʹ�õ�ѡ��:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:  printMarkCourse("������ͳ��������ķֱ���:\n",mark,0);
					break;
				case 2:  printMarkCourse("������ͳ�������С�ֱ���:\n",mark,1);
					break;
				case 0:  break;
			}
		}while (choice);
}
void searchManage(Goods good[],int n)               
{
    int i,choice,findnum,f[NUM];
	Goods g;
do
{
			menuSearch( );                         
			printf("ѡ����Ҫʹ�õ�ѡ��:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("���������ѯ��Ʒ���:\n");
					scanf("%ld",&g.num);
				          break;
				case 2:   printf("���������ѯ��Ʒ����:\n");
					scanf("%s",&g.name);
				      	  break;   
				case 3:   printf("���������ѯ��Ʒ����:\n");
					scanf("%d",&g.rank);
				          break;
				case 0:   break;
			}
		 
	    
if(choice>=1&&choice<=3)
{
	findnum=searchGood(good,n,g,choice,f);
	if(findnum)
	{
		printHead();
		for(i=0;i<findnum;i++)
			printGood(&good[f[i]],1);
	}
	else
		printf("�����Ʒ������!\n");}
}
while(choice);
}
int runMain(Goods good[],int n,int choice)    
{
		switch(choice)
		{
			case 1: printHead();
				sortGood(good,n,1);
				printGood(good,n);
				break;
			case 2:  n=baseManage(good,n);    
			   	     break;
			case 3:  scoreManage(good,n);     
					 break;
			case 4: countManage(good,n);     
					break;
			case 5: searchManage(good,n);     
				     break;
          case 0: break;
		}
		return n;
}
int main( )
{
		Goods good[NUM];                
      int choice,n;
	 n=readFile(good);                  
	 if (!n)                          
	     {
		    n=createFile(good);              
}	 	 
	do
	     {
	         menu();                      
	         printf("��ѡ����Ҫʹ�õ�ѡ��: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(good,n,choice);    
	         else 
		          printf("ѡ���������������!\n");
	} while (choice);
	sortGood(good,n,1);                   
	     saveFile(good,n);                   
      return 0;
}


