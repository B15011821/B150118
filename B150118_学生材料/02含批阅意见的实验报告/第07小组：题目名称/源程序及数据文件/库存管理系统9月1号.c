#ifndef _GOODS
#define _GOODs
#include<stdio.h>
#include<string.h>
#define NUM 30
struct Goods
{
	long num;
	char name[20];
    int  price;
	int  changes[2];
	int  stock;
	int  rank;
};
typedef struct Goods Goods;
#define sizestu sizeof(Goods)
#endif
int readGood(Goods *good,int n)     
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("��������Ʒ����Ϣ\n");
		printf("���:  ");
	     scanf("%ld", &good[i].num);
		if (good[i].num==0) break;
		printf("����: ");
		scanf("%s",good[i].name);	
		printf("�۸�:  ");
		scanf("%d",good[i].price);
    	     good[i].stock=0;              
		printf("��������Ʒ�ĳ������������:\n");
		for (j=0;j<2;j++)
	    {
		    scanf("%d",&good[i].changes[j]);	
		}
		good[i].rank=0;                
	}
	return i;                       
}
int equal(Goods g1,Goods g2,int condition)  
{
	if (condition==1)                    
		return g1.num==g2.num;
	else if (condition==2)                
     {
	     if (strcmp(g1.name,g2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                
	     return g1.rank==g2.rank;
 else if (condition==4)               
		return g1.stock==g2.stock;
	else return 1;                       
} 

int larger(Goods g1,Goods g2,int condition)  
{
	if (condition==1)                    
		return g1.num>g2.num;
	if (condition==2)                    
		return g1.stock>g2.stock;	
	else return 1; 
}


void sortGood(Goods good[],int n,int condition)  
{
	int i,j,minpos;                      
	Goods t;
	for (i=0;i<n-1;i++)                  
	{
		minpos=i;
		for (j=i+1;j<n;j++)             
			if (larger(good[minpos],good[j],condition))
				minpos=j;
		if (i!=minpos)                 
		{
			t=good[i];
			good[i]=good[minpos];
			good[minpos]=t;
		}
	}
}
int searchGood(Goods good[],int n,Goods g,int condition,int f[ ])  
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 
		if (equal(good[i],g,condition))  
		{
			f[j++]=i;                          
			find++;	                                                      
		}
	 return find;                                 
}

int insertGood(Goods good[],int n,Goods g)              
{
	int i;
	sortGood(good,n,1);                              
	for (i=0;i<n;i++)
	{
		if (equal(good[i],g,1))                      
		{
		    printf("�����¼�Ѵ��ڣ������ٴβ���!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          
	{
		if (!larger(good[i],g,1))                    
		break;
		good[i+1]=good[i];                        
	}
	good[i+1]=g;                                                                   
	n++;                                     
	return n;                                  
}

int deleteGood(Goods good[],int n,Goods g)            
{
	int i,j;
	for (i=0;i<n;i++)                           
		if (equal(good[i],g,1))   break;            
	if (i==n)                                 
	{
		printf("�����¼������!\n");    
		return n;
	}
	for (j=i; j<n-1; j++)                         
		good[j]=good[j+1];                       
                                                                            
	n--;                                      
	return n;                                  
}
void menu( )        
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ��Ʒ��Ϣ���� ********\n");
		printf("******** 3. ��Ʒ������ ********\n");
		printf("******** 4. ��Ʒ���ͳ�� ********\n");
        printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     
{
		printf("%%%%%%%% 1. ������Ʒ��Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ����Ʒ��Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸���Ʒ��Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuScore( )    
{
		printf("@@@@@@@@ 1. ������Ʒ��� @@@@@@@@\n");
		printf("@@@@@@@@ 2. ���ݼ۸����� @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}
 
void menuCount( )   
{		printf("&&&&&&&& 1. �������������Ʒ &&&&&&&&\n");
		printf("&&&&&&&& 2. �������������Ʒ &&&&&&&&\n");
		printf("&&&&&&&& 3. �����۶�������Ʒ &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵�       &&&&&&&&\n");
}

void menuSearch()    
{
		printf("######## 1. ����Ʒ��Ų�ѯ   ########\n");
		printf("######## 2. ����Ʒ���Ʋ�ѯ   ########\n");
		printf("######## 3. ���۸�������ѯ   ########\n");
		printf("######## 0. �����ϲ�˵�     ########\n");
}

int baseManage(Goods good[],int n)    	     

{  
		int choice,t,find[NUM];
		Goods g;
     
do
	    {   
         menuBase( );                  
         printf("ѡ����Ҫʹ�õ�ѡ��: ");
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
return 0;                             
}
void scoreManage()          
{  
	int choice;
	do
	{
		menuScore( );                        
		printf("ѡ����Ҫʹ�õ�ѡ��:\n");
		scanf("%d",&choice);	                 
		switch(choice)
		{
			case 1:   break;
			case 2:   break;		
			case 0:   break;
		}
	}while(choice);
}
void countManage()               
{
		int choice;
		do
		{
			menuCount( );                        
			printf("ѡ����Ҫʹ�õ�ѡ��:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:  break;
				case 2:  break;
				case 3:  break;
				case 0:  break;
			}
		}while (choice);
}
void searchManage()               
{
    int choice;
do
{
			menuSearch( );                         
			printf("ѡ����Ҫʹ�õ�ѡ��:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("���������ѯ��Ʒ���:\n");
				          break;
				case 2:   printf("���������ѯ��Ʒ����:\n");
				      	  break;   
				case 3:   printf("���������ѯ��Ʒ�۸�����:\n");
				          break;
				case 0:   break;
			}
		 
	    }while (choice);
}
int main()    
{
	int choice;
	int n;
	Goods *good;
	menu();
    printf("��ѡ����Ҫʹ�õ�ѡ��: ");
	scanf("%d",&choice);
		switch(choice)
		{
			case 1:  break;
			case 2:  n=baseManage(good,n);    
			   	     break;
			case 3:  scoreManage();     
					 break;
			case 4: countManage();     
					break;
			case 5: searchManage();     
				     break;
          case 0: break;
		}
		return 0;
}