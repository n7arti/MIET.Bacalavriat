#include <omp.h>
#include <iostream>
#include <ctime>
const int N = 5;
const int LIMIT = 1;
using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");
	int i;
	float total, prod;
	int* A = new int[N];
	int* B = new int[N];
	int* C = new int[N];

	for (int i = 0; i < N; i++) {
		A[i] = i;
		B[i] = i + 1;
		C[i] = i + 2;
	}
	total = 1;
	unsigned int start_time = clock();
	// ������������� ������

	// lab3 reduction

	//#pragma omp parallel shared(A,B,C) if (N > LIMIT)
	//{
	//	#pragma omp for private(i,prod) reduction(*:total)
	//		for (i = 0; i < N; i++)
	//		{
	//			prod = 0;
	//			if ((A[i] % 2 == 0) && (C[i] != 0))
	//				prod = (float)B[i]/(float)C[i];
	//			else { prod = B[i] + A[i]; }
	//			if (prod != 0)
	//				total = total * prod;
	//	} 
	//}/* ���������� ������������� ��������� */

	//lab4 atomic

	//#pragma omp parallel shared(total,A,B,C) private(i,prod) if (N > LIMIT)
	//{
	//	#pragma omp for
	//	for (i = 0; i < N; i++)
	//	{
	//		prod = 0;
	//		if ((A[i] % 2 == 0) && (C[i] != 0))
	//			prod = (float)B[i]/(float)C[i];
	//		else { prod = B[i] + A[i]; }
	//		if (prod != 0) {
	//		#pragma omp atomic
	//			total *= prod;
	//		}
	//	}
	//} /* ���������� ������������� ��������� */

	//lab4 critical

	//#pragma omp parallel shared(total,A,B,C) private(i,prod) if (N > LIMIT)
	//{
	//	#pragma omp for
	//	for (i = 0; i < N; i++)
	//	{
	//		prod = 0;
	//		if ((A[i] % 2 == 0) && (C[i] != 0))
	//			prod = (float)B[i] / (float)C[i];
	//		else { prod = B[i] + A[i]; }
	//		if (prod != 0) {
 //            #pragma omp critical 
	//			total *= prod;
	//		}
	//	}
	//} /* ���������� ������������� ��������� */

	//lab5 section1
//#pragma omp parallel shared(total,A,B,C)  if (N > LIMIT)
//	{
//#pragma omp sections private(i,prod)
//		{
//#pragma omp section
//			for (i = 0; i < N; i++)
//			{
//				prod = 0;
//				if ((A[i] % 2 == 0) && (C[i] != 0))
//					prod = (float)B[i] / (float)C[i];
//				else { prod = B[i] + A[i]; }
//				if (prod != 0) {
//					total *= prod;
//				}
//			}
//		}
//	} /* ���������� ������������� ��������� */

	//lab5 section2

	//lab6 lock
//	omp_lock_t lock;
//	omp_init_lock(&lock);
//#pragma omp parallel shared(total,A,B,C) private(i,prod) if (N > LIMIT)
//	{
//#pragma omp for
//		for (i = 0; i < N; i++)
//		{
//			prod = 0;
//			if ((A[i] % 2 == 0) && (C[i] != 0))
//				prod = (float)B[i] / (float)C[i];
//			else { prod = B[i] + A[i]; }
//			omp_set_lock(&lock);
//			if (prod != 0) {
//				total *= prod;
//			}
//			omp_unset_lock(&lock);
//		}
//	} /* ���������� ������������� ��������� */
	/*omp_destroy_lock(&lock);*/
	


	//lab6 barrier
#pragma omp parallel shared(total,A,B,C)  if (N > LIMIT)
	{
#pragma omp for private(i,prod)
		for (i = 0; i < N; i++)
		{
			prod = 0;
			if ((A[i] % 2 == 0) && (C[i] != 0))
				prod = (float)B[i] / (float)C[i];
			else { prod = B[i] + A[i]; }
#pragma omp barrier
			if (prod != 0) {

				total *= prod;
			}
		}
	} /* ���������� ������������� ��������� */
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "����� ������ ��������� � ��: " << search_time << endl;
	cout << "������������ ��������� �������� ����� " << total;
	
}
