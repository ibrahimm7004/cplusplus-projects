#include<iostream>
using namespace std;

bool search(int n, int &s, int a[])
{
	bool found = false;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == s)
		{
		found = true;
		s=i;
	}
	}
	return found;
}


int main()
{
	
	int n, a[n], s;
	
	cout << "Enter num of elements: ";
	cin >> n;
	cout << endl;
	
	for (int i = 0; i < n; i++)
	{
		cout << "Enter element " << i <<": ";
		cin >> a[i];
	}
	
	cout << "\nEnter search num: ";
	cin >> s;
	
	cout << "Number found = " << search(n, s, a);
	
	if (search(n,s,a) == true)
	cout << "\nNumber is at index "<<s<<"\n\n";
	
	return 0;
}