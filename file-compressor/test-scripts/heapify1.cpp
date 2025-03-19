#include <iostream>
using namespace std;

void min_heapify(int *a,int i,int n)
{
    int j, temp;   
    temp = a[i];   
    j = 2 * i;
    
    while (j <= n)
    {
        if (j < n && a[j+1] < a[j])
            j = j + 1;
        if (temp < a[j])
            break;
        else if (temp >= a[j])
        {
            a[j/2] = a[j];
            j = 2 * j;
        }
    }
    a[j/2] = temp;
    return;
}

void build_minheap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        min_heapify(a,i,n);
    }
}

int main()
{
	int n=10, a[n] = {2,14,6,8,4,1,23,56,2,5},i;
   
    build_minheap(a, n);
    
    cout<<"Min Heap\n";
    for (i = 1; i <= n; i++)
    {
        cout<<a[i]<<endl;
    }
	
	return 0;
}