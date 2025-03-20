#include<iostream>
#include<vector>
using namespace std;

void swap(vector <int> & a)   //passing vector by reference
{
	int temp;
	for (int i = 0; i < a.size() ; i++)     //for loop from 0th index of vector till the max index
	{
		temp = a[i];      //simple swapping 
		a[i] = a[i+1];
		a[i+1] = temp;
	}
}

void store(vector <int> a, string str)
{
    for (int i = 0; i < a.size();i++) 
	{
        str.push_back(i + '0');
    }
    cout<<str;
}


int main()
{
	int n, input;
	cin>> n;
	vector <int> vec;
	
	for (int i = 0; i<n; i++)
	{
		cout<<"Enter element " << i <<": ";
		cin>>input;
		vec.push_back(input);
	}
	
	for (int i = 0; i < vec.size(); i++)
	{
		cout<<vec[i] << " ";
	}
	
	cout<<endl;
	
	vector <string> str;
	string temp;
	
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < n-1 ; i++)
		{
			swap(vec);
			store(vec, temp);
		}
	}
	vec.
	return 0;
}