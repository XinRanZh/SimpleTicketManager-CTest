// ConsoleApplication9.cpp: 定义控制台应用程序的入口点。
//
#pragma warning(disable:4996)
#include "stdafx.h"
#include<logincontrol.h>
#include<database.h>
#pragma warning(disable:4996)
#include<stdlib.h>
#include<windows.h>
#include<regctrl.h>

//实验性程序
BOOL WINAPI Exitbreaker(DWORD ExitK);//退出自动保存更改
									 //实验性更改
int main()
{
	userread();
	read();//开始时将数据库读到缓存
	SetConsoleCtrlHandler(Exitbreaker, TRUE);//监听退出指令
start:
	fresh();
	printf("           欢迎使用本系统。您可用操作如下【0】登陆【1】注册【2】退出                  \n");
	show();
	int opt = 9999;
	scanf("%d", &opt);
	if (opt == 0 || opt == 1 || opt == 2) {
		switch (opt)
		{
		case 0:loginconfig(); break;//进入登陆模块
		case 1:reg(); main(); break;//进入注册模块，注册完成后重载主菜单
		case 2:printf("谢谢您的使用，下次再见\n"); system("pause"); break;

		}
	}
	else {
		fresh(); printf("操作数错误请重试\n"); system("pause"); exit(0);//乱打退出
	}
	save();//在最后退出前将缓存写到数据库
	return 0;
}

BOOL WINAPI Exitbreaker(DWORD ExitK)
{
	// 控制台关闭/CTRL+C等被触发
	if (CTRL_CLOSE_EVENT == ExitK || CTRL_SHUTDOWN_EVENT == ExitK || CTRL_C_EVENT == ExitK)
	{
		save();
	}
	return TRUE;
}
