#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node* list = NULL;
struct Rx {
	int year;
	int mon;
	int day;
};
struct tw {
	float tiwen;

};
struct Stu {
	char name[20];
	char sno[20];
	char tel[20];
	int dorm;
	char yimiao[8];
	struct Rx R;
	char Tjd[20];
	struct tw t[3];
};
typedef struct Node {
	struct Stu data;
	struct Node* next;
}*LinkList, LNode;

LinkList CreatList()//创建链表
{
	LinkList L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;//头节点置为NULL；
	return L;
}
LNode* CreateNode(struct Stu data)//创建新结点
{
	LNode* Newnode = (LinkList)malloc(sizeof(LNode));
	Newnode->data = data;
	Newnode->next = NULL;
	return Newnode;
}
void printNOde(LinkList dqjd)//打印查找结点
{
	printf("姓名\t学号\t联系方式\t 寝室号  入校日期\t14日内途径地\t是否接种过疫苗\t3日内的体温记录\n");
	printf("%s    %s   %s   %d   %d年%d月%d日\t%s\t%s\tD1:%.2f D2:%.2f D3:%10.2f\n", dqjd->data.name, dqjd->data.sno, dqjd->data.tel, dqjd->data.dorm, dqjd->data.R.year, dqjd->data.R.mon, dqjd->data.R.day, dqjd->data.Tjd, dqjd->data.yimiao, dqjd->data.t[0].tiwen, dqjd->data.t[1].tiwen, dqjd->data.t[2].tiwen);
}
void PrintList(LinkList L)//打印：浏览信息
{
	LinkList p = L->next;
	printf("姓名\t学号\t\t联系方式\t寝室号\t入校日期\t14日内途径地\t是否接种过疫苗\t3日内的体温记录\n");
	while (p)//依次打印数据
	{
		printf("%s\t%s\t%s\t%d\t%d年%d月%d日\t%s\t\t%s\tD1:%.2f D2:%.2f D3:%.2f\n", p->data.name, p->data.sno, p->data.tel, p->data.dorm, p->data.R.year, p->data.R.mon, p->data.R.day, p->data.Tjd, p->data.yimiao, p->data.t[0].tiwen, p->data.t[1].tiwen, p->data.t[2].tiwen);
		p = p->next;
	}
	printf("\n");
}
void Listinsert(LinkList L, struct Stu data)//l链表头插：录入信息
{
	LNode* s = CreateNode(data);
	s->next = L->next;
	L->next = s;
}
LNode* GetElem(LinkList L, char* sno)
{
	LNode* p = L->next;
	if (p == NULL)
	{
		return p;
	}
	else
	{
		while (strcmp(p->data.sno, sno))
		{
			p = p->next;
			if (p == NULL) break;
		}
		return p;
	}
}
LNode* GetElem2(LinkList L, char* tjd)
{
	LNode* p = L->next;
	if (p == NULL)
	{
		return p;
	}
	else
	{
		while (strcmp(p->data.Tjd, tjd))
		{
			p = p->next;
			if (p == NULL) break;
		}
		return p;
	}
}
void read(char* filename, LinkList L)//读文件
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)//若打不开则创建
	{
		fp = fopen(filename, "w");
	}
	struct Stu tempdata;
	while (fscanf(fp, "%s\t%s %s\t\t%d\t%d%d%d\t%s\t%s\t%f %f %f", tempdata.name, tempdata.sno, tempdata.tel, &tempdata.dorm, &tempdata.R.year, &tempdata.R.mon, &tempdata.R.day, tempdata.Tjd, tempdata.yimiao, &tempdata.t[0].tiwen, &tempdata.t[1].tiwen, &tempdata.t[2].tiwen) != EOF)
	{
		Listinsert(L, tempdata);
		memset(&tempdata, 0, sizeof(tempdata));
	}
	fclose(fp);
}
void writ(char* filename, LinkList L)
{
	FILE* fp = fopen(filename, "w");
	LinkList p = L->next;
	while (p)//依次打印数据
	{
		fprintf(fp, "%s   %s   %s  %d %d年%d月%d日  %s  %s  D1:%.2f D2:%.2f D3:%.2f\n", p->data.name, p->data.sno, p->data.tel, p->data.dorm, p->data.R.year, p->data.R.mon, p->data.R.day, p->data.Tjd, p->data.yimiao, p->data.t[0].tiwen, p->data.t[1].tiwen, p->data.t[2].tiwen);
		p = p->next;
	}
	fclose(fp);
}
void DelNode(LinkList L, char* name)//根据姓名删除
{
	LNode* prior = L;//前驱节点
	LNode* pnode = L->next;//后继节点
	if (pnode == NULL)
	{
		printf("无相关内容，无法删除\n");
		return;
	}
	else
	{
		while (strcmp(pnode->data.name, name))
		{
			prior = pnode;
			pnode = prior->next;
			if (pnode == NULL)
			{
				printf("无相关内容，无法删除\n");
				return;
			}
		}
		prior->next = pnode->next;
		free(pnode);
	}
}
void Menu()
{
	printf("----------【新冠疫情学生管理系统】----------\n");
	printf("\t\t1.【插入信息】\n");
	printf("\t\t2.【浏览信息】\n");
	printf("\t\t3.【查找信息】\n");
	printf("\t\t4.【修改信息】\n");
	printf("\t\t5.【筛选信息】\n");
	printf("\t\t6.【删除信息】\n");
	printf("\t\t7.【退出系统】\n");
	printf("--------------------------------------------\n");
	printf("请输入：");
}
void press()
{
	struct Stu ts;
	int keyboard;
	scanf("%d", &keyboard);
	switch (keyboard)
	{
	case 1:
		printf("\t\t【插入信息】\n");
		printf("请输入姓名,学号,联系方式,寝室号,入校日期,14日内途径地,是否接种过疫苗,3日内的体温记录\n");
		scanf("%s\t%s %s\t\t%d\t%d%d%d\t%s\t%s\t%f %f %f", ts.name, ts.sno, ts.tel, &ts.dorm, &ts.R.year, &ts.R.mon, &ts.R.day, ts.Tjd, ts.yimiao, &ts.t[0].tiwen, &ts.t[1].tiwen, &ts.t[2].tiwen);
		Listinsert(list, ts);
		writ("D://shiyan4/student.dat", list);
		break;
	case 2:
		printf("\t\t【浏览信息】\n");
		PrintList(list);
		break;
	case 3:
		printf("\t\t【查找信息】\n");
		printf("请输入要查找的学号：");
		scanf("%s", ts.sno);
		if (GetElem(list, ts.sno) == NULL)
		{
			printf("未找到相关信息");
		}
		else
		{
			printNOde(GetElem(list, ts.sno));
		}
		break;
	case 4:
		printf("\t\t【修改信息】\n");
		printf("请输入要修改的学号：");
		scanf("%s", ts.sno);
		if (GetElem(list, ts.sno) == NULL)
		{
			printf("未找到相关信息");
		}
		else
		{
			struct Node* s1 = GetElem(list, ts.sno);
			printf("请输入新的姓名，学号，联系方式，寝室号，入校日期，14日内途径地，是否接种过疫苗，3日内的体温记录");
			scanf("%s\t%s %s\t\t%d\t%d%d%d\t%s\t%s\t%f %f %f\n", s1->data.name, s1->data.sno, s1->data.tel, &s1->data.dorm, &s1->data.R.year, &s1->data.R.mon, &s1->data.R.day, s1->data.Tjd, s1->data.yimiao, &s1->data.t[0].tiwen, &s1->data.t[1].tiwen, &s1->data.t[2].tiwen);
			writ("D://shiyan4/guanzhu.dat", list);
		}
		break;
	case 5:printf("\t\t【筛选信息】\n");
		printf("请输入途径地：");
		scanf("%s", ts.Tjd);
		if (GetElem2(list, ts.Tjd) == NULL)
		{
			printf("未找到相关信息");
		}
		else
		{
			printf("查找出以下人员需要重点关注:\n");
			struct Node* s2 = (GetElem2(list, ts.Tjd));
			struct Node* d;
			d = s2;
			printf("姓名\t寝室号\n");
			while (d != NULL)
			{

				if (d->data.dorm == d->data.dorm)
				{
					printf("%s,%d\n", d->data.name, d->data.dorm);
				}
				d = d->next;
			}
			writ("D://shiyan4/guanzhu.dat", list);
		}
		break;
	case 6:
		printf("\t\t【删除信息】\n");
		printf("请输入要删除的学生姓名：");
		scanf("%s", ts.name);
		DelNode(list, ts.name);
		break;
	case 7:printf("\t\t【退出系统】\n"); exit(0); break;
	default:printf("输入内容无效，请重试:\n");
	}
}


int main()
{
	list = CreatList();
	read("D://shiyan4/jichu.dat", list);
	while (1)
	{
		Menu();
		press();
		system("pause");
		system("cls");
	}
	return 0;
}
