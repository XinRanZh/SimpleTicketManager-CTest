#pragma once
#include<stdio.h>
#include<database.h>
int placen;
int timen;
void ticketbuymain(int num);
void passwordchange(int num);
void usermain(int num);
void passwordchangemain(int num);
void searchenginemain(int num);
void searchengineplace(int num) {
	fresh();
	show();
	printf("������һ��������Ŀ�ĵػ򵽴�أ�\n");
	char tmp[64];
	scanf("%s", tmp);
	for (int i = 0; i < ticketcount; i++)
	{
		if (strcmp(tmp, t[i].from))
		{
			placen++;
			printf("�ҵ���%d���������ţ�%d------�����أ�%s\n", placen,i+1,tmp);
		}
		else if (strcmp(tmp, t[i].to))
		{
			placen++;
			printf("�ҵ���%d���������ţ�%d-----����أ�%s\n", placen, i + 1, tmp);
		}
		printf("\n");system("pause");
	}
	placen = 0;
}
void searchengingtime(int num) {
	fresh();
	show();
	printf("������һ�������ĳ���ʱ��򵽴�ʱ�䣺\n");
	char tmp[64];
	scanf("%s", tmp);
	for (int i = 0; i < ticketcount; i++)
	{
		if (strcmp(tmp, t[i].lefttime))
		{
			timen++;
			printf("�ҵ���%d���������ţ�%d------����ʱ�䣺%s\n", timen, i + 1, tmp);
		}
		else if (strcmp(tmp, t[i].arrivetime))
		{
			timen++;
			printf("�ҵ���%d���������ţ�%d-----����ʱ�䣺%s\n", timen, i + 1, tmp);
		}
		printf("\n");system("pause");
	}
	timen = 0;
}
void searchenginemain(int num) {
	fresh();
	printf("��ӭʹ��Ʊ��������");
	show();
	printf("\n�����ڿ��õĲ�������0��ˢ�³�Ʊ��Ϣ,��1���������ػ�Ŀ�ĵز���һ�ų�Ʊ��2��������ʱ��򵽴�ʱ�����һ�ų�Ʊ��3���˳�");
	int opte;
	scanf("%d", &opte);
	switch (opte){
	case 0:fresh(); show();  break;
	case 1:fresh(); searchengineplace(num); usermain(num); break;
	case 2:fresh(); searchengingtime(num); usermain(num); break;
	case 3:fresh(); printf("��������������"); printf("\n");system("pause"); fresh(); usermain(num); break;
	default:fresh(); printf("�������\n"); printf("\n");system("pause"); fresh(); ticketbuymain(num); break;

	}
}
void ticketbuy(int num) {
	fresh();
	show();
	printf("��������Ҫ����ĳ�Ʊ�ı��:\n");
	int ticketnum;
	scanf("%d", &ticketnum);
	if (ticketnum <= ticketcount&& t[ticketnum - 1].tleft > 0) {
		printf("����ɹ�");
		printf("\n");system("pause");
		t[ticketnum - 1].tleft--;
	}
	else
	{
		fresh();
		show();
		printf("����ʧ�ܣ������Ŵ������Ʊ���㣬������\n");
		printf("\n");system("pause");
		ticketbuymain(num);
	}
}
void ticketbuymain(int num) {
	fresh();
	printf("��ӭʹ�ù�Ʊϵͳ");
	show();
	printf("\n�����ڿ��õĲ�������0��ˢ�³�Ʊ��Ϣ,��1������һ�ų�Ʊ��2������������");
	int opte;
	scanf("%d", &opte);
	switch (opte)
	{
	case 0:fresh(); show();  break;
	case 1:fresh(); ticketbuy(num); usermain(num); break;
	case 2:fresh(); printf("��������������"); printf("\n");system("pause"); fresh();usermain(num); break;
	default:fresh(); printf("�������\n"); printf("\n");system("pause"); fresh(); ticketbuymain(num); break;

	}

}
void passwordchange(int num) {
	fresh();
	printf("����������ԭʼ����");
	char pwdorgintmp[64],pwdnewtmpa[64],pwdnewtmpb[64];
	scanf("%s", pwdorgintmp);
	if (strcmp(pwdorgintmp, u[num].password)!=0) {
		printf("����������"); passwordchangemain(num);
	}
	else {
		printf("�����������룺\n");
		scanf("%s",pwdnewtmpa);
		printf("���ٴ�����������\n");
		scanf("%s", pwdnewtmpb);
		if (strcmp(pwdnewtmpb, pwdnewtmpa) == 0) {
			strcpy(u[num].password, pwdnewtmpa);
			printf("�޸ĳɹ�");
			printf("\n");system("pause");
		}
		else printf("�������벻ƥ�䣬������");
		passwordchangemain(num);
	}

}
void passwordchangemain(int num) {
	fresh();
	printf("��ӭʹ���������ϵͳ");
	printf("\n�����ڿ��õĲ�������0��������������,��1������������");
	int opte;
	scanf("%d", &opte);
	switch (opte)
	{
	case 0:passwordchange(num); printf("�����˳�����򿪲����µ�½"); printf("\n");system("pause"); break;
	case 1:fresh(); printf("��������������"); printf("\n");system("pause"); fresh(); usermain(num); break;
	default:fresh(); printf("�������\n"); printf("\n");system("pause"); fresh(); ticketbuymain(num); break;

	}
}
void usermain(int num) {
	fresh();
	fresh();
	show();
	printf("��ӭʹ�ã��û�:\n�����ڿ��õĲ�������0��ˢ�³�Ʊ��Ϣ,��1������һ�ų�Ʊ��2����ѯһ�ų�Ʊ��3���޸����롾4���˳�");
	int opte;
	scanf("%d", &opte);
	switch (opte)
	{
	case 0:fresh(); show();  break;
	case 1:fresh(); ticketbuymain(num); usermain(num); break;
	case 2:fresh(); searchenginemain(num); usermain(num); break;
	case 3:fresh(); passwordchangemain(num); usermain(num); break;
	case 4:fresh(); printf("ллʹ��\n"); printf("\n");system("pause"); break;
	default:fresh(); printf("�������\n"); printf("\n");system("pause"); fresh(); usermain(num); break;

	}
}