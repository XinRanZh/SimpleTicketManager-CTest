#pragma once
#include<string.h>
#include<management.h>
#include<database.h>
#include<usermain.h>
void loginconfig();
void adminloginmain(char username[64])
{
	char password[64];
	scanf("%s", password);
	if (strcmp(password, "admin") == 0) {
		printf("欢迎您，管理员\n");
		system("pause");
		managewelcome();
	}
}
void userloginmain(char username[64])
{
	char password[64];
	scanf("%s", password);
	for (int i = 0; i < usercount; i++)
	{
		if (strcmp(username, u[i].username)==0) {
			if (strcmp(password, u[i].password)==0) {
				printf("欢迎使用：\n");
				system("pause");
				usermain(i);
			}
		}
		else {
			printf("登陆失败：用户名或密码错误，请重试\n");
			system("pause");
			loginconfig();
		}
	}
}
int usernamecheck(char username[64])
{
	for (int i = 0; i < usercount; i++)
	{
		if (strcmp(username, u[i].username)==0) {
			return 0;
		}
		else return 77777;
	}
}

void loginconfig() {
	fresh();
	printf("请输入您的用户名，按回车结束：\n");
	char username[64];

	scanf("%s", username);
	
	int usernamechk;
	usernamechk = usernamecheck(username);
	if (strcmp("admin", username)==0)
	{
		printf("欢迎您，尊敬的管理员，请输入密码：\n");
		adminloginmain(username);

	}	else if (usernamechk == 0) {
		printf("用户您好，请输入密码：\n");
		userloginmain(username);
		system("pause");
	}
	else {
		printf("对不起，输入错误，请重试\n");
		system("pause");
		loginconfig();
	}
}