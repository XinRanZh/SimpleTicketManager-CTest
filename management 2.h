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
	printf("=                   欢迎使用张昕冉牌火车票管理系统                    =\n");
	printf("=                                                                     =\n");
	printf("=======================================================================\n");
}
void managewelcome();
void ticketeditmain()
{
	fresh();
	printf("欢迎使用车票信息修改系统:\n您现在可用的操作：【0】刷新车票信息,【1】修改车票信息【2】返回管理后台首页");
	int opte;
	scanf("%d", &opte);
	switch (opte)
	{
	case 0:fresh(); show(); ticketeditmain(); break;
	case 1:ticketedit();
	case 2:fresh();; managewelcome(); break;
	default:printf("失败：输入了错误的功能编号"); system("pause"); ticketeditmain(); break;
	}
}
void ticketedit()
{
	fresh();
	show();
	printf("\n请输入你需要修改的车票编号：\n");
	int editnum = 0;
	scanf("%d", &editnum);
	if (editnum > ticketcount)
	{
		printf("失败，查无此车\n");
		system("pause");
	}
	else {
	start:
		printf("你要修改的内容是【0】修改完成，退出【1】出发地【2】目的地【3】出发时间【4】到达时间【5】价格【6】余票\n");
		int opnumb = 999;
		scanf("%d", &opnumb);
		char tmp[128];
		int tmpint;
		switch (opnumb)
		{
		case 0:system("clr"); ticketeditmain(); break;
		case 1:printf("更改前的数据是:%s\n输入更改后的数据:\n", t[editnum - 1].from); scanf("%s", tmp); strcpy(t[editnum - 1].from, tmp); goto start; break;
		case 2:printf("更改前的数据是:%s\n输入更改后的数据:\n", t[editnum - 1].to); scanf("%s", tmp); strcpy(t[editnum - 1].to, tmp); goto start; break;
		case 3:printf("更改前的数据是:%s\n输入更改后的数据:\n", t[editnum - 1].lefttime); scanf("%s", tmp); strcpy(t[editnum - 1].lefttime, tmp); goto start; break;
		case 4:printf("更改前的数据是:%s\n输入更改后的数据:\n", t[editnum - 1].arrivetime); scanf("%s", tmp); strcpy(t[editnum - 1].arrivetime, tmp); goto start; break;
		case 5:printf("更改前的数据是:%d\n输入更改后的数据:\n", t[editnum - 1].price); scanf("%d", &tmpint); t[editnum - 1].price = tmpint; goto start; break;
		case 6:printf("更改前的数据是:%d\n输入更改后的数据:\n", t[editnum - 1].tleft); scanf("%d", &tmpint); t[editnum - 1].tleft = tmpint; goto start; break;
		default:printf("错误的输入"); goto start; break;
		}

	}
}
void ticketaddmain();
void ticketadd()
{
	fresh();
	printf("\n这是目前已经有的车票：\n");
	show();
	printf("\n您新增的票编号为%d\n", ticketcount + 1);
	char tmp[64];
	int tmpint = 0;
	printf("请输入始发地");
	scanf("%s", tmp);
	strcpy(t[ticketcount].from, tmp);
	printf("请输入目的地");
	scanf("%s", tmp);
	strcpy(t[ticketcount].to, tmp);
	printf("请输入出发时刻");
	scanf("%s", tmp);
	strcpy(t[ticketcount].lefttime, tmp);
	printf("请输入到达时刻");
	scanf("%s", tmp);
	strcpy(t[ticketcount].arrivetime, tmp);
	printf("请输入价格");
	scanf("%d", &tmpint);
	t[ticketcount].price = tmpint; tmpint = 0;
	printf("请输入剩余票数");
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
	printf("欢迎使用车票种类增加系统:\n您现在可用的操作：【0】刷新车票信息,【1】增加车票种类【2】返回管理后台首页");
	int opte;
	scanf("%d", &opte);
	switch (opte)
	{
	case 0: show(); goto start; break;
	case 1:ticketadd();
	case 2:fresh();; managewelcome(); break;
	default:printf("失败：输入了错误的功能编号"); system("pause"); ticketeditmain(); break;
	}
}
void ticketdeletemain();
void ticketdel() {
	fresh();
	printf("\n这是目前已经有的车票：\n");
	show();
	printf("请输入您要删除的车票编号：\n");
	int opte = 0;
	scanf("%d", &opte);
	if (opte == 0 || opte < 0 || opte > ticketcount)
	{
		printf("错误，您输入了一个错误的编号");
	}
	else {
		printf("您确认要这么做么？\n输入小写yes确认");
		char confirm[64];
		scanf("%s", confirm);
		if (strcmp(confirm, "yes") == 0)
		{
			ticketcount--;//删掉最后一个编号
			for (int i = opte - 1; i < ticketcount - 1; i++)//判断是不是操作完成了
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
	printf("欢迎使用车票种类删除系统:\n您现在可用的操作：【0】刷新车票信息,【1】删除一张车票【2】返回管理后台首页");
	int opte;
	scanf("%d", &opte);
	switch (opte)
	{
	case 0:fresh();; show(); goto start; break;
	case 1:ticketdel(); break;
	case 2:fresh();; managewelcome(); break;
	default:printf("失败：输入了错误的功能编号"); system("pause"); goto start; break;
	}
}
void managewelcome() {
	fresh();
	show();
	printf("欢迎登陆管理后台:\n您现在可用的操作：【0】刷新车票信息,【1】车票种类增加系统【2】车票种类删除系统【3】车票修改系统【4】退出");
	int opte;
	scanf("%d", &opte);
	switch (opte)
	{
	case 0:fresh();show();  break;
	case 1:fresh(); ticketaddmain(); managewelcome(); break;
	case 2:fresh();ticketdeletemain(); managewelcome(); break;
	case 3:fresh(); ticketeditmain(); managewelcome(); break;
	case 4:fresh(); printf("谢谢使用"); system("pause"); break;
	default:fresh(); printf("输入错误\n"); system("pause"); fresh();managewelcome(); break;

	}
}