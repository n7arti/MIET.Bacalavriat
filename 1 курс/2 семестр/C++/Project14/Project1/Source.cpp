#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <clocale>
#include <iostream>
#include "Source.h"

#define N1 10
#define N2 5

using namespace std;

void f1(int** mass, int a, int b, int &k, int &l, int &h) // ������� ������� ������� ���������� ������������� � ������������� ����� � ������ ��������
{                                                         // ������� (������� �������� ������, ���� ��� ����)
    cout << endl;
   

    for (int i = a/2; i < a; i++)
        for (int j = 0; j < b; j++)
            
        {
            if (mass[i][j] > 0)
                k++;          
            else
            {
                if (mass[i][j] < 0)
                    l++;
                else               
                        h++;                
            }
        }                       

        
    
}

int main()
{
    int i, j;
    int k = 0,  l = 0,  h = 0;
   
    setlocale(0, "Russian");
    srand(time(0));

    int** mass = new int* [N1]; // ��������� ������ �� ������������ ������
    for (i = 0; i < N1; i++)
        mass[i] = new int[N2];


    cout << " ������ ����� " << endl;

    for (i = 0; i < N1; i++) // ���������� � ����� ������������� �������
    {
        cout << endl;
        for (j = 0; j < N2; j++)
        {
            mass[i][j] = rand() % 101 - 50;
            cout.width(4);
            cout << mass[i][j] << " ";
        }

    }

    cout << endl; 

    f1(mass, N1, N2, k,l,h); 
    
    cout << "���������� ������������� ����� " << k << endl; 
    cout << "���������� ������������� ����� " << l << endl;

    if (h == 0)
        cout << "����� ���" << endl;
    else 
        cout << "���������� ����� " << h << endl;
    
    delete[] mass;
    system("pause");
    return 0;
}