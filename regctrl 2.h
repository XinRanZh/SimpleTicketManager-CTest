#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<logincontrol.h>
void reg()
{
	fresh();
	printf("��ӭע�᣺\n������һ���û���\n");
	char username[64];
	scanf("%s", username);
	int chk = usernamecheck(username);
	char pwdtmpa[64];
	char pwdtmpb[64];

	if (chk == 77777&&strcmp(username,"admin")!=0)
	{
		printf("����������\n");
		scanf("%s", pwdtmpa);
		printf("���ٴ���������\n");
		scanf("%s", pwdtmpb);
		if (strcmp(pwdtmpa, pwdtmpb) == 0)
		{
			writeuser(usercount, username, pwdtmpa);
			printf("ע��ɹ�,�����������˵�\n");
			system("pause");
		}else {
			printf("������������һ�£�������"); 
			system("pause");
			reg();
		}
	}
	else printf("�û��Ѿ�����\n"); system("pause");
}