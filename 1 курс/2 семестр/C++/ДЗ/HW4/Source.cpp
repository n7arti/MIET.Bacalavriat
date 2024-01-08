#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
#define N 80
using namespace std;
struct cinema
{
    int id;
    char* name;
    int year;
    double mark;
    
};

//������� �����
void addInfo(cinema* cinema, int n)
{
    char buff[N];
    for (int i = 0; i < n; i++)
    {
        cout << "������� ���������� � ������ " << i + 1 << endl;
        cout << "ID: ";
        cin >> cinema[i].id;
        cout << "��������:";
        cin >> buff;	
        cinema[i].name = new char[strlen(buff) + 1];
        strcpy(cinema[i].name, buff);	
        cout << "��� �������: ";
        cin >> cinema[i].year;
        cout << "������: ";
        cin >> cinema[i].mark;
        cout << endl;
    }
}
//������� ������
void showInfo(cinema* cinema, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "���������� � ������ " << i + 1 << endl;
        cout << "ID: " << cinema[i].id << endl;
        cout << "��������: " << cinema[i].name << endl;
        cout << "��� �������: " << cinema[i].year << endl;
        cout << "������: " << cinema[i].mark << endl;
    }
}

//������� ���������� �� ����
void filtr(cinema* cinema, int n, int god)
{
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (god == cinema[i].year)
        {
            cout << "���������� � ������ " << i + 1 << endl;
            cout << "ID: " << cinema[i].id << endl;
            cout << "��������: " << cinema[i].name << endl;
            cout << "��� �������: " << cinema[i].year << endl;
            cout << "������: " << cinema[i].mark << endl;
            t++;
        }
    }
    if (t == 0)
        cout << "������� ������� ���� �� �������." << endl;
}
//������� �������� ������� ������ ���� �������
void srznach(cinema* cinema, int n, double& ocenka)
{
    for (int i = 0; i < n; i++)
    {
        ocenka += cinema[i].mark;
    }
    ocenka /= n;
}
int main()
{
    setlocale(0, "Russian");
    int count;
    cout << "������� ���������� �������: ";
    cin >> count;
    cinema* films = new cinema[count];
    // ����� ������� ����� ����������
    addInfo(films, count);
    // ����� ������� ������ ����������
    showInfo(films, count);
    // ����� ������� ���������� �� ������-���� ��������
    int god1 = 0;
    cout << "������� ��� ��������� ������: ";
    cin >> god1;
    filtr(films, count, god1);
    // ����� ������� ��������
    double val=0;
    srznach(films, count, val);
    cout << "������� ������ ���� �������: " << val << endl;
    return 0;
}
