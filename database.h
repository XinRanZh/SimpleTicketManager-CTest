#pragma warning(disable:4996)
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <malloc.h>
struct ticketlist
{
	char from[20];//始发
	char to[20];//到达
	char lefttime[20];//出发时间
	char arrivetime[20];//到达时间
	int price;//价格
	int tleft;//剩余票数
};
struct userlist
{
	char username[64];
	char password[64];
};
struct userlist u[64];
struct ticketlist t[128];
void writeuser(int num, char username[64], char password[64]) {
	strcpy(u[num].username, username);
	strcpy(u[num].password, password);
}
void writetlist(int num, char from[20], char to[20], char lefttime[20], char arrivetime[20], int price, int tleft)/*写入结构体*/ {
	strcpy_s(t[num].from, from);
	strcpy_s(t[num].to, to);
	strcpy_s(t[num].lefttime, lefttime);
	strcpy_s(t[num].arrivetime, arrivetime);
	t[num].price = price;
	t[num].tleft = tleft;
}
char *ReadData(FILE *fp, char *buf)
{
	return fgets(buf, 1024, fp);//读取一行到buf
}
int ticketcount=0;
int usercount=0;
void show() {
	printf_s("当前车票信息如下：共有%d张\n", ticketcount);
	for (int i = 0; i < ticketcount; i++) {
		printf_s("车票编号：%d    出发地：%s    到达地：%s    出发时间：%s    到达时间：%s    价格：%d     剩余票数:%d\n", i + 1, t[i].from, t[i].to, t[i].lefttime, t[i].arrivetime, t[i].price, t[i].tleft);
	}
}
void read() {
	FILE *fnum;
	char *num, *pnum;
	FILE *ffrom;
	char *from, *pfrom;
	FILE *fto;
	char *to, *pto;
	FILE *flefttime;
	char *lefttime, *plefttime;
	FILE *farrivetime;
	char *arrivetime, *parrivetime;
	FILE *fprice;
	char *price, *pprice;
	FILE *ftleft;
	char *tleft, *ptleft;
	fnum = fopen("num.txt", "r");
	ffrom = fopen("from.txt", "r");
	fto = fopen("to.txt", "r");
	flefttime = fopen("lefttime.txt", "r");
	farrivetime = fopen("arrivetime.txt", "r");
	fprice = fopen("price.txt", "r");
	ftleft = fopen("tleft.txt", "r");


	num = (char*)malloc(1024 * sizeof(char));
	from = (char*)malloc(1024 * sizeof(char));
	to = (char*)malloc(1024 * sizeof(char));
	lefttime = (char*)malloc(1024 * sizeof(char));
	arrivetime = (char*)malloc(1024 * sizeof(char));
	price = (char*)malloc(1024 * sizeof(char));
	tleft = (char*)malloc(1024 * sizeof(char));
	while (1) {
		pnum = ReadData(fnum, num);//每次调用文件指针fp会自动后移一行
		if (!pnum)//文件读取结束则跳出循环
		{
			break;
		}
		else ticketcount++;
	}

	for (int i = 0; i < ticketcount; i++) {
		pfrom = ReadData(ffrom, from);
		pfrom[strlen(pfrom) - 1] = '\0';
		pto = ReadData(fto, to);
		pto[strlen(pto) - 1] = '\0';
		plefttime = ReadData(flefttime, lefttime);
		plefttime[strlen(plefttime) - 1] = '\0';
		parrivetime = ReadData(farrivetime, arrivetime);
		parrivetime[strlen(parrivetime) - 1] = '\0';
		pprice = ReadData(fprice, price);
		ptleft = ReadData(ftleft, tleft);
		writetlist(i, pfrom, pto, plefttime, parrivetime, atoi(pprice), atoi(ptleft));
	}
}
void userread() {
	FILE *fusernum;
	char *usernum, *pusernum;
	FILE *fusername;
	char *username, *pusername;
	FILE *fpassword;
	char *password, *ppassword;

	fusernum = fopen("usernum.txt", "r");
	fusername = fopen("username.txt", "r");
	fpassword = fopen("password.txt", "r");

	usernum = (char*)malloc(1024 * sizeof(char));
	username = (char*)malloc(1024 * sizeof(char));
	password = (char*)malloc(1024 * sizeof(char));

	while (1) {
		pusernum = ReadData(fusernum, usernum);//每次调用文件指针fp会自动后移一行
		if (!pusernum)//文件读取结束则跳出循环
		{
			break;
		}
		else usercount++;
	}

	for (int i = 0; i < usercount; i++) {
		pusername = ReadData(fusername, username);
		pusername[strlen(pusername) - 1] = '\0';
		ppassword = ReadData(fpassword, password);
		ppassword[strlen(ppassword) - 1] = '\0';
		writeuser(i, pusername, ppassword);
	}
}

void save() {
	FILE *num;
	FILE *ffrom;
	FILE *fto;
	FILE *flefttime;
	FILE *farrivetime;
	FILE *fprice;
	FILE *ftleft;

	FILE *fusernum;
	FILE *fusername;
	FILE *fpassword;


	num = fopen("num.txt", "w");
	ffrom = fopen("from.txt", "w");
	fto = fopen("to.txt", "w");
	flefttime = fopen("lefttime.txt", "w");
	farrivetime = fopen("arrivetime.txt", "w");
	fprice = fopen("price.txt", "w");
	ftleft = fopen("tleft.txt", "w");

	fusernum = fopen("usernum.txt", "w");
	fusername = fopen("username.txt", "w");
	fpassword = fopen("password.txt", "w");


	for (int i = 0; i < ticketcount; i++)
	{
		char tmp[20];
		itoa(i+1,tmp,10);
		fputs(tmp, num);
		fputs("\n", num);
		fputs(t[i].from, ffrom);
		fputs("\n", ffrom);
		fputs(t[i].to, fto);
		fputs("\n", fto);
		fputs(t[i].lefttime, flefttime);
		fputs("\n", flefttime);
		fputs(t[i].arrivetime, farrivetime);
		fputs("\n", farrivetime);
		itoa(t[i].price, tmp, 10);
		fputs(tmp, fprice);
		fputs("\n", fprice);
		itoa(t[i].tleft, tmp, 10);
		fputs(tmp, ftleft);
		fputs("\n", ftleft);
	}

	for (int i = 0; i < usercount; i++)
	{
		char tmp[64];
		itoa(i + 1, tmp, 10);
		fputs(tmp, fusernum);
		fputs("\n", fusernum);
		fputs(u[i].username, fusername);
		fputs("\n", fusername);
		fputs(u[i].password, fpassword);
		fputs("\n", fpassword);
	}


	fclose(num);
	fclose(ffrom);
	fclose(fto);
	fclose(flefttime);
    fclose(farrivetime);
	fclose(fprice);
	fclose(ftleft);

	fclose(fusernum);
	fclose(fusername);
	fclose(fpassword);
}