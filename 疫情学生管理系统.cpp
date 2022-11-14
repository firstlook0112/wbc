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

LinkList CreatList()//��������
{
	LinkList L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;//ͷ�ڵ���ΪNULL��
	return L;
}
LNode* CreateNode(struct Stu data)//�����½��
{
	LNode* Newnode = (LinkList)malloc(sizeof(LNode));
	Newnode->data = data;
	Newnode->next = NULL;
	return Newnode;
}
void printNOde(LinkList dqjd)//��ӡ���ҽ��
{
	printf("����\tѧ��\t��ϵ��ʽ\t ���Һ�  ��У����\t14����;����\t�Ƿ���ֹ�����\t3���ڵ����¼�¼\n");
	printf("%s    %s   %s   %d   %d��%d��%d��\t%s\t%s\tD1:%.2f D2:%.2f D3:%10.2f\n", dqjd->data.name, dqjd->data.sno, dqjd->data.tel, dqjd->data.dorm, dqjd->data.R.year, dqjd->data.R.mon, dqjd->data.R.day, dqjd->data.Tjd, dqjd->data.yimiao, dqjd->data.t[0].tiwen, dqjd->data.t[1].tiwen, dqjd->data.t[2].tiwen);
}
void PrintList(LinkList L)//��ӡ�������Ϣ
{
	LinkList p = L->next;
	printf("����\tѧ��\t\t��ϵ��ʽ\t���Һ�\t��У����\t14����;����\t�Ƿ���ֹ�����\t3���ڵ����¼�¼\n");
	while (p)//���δ�ӡ����
	{
		printf("%s\t%s\t%s\t%d\t%d��%d��%d��\t%s\t\t%s\tD1:%.2f D2:%.2f D3:%.2f\n", p->data.name, p->data.sno, p->data.tel, p->data.dorm, p->data.R.year, p->data.R.mon, p->data.R.day, p->data.Tjd, p->data.yimiao, p->data.t[0].tiwen, p->data.t[1].tiwen, p->data.t[2].tiwen);
		p = p->next;
	}
	printf("\n");
}
void Listinsert(LinkList L, struct Stu data)//l����ͷ�壺¼����Ϣ
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
void read(char* filename, LinkList L)//���ļ�
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)//���򲻿��򴴽�
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
	while (p)//���δ�ӡ����
	{
		fprintf(fp, "%s   %s   %s  %d %d��%d��%d��  %s  %s  D1:%.2f D2:%.2f D3:%.2f\n", p->data.name, p->data.sno, p->data.tel, p->data.dorm, p->data.R.year, p->data.R.mon, p->data.R.day, p->data.Tjd, p->data.yimiao, p->data.t[0].tiwen, p->data.t[1].tiwen, p->data.t[2].tiwen);
		p = p->next;
	}
	fclose(fp);
}
void DelNode(LinkList L, char* name)//��������ɾ��
{
	LNode* prior = L;//ǰ���ڵ�
	LNode* pnode = L->next;//��̽ڵ�
	if (pnode == NULL)
	{
		printf("��������ݣ��޷�ɾ��\n");
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
				printf("��������ݣ��޷�ɾ��\n");
				return;
			}
		}
		prior->next = pnode->next;
		free(pnode);
	}
}
void Menu()
{
	printf("----------���¹�����ѧ������ϵͳ��----------\n");
	printf("\t\t1.��������Ϣ��\n");
	printf("\t\t2.�������Ϣ��\n");
	printf("\t\t3.��������Ϣ��\n");
	printf("\t\t4.���޸���Ϣ��\n");
	printf("\t\t5.��ɸѡ��Ϣ��\n");
	printf("\t\t6.��ɾ����Ϣ��\n");
	printf("\t\t7.���˳�ϵͳ��\n");
	printf("--------------------------------------------\n");
	printf("�����룺");
}
void press()
{
	struct Stu ts;
	int keyboard;
	scanf("%d", &keyboard);
	switch (keyboard)
	{
	case 1:
		printf("\t\t��������Ϣ��\n");
		printf("����������,ѧ��,��ϵ��ʽ,���Һ�,��У����,14����;����,�Ƿ���ֹ�����,3���ڵ����¼�¼\n");
		scanf("%s\t%s %s\t\t%d\t%d%d%d\t%s\t%s\t%f %f %f", ts.name, ts.sno, ts.tel, &ts.dorm, &ts.R.year, &ts.R.mon, &ts.R.day, ts.Tjd, ts.yimiao, &ts.t[0].tiwen, &ts.t[1].tiwen, &ts.t[2].tiwen);
		Listinsert(list, ts);
		writ("D://shiyan4/student.dat", list);
		break;
	case 2:
		printf("\t\t�������Ϣ��\n");
		PrintList(list);
		break;
	case 3:
		printf("\t\t��������Ϣ��\n");
		printf("������Ҫ���ҵ�ѧ�ţ�");
		scanf("%s", ts.sno);
		if (GetElem(list, ts.sno) == NULL)
		{
			printf("δ�ҵ������Ϣ");
		}
		else
		{
			printNOde(GetElem(list, ts.sno));
		}
		break;
	case 4:
		printf("\t\t���޸���Ϣ��\n");
		printf("������Ҫ�޸ĵ�ѧ�ţ�");
		scanf("%s", ts.sno);
		if (GetElem(list, ts.sno) == NULL)
		{
			printf("δ�ҵ������Ϣ");
		}
		else
		{
			struct Node* s1 = GetElem(list, ts.sno);
			printf("�������µ�������ѧ�ţ���ϵ��ʽ�����Һţ���У���ڣ�14����;���أ��Ƿ���ֹ����磬3���ڵ����¼�¼");
			scanf("%s\t%s %s\t\t%d\t%d%d%d\t%s\t%s\t%f %f %f\n", s1->data.name, s1->data.sno, s1->data.tel, &s1->data.dorm, &s1->data.R.year, &s1->data.R.mon, &s1->data.R.day, s1->data.Tjd, s1->data.yimiao, &s1->data.t[0].tiwen, &s1->data.t[1].tiwen, &s1->data.t[2].tiwen);
			writ("D://shiyan4/guanzhu.dat", list);
		}
		break;
	case 5:printf("\t\t��ɸѡ��Ϣ��\n");
		printf("������;���أ�");
		scanf("%s", ts.Tjd);
		if (GetElem2(list, ts.Tjd) == NULL)
		{
			printf("δ�ҵ������Ϣ");
		}
		else
		{
			printf("���ҳ�������Ա��Ҫ�ص��ע:\n");
			struct Node* s2 = (GetElem2(list, ts.Tjd));
			struct Node* d;
			d = s2;
			printf("����\t���Һ�\n");
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
		printf("\t\t��ɾ����Ϣ��\n");
		printf("������Ҫɾ����ѧ��������");
		scanf("%s", ts.name);
		DelNode(list, ts.name);
		break;
	case 7:printf("\t\t���˳�ϵͳ��\n"); exit(0); break;
	default:printf("����������Ч��������:\n");
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
