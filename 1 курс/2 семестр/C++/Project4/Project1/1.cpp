#include <iostream>
#include <time.h>

#define size 6
using namespace std;

void creation_array(int *mas, int n)//�������� �������
{
	int *i;
	for (i = mas; i < mas + n; i++)
		*i = rand() % 10;
}

void show_array(int* mas, int n) //����� �������
{
	int* i;
	for (i = mas; i < mas + n; i++)
		cout <<* i <<" ";

	cout << endl;
}

void bublesort(int* mas, int n) //���������� ��������� �� �����������
{
	int* i, temp;
	bool b = true;
	while (b)
	{
		b = false;
		for (i = mas; i < mas + n; i++)
		{
			if (*i > * (i + 1))
			{
				b = true;
				temp = *i;
				*i = *(i + 1);
				*(i + 1) = temp;
			}
		}
	}
}

int find_repetitive_elem(const int* mas, int n) // ������� ���������� ���� ������������� ���������(kol)
// � ���������� ���������� ������� �� ����� ���������(kol_pov)
{
	int kol = 0;
	int kol_pov = 0;

	for (int i = 0; i < n; i++)
	{
		if (mas[i] == mas[i + 1])
		{
			kol++;
			kol_pov++;
			continue;
		}
		if (kol_pov != 0)

			cout << mas[i] << " ���������� ���������� ������ ������������� ���������� : " << kol_pov << endl;

		if (kol_pov == 0)
			cout << "��� ������������� ���������" << endl;

		if (&kol_pov == 0)
			cout << "��� ������������� ���������" << endl;

	}

	cout << "\n���������� ������������� ���������: " << kol << endl;
	return 0;
}




int main() {
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(NULL));
	int mas[size], size1;
	bool unique = true;

	creation_array(&mas[0], size);
	show_array(&mas[0], size);
	bublesort(&mas[0], size);
	show_array(&mas[0], size);
	find_repetitive_elem(&mas[0], size);

	system("pause");
	delete mas;
	return 0;

}