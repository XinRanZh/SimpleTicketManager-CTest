#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<logincontrol.h>
void reg()
{
	fresh();
	printf("欢迎注册：\n请输入一个用户名\n");
	char username[64];
	scanf("%s", username);
	int chk = usernamecheck(username);
	char pwdtmpa[64];
	char pwdtmpb[64];

	if (chk == 77777&&strcmp(username,"admin")!=0)
	{
		printf("请输入密码\n");
		scanf("%s", pwdtmpa);
		printf("请再次输入密码\n");
		scanf("%s", pwdtmpb);
		if (strcmp(pwdtmpa, pwdtmpb) == 0)
		{
			writeuser(usercount, username, pwdtmpa);
			printf("注册成功,即将返回主菜单\n");
			system("pause");
		}else {
			printf("两次输入结果不一致，请重试"); 
			system("pause");
			reg();
		}
	}
	else printf("用户已经存在\n"); system("pause");
}