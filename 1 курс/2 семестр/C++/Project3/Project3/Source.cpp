#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <clocale>
const int N = 10;
int sums(int mas[N][N],int k)
{
	int sum = 0;
	//�������� �������� �������������� ������� � ������� ����� � �������
	for (int i = k; i < N; i++)
		sum += mas[i][k];
	return sum;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int A[N][N];
	srand(time(NULL));
	for (int i = 0; i < N; i++) //������ ������
	{
		for (int j = 0; j < N; j++)
			A[i][j] = rand() % 10;
	}
	for (int i = 0; i < N; i++) //������� ������
	{
		printf("\n");
		for (int j = 0; j < N; j++)
			printf("%d ", A[i][j]);
	}
	printf("\n");
	for (int i = 0; i < N; i++) //������� ����� ��������� ������� ������� �������������� �������
	{
		int res = sums(A, i);
		printf("����� ��������� %d", i);
		printf("-��� ������� ����� %d\n", res);
	}
	system("pause");
	return 0;

}