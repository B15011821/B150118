#include"zhibo.h"
#include<stdio.h>
#include <stdlib.h>

FILE *fp;
int readzhu(zhubo *zhu , int n)
{
   int i;
   for(i=0;i<n;i++)
   {
       printf("������������Ϣ\n");
       printf("����:  ");
         scanf("%s",&zhu[i].name);
       printf("�Ա�:  ");
         scanf("%s",&zhu[i].sex);
       printf("���뷿���");
         scanf("%d",&zhu[i].num);
       printf("����ۿ�����");
         scanf("%d",&zhu[i].people);
       printf("ÿ��ֱ����ʱ��");
         scanf("%d",&zhu[i].Time);
       pirntf("ֱ����Ϸ����");
         scanf("&c",&zhu[i].game);
       zhu[i].rank=0;
   }
   return i;
}

void printzhu( zhubo *zhu , int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%8s",zhu[i].name);
        printf("%8s",zhu[i].sex);
        printf("%8d",zhu[i].num);
        printf("%8d",zhu[i].people);
        printf("%8d",zhu[i].Time);
        printf("%8s",zhu[i].game);
        printf("%7d",zhu[i].time);
        printf("%7d",zhu[i].rank);
    }
}

int  calcuTotal(zhubo zhu[],int n)
{
    int i,sum;
    sum==0;
    for(i=0;i<n;i++)
        {
            sum+=zhu[i].Time;
        }
    return sum;
}

int deletezhu(zhubo zhu[],int n ,zhubo  z)
{
	int i,j;
	for (i=0;i<n;i++)
		if (equal(zhu[i],z,1))   break;
	if (i==n)
	{
		printf("This record does not exist!\n");
		return n;
	}
	for (j=i; j<n-1; j++)
		zhu[j]=zhu[j+1];

	n--;
	return n;
}

int searchzhu(zhubo zhu[],int n,zhubo z,int condition,int f[ ])

{
	int i,j=0,find=0;
	for (i=0;i<n;i++)
		if (equal(zhu[i],z,condition))
		{
			f[j++]=i;
			find++;
		}
	 return find;
}

int insertzhu(zhubo zhu[],int n,zhubo z)
{
	int i;
	sortzhu(zhu,n,1);
	for (i=0;i<n;i++)
	{
		if (equal(zhu[i],z,1))
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)
	{
		if (!larger(zhu[i],z,1))
		break;
		zhu[i+1]=zhu[i];
	}
	zhu[i+1]=z;
	n++;
	return n;
}

void sortzhu(zhubo zhu[],int n,int condition)
{
	int i,j,minpos;
	zhubo z;
	for (i=0;i<n-1;i++)
	{
		minpos=i;
		for (j=i+1;j<n;j++)
			if (larger(zhu[minpos],zhu[j],condition))
				minpos=j;
		if (i!=minpos)
		{
			z=zhu[i];
			zhu[i]=zhu[minpos];
			zhu[minpos]=z;
		}
	}
}

int equal(zhubo z1,zhubo z2,int condition)  /*����ж�����Student��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����ȽϷ����*/
		return z1.num==z2.num;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
     {
	     if (strcmp(z1.name,z2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*�������condition��ֵΪ3����Ƚ���Ϸ*/
	     return z1.game==z2.game;

	else return 1;                       /*�����������1*/
}

int larger(zhubo z1,zhubo z2,int condition)  /*����condition�����Ƚ�����Student��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����ȽϷ����*/
		return z1.num>z2.num;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚ���ʱ��*/
		return z1.Time>z2.Time;
	else return 1; /*�����������1*/
}

void reverse(zhubo zhu[],int n)             /*����Ԫ������*/
{
	int i;
	zhubo temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=zhu[i];
		zhu[i]=zhu[n-1-i];
		zhu[n-1-i]=temp;
	}
}

void calcuRank(zhubo zhu[],int n)          /*������ʱ���������ѧ����������ʱ����ͬ��������ͬ*/
{
	int i ;
	sortzhu(zhu,n,2);                     /*�ȵ���sortStu�㷨�����ܷ���С��������*/
	reverse(zhu,n);                      /*�����ã����ܷ��ɴ�С������*/
	zhu[0].rank=1;                      /*��һ����¼������һ����1*/
	for (i=1;i<n;i++)                     /*�ӵڶ�����¼һֱ�����һ������ѭ��*/
	{
		if (equal(zhu[i],zhu[i-1],4))         /*��ǰ��¼�������ڵ�ǰһ����¼����ܷ����*/
			zhu[i].rank=zhu[i-1].rank;     /*��ǰ��¼���ε��������ڵ�ǰһ����¼����*/
	    else
			zhu[i].rank=i+1;             /*�����ʱ��ǰ��¼���ε������±��+1*/
	}
}


int calcumax(int m[NUM], zhubo zhu[] ,int n)  /*��ֱ��ʱ���*/
{
   int i,j,max;
   max=zhu[0].Time ;
   for(i=0;i<NUM;i++)
   {
       m[i]=zhu[i].Time;
       if(m[i]<m[i+1])
       {
           max=zhu[i+1].Time;
       }
       else
       {
           max=zhu[i].Time;
       }
   }
   return max;
}


int calcumost(int m[NUM], zhubo zhu[] ,int n)  /*��ֱ���������*/
{
   int i,j,most;
   most=zhu[0].people ;
   for(i=0;i<NUM;i++)
   {
       m[i]=zhu[i].Time;
       if(m[i]<m[i+1])
       {
           most=zhu[i+1].people;
       }
       else
       {
           most=zhu[i].people;
       }
   }
   return most;
}


int calcupj(int m[NUM], zhubo zhu[] ,int n)  /*��ֱ��ƽ��ʱ��*/
{
   int i,j,pj,sum;
   sum=0;
   for(i=0;i<NUM;i++)
   {
      m[i]=zhu[i].Time;
      sum+sum+m[i];
   }
   pj=sum/NUM;
   return pj;
}


