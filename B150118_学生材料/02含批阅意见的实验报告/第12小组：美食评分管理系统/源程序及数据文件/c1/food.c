/*��food.c�ļ�����������*/
#include "food.h"
#include <stdio.h>

int readFoo(Food  *foo , int n)          /*�����Ʒ��¼ֵ�����Ϊ0������涨������¼ʱֹͣ*/
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one food\'s information\n");
		printf("num:  ");
	     scanf("%ld", &foo[i].num);
		if (foo[i].num==0) break;
		printf("name: ");
		scanf("%s",foo[i].name);	
		printf("style:  ");
		scanf("%s",foo[i].style);
		printf("taste:  ");
		scanf("%s",foo[i].taste);
    	foo[i].total=0;                /*�ܷ���Ҫ������ã���ֵ��Ϊ0*/
		printf("Input three mark of the food:\n");
		for (j=0;j<3;j++)
	    {
		    scanf("%lf",&foo[i].score[j]);	
		}
		foo[i].rank=0;                 /*������Ҫ�����ܷ������㣬��ֵ��Ϊ0*/
	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printFoo ( Food   *foo , int n)       /*������в�Ʒ��¼��ֵ*/
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%6ld  ", foo[i].num);
		printf("%8s", foo[i].name);
		printf("%8s", foo[i].style);
		printf("%4s",foo[i].taste);
		for (j=0;j<3;j++)
		   printf("       %3.1f",foo[i].score[j]);
		printf("   ");
	    printf("  %3.1f",foo[i].total);
	    printf("%7d\n",foo[i].rank);
	}
}

int equal(Food s1,Food s2,int condition)  /*����ж�������Ʒ��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ����*/
		return s1.num==s2.num;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚϲ���*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*�������condition��ֵΪ3����Ƚ�����*/
	     return s1.rank==s2.rank;
 else if (condition==4)                /*�������condition��ֵΪ4����Ƚ��ܷ�*/
		return s1.total==s2.total;
 else if(condition==5)                 /*�������condition��ֵΪ5����ȽϿ�ζ*/
	    {
	     if (strcmp(s1.taste,s2.taste)==0) 	return 1;
		else return 0;
     }
	else return 1;                       /*�����������1*/
}

int larger(Food s1,Food s2,int condition)  /*����condition�����Ƚ�������Ʒ��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ����*/
		return s1.num>s2.num;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚ��ܷ�*/
		return s1.total>s2.total;	
	else return 1; /*�����������1*/
}

void reverse(Food foo[],int n)             /*����Ԫ������*/
{
	int i;
	Food temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=foo[i];
		foo[i]=foo[n-1-i];
		foo[n-1-i]=temp;
	}
}

void calcuTotal(Food foo[],int n)         /*�������в�Ʒ���ܷ�*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*���ѭ���������в�Ʒ��¼*/
	{
		foo[i].total =0;
		for (j=0;j<3;j++)               /*�ڲ�ѭ����������������Ŀ*/
			foo[i].total +=foo[i].score[j];
	}	
}

void calcuRank(Food foo[],int n)          /*�����ּܷ������в�Ʒ���������ܷ���ͬ��������ͬ*/
{
	int i ;                       
	sortFoo(foo,n,2);                     /*�ȵ���sortFoo�㷨�����ܷ���С��������*/
	reverse(foo,n);                      /*�����ã����ܷ��ɴ�С������*/
	foo[0].rank=1;                      /*��һ����¼������һ����1*/
	for (i=1;i<n;i++)                     /*�ӵڶ�����¼һֱ�����һ������ѭ��*/
	{
		if (equal(foo[i],foo[i-1],4))         /*��ǰ��¼�������ڵ�ǰһ����¼����ܷ����*/
			foo[i].rank=foo[i-1].rank;     /*��ǰ��¼���ε��������ڵ�ǰһ����¼����*/ 
	    else
			foo[i].rank=i+1;             /*�����ʱ��ǰ��¼���ε������±��+1*/
	}
}

void calcuMark(double m[3][3],Food foo[],int n) /*������������Ŀ����ߡ���͡�ƽ����*/
/*������ʽ������ά����m�ĵ�һά��������������Ŀ���ڶ�ά������ߡ���͡�ƽ����*/
{
	int i,j;
	for (i=0;i<3;i++)                 /*������������Ŀ����߷�*/		
	{ 
		m[i][0]=foo[0].score[i];     
		for (j=1;j<n;j++)
			if (m[i][0]<foo[j].score[i])
				m[i][0]=foo[j].score[i];
	}
	for (i=0;i<3;i++)                  /*������������Ŀ����ͷ�*/
	{ 
		m[i][1]=foo[0].score[i];      
		for (j=1;j<n;j++)
			if (m[i][1]>foo[j].score[i])
				m[i][1]=foo[j].score[i];
	}
	for (i=0;i<3;i++)                 /*������������Ŀ��ƽ����*/
	{ 
		m[i][2]=foo[0].score[i];     
		for (j=1;j<n;j++)
			m[i][2]+=foo[j].score[i];
		m[i][2]/=n;
	}
}

void sortFoo(Food foo[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	Food t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(foo[minpos],foo[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=foo[i];
			foo[i]=foo[minpos];
			foo[minpos]=t;
		}
	}
}

int searchFoo(Food foo[],int n,Food s,int condition,int f[ ])  /*��foo��������condition��������*/
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(foo[i],s,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}


int insertFoo(Food foo[],int n,Food s)              /*��foo����������ŵ�������һ��Ԫ��s*/
{
	int i;
	sortFoo(foo,n,1);                              /*�Ȱ��������*/
	for (i=0;i<n;i++)
	{
		if (equal(foo[i],s,1))                      /*�����ͬ��������룬��֤��ŵ�Ψһ��*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*����Ŵ�С��������*/
	{
		if (!larger(foo[i],s,1))                    /*���s���ڵ�ǰԪ��foo[i]�����˳�ѭ��*/
		break;
		foo[i+1]=foo[i];                         /*����Ԫ��foo[i]����һ��λ��*/
	}
	foo[i+1]=s;                                /*���±�i+1������Ԫ��s*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deleteFoo(Food foo[],int n,Food f)            /*��������ɾ��ָ����ŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(foo[i],f,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(foo[i],s,1)����*/ 
		foo[j]=foo[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}