
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <clocale>
using namespace std;
#define N 10

int f1(int **mass, int k) // ���������� ������������� ����� ������ � ������� ����������� ������� ���������� (�� ������)
{
    int max = INT_MIN;
    for (int i = 0; i < k; i++)
    {
        max = INT_MIN;
        for (int j = i; j < k; j++)
        {
            if (max < abs(mass[i][j]))
            {
                max = abs(mass[i][j]);
                
            }
            
            
        }
        cout << "������������ ����� �� ������ " << i + 1 << " ������ " << max << " ";
        cout << endl;
        
      

    }
    return max;
}
int main()
{   
    setlocale(0, "Russian");
    srand(time(0));

    int size; // ��������� ������ ��� ��������� ������������ ������
    size = N;
    int **mass = new int* [size];
    for (int i = 0; i < size; i++)
        mass[i] = new int[size];;


    for (int i = 0; i < N; i++) // �������� ������
        for (int j = 0; j < N; j++)
            mass[i][j] = rand() % 101 - 50;

    for (int i = 0; i < N; i++) // ����� ������� �� �����
    {
        cout << endl;
        for (int j = 0; j < N; j++)
            cout << mass[i][j] << " ";
    }
    cout << endl;


    f1(mass,N);
    system("pause");
    return 0;
}