#include <stdio.h> 
#include <stdlib.h>
#include <clocale>

int main()
{
	setlocale(LC_ALL, "Russian");
	int x,a,b;
	int s = 0;
	printf("������� ��������,������ ��������� ���� ����� ������ ���� ������ �������:");
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	while (b<a)
	{ 
		printf("������� ������ ��������:");
		scanf_s("%d", &a);
		scanf_s("%d", &b);
	}
	printf("������� ����� �����:");
	scanf_s("%d", &x);
	while (x != 0)
	{
		printf("������� ��� ���� ����� �����:");
		scanf_s("%d", &x);
		if ((x >= a) && (x <= b))
			s += x;
	}
	printf("����� �����:%d\n", s);
	system("pause");
	return 1;
}