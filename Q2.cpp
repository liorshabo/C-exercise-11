#include <iostream>
using namespace std;

int * intToArray(int &x);

void main()
{
	int num, *pt;
	cout << "insert a number\n";
	cin >> num;
	pt = intToArray(num);
	if (!pt)
		cout << "yout plain didnt work\n";
	else
	{
		for (int i = 0; i < num; i++)
			cout << pt[i] << " ";
		delete[] pt;

	}

	cout << endl;

}


int * intToArray(int &x)
{
	int cnt = 0, tmp = x, *ptr = NULL;
	if (!x)//x==0
		return ptr;
	while (tmp)
	{
		tmp /= 10;
		cnt++;
	}

	ptr = new int[cnt];
	for (int *p = ptr + cnt - 1; p >= ptr; p--)
	{
		*p = x % 10;
		x /= 10;
	}
	x = cnt;
	return ptr;




}