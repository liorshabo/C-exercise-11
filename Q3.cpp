#include <iostream>
using namespace std;
#define SIZE 200
#define STOP 5
#define TAV 11
void main()
{
	char str[SIZE], stop[STOP] = "stop";
	FILE *f;
	int size;
	fopen_s(&f, "q3.txt", "a");
	cout << "enter sentences to append .to finish press stop\n";
	do
	{
		cin.getline(str, SIZE, '\n');
		if (strcmp(str, stop))
		{
			strcat_s(str, "\n");
			fputs(str, f);
		}
	} while (strcmp(str, stop));
	fclose(f);
	fopen_s(&f, "q3.txt", "r");
	if (f == NULL)
		cout << "ERROR OPENING FILE\n";
	else
	{
		cout << "your sntences are:\n";
		while (!feof(f))
		{
			if (fgets(str, SIZE, f) != NULL)
			{
				size = strlen(str);
				if (size < TAV)
					cout << str;
			}
		}
		fclose(f);

	}
}
