/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"medcine.h"

void printHead( )      /*��ӡҩƷ��Ϣ�ı�ͷ*/
{
printf("%4s%10s%6s%6s%10s%6s%10s%10s%8s%10s\n","����","ҩƷ����","����","���","�������","�۸�","���ʱ��","����ʱ��","������","����ʱ��");
}

void menu( )         /*����˵�����*/
{
		printf("******** 1. ҩƷ�����Ϣ ********\n");
		printf("******** 2. ҩƷ�������¼ ********\n");
		printf("******** 3. ҩƷ��������� ********\n");
		printf("******** 4. ������Ϣ ********\n");
        printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     /*2��ҩƷ�������¼�˵�����*/
{
		printf("%%%%%%%% 1. ҩƷ����¼ %%%%%%%%\n");
		printf("%%%%%%%% 2. ҩƷ�����¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuScore( )     /*3��ҩƷ���������˵�����*/
{
		printf("@@@@@@@@ 1. ҩƷ��� @@@@@@@@\n");
		printf("@@@@@@@@ 2. ҩƷ���� @@@@@@@@\n");
        printf("@@@@@@@@ 3. �޸Ŀ����Ϣ @@@@@@@@\n");
        printf("@@@@@@@@ 4. ɾ��ҩƷ @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}
 
void menuCount( )    /*4��������Ϣ�˵�����*/
{
		printf("&&&&&&&& 1. ҩƷ�ܼ� &&&&&&&&\n");
		printf("&&&&&&&& 2. ��������ҩƷ &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
}

void menuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. ��ҩƷ���Ʋ�ѯ   ########\n");
		printf("######## 2. ��ҩƷ���Ͳ�ѯ   ########\n");
		printf("######## 3. �����ʱ���ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}


int baseManage(Medcine med[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*��ѧ�Ž��в���ɾ���޸ģ�ѧ�Ų����ظ�*/
{  
		int choice,t,find[COD];
     Medcine s;
do
	    {   
menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readMed(&s,1);       /*����һ���������ѧ����¼*/
					 n=insertMed(med,n,s);   /*���ú�������ѧ����¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.cod);  /*����һ����ɾ����ѧ��ѧ��*/
					 n=deleteMed(med,n,s);   /*���ú���ɾ��ָ��ѧ�ŵ�ѧ����¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.cod);  /*����һ�����޸ĵ�ѧ��ѧ��*/
				      t=searchMed(med,n,s,1,find) ; /*���ú�������ָ��ѧ�ŵ�ѧ����¼*/
				      if (t)                 /*�����ѧ�ŵļ�¼����*/
					 {
						  readMed(&s,1);   /*����һ��������ѧ����¼��Ϣ*/
					      med[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*�����ѧ�ŵļ�¼������*/ 
 printf("this medcine is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

void scoreManage(Medcine med[],int n)          /*�ú������ѧ���ɼ�������*/
{  
	int choice;
	do
	{
		menuScore( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*�������ѡ��*/
		switch(choice)
		{
			case 1:   calcuNum(med,n);         /*������ѧ�����ܷ�*/
					  break;
			case 2:   calcuIntime(med,n);         /*��������ѧ�����ܷ�������*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}

void printMarkCourse(char *s,double m[3][3],int k)   /*��ӡ����ͨ�ú�������countManage ����*/
{                 /*��ʽ����k���������ͬ�����ݣ�0��1��2�ֱ��Ӧ��߷֡���ͷ֡�ƽ����*/
int i;
    printf(s);                                  /*�����s������������������ʾ��Ϣ*/
    for (i=0;i<3;i++)                           /*i������һ�ſ�*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}

void countManage(Medcine med[],int n)               /*�ú�����ɿ��Գɼ�ͳ�ƹ���*/
{
		int choice;
		double mark[3][3];
		do
		{
			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/
			calcuMark(mark,med,n);                 /*���ô˺��������ſε���ߡ���͡�ƽ��ֵ*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("���ſε���߷ֱַ���:\n",mark,0);  /*�����߷�*/
				      break;
				case 2:   printMarkCourse("���ſε���ͷֱַ���:\n",mark,1);  /*�����ͷ�*/
				      break;
				case 3:   printMarkCourse("���ſε�ƽ���ֱַ���:\n",mark,2);  /*���ƽ����*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Medcine med[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findcod,f[COD];
Medcine s;
	   do
{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a student\'s num will be searched:\n");
				      scanf("%ld",&s.cod);         /*�������ѯѧ����ѧ��*/
					  break;
				case 2:   printf("Input a student\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*�������ѯѧ��������*/		  
				      break;   
				case 3:   printf("Input a rank will be searched:\n");
				      scanf("%d",&s.intime);          /*�������ѯѧ��������*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findcod=searchMed(med,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findcod)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findcod;i++)         /*ѭ������f������±�*/
	      	 printMed(&med[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

int runMain(Medcine med[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				 sortMed(med,n,1);         /*��ѧ����С�����˳�������¼*/ 
          	 printMed(med,n);          /*��ѧ����С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(med,n);    /* 2. ������Ϣ����*/
			   	     break;
			case 3: scoreManage(med,n);     /* 3. ѧ���ɼ�����*/
					break;
			case 4: countManage(med,n);     /* 4. ���Գɼ�ͳ��*/
					break;
			case 5: searchManage(med,n);     /* 5. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Medcine med[COD];                /*����ʵ��һά����洢ѧ����¼*/
      int choice,n;
	 n=readFile(med);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(med);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(med,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortMed(med,n,1);                   /*�����ļ�ǰ��ѧ����С��������*/ 
	     saveFile(med,n);                   /*����������ļ�*/
      return 0;
}













/*��medcine.c�ļ�����������*/
#include "medcine.h"
#include <stdio.h>

int readMed(Medcine  *med , int n)          /*����ѧ����¼ֵ��ѧ��Ϊ0������涨������¼ʱֹͣ*/
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("����ҩƷ��Ϣ\n");
		printf("ҩƷ����:  ");
	     scanf("%ld", &med[i].cod);
		if (med[i].cod==0) break;
		printf("ҩƷ����: ");
		scanf("%s",&med[i].name);	
		printf("ҩƷ����:  ");
		scanf("%s",&med[i].type);
		printf("���:\n");
		scanf("%s",&med[i].spec);
		printf("����: ");
		scanf("%ld",&med[i].num);	
		printf("�۸�: ");
		scanf("%lf",&med[i].price);	
		printf("���ʱ��:  ");
		scanf("%ld",&med[i].intime);
		printf("����ʱ��: ");
		scanf("%ld",&med[i].outtime);	
		printf("������:  ");
		scanf("%s",&med[i].term);
		printf("�����ڵ���ʱ��:  ");
		scanf("%ld",&med[i].outterm);
	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printMed ( Medcine  *med , int n)       /*�������ѧ����¼��ֵ*/
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%2ld", med[i].cod);
		printf("%10s", med[i].name);
		printf("%8s", med[i].type);
		printf("%12s",med[i].spec);
	    printf("%4ld",med[i].num);
	    printf("%10f",med[i].price);
		printf("%10ld",med[i].intime);
	    printf("%4ld",med[i].outtime);
	    printf("%6s",med[i].term);
	    printf("%10ld\n",med[i].outterm);
	}
}

int equal(Medcine s1,Medcine s2,int condition)  /*����ж�����Student��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ�ѧ��*/
		return s1.cod==s2.cod;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*�������condition��ֵΪ3����Ƚ�����*/
	     return s1.intime==s2.intime;
 else if (condition==4)                /*�������condition��ֵΪ4����Ƚ��ܷ�*/
		return s1.num==s2.num;
	else return 1;                       /*�����������1*/
} 

int larger(Medcine s1,Medcine s2,int condition)  /*����condition�����Ƚ�����Student��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ�ѧ��*/
		return s1.cod>s2.cod;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚ��ܷ�*/
		return s1.num>s2.num;	
	else return 1; /*�����������1*/
}

void reverse(Medcine med[],int n)             /*����Ԫ������*/
{
	int i;
	Medcine temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=med[i];
		med[i]=med[n-1-i];
		med[n-1-i]=temp;
	}
}

void calcuNum(Medcine med[],int n)         /*��������ѧ�����ܷ�*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*���ѭ����������ѧ����¼*/
	{
		med[i].cod =0;
		for (j=0;j<3;j++)               /*�ڲ�ѭ���������Ź���*/
			med[i].cod +=med[i].spec[j];
	}	
}

void calcuIntime(Medcine med[],int n)          /*�����ּܷ�������ѧ�����������ɼ���ͬ��������ͬ*/
{
	int i ;                       
	sortMed(med,n,2);                     /*�ȵ���sortStu�㷨�����ܷ���С��������*/
	reverse(med,n);                      /*�����ã����ܷ��ɴ�С������*/
	med[0].intime=1;                      /*��һ����¼������һ����1*/
	for (i=1;i<n;i++)                     /*�ӵڶ�����¼һֱ�����һ������ѭ��*/
	{
		if (equal(med[i],med[i-1],4))         /*��ǰ��¼�������ڵ�ǰһ����¼����ܷ����*/
			med[i].intime=med[i-1].intime;     /*��ǰ��¼���ε��������ڵ�ǰһ����¼����*/ 
	    else
			med[i].intime=i+1;             /*�����ʱ��ǰ��¼���ε������±��+1*/
	}
}

void calcuMark(double m[3][3],Medcine med[],int n) /*�����ſε���ߡ���͡�ƽ����*/
/*������ʽ������ά����m�ĵ�һά�������ſΣ��ڶ�ά������ߡ���͡�ƽ����*/
{
	int i,j;
	for (i=0;i<3;i++)                 /*�����ſε���߷�*/		
	{ 
		m[i][0]=med[0].spec[i];     
		for (j=1;j<n;j++)
			if (m[i][0]<med[j].spec[i])
				m[i][0]=med[j].spec[i];
	}
	for (i=0;i<3;i++)                  /*�����ſε���ͷ�*/
	{ 
		m[i][1]=med[0].spec[i];      
		for (j=1;j<n;j++)
			if (m[i][1]>med[j].spec[i])
				m[i][1]=med[j].spec[i];
	}
	for (i=0;i<3;i++)                 /*�����ſε�ƽ����*/
	{ 
		m[i][2]=med[0].spec[i];     
		for (j=1;j<n;j++)
			m[i][2]+=med[j].spec[i];
		m[i][2]/=n;
	}
}

void sortMed(Medcine med[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	Medcine t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(med[minpos],med[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=med[i];
			med[i]=med[minpos];
			med[minpos]=t;
		}
	}
}

int searchMed(Medcine med[],int n,Medcine s,int condition,int f[ ])  /*��stu��������condition��������*/
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(med[i],s,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}

int insertMed(Medcine med[],int n,Medcine s)              /*��stu��������ѧ�ŵ�������һ��Ԫ��s*/
{
	int i;
	sortMed(med,n,1);                              /*�Ȱ�ѧ������*/
	for (i=0;i<n;i++)
	{
		if (equal(med[i],s,1))                      /*ѧ����ͬ��������룬��֤ѧ�ŵ�Ψһ��*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*��ѧ�Ŵ�С��������*/
	{
		if (!larger(med[i],s,1))                    /*���s���ڵ�ǰԪ��stu[i]�����˳�ѭ��*/
		break;
		med[i+1]=med[i];                         /*����Ԫ��stu[i]����һ��λ��*/
	}
	med[i+1]=s;                                /*���±�i+1������Ԫ��s*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deleteMed(Medcine med[],int n,Medcine s)            /*��������ɾ��ָ��ѧ�ŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(med[i],s,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(stu[i],s,1)����*/ 
		med[j]=med[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}






