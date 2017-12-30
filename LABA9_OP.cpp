#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
int n, k = 0;   // n - довжина слів, вказана користувачем, k - кількість введених слів
char s[100];
const int h = 20;
typedef char str[h][h];
str arr;


char *next_token = NULL;

void first(char[], str);
void first(char string[], str mas)
{
	char *delimiter = " ";
	char *p = NULL;
	p = strtok_s(string, delimiter, &next_token);
	while (p != NULL)
	{
		strcpy_s(mas[k], p);
		p = strtok_s(NULL, delimiter, &next_token);
		k++;
	}
}

void long_words(str mas, int k)
{
	int number_of_words = 0; // кількість слів, що задовільняють умову
	cout << "Result word(s):" << endl;
	for (int j = 0; j < k; j++)
		if (strlen(mas[j]) > n)
		{
			cout << mas[j] << endl;
			number_of_words++;
		}
	cout << "Number of words - " << number_of_words << endl;
}

int main()
{
	cout << "Enter string: ";
	gets_s(s);
	cout << "Enter n: ";
	cin >> n;
	first(s, arr);
	long_words(arr, k);
	system("pause");
}
