#include<iostream>
#define RANGE 127
using namespace std;

int getMax(int a[])
{
	int i=1, max=a[0];
	while(a[i])
	{
		if(a[i] > max) max = a[i];
		i++;
	}
	return max;
}

void countingSort(int a[], char b[], int n)
{
	int c[getMax(a)];
	
	for(int i=0;i<n;i++)
	c[a[i]] = c[a[i]]++;
	
	for(int i=1;i<getMax(a);i++)
	c[i] += c[i-1];
	
	for(int i=0;i<n;i++) cout<< c[i]<<" ";
}

void print(int a[])
{
	int i=0;
	while(a[i]) 
	{
		cout<<a[i]<<" ";
		i++;
	}
}

int main()
{
	int i;
	cin>>i;
	char a[i] = {};
	char b[i];
	
	for(int j=0;j<i;j++) cin>>a[j];
	cout<<getMax(a);
	//countingSort(a,b,i);
	//print(a);
	
	return 0;
}