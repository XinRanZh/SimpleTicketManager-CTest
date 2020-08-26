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
	printf("请输入一个完整的目的地或到达地：\n");
	char tmp[64];
	scanf("%s", tmp);
	for (int i = 0; i < ticketcount; i++)
	{
		if (strcmp(tmp, t[i].from))
		{
			placen++;
			printf("找到第%d个符合项：编号：%d------出发地：%s\n", placen,i+1,tmp);
		}
		else if (strcmp(tmp, t[i].to))
		{
			placen++;
			printf("找到第%d个符合项：编号：%d-----到达地：%s\n", placen, i + 1, tmp);
		}
		printf("\n");system("pause");
	}
	placen = 0;
}
void searchengingtime(int num) {
	fresh();
	show();
	printf("请输入一个完整的出发时间或到达时间：\n");
	char tmp[64];
	scanf("%s", tmp);
	for (int i = 0; i < ticketcount; i++)
	{
		if (strcmp(tmp, t[i].lefttime))
		{
			timen++;
			printf("找到第%d个符合项：编号：%d------出发时间：%s\n", timen, i + 1, tmp);
		}
		else if (strcmp(tmp, t[i].arrivetime))
		{
			timen++;
			printf("找到第%d个符合项：编号：%d-----到达时间：%s\n", timen, i + 1, tmp);
		}
		printf("\n");system("pause");
	}
	timen = 0;
}
void searchenginemain(int num) {
	fresh();
	printf("欢迎使用票查找引擎");
	show();
	printf("\n您现在可用的操作：【0】刷新车票信息,【1】按出发地或目的地查找一张车票【2】按出发时间或到达时间查找一张车票【3】退出");
	int opte;
	scanf("%d", &opte);
	switch (opte){
	case 0:fresh(); show();  break;
	case 1:fresh(); searchengineplace(num); usermain(num); break;
	case 2:fresh(); searchengingtime(num); usermain(num); break;
	case 3:fresh(); printf("即将返回主界面"); printf("\n");system("pause"); fresh(); usermain(num); break;
	default:fresh(); printf("输入错误\n"); printf("\n");system("pause"); fresh(); ticketbuymain(num); break;

	}
}
void ticketbuy(int num) {
	fresh();
	show();
	printf("请输入您要购买的车票的编号:\n");
	int ticketnum;
	scanf("%d", &ticketnum);
	if (ticketnum <= ticketcount&& t[ticketnum - 1].tleft > 0) {
		printf("购买成功");
		printf("\n");system("pause");
		t[ticketnum - 1].tleft--;
	}
	else
	{
		fresh();
		show();
		printf("购买失败，输入编号错误或余票不足，请重试\n");
		printf("\n");system("pause");
		ticketbuymain(num);
	}
}
void ticketbuymain(int num) {
	fresh();
	printf("欢迎使用购票系统");
	show();
	printf("\n您现在可用的操作：【0】刷新车票信息,【1】购买一张车票【2】返回主界面");
	int opte;
	scanf("%d", &opte);
	switch (opte)
	{
	case 0:fresh(); show();  break;
	case 1:fresh(); ticketbuy(num); usermain(num); break;
	case 2:fresh(); printf("即将返回主界面"); printf("\n");system("pause"); fresh();usermain(num); break;
	default:fresh(); printf("输入错误\n"); printf("\n");system("pause"); fresh(); ticketbuymain(num); break;

	}

}
void passwordchange(int num) {
	fresh();
	printf("请输入您的原始密码");
	char pwdorgintmp[64],pwdnewtmpa[64],pwdnewtmpb[64];
	scanf("%s", pwdorgintmp);
	if (strcmp(pwdorgintmp, u[num].password)!=0) {
		printf("错误，请重试"); passwordchangemain(num);
	}
	else {
		printf("请输入新密码：\n");
		scanf("%s",pwdnewtmpa);
		printf("请再次输入新密码\n");
		scanf("%s", pwdnewtmpb);
		if (strcmp(pwdnewtmpb, pwdnewtmpa) == 0) {
			strcpy(u[num].password, pwdnewtmpa);
			printf("修改成功");
			printf("\n");system("pause");
		}
		else printf("两次密码不匹配，请重试");
		passwordchangemain(num);
	}

}
void passwordchangemain(int num) {
	fresh();
	printf("欢迎使用密码更改系统");
	printf("\n您现在可用的操作：【0】更改您的密码,【1】返回主界面");
	int opte;
	scanf("%d", &opte);
	switch (opte)
	{
	case 0:passwordchange(num); printf("即将退出，请打开并重新登陆"); printf("\n");system("pause"); break;
	case 1:fresh(); printf("即将返回主界面"); printf("\n");system("pause"); fresh(); usermain(num); break;
	default:fresh(); printf("输入错误\n"); printf("\n");system("pause"); fresh(); ticketbuymain(num); break;

	}
}
void usermain(int num) {
	fresh();
	fresh();
	show();
	printf("欢迎使用，用户:\n您现在可用的操作：【0】刷新车票信息,【1】购买一张车票【2】查询一张车票【3】修改密码【4】退出");
	int opte;
	scanf("%d", &opte);
	switch (opte)
	{
	case 0:fresh(); show();  break;
	case 1:fresh(); ticketbuymain(num); usermain(num); break;
	case 2:fresh(); searchenginemain(num); usermain(num); break;
	case 3:fresh(); passwordchangemain(num); usermain(num); break;
	case 4:fresh(); printf("谢谢使用\n"); printf("\n");system("pause"); break;
	default:fresh(); printf("输入错误\n"); printf("\n");system("pause"); fresh(); usermain(num); break;

	}
}