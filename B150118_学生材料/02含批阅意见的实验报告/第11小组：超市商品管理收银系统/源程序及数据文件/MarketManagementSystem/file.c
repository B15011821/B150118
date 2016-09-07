#include<stdio.h>
#include "welcome.h"
#include<stdlib.h>
#include <time.h>
//�����Ƿ���ں���
int ifexist(char code[])
{
    int a = 0;
    goods read;
    FILE *fp;
    if(fp = fopen(".\\1.txt","r")) //�ļ���
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);  //��ȡ�ļ�
            if(!strcmp(code,read.code))
            {
                fclose(fp);
                a = 1;
                break;
            }
        }
    }
    else
    {
        printf("�ļ����ش����������ݿ��ļ�");
    }
    if(a==0)
        printf("���벻���ڣ�����������\n");
    return a;
}
//���������
double totalprofit()
{
    int id;
    double total=0,profit=0,abc=0;
    FILE *fp;
    if(fp = fopen(".\\2.txt","r"))//�ļ���
    {
        while(!feof(fp))
        {
            fscanf(fp,"%d %lf %lf\n",&id,&total,&profit);//��ȡ���ж�����Ϣ���������ܺ�����
            abc = abc+profit;
        }
    }
    else
    {
        printf("�ļ����ش����������ݿ��ļ�");
    }
    return total;
}




//ɨ�� ���ز�ѯ����������Ϣ
struct goods readcode(char code[])
{
    goods read;
    FILE *fp;
    if(fp = fopen(".\\1.txt","r"))
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);
            if(!strcmp(code,read.code)) //������Ҫ������
            {
                fclose(fp);
                break;
            }
        }
    }
    else
    {
        printf("�ļ����ش����������ݿ��ļ�");
    }
    return read;
}

//��ʾ���е�ȫ����Ʒ
void showgoods()
{
    system("cls");
    goods read;
    FILE *fp;
    if(fp = fopen(".\\1.txt","r")) //�ļ���
    {
        printf("   ����           ����       �ۼ�      �ɱ�     ����   \n");
        while(!feof(fp))
        {

            fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);  //��ȡ�ļ�
            printf("%10s   %10s %10.2f %10.2f   %10d\n",read.code,read.name,read.price,read.chengben,read.num);
        }
    }
    else
    {
        printf("�ļ����ش����������ݿ��ļ�");
    }
    printf("�밴�����������һ��˵�");
    getchar();
    getchar();
    system("cls");
    adminabc();

}
//����µ���Ʒ
int addgoods(char code[],char name[],char price[],char chengben[],char num[])
{
    FILE *fp;
    if(fp = fopen(".\\1.txt","a+")) //���ļ�
    {
        fprintf(fp,"\n%s %s %s %s %s",code,name,price,chengben,num); //����һ���ĸ�ʽ��д���ļ�
        fclose(fp);
        return 1;
    }
    else
    {
        printf("�ļ����ش����������ݿ��ļ�");
        return 0;
    }
}

//д��������Ϣ����������
void createorder(double price,double profit)
{
    int id;
    order add;
    add.id = neworder();//���������������������
    add.total = price;
    add.profit = profit;
    printf("�����������\n");
    FILE *fp;
    if(fp = fopen(".\\2.txt","a+"))
    {
        id = neworder();
        fprintf(fp,"\n%d %.2f %.2f",id,add.total,add.profit);//д���ļ�����ʾ���ζ����۸�
        fclose(fp);
        printf("\n\n���ζ����ţ�%d�ܼ۸�%.2f\n\n",id,add.total);
        checkabc(add.id,add.total,add.profit);
        return 1;
    }
    else
    {
        printf("�ļ����ش����������ݿ��ļ�");
        return 0;
    }

}
//����һ
void sale(char code[])
{
    goods read;
    FILE *fp;
    char c,d[20],e[20];
    int i=-2;
    if(fp = fopen(".\\1.txt","r+"))//���ļ�
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);//��ȡ���ݽ���ṹ�����
            if(!strcmp(code,read.code))
            {
                while(c != ' ') //�ļ�ָ����ҵ���һ���ո�
                {
                    fseek(fp,-1,1);
                    c = fgetc(fp);
                    fseek(fp,-1,1);
                }
                fseek(fp,1,1);//�ļ�ָ�붨λ���
                sprintf(e,"0%d\n",read.num-1);//��0��д����ֹλ���仯��������
                fputs(e,fp);
                fclose(fp); //�ر��ļ�
                break;
            }
        }
    }
    else
    {
        printf("�ļ����ش����������ݿ��ļ�");
    }
}
//���+1 ˼·ͬ��
void saleadd(char code[])
{
    goods read;
    FILE *fp;
    char c,d[20],e[20];
    int i=-2;
    if(fp = fopen(".\\1.txt","r+"))
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);
            if(!strcmp(code,read.code))
            {
                while(c != ' ')
                {
                    fseek(fp,-1,1);
                    c = fgetc(fp);
                    fseek(fp,-1,1);
                }
                fseek(fp,1,1);
                sprintf(e,"0%d\n",read.num+1);
                fputs(e,fp);
                fclose(fp);
                break;
            }
        }
    }
    else
    {
        printf("�ļ����ش����������ݿ��ļ�");
    }
}


//�������������
int neworder()
{
    int id;
    goods read;
    srand( (unsigned)time( NULL ) );
    id = rand()%(9999999-1000000+1)+1000000; //�������������
    return id;
}
