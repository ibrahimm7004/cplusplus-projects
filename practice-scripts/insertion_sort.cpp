#include<iostream>
using namespace std;

void sort(int a[], int n)
{	
	int key, j;
for (int i =1; i < n;i++)
{
	key = a[i];
	j = i-1;
	
		while(j>=0 && a[j] > key)
		{
			a[j+1] = a[j];
			j=j-1;
		}
		a[j+1] = key;
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
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	int arr[n] = {0};
	
	cout <<endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter element " << i << ": ";
		cin >> arr[i];
	}
	
	sort(arr, n);
	print(arr, n);
	
	return 0;
}