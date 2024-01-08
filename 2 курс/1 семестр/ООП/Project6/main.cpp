#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
#include <fstream>
#include <iomanip>
#include "ticket.h"
#include "bus.h"
#include "train.h"
#include "except.h"

#define N 100
using namespace std;


void Sort(ticket* tick)
{
    system("cls");
    tick->FromFile(tick);
    int y = 0;
    ticket buff;
    char FIO[150];
    strcpy(FIO, "");
    double t;
    int sizefio = 0, sizefrom = 0, sizeto = 0, sizeprice = 0, sizefamilia = 0, sizeimya = 0, sizeotchestvo = 0, size = 0;
    tick->count--;
    if (tick->count > 0)
    {
        for (int i = 0; i < tick->count - 1; i++)
        {
            for (int j = i + 1; j < tick->count; j++)
            {
                if (strcmp(tick[i].point_from, tick[j].point_from) > 0)
                {
                    buff = tick[i];
                    tick[i] = tick[j];
                    tick[j] = buff;
                }
            }
        }
        for (int i = 0; i < tick->count; i++)
        {
            y = strlen(tick[i].Fio.get_familia());
            if (y > sizefamilia)
                sizefamilia = strlen(tick[i].Fio.get_familia());
            y = strlen(tick[i].Fio.get_imya());
            if (y > sizeimya)
                sizeimya = strlen(tick[i].Fio.get_imya());
            y = strlen(tick[i].Fio.get_otchestvo());
            if (y > sizeotchestvo)
                sizeotchestvo = strlen(tick[i].Fio.get_otchestvo());
            y = strlen(tick[i].point_from);
            if (y > sizefrom)
                sizefrom = strlen(tick[i].point_from);
            y = strlen(tick[i].point_to);
            if (y > sizeto)
                sizeto = strlen(tick[i].point_to);
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
        for (int i = 0; i < tick->count; i++)
        {
            strcat(FIO, tick[i].Fio.get_familia());
            strcat(FIO, " ");
            strcat(FIO, tick[i].Fio.get_imya());
            strcat(FIO, " ");
            strcat(FIO, tick[i].Fio.get_otchestvo());
            for (int i = 0; i < size; i++)
                cout << "-";
            cout << endl;
            cout << "|" << setw(sizefio + 1) << FIO << "|";
            cout << setw(sizefrom + 1) << tick[i].point_from << "|" << setw(sizeto + 1) << tick[i].point_to << "|";
            cout << setw(14) << tick[i].price << "|" << endl;
            strcpy(FIO, "");

        }
        for (int i = 0; i < size; i++)
            cout << "-";
        cout << endl;
        ofstream outf("DataBase.txt");
        for (int i = 0; i < tick->count; i++)
        {
            outf << tick[i].Fio.get_familia() << endl;
            outf << tick[i].Fio.get_imya() << endl;
            outf << tick[i].Fio.get_otchestvo() << endl;
            outf << tick[i].point_from << endl;
            outf << tick[i].point_to << endl;
            outf << tick[i].price << endl;
        }
    }
    if (tick->count == 0)
        cout << "������ �� ����������" << endl;
    system("pause");
}
void AddInfo(ticket* pas, train* pastr, bus* pasb)
{
    system("cls");
    char* t = new char[10];
    cout << "�������� ��� ����������: " << endl;
    cout << "- Bus" << endl;
    cout << "- Train" << endl;
    cin >> t;
    while (cin.get() != '\n')
        ;
    while (1)
    {

        if (!abs(strcmp(t, "Train")) || !abs(strcmp(t, "train")) || !abs(strcmp(t, "Bus")) || !abs(strcmp(t, "bus")))
            break;
        else 
        {
            throw except("�� ���������� ����!");
            cin >> t;
        }
    }

    if (!abs(strcmp(t, "Bus")) || !abs(strcmp(t, "bus")))
        pasb[bus::get_countb()].AddInfoB(pas);
    if (!abs(strcmp(t, "Train")) || !abs(strcmp(t, "train")))
        pastr[train::get_counttr()].AddInfoTr(pas);
    delete[] t;
}

int main()
{
    setlocale(LC_ALL, "rus");
    char* n1 = new char[2];
    int n = 0;
    int g = 0;
    int number = 0;
    ticket::Set_filename("DataBase.txt");
    train::set_filenametr("DataBaseTrain.txt");
    bus::set_filenameb("DataBaseBus.txt");
    ticket* pas = new ticket[N];
    train* pastr = new train[N];
    bus* pasb = new bus[N];
    pas[N - 1].FromFile(pas);
    pastr[N - 1].FromFile(pastr);
    pasb[N - 1].FromFile(pasb);
    number = pas[N-1].Get_count();
    
    while (n != 8)
    {
        
        system("cls");
        cout << "�������� ������ ���������.......................1" << endl;
        cout << "����������� ������..............................2" << endl;
        cout << "����� ������ �� ������ ��������.................3" << endl;
        cout << "���������� �� �������� �� ������ �����������....4" << endl;
        cout << "�������� ����������.............................5" << endl;
        cout << "����������� ������(�����).......................6" << endl;
        cout << "����������� ������(�������).....................7" << endl;
        cout << "����� �� ���������..............................8" << endl;
        cout << "������� ����� �������" << endl;
        
            cin >> n1;
            while (1)
            {
                try
                {
                    for (int i = 0; i < strlen(n1); i++)
                    {
                        if (!isdigit(n1[i]))
                        {
                            throw except("�� ���������� ����!");
                            
                            
                        }
                    }
                    n = atoi(n1);
                    break;
                   
                }
                catch (except e)
                {
                    cout << e.msg << endl;
                    cin >> n1;
                }
            }
            while (cin.get() != '\n')
                ;
            switch (n)
            {
            case 1:
                pas[number].InitTicket();
                number++;
                break;
            case 2:
                pas[N - 1].Print(pas);
                break;
            case 3:
                pas[N - 1].Find(pas);
                break;
            case 4:
                Sort(pas);
                break;
            case 5:
                AddInfo(pas, pastr, pasb);
                break;
            case 6:
                pastr[N - 1].Print(pas, pastr);
                break;
            case 7:
                pasb[N - 1].Print(pas, pasb);
                break;
            }
        
        

    }
}