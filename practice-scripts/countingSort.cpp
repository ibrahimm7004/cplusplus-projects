#include<iostream>
using namespace std;

int main()
{
	int n=7;
	int a[n] = {4,2,2,8,3,3,1}, max=a[0];

	for(int i=1;i<n;i++)
		if(a[i]>max) max = a[i];
	
	int indexArr[max+1];
	
	for(int i=0;i<=max;i++)
	{
		indexArr[i] = 0;
	}
	
	for(int i=0;i<n;i++)
	{
		indexArr[a[i]]++;
	}
	
	for(int i=1;i<=max;i++) 
	{
		indexArr[i] += indexArr[i-1];
	}
	
	int outputArr[n];
	
	for(int i=0;i<n;i++) 
	{
//		outputArr[indexArr[a[i]]-1] = a[i];
		outputArr[indexArr[a[i]] - 1] = a[i];
    	indexArr[a[i]]--;
	}
	
	
	for(int i=0;i<n;i++) cout<<outputArr[i]<<" ";
		
	return 0;
}