#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <clocale>
#include <iostream>
using namespace std;
void polot(int **mas, int size, int &polo, int &otr)//���������� ���������� ������������� ������ � ������������� ������ ���������
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - i - 1; j < size; j++)
		{
			if (*(*(mas + i) + j) % 2 == 0)
			{
				if (*(*(mas + i) + j) > 0)
					polo++;
				else if (*(*(mas + i) + j) < 0)
					otr++;

			}
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int N;
	cin >> N;
	int **Arr = new int* [N];//��������� ������������ ������
	for (int i = 0; i < N; i++)
		Arr[i] = new int[N];
	for (int i = 0; i < N; i++)//���������� � ����� �������
	{
		cout << endl;
		for (int j = 0; j < N; j++)
		{
			*(*(Arr + i) + j) = rand() % 21 - 10;
			cout << *(*(Arr + i) + j) << " ";
		}
	}
	int pol = 0, ot = 0;//������� ������������� ������ � ������������� ������ ���������
	polot(Arr, N, pol, ot);
	cout << "���������� ������������� ������ ��������� � �������������� �������:" << pol << endl;
	cout << "���������� ������������� ������ ��������� � �������������� �������:" << ot << endl;
	system("pause");
	return 0;
}
