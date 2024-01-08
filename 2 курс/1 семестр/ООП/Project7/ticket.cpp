#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "ticket.h"
#include "fio.h"
using namespace std;
#define N 100
int ticket::count;
string ticket::filename;
ticket::ticket()
{
    point_from = new char[50];
    strcpy(point_from, " ");
    point_to = new char[50];
    strcpy(point_to, " ");
    price = 0;
    count++;
}
ticket::~ticket()
{
    count--;
}
ticket::ticket(fio Fio_v, char* point_from_v, char* point_to_v, double price_v)
{
    if (Fio.familia != nullptr)
        delete[] Fio.familia;
    if (Fio.imya != nullptr)
        delete[] Fio.imya;
    if (Fio.otchestvo != nullptr)
        delete[] Fio.otchestvo;
    if (point_to != nullptr)
        delete[] point_to;
    if (point_from != nullptr)
        delete[] point_from;

    Fio.familia = new char[strlen(Fio_v.familia) + 1];
    strcpy(Fio.familia, Fio_v.familia);
    Fio.imya = new char[strlen(Fio_v.imya) + 1];
    strcpy(Fio.imya, Fio_v.imya);
    Fio.otchestvo = new char[strlen(Fio_v.otchestvo) + 1];
    strcpy(Fio.otchestvo, Fio_v.otchestvo);
    point_to = new char[strlen(point_to_v) + 1];
    strcpy(point_to, point_to_v);
    point_from = new char[strlen(point_from_v) + 1];
    strcpy(point_from, point_from_v);
    price = price_v;
}
ticket& ticket::operator = (const ticket& ticket_v)
{
    if (Fio.familia != nullptr)
        delete[] Fio.familia;
    if (Fio.imya != nullptr)
        delete[] Fio.imya;
    if (Fio.otchestvo != nullptr)
        delete[] Fio.otchestvo;
    if (point_from != nullptr)
        delete[] point_from;
    if (point_to != nullptr)
        delete[] point_to;

    Fio.familia = new char[strlen(ticket_v.Fio.familia)+1];
    Fio.imya = new char[strlen(ticket_v.Fio.imya) + 1];
    Fio.otchestvo = new char[strlen(ticket_v.Fio.otchestvo) + 1];
    point_from = new char[strlen(ticket_v.point_from) + 1];
    point_to = new char[strlen(ticket_v.point_to) + 1];

    strcpy(Fio.familia, ticket_v.Fio.familia);
    strcpy(Fio.imya, ticket_v.Fio.imya);
    strcpy(Fio.otchestvo, ticket_v.Fio.otchestvo);
    strcpy(point_from, ticket_v.point_from);
    strcpy(point_to, ticket_v.point_to);
    price = ticket_v.price;
    return *this;
}
void ticket::FromFile(vector<ticket> tick)
{

    int k = 0;
    int y = 0;
    char* buff = new char[52];
    ofstream file(filename.c_str(), ios::app);
    file << "";
    file.close();
    ifstream fs(filename.c_str());
    if (!fs)
        cout << "warning";
    else if (fs)
    {
        while (!fs.eof())
        {
            fs.getline(buff, 53, '\n');
            y = strlen(buff) + 1;
            tick[k].Fio.familia = new char[y];
            strcpy(tick[k].Fio.familia, buff);

            fs.getline(buff, 53, '\n');
            tick[k].Fio.imya = new char[y];
            strcpy(tick[k].Fio.imya, buff);

            fs.getline(buff, 53, '\n');
            tick[k].Fio.otchestvo = new char[y];
            strcpy(tick[k].Fio.otchestvo, buff);

            fs.getline(buff, 53, '\n');
            tick[k].point_from = new char[y];
            strcpy(tick[k].point_from, buff);

            fs.getline(buff, 53, '\n');
            tick[k].point_to = new char[y];
            strcpy(tick[k].point_to, buff);

            fs.getline(buff, 53, '\n');
            tick[k].price = atoi(buff);
            k++;
        }
        fs.close();
        if (k == 0)
            count = k;
        else
            count = k - 1;

    }
    
    delete[] buff;
}
void ticket::InitTicket(vector<ticket> tick)
{
    char* x = new char[50];
    int g = 0;
    system("cls");
    char* point_from = new char[50];
    char* point_to = new char[50];
    fio Fio;
    double price;
    char* buff = new char[50];
    cout << "������� �������: ";
    cin >> buff;
    Fio.set_familia(buff);
    cout << "������� ���: ";
    cin >> buff;
    Fio.set_imya(buff);
    cout << "������� ��������: ";
    cin >> buff;
    Fio.set_otchestvo(buff);
    cout << "������� ����� �����������: ";
    cin >> point_from;
    cout << "������� ����� �����������: ";
    cin >> point_to;
    cout << "������� ����: ";
    cin >> x;
    while (g == 0)
    {
        if (isdigit(*x))
        {
            price = atoi(x);
            g++;
        }
        else
        {
            cout << "�� ���������� ����!" << endl;
            cin >> x;
        }
    }
    tick.push_back(ticket(Fio, point_from, point_to, price));
    count++;
    ofstream outf(filename.c_str(), ios::app);
    outf << Fio.familia << endl;
    outf << Fio.imya << endl;
    outf << Fio.otchestvo << endl;
    outf << point_from << endl;
    outf << point_to << endl;
    outf << price << endl;
    cout << endl;
    cout << "������ ������� ��������" << endl;
    cout << endl;
    system("pause");
}
void ticket::Delete(vector<ticket> tick)
{
    system("cls");
    FromFile(tick);
    tick.pop_back();
    cout << "������ ������" << endl;
    system("pause");
}
void ticket::Print(vector<ticket> tick)
{
    system("cls");
    FromFile(tick);
    int y = 0;
    vector<ticket>::iterator i;
    char FIO[150];
    strcpy(FIO, "");
    int sizefio = 0, sizefamilia = 0, sizeimya = 0, sizeotchestvo = 0, sizefrom = 0, sizeto = 0, sizeprice = 0, size = 0;
    if (count > 0)
    {
        for (i = tick.begin(); i != tick.end(); i++)
        {
            y = strlen((*i).Fio.familia);
            if (y > sizefamilia)
                sizefamilia = strlen((*i).Fio.familia);
            y = strlen((*i).Fio.imya);
            if (y > sizeimya)
                sizeimya = strlen((*i).Fio.imya);
            y = strlen((*i).Fio.otchestvo);
            if (y > sizeotchestvo)
                sizeotchestvo = strlen((*i).Fio.otchestvo);
            y = strlen((*i).point_from);
            if (y > sizefrom)
                sizefrom = strlen((*i).point_from);
            y = strlen((*i).point_to);
            if (y > sizeto)
                sizeto = strlen((*i).point_to);
        }
        if (sizefamilia + sizeimya + sizeotchestvo + 2 < 3) sizefio = 3;
        else sizefio = sizefamilia + sizeimya + sizeotchestvo + 2;
        if (sizefrom < 17) sizefrom = 17;
        if (sizeto < 14) sizeto = 14;
        size = sizefio + sizefrom + sizeto + 22;
        for (int i = 0; i < size; i++)
            cout << "-";
        cout << endl;
        cout << "|" << setw(sizefio + 2) << "���|" << setw(sizefrom + 2) << "����� �����������|" << setw(sizeto + 2) << "����� ��������|" << setw(15);
        cout << "����|" << endl;
        for (i = tick.begin(); i != tick.end(); i++)
        {
            strcat(FIO, (*i).Fio.familia);
            strcat(FIO, " ");
            strcat(FIO, (*i).Fio.imya);
            strcat(FIO, " ");
            strcat(FIO, (*i).Fio.otchestvo);
            for (int i = 0; i < size; i++)
                cout << "-";
            cout << endl;
            cout << "|" << setw(sizefio + 1) << FIO << "|";
            cout << setw(sizefrom + 1) << (*i).point_from << "|" << setw(sizeto + 1) << (*i).point_to << "|";
            cout << setw(14) << (*i).price << "|" << endl;
            strcpy(FIO, "");

        }
        for (int i = 0; i < size; i++)
            cout << "-";
        cout << endl;
    }
    if (count == 0)
        cout << "������ �� ����������" << endl;
    system("pause");
}
void ticket::Find(vector<ticket> tick)
{
    system("cls");
    char buff[50];
    ticket* mas = new ticket [N];
    vector<ticket>::iterator i;
    system("cls");
    FromFile(tick);
    if (count > 0)
    {
        cout << "������� ����� ��������: " << endl;
        fgets(buff, 50, stdin);
        buff[strlen(buff) - 1] = '\0';
        int m = 0;
        cout << endl;
        for (i = tick.begin(); i !=tick.end(); i++)
        {

            if (!abs(strcmp(buff, (*i).point_to)))
            {
                cout << "��� ���������: " << (*i).Fio.familia << " " << (*i).Fio.imya << " " << (*i).Fio.otchestvo << endl;
                cout << "����� �����������: " << (*i).point_from << endl;
                cout << "����� ��������: " << (*i).point_to << endl;
                cout << "����: " << (*i).price << endl;
                cout << endl;
                mas[m] = (*i);
                m++;
            }
        }
        if (m == 0)
            cout << "������ �� ��������� ����������" << endl;
    }
    if (count == 0)
        cout << "������ �� ����������" << endl;
    system("pause");
}