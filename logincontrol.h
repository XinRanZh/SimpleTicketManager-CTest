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
		printf("��ӭ��������Ա\n");
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
				printf("��ӭʹ�ã�\n");
				system("pause");
				usermain(i);
			}
		}
		else {
			printf("��½ʧ�ܣ��û������������������\n");
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
	printf("�����������û��������س�������\n");
	char username[64];

	scanf("%s", username);
	
	int usernamechk;
	usernamechk = usernamecheck(username);
	if (strcmp("admin", username)==0)
	{
		printf("��ӭ�����𾴵Ĺ���Ա�����������룺\n");
		adminloginmain(username);

	}	else if (usernamechk == 0) {
		printf("�û����ã����������룺\n");
		userloginmain(username);
		system("pause");
	}
	else {
		printf("�Բ����������������\n");
		system("pause");
		loginconfig();
	}
}