#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
	srand(time(NULL));
	int n1, n2, n3, sum = 0, result, N, smallnum, max_num, ifkuohao, i, flag = 1;
	char opt1, opt2;
	float num1=0, num2=0, num3=0;

	printf("\t------�������������ɵ���Ŀ������------\n");
	scanf("%d", &N);
	printf("\t------���������Ƿ���С��:(1:�ǣ�0:��)��------\n");
	scanf("%d", &smallnum);
	printf("\t-------�������������ֵ���ޡ�-------\n");
	scanf("%d", &max_num);
	printf("\t-------���Ƿ����С����:(1:�ǣ�0:��)��-------\n");
	scanf("%d", &ifkuohao);
	printf("\n\t\t--------����Ŀ�б�-------\n");
	srand(time(NULL));
	FILE* fp = fopen("D://test.txt", "w+");
	if (!smallnum && !ifkuohao)
	{
		for (i = 0; i < N; i++)
		{
			n1 = (rand() % 100) * max_num / 100;
			n2 = (rand() % 100) * max_num / 100;
			n3 = (rand() % 100) * max_num / 100;
			switch (n1 % 4)
			{
			case 0:opt1 = '+'; break;
			case 1:opt1 = '-'; break;
			case 2:opt1 = '*'; break;
			case 3:opt1 = '/'; break;
			default:break;
			}
			switch (n2 % 4)
			{
			case 0:opt2 = '+'; break;
			case 1:opt2 = '-'; break;
			case 2:opt2 = '*'; break;
			case 3:opt2 = '/'; break;
			}
			if (sum % 3 == 0)
			{
				printf("\n------------------------------------------------------------------------------------------------------\n");
				fprintf(fp, "\n");
			}
			sum++;
			printf("(%d) %d %c %d %c %d=_?_\t", i + 1, n1, opt1, n2, opt2, n3);
			fprintf(fp, "(%d) %d %c %d %c %d=_?_\t", i + 1, n1, opt1, n2, opt2, n3);
		}
	}
	else if (smallnum && ifkuohao)
	{

		for (i = 0; i < N; i++)
		{
			num1 = (float)(rand() % 100) * max_num / 100;
			num2 = (float)(rand() % 100) * max_num / 100;
			num3 = (float)(rand() % 100) * max_num / 100;
			switch (int(num1) % 4)
			{
			case 0:opt1 = '+'; break;
			case 1:opt1 = '-'; break;
			case 2:opt1 = '*'; break;
			case 3:opt1 = '/'; break;
			default:break;
			}
			switch (int(num2) % 4)
			{
			case 0:opt2 = '+'; break;
			case 1:opt2 = '-'; break;
			case 2:opt2 = '*'; break;
			case 3:opt2 = '/'; break;
			}
			if (sum % 3 == 0) {
				printf("\n------------------------------------------------------------------------------------------------------\n");
				fprintf(fp, "\n");
			}
			sum++;
			if (flag==1)
			{
				flag = 0;
				printf("(%d) %.2f %c (%.2f %c %.2f)=_?_\t", i + 1, num1, opt1, num2, opt2, num3);
				fprintf(fp, "(%d) %.2f %c (%.2f %c %.2f)=_?_\t", i + 1, num1, opt1, num2, opt2, num3);

			}
			else if(flag==0)
			{
				flag = 1;
				printf("(%d) (%.2f %c %.2f) %c %.2f=_?_\t", i + 1, num1, opt1, num2, opt2, num3);
				fprintf(fp, "(%d) (%.2f %c %.2f) %c %.2f=_?_\t", i + 1, num1, opt1, num2, opt2, num3);

			}
		}
	}
	else if (smallnum && !ifkuohao)
	{
		for (i = 0; i < N; i++)
		{
			num1 = (float)(rand() % 100) * max_num / 100;
			num2 = (float)(rand() % 100) * max_num / 100;
			num3 = (float)(rand() % 100) * max_num / 100;
			switch (int(num1) % 4)
			{
			case 0:opt1 = '+'; break;
			case 1:opt1 = '-'; break;
			case 2:opt1 = '*'; break;
			case 3:opt1 = '/'; break;
			default:break;
			}
			switch (int(num2) % 4)
			{
			case 0:opt2 = '+'; break;
			case 1:opt2 = '-'; break;
			case 2:opt2 = '*'; break;
			case 3:opt2 = '/'; break;//Ҫɾ��flag���������Ҫ�����Ļ�
			}
			if (sum % 3 == 0) {
				printf("\n------------------------------------------------------------------------------------------------------\n");
				fprintf(fp, "\n");
			}
			sum++;
			printf("(%d) %.2f %c %.2f %c %.2f=_?_\t", i + 1, num1, opt1, num2, opt2, num3);
			fprintf(fp, "(%d) %.2f %c %.2f %c %.2f=_?_\t", i + 1, num1, opt1, num2, opt2, num3);
		}
	}
	else if (!smallnum && ifkuohao)
	{
		flag = 1;
		for (i = 0; i < N; i++)
		{
			n1 = (rand() % 100) * max_num / 100;
			n2 = (rand() % 100) * max_num / 100;
			n3 = (rand() % 100) * max_num / 100;
			switch (n1 % 4)
			{
			case 0:opt1 = '+'; break;
			case 1:opt1 = '-'; break;
			case 2:opt1 = '*'; break;
			case 3:opt1 = '/'; break;
			default:break;
			}
			switch (n2 % 4)
			{
			case 0:opt2 = '+'; break;
			case 1:opt2 = '-'; break;
			case 2:opt2 = '*'; break;
			case 3:opt2 = '/'; break;
			}
			if (sum % 3 == 0) {
				printf("\n------------------------------------------------------------------------------------------------------\n");
				fprintf(fp, "\n");
			}
			sum++;
			if (flag == 1)
			{
				printf("(%d) (%d %c %.d) %c %d=_?_\t", i + 1, n1, opt1, n2, opt2, n3);
				fprintf(fp, "(%d) (%d %c %d) %c %d=_?_\t",  i + 1, n1, opt1, n2, opt2, n3);
				flag = 0;
			}
			else if (flag == 0)
			{
				printf("(%d) %d %c (%d %c %d)=_?_\t", i + 1, n1, opt1, n2, opt2, n3);
				fprintf(fp, "(%d) %d %c (%d %c %d)=_?_\t",  i + 1, n1, opt1, n2, opt2, n3);
				flag = 1;
			}
		}
	}
	fclose(fp);

	return 0;
}

