//#include <iostream>
//#include <string>
//#include <vector> 
//#include <string.h>
//
//
//using namespace std;
//
//int Rabin(string S1, string S2)
//{ 
//	int index = -1;
//	for (int i = 0; i < S2.length() - S1.length() + 1; i++) {
//		for (int j = 0; j < S1.length(); j++) {
//			if (S2[i + j] != S1[j]) {
//				break;
//			}
//		}
//		index = i;
//	}
//	return index;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//
//	string s1;
//	string s2;
//	cout << "������� ������� ������: ";
//	cin >> s1;
//	cout << "������� ������, � ������� ����� ����� ������: ";
//	cin >> s2;
//	int index = Rabin(s1, s2);
//	if (index == -1)
//		cout << "������ �� �������" << endl;
//	else
//		cout << "������ ���������� � ������� " << index << endl;
//
//
//	return 0;
//}
