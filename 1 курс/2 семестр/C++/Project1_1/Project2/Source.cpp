#include <stdio.h> 
#include <stdlib.h>
#include <clocale>

int main()
{
	setlocale(LC_ALL, "Russian");
	int x;
	printf("������� ����� ������:");
	scanf_s("%d", &x);
	while (x>12)
	{
		printf("������� ������ �����:");
		scanf_s("%d", &x);
	}
	switch (x)
	{
	case 1: printf("1 - ������, ����\n");
		break;
	case 2: printf("2 - �������, ����\n");
		break;
	case 3: printf("3 - ����, �����\n");
		break;
	case 4: printf("4 - ������, �����\n");
		break;
	case 5: printf("5 - ���, �����\n");
		break;
	case 6: printf("6 - ����, ����\n");
		break;
	case 7: printf("7 - ����, ����\n");
		break;
	case 8: printf("8 - ������, ����\n");
		break;
	case 9: printf("9 - ��������, �����\n");
		break;
	case 10: printf("10 - �������, �����\n");
		break;
	case 11: printf("11 - ������, �����\n");
		break;
	case 12: printf("12 - �������, ����\n");
		break;
	}
	system("pause");
	return 1;
}