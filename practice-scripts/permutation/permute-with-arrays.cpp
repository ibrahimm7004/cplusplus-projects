#include<iostream>
#include<vector>
using namespace std;

void swap(int a[], int n)
{
	int temp;
	for (int i = 0; i < n ; i++)     //for loop from 0th index of vector till the max index
	{
		temp = a[i];      //simple swapping 
		a[i] = a[i+1];
		a[i+1] = temp;
	}
}

void store(int b[], string &str)
{
   	char arr[sizeof(b)];
	for (int i =0; i<3;i++)
	arr[i] = b[i] + '0';
	
	for (int i = 0; i<3; i++)
	str = str + arr[i];
}

void compare(int a[], string b[], string str, int &r)
{
	int u = r+1;
	for (int i = 0; i < u; i++)
	{
		if (b[i] == str)
		{
			b[r] = str;
			r++;
			cout<<" "<<b[r];
		}
	}
	
}

int factorial(int n) {
    if (n > 1) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}

int main()
{
	int n, input, r = 0;
	
	cout<<"Enter size of array: ";
	cin>> n;
	int a1[n];
	string a2[factorial(n)] = {"0"};
	
	for (int i = 0; i<n; i++)
	{
		cout<<"Enter element " << i <<": ";
		cin>>a1[i];
	}
	
	cout<<endl;
	
	string temp;
	
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < n-1 ; i++)
		{
			swap(a1, n);
			store(a1, temp);
			compare(a1, a2, temp, r);
		}
	}
	
	return 0;
}