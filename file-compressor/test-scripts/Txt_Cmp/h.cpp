#include<iostream>
#include <fstream>
#include <string>
using namespace std;

string readFile()
{
	ifstream myfile; 
	string store, line;
	
	myfile.open("c:/htree.txt", ios::in);
	while(getline(myfile, line))
	{
		store += line;
	}
	myfile.close();
	
	return store;
}

char*storeChars(string s)
{
	int i=0, k=0,j=0;
	bool valid;
	char*c;
	while(s[i])
	{
		j=0, valid=false;
		while(c[j]) 
		{
			if(c[j] == s[i]) 
			{
				valid=true;
			}
			j++;
		}
		if(valid) 
		{
			c[k] = s[i];
			k++;
		}
		i++;
	}
	return c;
}

void print(char*c)
{
	int i=0;
	
	while(c[i]) cout<<c[i]<<" ";
}

