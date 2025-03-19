#include <iostream>
#include <fstream>
#include <string>
#define RANGE 127
using namespace std;

int getLen(string s)
{
	int i;
	while(s[i]) i++;
	return i;
}

void cSort(string a, int freq[])
{
	int j = getLen(a), i=0;
	
	for(int i=0;i<j;i++) freq[a[i]]+=1;	
}

int uniqueCharLen(int freq[])
{
	int i=0;
	while(freq[i]) i++;
	return i;
}

void getCharArr(int freq[], char c[])
{
	int j=0;
	for(int i=0;i<RANGE;i++) 
	{
		if(freq[i]!=0) 
		{
			c[j] = char(i); 
			j++;
		}
	}
}

