#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#define N 20// максимальное количество строк

using namespace std;

bool chisla(char* str)//проверка строки на наличие в ней цифр
{
	int lenth = strlen(str);
	for (int i = 0; i < lenth; i++)
		if (isdigit(str[i]))
			return 1;
	return 0;
}
void analyze(char* str)
{
	int lenth = strlen(str), k_numbers = 0, k_space = 0;
	for (int i = 0; i < lenth; i++)
	{
		if (isdigit(str[i])) k_numbers++;
		if (isspace(str[i])) k_space++;
	}
	int k_words = k_space + 1;
	cout << "  кол-во цифр==" << k_numbers << "  кол-во пробелов==" << k_space << "  кол-во слов==" << k_words << "  длина строки==" << lenth << endl;
}
void main()
{
	setlocale(LC_ALL, "Russian");

	char** text_without_numbers;
	char** text_with_numbers;

	text_without_numbers = (char**)malloc(sizeof(*text_without_numbers) * N);
	text_with_numbers = (char**)malloc(sizeof(*text_with_numbers) * N);
	char buff[80];
	int  k_with_numbers = 0, k_without_numbers = 0;

	cout << "введите несколько строк на латинице, заканчивающихся словом and\n";
	while (strcmp(buff, "and") != 0)
	{
		gets_s(buff);
		if (chisla(buff) == 0)
		{
			text_without_numbers[k_without_numbers] = (char*)malloc(sizeof(char) * (strlen(buff) + 1));
			strcpy(text_without_numbers[k_without_numbers], buff);
			k_without_numbers++;
		}
		else
		{
			text_with_numbers[k_with_numbers] = (char*)malloc(sizeof(char) * (strlen(buff) + 1));
			strcpy(text_with_numbers[k_with_numbers], buff);
			k_with_numbers++;
		}
	}
	//вывод
	int str = 0, strok_na_str;
	cout << "введите количество строк на одной странице\n";
	cin >> strok_na_str;
	cout << "\nвывод:\n";
	for (int k = 0; k < k_with_numbers; k++)
	{
		cout.width(30);
		cout << text_with_numbers[k];
		analyze(text_with_numbers[k]);
		str++;
		if (str % strok_na_str == 0) cout << "\f\n";
	}
	for (int k = 0; k < k_without_numbers; k++)
	{
		cout.width(30);
		cout << text_without_numbers[k];
		analyze(text_without_numbers[k]);
		str++;
		if (str % strok_na_str == 0) cout << "\f\n";
	}
}
