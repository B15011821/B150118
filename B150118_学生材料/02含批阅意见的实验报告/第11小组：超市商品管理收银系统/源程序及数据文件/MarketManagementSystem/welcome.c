#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"welcome.h"
//��¼����
int login()
{
    printf("��ӭ���볬����Ʒ������ϵͳ\n"); //��¼UI����
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
    char admin[] = "root"; //��֤�˺����������Ӧ�ĺ���
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

            printf("\n�û������������,�밴�س����µ�¼\n"); //����������ʾ�ݹ����
            getchar();
            getchar();
            system("cls");
            login();
        }
    }
    return 0;
}
//����Ա����
void checkabc(int id,double total,double profit)
{
    int command;
    printf("��ӭ��������Աϵͳ\n");
    printf("1������\n2��������������\n3�����ص�¼ҳ��\nW");
    do                  //����Ƿ�������ȷ��ָ�������������������
    {
        printf("���������");
        scanf("%d",&command);
        printf("\n");
        if(command!=1&&command!=2)
            printf("�������\n�ٴ�����");

    }
    while(command!=1&&command!=2&&command!=3);
    if(command==1)           //1����������Ա����  2�����뱾����������3.���ص�¼ҳ��
    {
        system("cls");
        checkcode();
    }
    else
    { //���ζ����ı���
        if(command == 3) //��⵽���ͻص���¼ҳ��
        {
            system("cls");
            login();
        }
        system("cls");
        printf("��ӭ�鿴����Ӫ������\n���ζ����ţ�%d�ܼ۸�%.2f%����%.2f\n",id,total,profit);  //������ε�Ӫ������
        printf("�������������һ��");
        getchar();
        getchar();
        system("cls");
        checkabc(id,total,profit); //���������Ϣ��������Ա������������������
    }
    return 0;
}

//��������
void checkcode()
{
    char code[20],endcode[20]="q",number[20],deletecode[20]="d";
    int flag=0;
    goods good[100]; //�ṹ�����鴢���Ѿ��յ�������
    int i=0,c=1,d=0,e = 0;
    double total=0.0,numdouble,intnum[100];
    order profit;
    printf("��ӭ��������ϵͳ\n��������Ʒ�������Լ�����Ҫ������(����q����,����d����ɾ��ģʽ)��\n");
    do
    {
        scanf("%s",code); //���ȼ���ǲ���������end
        if(!strcmp(code,endcode))
            break;
        //ɾ��ģʽ��ʼ
        if(!strcmp(code,deletecode))
        {
            if(flag == 0) // ���flag��0 ����Ϊû��������Ʒ
            {
                printf("�㻹û�������κ���Ʒ�����������롣");
                checkcode();
            }
            printf("���ѽ���ɾ��ģʽ��������Ҫɾ������Ʒ�������Լ�����Ҫɾ����������(����q����)\n");
            printf("���ι������Ʒ��\n");
            printf("       ����         ����    ����     \n");
            for(d=0; d<i; d++) //����������ڶ����������Ʒ
            {
                printf("%10s%10s%10.0f\n",good[d].code,good[d].name,intnum[d+1]);
            }
            do
            {
                scanf("%s",code);
                if(!strcmp(code,endcode))
                    break;
                scanf("%s",number);
                if(checknum(code) || checknum(number)) // ������˼��
                {
                    printf("����������������������");
                    continue;
                }
                numdouble = atof(number); //�������������ת����ʵ��
                if(numdouble <= 0)
                {
                    printf("����������������������");
                    continue;
                }
                if(ifexist(code))
                {
                    good[i++] = readcode(code);
                    if(good[i-1].num>0)

                    {
                        c=1;
                        for(; c<=numdouble; c++) //���ݽṹ���������Ϣ��������Ʒ
                        {
                            total = total-good[i-1].price;
                            profit.profit = profit.profit - (good[i-1].price-good[i-1].chengben);
                            profit.total = total;
                            saleadd(good[i-1].code);
                        } //���+һ
                        printf("��Ʒ���ƣ�%10s �۸�%10.2fԪ ɾ������:%10.0f \n���ܼ�:%10.2fԪ\n",good[i-1].name,good[i-1].price,numdouble,total);
                    }
                    else
                    {
                        printf("����Ʒ������������������"); //�����Ʒ�Ƿ�������
                        continue;
                    }
                }
                else
                {
                    continue;

                }
            }
            while(1);
            printf("\n��������Ʒ�������Լ�����Ҫ������(����end����)��\n");
            continue;
        }
        //ɾ��ģʽ����
        //�����Ʒ
        scanf("%s",number);
        if(checknum(code) || checknum(number))
        {
            printf("����������������������");
            continue;
        }
        numdouble = atof(number);
        intnum[++e] = numdouble;
        if(numdouble <= 0)
        {
            printf("����������������������");
            continue;
        }
        if(ifexist(code))
        {
            good[i++] = readcode(code);
            if(good[i-1].num>0)
            {
                c=1;
                for(; c<=numdouble; c++)
                {
                    total = total+good[i-1].price;
                    profit.profit = profit.profit + good[i-1].price-good[i-1].chengben;
                    profit.total = total;
                    sale(good[i-1].code);
                    flag = 1; //�б����Ѿ�����Ʒ�ˡ�
                } //����һ
                printf("��Ʒ���ƣ�%10s �۸�%10.2fԪ ��������:%10.0f \n�ܼ�:%10.2fԪ\n",good[i-1].name,good[i-1].price,numdouble,total);
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
    createorder(profit.total,profit.profit);//����������д���ļ�

}

// ����Ա��ں���
void adminabc()
{
    int month;
    int a;
    char b;
    do
    {
        printf("��ӭ�������Աҳ��\n\n"); //UI��ʼ��
        printf("  1��Ʒ��Ϣ¼��\n  2��Ʒ�������б�\n  3�������󱨱�\n  4���ص�¼ҳ��\n\n\n");
        printf("���������");
        scanf("%d",&a);
        if(a!=1&&a!=2&&a!=3&&a!=4)
        {
            printf("������������������!\n\n\n");
        }
    }
    while(a!=1&&a!=2&&a!=3&&a!=4);

    switch (a) //�������������ں���
    {
    case 1:
        inputgoods();
        break;
    case 2:
        showgoods();
        break;
    case 3:
        printf("\t\t\t\t�������ѯ�·ݣ�");
        scanf("%d",&month);
        while(month!=1&&month!=2&&month!=3&&month!=4&&month!=5&&month!=6&&month!=7&&month!=8&&month!=9&&month!=10&&month!=111&&month!=12)   //����������Ƿ�Ϊ�Ϸ��·�
        {
            printf("\t\t\t\t�����������������룡");
            scanf("%d",&month);
        }

        printf ("\n\n\t\t\t\t********************\n");
        printf ("\t\t\t\t��ӭ�鿴%d��Ӫ������\n",month);
        printf ("\t\t\t\t********************\n");

        printf("\n\n\t\t  ���¶����嵥:");

        printf("\n\n\n\n\t\t ���������ܶ�:");
        printf("����������:%.2f",totalprofit());
        printf("�������������һ��");
        getchar();
        getchar();
        system("cls");
        adminabc();
        break;
    case 4:
        system("cls");
        login();
        break    ;
    }


}

// ����Ա¼�뺯��
void inputgoods()
{
    system("cls");
    char code[20];
    char name[20],num[20],price[20],chengben[20],end[20] = "end";
    int s;

    do
    {
        printf("��ֱ������Ʒ��Ϣ�����롢��Ʒ���ơ��۸񡢳ɱ������*�Կո����* \n����end�������˵�\n\n");
        scanf("%s",code);
        if(!strcmp(code,end))
        {
            system("cls");
            adminabc();
        }
        scanf("%s%s%s%s",name,price,chengben,num);
        if(!checknum(num) && !checknum(code) && !checknum(chengben) && !checknum(price))  //���ü�麯����������Ƿ�Ϸ�
            printf("\n   ����:%s\n   ����:%s\n   �۸�:%s\n   �ɱ�:%s\n",code,name,price,chengben);
        else
        {
            printf("���������������������롣\n");
            s = 1;
            continue;

        }
        if(addgoods(code,name,price,chengben,num))
            printf("��ӳɹ�");
        else
            printf("���ʧ��");
        printf("\n�Ƿ���� 1�� or 2��\n\n"); //ѭ���ݹ�
        scanf("%d",&s);
        if(s==2)
        {
            system("cls");
            adminabc();
        }
    }
    while (s==1);
}


//������˺���
int checknum(const char*num)
{
    int i;
    for(i=0; i<20; i++)
    {
        if(num[i]=='\0') break;
        if(!(num[i]>='0'&&num[i]<='9'||num[i]=='\0'))
        {
            //printf("%s",num);
            return 1;
            break;
        }
    }

    return 0;

}
