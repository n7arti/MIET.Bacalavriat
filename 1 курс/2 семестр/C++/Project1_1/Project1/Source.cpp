
#include <stdio.h> 
#include <stdlib.h>
#include <clocale>

int main()
{
	setlocale(LC_ALL, "Russian");
	double x;
	int a, b, c, d;
	printf("������� ������ ����� �����:");
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	scanf_s("%d", &d);
	while (b==0)
	
	{
		printf("������� ������ �����:");
		scanf_s("%d", &b);
	}
	while (d == 0)
	{
		printf("������� ������ �����:");
		scanf_s("%d", &d);
	}
	x = (a / (double)b) + (c / (double)d);
	printf("��������� ���������:%f\n",x);

	system("pause");
	return 1;
}