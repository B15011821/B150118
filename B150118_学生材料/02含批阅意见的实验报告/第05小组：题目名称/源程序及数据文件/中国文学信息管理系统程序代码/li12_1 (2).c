/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"student.h"

void printHead( )      /*��ӡ�й���ѧ������Ϣ�ı�ͷ*/
{
printf("%8s%10s%8s%6s%6s%8s%\n","��Ʒ����","����","��������","�����Ա�","��Ʒ��Ϣ","������Ϣ");
}

void menu( )         /*����˵�����*/
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ������Ϣ���� ********\n");
		printf("******** 3. ������Ϣ���� ********\n");
		printf("******** 4. ������Ϣͳ�� ********\n");
     printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ������ѧ������Ʒ��¼ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ����ѧ������Ʒ��¼ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸���ѧ������¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuScore( )     /*3����ѧ������Ϣ����˵�����*/
{
		printf("@@@@@@@@ 1. ����������ѧ��Ʒ���� @@@@@@@@\n");
		printf("@@@@@@@@ 2. ����������ѧ��Ʒ�������� @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}
 
void menuCount( )    /*4��������Ϣͳ�Ʋ˵�����*/
{
		printf("&&&&&&&& 1. ����Ʒ������� &&&&&&&&\n");
		printf("&&&&&&&& 2. ����Ʒ������� &&&&&&&&\n");
		printf("&&&&&&&& 3. ��������Ʒƽ���� &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
}

void menuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. ����ѧ��Ʒ���Ʋ�ѯ   ########\n");
		printf("######## 2. ������������ѯ   ########\n");
		printf("######## 3. ����Ʒ��������ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}

int baseManage(Student stu[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*�������������в���ɾ���޸ģ��������������ظ�*/
{  
		int choice,t,find[NUM];
     Student s;
do
	    {   
menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readStu(&s,1);       /*����һ�������������������¼*/
					 n=insertStu(stu,n,s);   /*���ú�������ѧ����¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*����һ����ɾ������������*/
					 n=deleteStu(stu,n,s);   /*���ú���ɾ��ָ��������������ѧ������¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*����һ�����޸ĵ���������*/
				      t=searchStu(stu,n,s,1,find) ; /*���ú�������ָ����������ѧ����*/
				      if (t)                 /*��������������ļ�¼����*/
					 {
						  readStu(&s,1);   /*����һ������������������¼��Ϣ*/
					      stu[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*��������ߵļ�¼������*/ 
 printf("this student is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

void scoreManage(Student stu[],int n)          /*�ú�������й���ѧ����������*/
{  
	int choice;
	do
	{
		menuScore( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*�������ѡ��*/
		switch(choice)
		{
			case 1:   calcuTotal(stu,n);         /*������ӵ����Ʒ������*/
					  break;
			case 2:   calcuRank(stu,n);         /*��������ӵ����Ʒ����������*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}

void printMarkCourse(char *s,double m[3][3],int k)   /*��ӡ����ͨ�ú�������countManage ����*/
{                 /*��ʽ����k���������ͬ�����ݣ�0��1��2�ֱ��Ӧ��Ʒ������ߣ�����ߣ�ƽ����*/
int i;
    printf(s);                                  /*�����s������������ѧ������Ϣ*/
    for (i=0;i<3;i++)                           /*i������һ����Ʒ*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}

void countManage(Student stu[],int n)               /*�ú��������ѧ����ͳ�ƹ���*/
{
		int choice;
		double mark[3][3];
		do
		{
			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/
			calcuMark(mark,stu,n);                 /*���ô˺���������ӵ����Ʒ������ߣ�����ߣ�ƽ����*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("���ſε���߷ֱַ���:\n",mark,0);  /*��������*/
				      break;
				case 2:   printMarkCourse("���ſε���ͷֱַ���:\n",mark,1);  /*��������*/
				      break;
				case 3:   printMarkCourse("���ſε�ƽ���ֱַ���:\n",mark,2);  /*���ƽ����*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Student stu[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
Student s;
	   do
{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a student\'s num will be searched:\n");
				      scanf("%ld",&s.num);         /*�������ѯ��ѧ��������������*/
					  break;
				case 2:   printf("Input a student\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*�������ѯ������������Ʒ*/
				      break;   
				case 3:   printf("Input a rank will be searched:\n");
				      scanf("%d",&s.rank);          /*�������ѯƷӵ������������*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchStu(stu,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printStu(&stu[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

int runMain(Student stu[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				 sortStu(stu,n,1);         /*��ѧ����С�����˳�������¼*/ 
          	 printStu(stu,n);          /*��ѧ����С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(stu,n);    /* 2. ������Ϣ����*/
			   	     break;
			case 3: scoreManage(stu,n);     /* 3. ��ѧ������Ϣ����*/
					break;
			case 4: countManage(stu,n);     /* 4. ��ѧ������Ϣͳ��*/
					break;
			case 5: searchManage(stu,n);     /* 5. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Student stu[NUM];                /*����ʵ��һά����洢ѧ����¼*/
      int choice,n;
	 n=readFile(stu);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(stu);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(stu,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortStu(stu,n,1);                   /*�����ļ�ǰ������ӵ����Ʒ���������δӸߵ�������*/
	     saveFile(stu,n);                   /*����������ļ�*/
      return 0;
}
/*��student.c�ļ�����������*/
#include "student.h"
#include <stdio.h>

int readStu(Student  *stu , int n)          /*�����й���ѧ������¼ֵ����¼ʱֹͣ*/
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one student\'s information\n");
		printf("num:  ");
	     scanf("%ld", &stu[i].num);
		if (stu[i].num==0) break;
		printf("name: ");
		scanf("%s",stu[i].name);	
		printf("sex:  ");
		scanf("%s",stu[i].sex);
    	     stu[i].total=0;                /*�ܷ���Ҫ������ã���ֵ��Ϊ0*/
		printf("Input three courses of the student:\n");
		for (j=0;j<3;j++)
	    {
		    scanf("%d",&stu[i].score[j]);	
		}
		stu[i].rank=0;                 /*������Ҫ�����ܷ������㣬��ֵ��Ϊ0*/
	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printStu ( Student  *stu , int n)       /*�������ѧ����¼��ֵ*/
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", stu[i].num);
		printf("%8s", stu[i].name);
		printf("%8s", stu[i].sex);
		for (j=0;j<3;j++)
		   printf("%6d",stu[i].score[j]);
	    printf("%7d",stu[i].total);
	    printf("%5d\n",stu[i].rank);
	}
}

int equal(Student s1,Student s2,int condition)  /*����ж�����Student��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ�ѧ��*/
		return s1.num==s2.num;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*�������condition��ֵΪ3����Ƚ�����*/
	     return s1.rank==s2.rank;
 else if (condition==4)                /*�������condition��ֵΪ4����Ƚ��ܷ�*/
		return s1.total==s2.total;
	else return 1;                       /*�����������1*/
} 

int larger(Student s1,Student s2,int condition)  /*����condition�����Ƚ�����Student��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ�ѧ��*/
		return s1.num>s2.num;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚ��ܷ�*/
		return s1.total>s2.total;	
	else return 1; /*�����������1*/
}

void reverse(Student stu[],int n)             /*����Ԫ������*/
{
	int i;
	Student temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=stu[i];
		stu[i]=stu[n-1-i];
		stu[n-1-i]=temp;
	}
}

void calcuTotal(Student stu[],int n)         /*��������ѧ�����ܷ�*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*���ѭ����������ѧ����¼*/
	{
		stu[i].total =0;
		for (j=0;j<3;j++)               /*�ڲ�ѭ���������Ź���*/
			stu[i].total +=stu[i].score[j];
	}	
}

void calcuRank(Student stu[],int n)          /*�����ּܷ�������ѧ�����������ɼ���ͬ��������ͬ*/
{
	int i ;                       
	sortStu(stu,n,2);                     /*�ȵ���sortStu�㷨�����ܷ���С��������*/
	reverse(stu,n);                      /*�����ã����ܷ��ɴ�С������*/
	stu[0].rank=1;                      /*��һ����¼������һ����1*/
	for (i=1;i<n;i++)                     /*�ӵڶ�����¼һֱ�����һ������ѭ��*/
	{
		if (equal(stu[i],stu[i-1],4))         /*��ǰ��¼�������ڵ�ǰһ����¼����ܷ����*/
			stu[i].rank=stu[i-1].rank;     /*��ǰ��¼���ε��������ڵ�ǰһ����¼����*/ 
	    else
			stu[i].rank=i+1;             /*�����ʱ��ǰ��¼���ε������±��+1*/
	}
}

void calcuMark(double m[3][3],Student stu[],int n) /*�����ſε���ߡ���͡�ƽ����*/
/*������ʽ������ά����m�ĵ�һά�������ſΣ��ڶ�ά������ߡ���͡�ƽ����*/
{
	int i,j;
	for (i=0;i<3;i++)                 /*�����ſε���߷�*/		
	{ 
		m[i][0]=stu[0].score[i];     
		for (j=1;j<n;j++)
			if (m[i][0]<stu[j].score[i])
				m[i][0]=stu[j].score[i];
	}
	for (i=0;i<3;i++)                  /*�����ſε���ͷ�*/
	{ 
		m[i][1]=stu[0].score[i];      
		for (j=1;j<n;j++)
			if (m[i][1]>stu[j].score[i])
				m[i][1]=stu[j].score[i];
	}
	for (i=0;i<3;i++)                 /*�����ſε�ƽ����*/
	{ 
		m[i][2]=stu[0].score[i];     
		for (j=1;j<n;j++)
			m[i][2]+=stu[j].score[i];
		m[i][2]/=n;
	}
}

void sortStu(Student stu[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	Student t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(stu[minpos],stu[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=stu[i];
			stu[i]=stu[minpos];
			stu[minpos]=t;
		}
	}
}

int searchStu(Student stu[],int n,Student s,int condition,int f[ ])  /*��stu��������condition��������*/
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(stu[i],s,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}

int insertStu(Student stu[],int n,Student s)              /*��stu��������ѧ�ŵ�������һ��Ԫ��s*/
{
	int i;
	sortStu(stu,n,1);                              /*�Ȱ�ѧ������*/
	for (i=0;i<n;i++)
	{
		if (equal(stu[i],s,1))                      /*ѧ����ͬ��������룬��֤ѧ�ŵ�Ψһ��*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*��ѧ�Ŵ�С��������*/
	{
		if (!larger(stu[i],s,1))                    /*���s���ڵ�ǰԪ��stu[i]�����˳�ѭ��*/
		break;
		stu[i+1]=stu[i];                         /*����Ԫ��stu[i]����һ��λ��*/
	}
	stu[i+1]=s;                                /*���±�i+1������Ԫ��s*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deleteStu(Student stu[],int n,Student s)            /*��������ɾ��ָ��ѧ�ŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(stu[i],s,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(stu[i],s,1)����*/ 
		stu[j]=stu[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}
