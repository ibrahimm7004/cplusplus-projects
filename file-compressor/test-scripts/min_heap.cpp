#include<iostream>
using namespace std;

void min_heapify(int*a, int n, int i)
{
	int j = 2*i;
	int temp=a[i];
	
	while(j<n+1)
	{
		if( (j < n) && ( a[j+1] < a[j] ) ) j++;
		if(temp < a[j]) break;
		else if (temp >= a[j])
		{
			a[j/2] = a[j];
			j *= 2;
		}
	} 
	a[j/2] = temp;
	return;
}

void build_min(int*a, int n)
{
	int i;
	for(i=n/2;i>=1;i--)	min_heapify(a,n,i);
}

int main()
{
	int n=10;
	
	int a[n] =  {4,1,5,3,6,2,7,3,42,1};
	
	build_min(a,n);	
	
	int i=0;
	cout<<"Min Heap\n";
    for (i = 1; i <= n; i++)
    {
        cout<<a[i]<<endl;
    }
	
	return 0;
}