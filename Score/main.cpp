#include "seqlist.h"
int main()
{
	while (1)
	{
		switch (menu_select())
		{
		case 1:
			t_output();
			break;
		case 2:
			s_output();
			break;
		case 3:
			//mark();
			break;
		case 4:
			//show();
			break;
		case 0:
			//save();
			printf("Thank you for using！\n");
			system("pause");
			return 0;
		}
	}
}
//菜单模块
extern int menu_select()
{
	int MenuItem;
	printf("\n ");
	printf("         | ***********打分系统*********** |          \n");
	printf("          | ------------------------------ |          \n");
	printf("          |            主菜单项            |          \n");
	printf("          | ------------------------------ |          \n");
	printf("          |	  1 --- 显示裁判信息       |          \n");
	printf("          |	  2 --- 显示选手信息	   |          \n");
	printf("          |	  3 --- 裁判打分环节	   |          \n");
	printf("          |	  4 --- 显示参赛成绩	   |          \n");
	printf("          |	  0 --- 退出系统  	   |          \n");
	do
	{
		printf("\n请输入选项（0－4）：");
		fflush(stdin);
		scanf("%d", &MenuItem);
	} while (MenuItem<0 || MenuItem>4);
	return MenuItem;
}
//裁判信息输出模块
extern void t_output()
{
	FILE *fp;
	int i;
	fp = fopen("teacher.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败！\n");
		exit(-1);
	}
	else
	{
		printf("姓名 性别 电话号码\n");
		for (i = 0; i < 5; i++)
			fscanf(fp,"%s %s %ld\n", &t[i].name, &t[i].sex, &t[i].num);
		for (i = 0; i < 5; i++)
			printf("%2s %3s %8ld\n", t[i].name, t[i].sex, t[i].num);
	}
	fclose(fp);
}
//选手信息输出模块
extern void s_output()
{
	FILE *fp;
	int i;
	fp = fopen("student.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败！\n");
		exit(-1);
	}
	else
	{
		printf("序号 姓名   性别  节目名称  节目类别   班级    电话号码\n");
		for (i = 0; i < 6; i++)
			fscanf(fp, "%d %s %s %s %s %s %ld\n", & s[i].snum, &s[i].name, &s[i].sex, &s[i].showname, &s[i].showtype, &s[i].stuclass, &s[i].num);
		for (i = 0; i < 6; i++)
			printf("%3d %6s %4s %9s %8s %10s %9ld\n", s[i].snum, s[i].name, s[i].sex, s[i].showname, s[i].showtype, s[i].stuclass, s[i].num);
	}
	fclose(fp);
}

