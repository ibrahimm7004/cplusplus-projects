#include <iostream>
using namespace std;

void swap(int a[], int j)
{
	int temp;
	
	temp = a[j];
	a[j]  =a[j+1];
	a[j+1] = temp;
}

void sort(int a[], int len)
{
	
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-i-1; j++)
		{
			if (a[j] > a[j+1]) swap(a, j);
		}
	}
}

void print(int a[], int len)
{
	cout << "\n\nSorted Order: \n";
	for (int i = 0; i < len; i++)
	cout << a[i] << endl;
}

int main()
{
	int n, i = 0, len;
	cout << "Enter size of array: ";
	cin >> n;
	cout << endl;
	
	int a[n] = {0};
	len = sizeof(a)/sizeof(a[0]);

	for (;i<len;i++)
	{
		cout << "Enter element no. " << i << ": ";
		cin >> a[i];
	}
	
	sort(a, len);
	print(a, len);
}