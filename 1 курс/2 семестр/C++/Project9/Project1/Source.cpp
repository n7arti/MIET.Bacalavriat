#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>
#include <locale.h>


typedef struct supplier
{
	int section;
	char* name;
	double price;
	int quant;
}
supplier;

int addproduct(supplier* prod, int number)
{

	bool repit = false;
	char buff[50];
	int x, num, quant;
	double price;
	system("cls");
	printf("����� ������: ");
	x = scanf("%d", &num);
	getchar();
	printf("�������� ������: ");
	fgets(buff, 50, stdin);
	buff[strlen(buff) - 1] = '\0';
	printf("����: ");
	x = scanf("%lf", &price);
	printf("����������: ");
	x = scanf("%d", &quant);
	for (int i = 0; i < number; i++)
		if (strcmp(prod[i].name, buff) == 0)
		{
			prod[i].quant += quant;
			repit = true;
		}
	if (!repit)
	{
		number++;
		prod[number - 1].section = num;
		prod[number - 1].name = (char*)calloc(strlen(buff) + 1, sizeof(char));
		strcpy(prod[number - 1].name, buff);
		prod[number - 1].price = price;
		prod[number - 1].quant = quant;
		repit = false;
	}
	return number;
}

void secprod(supplier* prod, int number, int sec)
{

	int** temp_array, a;
	char** text;
	int count = 0;
	for (int i = 0; i < number; i++)
		if (prod[i].section == sec) count++;
	if (count > 0)
	{
		text = (char**)calloc(count, sizeof(char*));
		for (int i = 0, k = 0; i < number; i++)
			if (prod[i].section == sec)
			{
				text[k] = (char*)calloc(strlen(prod[i].name) + 1, sizeof(char));
				strcpy(text[k], prod[i].name); k++;
			}
		temp_array = (int**)calloc(2, sizeof(int*));
		for (int i = 0; i < 2; i++)
			temp_array[i] = (int*)calloc(count, sizeof(int));
		for (int i = 0; i < count; i++)
		{
			temp_array[0][i] = i;
			temp_array[1][i] = text[i][0];
		}
		for (int i = 0; i < count; i++)
			for (int j = 0; j < count; j++)
				if (j + 1 != count && temp_array[1][j] > temp_array[1][j + 1])
				{
					a = temp_array[1][j];
					temp_array[1][j] = temp_array[1][j + 1];
					temp_array[1][j + 1] = a;
					a = temp_array[0][j];
					temp_array[0][j] = temp_array[0][j + 1];
					temp_array[0][j + 1] = a;
				}
		printf("������ � ������  %d : ", sec);
		for (int i = 0; i < count; i++)
		{
			a = temp_array[0][i];
			if (i == 0) printf("%s", text[a]);
			else printf(", %s", text[a]);
		}
		printf(".\n");
		for (int i = 0; i < 2; i++)
			free(temp_array[i]);
		free(temp_array);
		for (int i = 0; i < count; i++)
			free(text[i]);
		free(text);
	}
	else printf("����� ������ �� ����������\n");
}

int main()
{
	setlocale(LC_ALL, "rus");
	char buff[50];
	int n, x, func, number = 0;
	bool b = false;
	printf("������� ���������� �������: ");
	x = scanf("%d", &n);
	supplier* sklad = (supplier*)calloc(n, sizeof(supplier));
	while (!b)
	{
		system("cls");
		printf("�������� �����..................................................1\n");
		printf("����������� ���������� � ������ ................................2\n");
		printf("����� ��� ������ �������� ������................................3\n");
		printf("���������� ������ � ����������� ������ ���������................4\n");
		printf("����������� ���������� � ���� �������...........................5\n");
		printf("�����...........................................................6\n");
		printf("������� ����� �������: ");
		x = scanf("%d", &func);
		switch (func)
		{
		case 1:
		{
			if (number < n) number = addproduct(sklad, number);
			else
			{
				system("cls");
				printf("�� �������� �������� ���������\n");
				system("pause");
			}
			break;
		}
		case 2:
		{
			system("cls");
			int isexist = -1;
			printf("������� �������� ������:\n ");
			getchar();
			fgets(buff, 50, stdin);
			buff[strlen(buff) - 1] = '\0';
			for (int i = 0; i < number; i++)
				if (strcmp(buff, sklad[i].name) == 0) isexist = i;
			if (isexist != -1)
			{
				system("cls");
				printf("������:\t ��������: \t ����:\t ����������:\n");
				printf("---------------------------------------------------\n");
				printf("\%d\t\t%s\t%lf\t%d\n", sklad[isexist].section, sklad[isexist].name, sklad[isexist].price, sklad[isexist].quant);
				printf("---------------------------------------------------\n");
			}
			else printf("������� � ����� ��������� �� ����������\n");
			system("pause");
			break;
		}
		case 3:
		{
			int sec;
			system("cls");
			printf("������� ����� ������: ");
			x = scanf("%d", &sec);
			secprod(sklad, number, sec);
			system("pause");
			break;
		}
		case 4:
		{
			int c, q = 0;
			system("cls");
			printf("������� ����������: ");
			x = scanf("%d", &c);
			for (int i = 0; i < number; i++)
				if (sklad[i].quant < c) q++;
			if (q > 0)
			{
				printf("������:\t ��������: \t ����:\t ����������:\n");
				for (int i = 0; i < number; i++)
					if (sklad[i].quant < c)
					{
						printf("---------------------------------------------------\n");
						printf("\%d\t\t%s\t%lf\t%d\n", sklad[i].section, sklad[i].name, sklad[i].price, sklad[i].quant);
					}
				printf("---------------------------------------------------\n");
			}
			else printf("����������� ������ � ������� �����������\n");
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			if (number != 0)
			{
				printf("������:\t ��������: \t ����:\t ����������:\n");
				for (int i = 0; i < number; i++)
				{
					printf("---------------------------------------------------\n");
					printf("\%d\t\t%s\t%lf\t%d\n", sklad[i].section, sklad[i].name, sklad[i].price, sklad[i].quant);
				}
				printf("---------------------------------------------------\n");
			}
			else printf("� ���� ������ ��� ������� ����������\n");
			system("pause");
			break;
		}
		case 6:
			b = true;
		}
	}
	free(sklad);
	return 0;
}
