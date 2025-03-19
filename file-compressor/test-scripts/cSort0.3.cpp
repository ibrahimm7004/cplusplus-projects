#include <iostream>
#include <fstream>
#include <string>
#define RANGE 127
using namespace std;

void cSort(string a, int j)
{
	int count[RANGE+1]={};
	
	for(int i=0;i<j;i++) count[a[i]]+=1;
	for(int i=0;i<RANGE;i++) cout<<i<<": "<<count[i]<<"\n";
}

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

int getLen(string s)
{
	int i=0;
	while(s[i])	i++;
	return i;
}
