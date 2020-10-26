#include <iostream>
using namespace std;
#define N 3
#define SIZE 30
char* concatChar(char * str_array[], int size, int index);

void main()
{
	char *str[N], s[SIZE], *st;
	int i = 0, size, index;
	cout << "insert " << N << " strings\n";
	do
	{
		cout << "insert string " << i + 1 << ": ";
		cin >> s;
		size = strlen(s) + 1;
		str[i] = new char[size];
		strcpy_s(str[i], size, s);
		i++;
	} while (i < N);

	cout << "please insert a index\n";
	cin >> index;
	st = concatChar(str, N, index);
	if (!st)
		cout << "your index is not good\n";
	else
	{
		cout << "the new string is: " << st << endl;
 		delete[] st;
	}
	do
	{	
		i--;
		delete[] str[i];
	} while (i >-1);

}



char* concatChar(char * str_array[], int size, int index)
{
	int counter = 0, siz;
	char* p = NULL;
	for (int i = 0; i < size; i++)
	{
		siz = strlen(str_array[i]);
		if (siz > index)
			counter++;
	}
	if (!counter)
		return p;
	p = new char[counter + 1];
	counter = 0;
	for (int i = 0; i < size; i++)
	{
		siz = strlen(str_array[i]);
		if (siz > index)
			*(p + counter++) = *(str_array[i] + index);//str_array[i][index];   //p[counter++]
	}

	p[counter] = '\0';
	return p;

}