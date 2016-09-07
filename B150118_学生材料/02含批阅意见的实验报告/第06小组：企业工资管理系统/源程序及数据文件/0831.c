#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>   
#define N 100


struct student
{
	char num[10];
	char name[10];
	char tel[11];
    char sex[2];
	int add;                                                       /*��ַ*/
	char deptnum[3];                                              /*���ű��*/
    char deptname[25];                                            /*��������*/
	float basepay;                                                /*��������*/
	signed int bonus;                                           /*����*/
	float meritpay;                                       /*��Ч����*/
	float sumbasepay;                                          /*�ܻ�������*/
	float totalpay;                                          /*ʵ��ѧ��*/
}stu[12];

void print();                                                    /*�������˵�*/
void create();                                                   /*��������ϵͳ*/
void display();                                                  /*��ʾ*/
void searchbase();                                               /*���������ѯ*/
/* schbase_num  sch_dom��schbase_name������searchbase���� */
void sch_num(FILE *fp); 
void sch_name(FILE *fp); 
void sch_dom(FILE *fp);
void search();                                                    /*��ѯ*/
void searchpay();                                           /*���ʲ�ѯ*/
void schpayum(FILE *fp,FILE *f);                                /*���ʲ�ѯ*/
void delete1();                                                    /*ɾ��*/
/* del_num������delete1���� */
void del_num(FILE *fp,FILE *f);
void sort();                                                      /*����*/
/* sort_sumscore��sort_count������sort���� */
void sort_sumscore();
void sort_count();

void main()
{  
	char choose,yes_no;
	do
	{
		print();                                                    /*��ʾ���˵�*/
		printf("         ");
		choose=getch(); 
		switch(choose)
		{
		case '1':	create();		break;		                    /*����*/
		case '2':	display();   	break;		                    /*��ʾ*/
		case '3':	search();		break;	                      	/*��ѯ */
		case '4':	delete1();		break;		                    /*ɾ��*/
		case '5':	sort();		    break;		                    /*����*/
		case '0':	break;		
		default:printf("\n        ��Ϊ�Ƿ�ѡ��   \n");
		}
		if(choose=='0')
			break;
		printf("        Ҫ����ѡ����(Y/N)?   ");
		do 
		{
			yes_no=getch();
		}while(yes_no!='Y'&&yes_no!='y'&&yes_no!='N'&&yes_no!='n');
	}while(yes_no=='Y'||yes_no=='y');
}

void print()                                                      /*��ʾ�˵�����*/
{  
	printf("\n\n");
	printf("                         ��ҵ���ʹ���ϵͳ  ");
	printf("\n");
	printf("       �q�T�T�T�T�T�T�T�T�T�T�T�T���������T�T�T�T�r\n");
	printf("	|	     ������ѡ����(0-5):         |\n"); 
	printf("	|-----------------------------------------|\n");
	printf("	|	1--����Ա����Ϣ     	          |\n"); 
	printf("	|	2--��ʾԱ����Ϣ     	          |\n");
	printf("	|	3--��ѯԱ����Ϣ                   |\n");
	printf("	|	4--ɾ��Ա����Ϣ                   |\n");
	printf("	|	5--����Ա����Ϣ    	          |\n");
	printf("	|	0--�˳�				  |\n");  
	printf("	|-----------------------------------------|\n");
	printf("        �t�T�T�T�T���������T�T�T�T�T�T�T�T�T�T�T�T�s\n");
    printf("\n");
    printf("     ��ӭ������ҵ���ʹ���ϵͳ������ѡ��Ҫ���еĲ���!\n ");

}