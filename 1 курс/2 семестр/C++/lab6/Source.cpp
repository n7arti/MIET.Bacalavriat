#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>
#include <locale.h>
#include <windows.h>
#define N 80
using namespace std;
struct supplier
{
    int id;
    char* name;
    char* namefirm;
    double price;
    int couunt;
};
/*void find(char** tovar, int size, int& colvo)
{
    int h = 0, r =0;
    char buff[N];
    cout << "������� �������� �������" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> buff;
        tovar[i] = new char[strlen(buff) + 1];
        strcpy(tovar[i], buff);
        for (int j = 0; j < i; j++)
        {
            if (!abs(strcmp(tovar[i], tovar[j])))
            {
                h++;
                break;
            }
        }
    }
    colvo = size - h;
}
void addInfo(supplier* supplier, int colvo)
{
    char buff[N];
    cin >> buff;
    for (int i = 0; i < colvo; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < j; k++)
            {
                if (abs(strcmp(tovar[i], tovar[j])))
                {
                    
                    supplier[j].name = new char[strlen(tovar[j]) + 1];
                    strcpy(supplier[j].name, tovar[j]);
                    supplier[j].couunt++;
                }
            }
        }
        cout << "������� ���������� � ������ " << i + 1 << endl;
        cout << "����� ������: ";
        cin >> supplier[i].id;
        cout << "�������� �����:";
        cin >> buff;
        supplier[i].namefirm = new char[strlen(buff) + 1];
        strcpy(supplier[i].namefirm, buff);
        cout << "����: ";
        cin >> supplier[i].price;
        cout << endl;
    }
}
void showInfo(supplier* supplier, int colvo)
{
    for (int i = 0; i < colvo; i++)
    {
        cout << "���������� � ������ " << i + 1 << endl;
        cout << "����� ������: " << supplier[i].id << endl;
        cout << "�������� ������: " << supplier[i].name << endl;
        cout << "�������� �����: " << supplier[i].namefirm << endl;
        cout << "����: " << supplier[i].price << endl;
        cout << "����������: " << supplier[i].couunt << endl;
    }
}
void printing(supplier* supplier, int colvo)
{
    cout << setw(30) << "�������� ������ ";
    cout << setw(30) << "������������� ";
    cout << setw(10) << "���� ";
    cout << setw(10) << "���������� ";
    cout << setw(15) << "����� ����� " << endl;
    double sum = 0, sumo=0;
    for (int i = 0; i < colvo; i++)
    {
        cout << setw(30) << supplier[i].name;
        cout << setw(30) << supplier[i].namefirm;
        cout << setw(10) << supplier[i].price;
        cout << setw(10) << supplier[i].couunt;
        sum = supplier[i].price * supplier[i].couunt;
        cout << setw(15) << sum << endl;
        sumo += sum;
        sum = 0;
    }
    cout <<setw(25)<< "����� ������� �� ����� ";
    cout << setw(70) << sumo << endl;
}*/
void find(supplier* supplier, int colvo, int& k, int& l)
{
    cout << "������� ���������� � ������ " << colvo+1 << endl;
    cout << "������� �������� �����a" << endl;
    char buff[N];
    cin >> buff;
    supplier[colvo].name = new char[strlen(buff) + 1];
    for (int i = 0; i < colvo+1; i++)
    {
        if (abs(strcmp(buff, supplier[i].name)))
        {
            k++;
            l = i;
            break;
        }
        else if (!abs(strcmp(buff, supplier[i].name)))
            strcpy(supplier[colvo].name, buff);
    }
}
void addInfo(supplier* supplier, int colvo)
{
    char buff[N];
    cout << "����� ������: ";
    cin >> supplier[colvo].id;
    cout << "�������� �����:";
    cin >> buff;
    supplier[colvo].namefirm = new char[strlen(buff) + 1];
    strcpy(supplier[colvo].namefirm, buff);
    cout << "����: ";
    cin >> supplier[colvo].price;
    cout << endl;
}
int main()
{
    setlocale(0, "Russian");
    int n = 0;
    int col = 100;
    supplier* product = new supplier[col];
    int t = 0;
    int l = 0;
    while (n != 5)
    {
        system("cls");
        cout << "�������� �����.........................................1" << endl;
        cout << "����������� ���������� � ������ � ��������� ����.......2" << endl;
        cout << "����� ��� ������ �������� ������.......................3" << endl;
        cout << "���������� ������ � ����������� ������ ���������.......4" << endl;
        cout << "�����..................................................5" << endl;
        cout << "������� ����� �������: ";
        cin >> n;
        switch (n)
        {
        case 1:
            int k = -1;
            find(product, t, k,l);
            cout << k;
            if (k == 0)
            {
                addInfo(product, t);
                t++;
            }
            else if (k > 0)
                product[l].couunt++;
            break;

        /*case 2:
        break;
        case 3:
            break;
        case 4:
            break;*/
        }
    }
 
    delete[] product;
    system("pause");
    return 0;
}
