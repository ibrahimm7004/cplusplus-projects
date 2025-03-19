#include<iostream>
#include"h.cpp"
#include"countingSort.cpp"
#define RANGE 127
using namespace std;

void print(int freq[], char c[], int n)
{
	int i=0;
	cout<<"\n\nCHARS:\n";
	while(c[i]) 
	{
		cout<<c[i]<<" ";
		i++;
	}
	i=0;
	  
	cout<<"\n\n\n\n\FREQUENCY:\n";
	for(i=0;i<n;i++) cout<<freq[i]<<" ";
}

int main()
{
	string store = readFile();
	int freq[RANGE+1]={};
	cSort(store, freq);
	
	int n=uniqueCharLen(freq);
	char charArr[n];
	getCharArr(freq, charArr);
	cout<<"\n\n\n\n\FREQUENCY:\n";
	for(int i=0;i<n;i++) cout<<freq[i]<<" ";
	print(freq, charArr,n);

	return 0;
}