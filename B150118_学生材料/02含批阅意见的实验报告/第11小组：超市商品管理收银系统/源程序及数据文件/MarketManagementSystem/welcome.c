#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"welcome.h"
// ����Ա����
void adminabc()
{
    int a;
    char b;
    do
    {
        printf("��ӭ�������Աҳ��\n\n");
        printf("  1��Ʒ��Ϣ¼��\n  2��Ʒ�������б�\n  3�������󱨱�\n  4���ص�¼ҳ��\n\n\n");
        printf("���������");
        scanf("%d",&a);
        if(a!=1&&a!=2&&a!=3&&a!=4)
        {
            printf("������������������!\n\n\n");
        }
    }
    while(a!=1&&a!=2&&a!=3&&a!=4);

    switch (a)
    {
    case 1:
        inputgoods();
        break;
    case 2:
       showgoods();
        break;
    case 3:
        printf("����������:%.2f",totalprofit());
         printf("�������������һ��");
         getchar();
         getchar();
         system("cls");
        adminabc();
        break;
    case 4:
        login();
        break    ;
    }


}



//��¼����
int login()
{
    printf("��ӭ���볬����Ʒ������ϵͳ\n");
    printf("���¼��\n");
    printf("�������û�����");
    char user_name[200];
    char user_password[200];
    int c=0,i=0;
    scanf("%s",&user_name);
    printf("���������룺");
    while ((c=getch()) != '\r') //ʹ���������ʱ����ʾ*��
    {
        user_password[i++] = c;
        putchar('*');
    }
    user_password[i] = '\0';
    char admin[] = "root";
    char adminpassword[] = "123456";
    char check[] = "check";
    char checkpassword[] = "123456";
    if(!strcmp(user_name,admin)&& !strcmp(user_password,adminpassword))
    {
        system("cls");
        printf("\n����Ա���\n");
        adminabc();
    }
    else
    {
        if(!strcmp(user_name,check)&& !strcmp(user_password,checkpassword))
        {
            system("cls");
            printf("\n����Ա���\n");
            checkabc(0,0.0,0.0);
        }
        else
        {

            printf("\n�û������������,�밴�س����µ�¼\n");
            getchar();
            getchar();
            system("cls");
            login();
        }
    }
    return 0;
}
//����Ա����
void checkabc(int id,double total,double profit){
 int command;
    printf("��ӭ��������Աϵͳ\n");
    printf("1������\n2��������������\n");
    do                  //����Ƿ�������ȷ��ָ�������������������
    {
        printf("���������");
        scanf("%d",&command);
         printf("\n");
        if(command!=1&&command!=2)
            printf("�������\n�ٴ�");

    }
    while(command!=1&&command!=2);
    if(command==1)           //1����������Ա����  2�����뱾����������
    {
    system("cls");
    checkcode();
    }
    else
    {
        printf("��ӭ�鿴����Ӫ������\n���ζ����ţ�%d�ܼ۸�%.2f%����%.2f\n",id,total,profit);
         printf("�������������һ��");
         getchar();
         getchar();
         system("cls");
        checkabc(id,total,profit);
    }
    return 0;
}


// ¼�뺯��
void inputgoods()
{
    system("cls");
    char code[20];
    double price,chengben;
    char name[20],num[20];
    int s,num;

    do
    {
        printf("��ֱ������Ʒ��Ϣ�����롢��Ʒ���ơ��۸񡢳ɱ������*�Կո����*\n\n");
        scanf("%s%s%lf%lf%d",code,name,&price,&chengben,&num);
        printf("\n   ����:%s\n   ����:%s\n   �۸�:%10.2f\n   1�ɱ�:%10.2f\n",code,name,price,chengben,);
        if(addgoods(code,name,price,chengben,num))
            printf("��ӳɹ�");
        else
            printf("���ʧ��");
        printf("\n�Ƿ���� 1�� or 2��\n\n");
        scanf("%d",&s);
        if(s==2)
        {
            system("cls");
            adminabc();
        }
    }
    while (s==1);
}


//��������
void checkcode()
{
    char code[20],endcode[20]="end";
    goods good[100];
    int i=0;
    double total=0.0;
    order profit;
    printf("��ӭ��������ϵͳ\n��������Ʒ������(����end����)��\n");
    do
    {
        scanf("%s",code);
        if(!strcmp(code,endcode))
            break;
        if(ifexist(code))
        {
            good[i++] = readcode(code);
            if(good[i-1].num>0)
            {
                total = total+good[i-1].price;
                profit.profit = profit.profit + good[i-1].price-good[i-1].chengben;
                profit.total = total;
               sale(good[i-1].code); //����һ
                printf("��Ʒ���ƣ�%10s �۸�%10.2fԪ ����:%d \n�ܼ�:%10.2fԪ\n",good[i-1].name,good[i-1].price,good[i-1].num-1,total);
            }
            else
            {
                printf("����Ʒ������������������");
                continue;
            }
        }
        else
        {
            continue;

        }
    }
    while(1);
    createorder(profit.total,profit.profit);

}


//���һά���Ƿ�ϸ���
int checknum(const char*num)
{
    int i;
     for(i=0;i<20;i++)
            {
                if(num[i]=='\0') break;
                if(!(num[i]>='0'&&num[i]<='9'||num[i]=='\0'))
                   {//printf("%s",num);
                    return 1;
                    break;
                   }
            }

     return 0;

}
