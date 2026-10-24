#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void create(int* a, int size, int low, int high, int i);
void print(int* a, int size, int i);
int sum(int* a, int i);
int num(int* a, int i);
void modif(int* a, int i);
int main()
{
	srand((unsigned)time(NULL));
	const int n = 24;
	int a[n];
	int low = -10;
	int high = 14;
	create(a, n, low, high, 0);
	print(a, n, 0);
	cout << "Sum = " << sum(a, n - 1) << endl;
	cout << "Num = " << num(a, n - 1) << endl;
	modif(a, n - 1);
	cout << endl;
	return 0;
}
void create(int* a, int size, int low, int high, int i)
{
	a[i] = low + rand() % (high - low + 1);
	if (i < size - 1)
		create(a, size, low, high, i + 1);
}
void print(int* a, int size, int i)
{
	cout << setw(4)<< a[i];
	if (i < size - 1)
		print(a, size, i + 1);
	else
		cout << endl;
}
int sum(int* a, int i)
{
	if (i < 0)
		return 0;
	else
		if (a[i] > 0 || i % 2 == 0)
			return a[i] + sum(a, i - 1);
		else
			return sum(a, i - 1);
}
int num(int* a, int i)
{
	if (i < 0)
		return 0;
	else
		if (a[i] > 0 || i % 2 == 0)
			return 1 + num(a, i - 1);
		else
			return num(a, i - 1);
}
void modif(int* a, int i)
{
	if (i >= 0)
	{
		if (a[i] > 0 || i % 2 == 0)
			a[i] = 0;
		modif(a, i - 1);
		cout << setw(4) << a[i];
	}
}