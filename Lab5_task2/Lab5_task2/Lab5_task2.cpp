#include<iostream>
#include<time.h>
#include <stdlib.h>
using namespace std;


void init_massiv(float* fstart, int size)
{

	for (float* ru = fstart; ru < fstart + size; ru++)
	{
		*ru = (rand() % 1000) / 100.0 - 5;
	}
}

void print_massiv(float* fstart, int size)
{
	int i = 0;
	for (float* ru = fstart; ru < fstart + size; ru++)
	{
		cout.width(16);
		cout << *ru;
		if ((i + 1) % 5 == 0) cout << '\n';
		i++;
	}
}

int obhod(float* fstart, int M, int N, float* fstart_B)
{
	float* ru_B = fstart_B;
	int k = M / 2, size_B = 0;;
	if (M % 2 == 1)
		k = k + 1;
	float* ru = fstart + k;
	for (int j = 0; j < N / 2; j++)
	{
		for (int i = 0; i < M / 2; i++)
		{
			if (*ru < 0)
			{
				*ru_B = *ru;
				ru_B++;
				size_B++;
			}
			ru++;
		}
		ru += k;
	}
	ru -= k;
	if (N % 2 == 1)
		ru += M;
	while (ru < fstart + M * N)
	{
		for (int i = 0; i < M / 2; i++)
		{
			if (*ru < 0)
			{
				*ru_B = *ru;
				ru_B++;
				size_B++;
			}
			ru++;
		}
		ru += k;
	}
	return size_B;
}


void main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int M, N;
	cout << "введите размеры матрицы N x M(целые числа от 1 до 1000)\n";
	cin >> N >> M;
	while ((N<=0)||(N>1000)|| (M <= 0) || (M > 1000))
	{
		cout << "введены некорректные данные\nвведите размеры матрицы N x M(целые числа от 1 до 1000)\n";
		cin >> N >> M;
	}
	

	float* A = new float[N*M];
	float* start = A;
	int size = N * M;

	init_massiv(start, size);
	float* B = new float[N*M / 2];

	cout << "\n матрица:\n";
	for (int i = 0; i < N*M; i++)
	{
		cout.width(8);
		cout << A[i];
		if ((i + 1) % M == 0) cout << '\n';
	}

	cout << "\n минимальные элементы в заштрихованной области:\n";
	int size_B = obhod(A, M, N, B);
	print_massiv(B, size_B);
}



