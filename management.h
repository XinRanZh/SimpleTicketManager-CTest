#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<database.h>
#include<setjmp.h>
#include<logincontrol.h>
#include<stdafx.h>
void ticketedit();
void fresh()
{
	system("cls");
	printf("=======================================================================\n");
	printf("=                                                                     =\n");
	printf("=                   ��ӭʹ�����Ƚ�ƻ�Ʊ����ϵͳ                    =\n");
	printf("=                                                                     =\n");
	printf("=======================================================================\n");
}
void managewelcome();
void ticketeditmain()
{
	fresh();
	printf("��ӭʹ�ó�Ʊ��Ϣ�޸�ϵͳ:\n�����ڿ��õĲ�������0��ˢ�³�Ʊ��Ϣ,��1���޸ĳ�Ʊ��Ϣ��2�����ع����̨��ҳ");
	int opte;
	scanf("%d", &opte);
	switch (opte)
	{
	case 0:fresh(); show(); ticketeditmain(); break;
	case 1:ticketedit();
	case 2:fresh();; managewelcome(); break;
	default:printf("ʧ�ܣ������˴���Ĺ��ܱ��"); system("pause"); ticketeditmain(); break;
	}
}
void ticketedit()
{
	fresh();
	show();
	printf("\n����������Ҫ�޸ĵĳ�Ʊ��ţ�\n");
	int editnum = 0;
	scanf("%d", &editnum);
	if (editnum > ticketcount)
	{
		printf("ʧ�ܣ����޴˳�\n");
		system("pause");
	}
	else {
	start:
		printf("��Ҫ�޸ĵ������ǡ�0���޸���ɣ��˳���1�������ء�2��Ŀ�ĵء�3������ʱ�䡾4������ʱ�䡾5���۸�6����Ʊ\n");
		int opnumb = 999;
		scanf("%d", &opnumb);
		char tmp[128];
		int tmpint;
		switch (opnumb)
		{
		case 0:system("clr"); ticketeditmain(); break;
		case 1:printf("����ǰ��������:%s\n������ĺ������:\n", t[editnum - 1].from); scanf("%s", tmp); strcpy(t[editnum - 1].from, tmp); goto start; break;
		case 2:printf("����ǰ��������:%s\n������ĺ������:\n", t[editnum - 1].to); scanf("%s", tmp); strcpy(t[editnum - 1].to, tmp); goto start; break;
		case 3:printf("����ǰ��������:%s\n������ĺ������:\n", t[editnum - 1].lefttime); scanf("%s", tmp); strcpy(t[editnum - 1].lefttime, tmp); goto start; break;
		case 4:printf("����ǰ��������:%s\n������ĺ������:\n", t[editnum - 1].arrivetime); scanf("%s", tmp); strcpy(t[editnum - 1].arrivetime, tmp); goto start; break;
		case 5:printf("����ǰ��������:%d\n������ĺ������:\n", t[editnum - 1].price); scanf("%d", &tmpint); t[editnum - 1].price = tmpint; goto start; break;
		case 6:printf("����ǰ��������:%d\n������ĺ������:\n", t[editnum - 1].tleft); scanf("%d", &tmpint); t[editnum - 1].tleft = tmpint; goto start; break;
		default:printf("���������"); goto start; break;
		}

	}
}
void ticketaddmain();
void ticketadd()
{
	fresh();
	printf("\n����Ŀǰ�Ѿ��еĳ�Ʊ��\n");
	show();
	printf("\n��������Ʊ���Ϊ%d\n", ticketcount + 1);
	char tmp[64];
	int tmpint = 0;
	printf("������ʼ����");
	scanf("%s", tmp);
	strcpy(t[ticketcount].from, tmp);
	printf("������Ŀ�ĵ�");
	scanf("%s", tmp);
	strcpy(t[ticketcount].to, tmp);
	printf("���������ʱ��");
	scanf("%s", tmp);
	strcpy(t[ticketcount].lefttime, tmp);
	printf("�����뵽��ʱ��");
	scanf("%s", tmp);
	strcpy(t[ticketcount].arrivetime, tmp);
	printf("������۸�");
	scanf("%d", &tmpint);
	t[ticketcount].price = tmpint; tmpint = 0;
	printf("������ʣ��Ʊ��");
	scanf("%d", &tmpint);
	t[ticketcount].tleft = tmpint; tmpint = 0;
	ticketcount++;
	ticketaddmain();
}
void ticketaddmain()
{
	fresh();
start:
	show();
	printf("��ӭʹ�ó�Ʊ��������ϵͳ:\n�����ڿ��õĲ�������0��ˢ�³�Ʊ��Ϣ,��1�����ӳ�Ʊ���ࡾ2�����ع����̨��ҳ");
	int opte;
	scanf("%d", &opte);
	switch (opte)
	{
	case 0: show(); goto start; break;
	case 1:ticketadd();
	case 2:fresh();; managewelcome(); break;
	default:printf("ʧ�ܣ������˴���Ĺ��ܱ��"); system("pause"); ticketeditmain(); break;
	}
}
void ticketdeletemain();
void ticketdel() {
	fresh();
	printf("\n����Ŀǰ�Ѿ��еĳ�Ʊ��\n");
	show();
	printf("��������Ҫɾ���ĳ�Ʊ��ţ�\n");
	int opte = 0;
	scanf("%d", &opte);
	if (opte == 0 || opte < 0 || opte > ticketcount)
	{
		printf("������������һ������ı��");
	}
	else {
		printf("��ȷ��Ҫ��ô��ô��\n����Сдyesȷ��");
		char confirm[64];
		scanf("%s", confirm);
		if (strcmp(confirm, "yes") == 0)
		{
			ticketcount--;//ɾ�����һ�����
			for (int i = opte - 1; i < ticketcount - 1; i++)//�ж��ǲ��ǲ��������
			{
				t[i] = t[i + 1];
			}
			ticketdeletemain();
		}
		else ticketdeletemain();
	}

}
void ticketdeletemain()
{
	fresh();;
start:
	show();
	printf("��ӭʹ�ó�Ʊ����ɾ��ϵͳ:\n�����ڿ��õĲ�������0��ˢ�³�Ʊ��Ϣ,��1��ɾ��һ�ų�Ʊ��2�����ع����̨��ҳ");
	int opte;
	scanf("%d", &opte);
	switch (opte)
	{
	case 0:fresh();; show(); goto start; break;
	case 1:ticketdel(); break;
	case 2:fresh();; managewelcome(); break;
	default:printf("ʧ�ܣ������˴���Ĺ��ܱ��"); system("pause"); goto start; break;
	}
}
void managewelcome() {
	fresh();
	show();
	printf("��ӭ��½�����̨:\n�����ڿ��õĲ�������0��ˢ�³�Ʊ��Ϣ,��1����Ʊ��������ϵͳ��2����Ʊ����ɾ��ϵͳ��3����Ʊ�޸�ϵͳ��4���˳�");
	int opte;
	scanf("%d", &opte);
	switch (opte)
	{
	case 0:fresh();show();  break;
	case 1:fresh(); ticketaddmain(); managewelcome(); break;
	case 2:fresh();ticketdeletemain(); managewelcome(); break;
	case 3:fresh(); ticketeditmain(); managewelcome(); break;
	case 4:fresh(); printf("ллʹ��"); system("pause"); break;
	default:fresh(); printf("�������\n"); system("pause"); fresh();managewelcome(); break;

	}
}