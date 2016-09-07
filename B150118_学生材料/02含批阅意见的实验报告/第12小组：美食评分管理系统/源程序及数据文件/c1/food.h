/* ��food.h�ļ����������� */
#ifndef _FOOD             /*�������룬��ֹ�ظ������Ĵ���*/
#define _FOOD
#include <string.h>
#define NUM 20                /*�����Ʒ�����������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Food                   /*��Ʒ��¼��������*/
{
		long num;
		char name[20];
		char style[10];
		char taste[10];
		double score[3];
		double total;
		int rank;
};
typedef struct Food Food;
#define sizeFoo sizeof(Food)      /*һ����Ʒ��¼����Ҫ���ڴ�ռ��С*/
int readFoo(Food foo[],int n);       /*�����Ʒ��¼ֵ�����Ϊ0������涨������¼ʱֹͣ*/
void printFoo(Food  *foo , int n);   /*������в�Ʒ��¼��ֵ*/

int equal(Food s1,Food s2,int condition);  /*����condition�����ж�����Food����������ȷ�*/
int larger(Food s1,Food s2,int condition);  /*����condition�Ƚ�Food�������ݴ�С*/
void reverse(Food foo[],int n);             /*��Ʒ��¼����Ԫ������*/
void calcuTotal(Food foo[],int n);           /*�������в�Ʒ���ܷ�*/
void calcuRank(Food foo[],int n);           /*�����ּܷ����Ʒ�����Σ������в�������*/
void calcuMark(double m[3][3],Food foo[],int n); /*��������Ŀ����ߡ���͡�ƽ���֣�m�����һά*/
/*��ʾ�ĸ�������Ŀ���ڶ�ά��ʾ��ߡ���͡�ƽ����*/
void sortFoo(Food foo[],int n,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/
int searchFoo(Food foo[],int n,Food s,int condition,int f[]) ;  /*������������������s��ȵĸ�Ԫ��*/
/*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/
int insertFoo(Food foo[],int n,Food s);                   /*�������в���һ��Ԫ�ذ��������*/
int deleteFoo(Food foo[],int n,Food s);                   /*��������ɾ��һ��ָ����ŵ�Ԫ��*/
#endif