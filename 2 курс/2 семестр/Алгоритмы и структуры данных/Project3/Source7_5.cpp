//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <iostream>
//#include<clocale>
//#include <time.h>
//#include <vector>
//
//#define N 6 
//
//using namespace std;
//
//struct Box
//{
//	int sub[N];  
//	int sum = 0; 
//	int count = 0; 
//};
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	vector <int> subjects;
//	int n, max = 0;
//	clock_t start = clock();  
//
//	cout << "������� ���������� ��������� c �������� 4: ";
//	cin >> n;
//	for (int i = 0; i < n; i++) 
//		subjects.push_back(4);
//
//	cout << "������� ���������� ��������� c �������� 3: ";
//	cin >> n;
//	for (int i = 0; i < n; i++) 
//		subjects.push_back(3);
//
//	cout << "������� ���������� ��������� c �������� 2: ";
//	cin >> n;
//	for (int i = 0; i < n; i++) 
//		subjects.push_back(2);
//
//	cout << "������� ���������� ��������� c �������� 1: ";
//	cin >> n;
//	for (int i = 0; i < n; i++) 
//		subjects.push_back(1);
//
//
//	vector<Box> box(subjects.size());
//
//	int j = 0, i = 0;
//
//	while (j != subjects.size())
//	{
//		i = 0;
//		
//		while (subjects[j] + box[i].sum > N) {
//			i++;
//		}
//
//		box[i].sub[box[i].count] = subjects[j];
//		box[i].sum += subjects[j];
//		box[i].count++;
//
//
//		j++;
//
//		if (i > max) 
//			max = i;
//	}
//
//	cout << endl;
//
//	for (int k = 0; k < max; k++)
//	{
//		cout << k + 1 << "-� ����:" << endl;
//		for (int j = 0; j < box[i].count; j++) 
//			cout << box[k].sub[j] << "  ";
//		cout << endl;
//	}
//
//	clock_t end = clock();         
//	double seconds = (double)(end - start) / CLOCKS_PER_SEC;  
//	cout << endl << "����� ���������� ��������� " << seconds << endl; 
//	system("pause");
//}
