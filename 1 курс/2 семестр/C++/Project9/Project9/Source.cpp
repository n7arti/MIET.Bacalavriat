#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <clocale>

#include <stdio.h>

#include <stdlib.h>

#include <iomanip>// ����� �������� ����� ���

#include <string.h>

#define N 80

using namespace std;

struct parcel

{

	char* surname;// ������� �����������

	char* name;// ��� �����������

	char* adres;// ����� �����������

	char* surname1;//������� ����������

	char* name1;// ��� ����������

	double weight;// ���

} bebe;

void add_new_parcel(parcel* bebe, int kol)// ������� ���������� ����� �������

{

	char buf[N]; // kol- ���������� �������

	for (int i = 0; i < kol ; i++)

	{

		cout << "kkkkkk " << i+1;

		cout << "������� ���������� � �������" << endl;

		cout << "������� ����������� :" << endl;

		cin >> buf;

		bebe[i].surname = new char[strlen(buf) + 1];

		strcpy(bebe[i].surname, buf); // ���������� buff � ������������ ������

		cout << "��� ����������� :" << endl;

		cin >> buf;

		bebe[i].name = new char[strlen(buf) + 1];

		strcpy(bebe[i].name, buf);

		cout << "����� ����������� :" << endl;

		cin >> buf;

		bebe[i].adres = new char[strlen(buf) + 1];

		strcpy(bebe[i].adres, buf);

		cout << "������� ���������� :" << endl;

		cin >> buf;

		bebe[i].surname1 = new char[strlen(buf) + 1];

		strcpy(bebe[i].surname1, buf);

		cout << "��� ���������� :" << endl;

		cin >> buf;

		bebe[i].name1 = new char[strlen(buf) + 1];

		strcpy(bebe[i].name1, buf);

		cout << "��� ������� :" << endl;

		cin >> bebe[i].weight;

		cout << "---------------------------------" << endl;

	}

}

void print_info_parcel(parcel* bebe, int num)// ����������� ���������� � �������

{

	for (int i = num; ; )

	{

		cout << "���������� � �������" << i << ":" << endl;

		cout << "������� ����������� :" << bebe[i].surname << endl;

		cout << "��� ����������� :" << bebe[i].name << endl;

		cout << "����� ����������� :" << bebe[i].adres << endl;

		cout << "������� ���������� :" << bebe[i].surname1 << endl;

		cout << "��� ����������" << bebe[i].name1 << endl;

		cout << "��� �������" << bebe[i].weight << endl;

		cout << "-------------------------" << endl;

	}

}

void find_parcel_ot()// ����� ��� ������� ��������� �����������

{

}

void find_parcel_weight(double* w)// ����� ��� ������� � ����� ������ ���������

{

}

int main()

{

	setlocale(0, "Russian");

	// ������������ ��������� ������ ��� ���������� �������

	// �������� �������� ����� ������ �����!

	cout << " ������ �����" << endl;

	cout << "������� ���������� ������� , ������� �� ������ ������ � ����" << endl;

	int kol;

	cin >> kol;

	parcel* basa = new parcel[kol];

	cout << "�������� �����.........................................1" << endl;
	cout << "����������� ���������� � ������ � ��������� ����......2" << endl;
	cout << "����� ��� ������� ��������� �����������................3" << endl;
	cout << "����� ��� ������� � ����� ������ ���������.............4" << endl;
	cout << "�����..................................................5" << endl;

	int n;

	cin >> n;

	while (n != 5)

	{

		switch (n)

		{

		case 1:

			add_new_parcel(basa, kol);
			cin >> n;

			break;

		case 2:

		{

			cout << "� ����� ������� �� ������ ������ ����������?" << endl;

			cout << "������� ����� �������: " << endl;

			int num;

			cin >> num;

			print_info_parcel(basa, num);

		}

		break;

		case 3:

			break;

		case 4:

			break;

		}

	}

	delete[] basa;// �������� ������������� �������

	system("pause");

	return 0;

}