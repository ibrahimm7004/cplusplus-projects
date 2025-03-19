#include <iostream>
#include <fstream>
#include <string>
#define RANGE 127
using namespace std;

struct node
{
	char c;
	int freq;
	node*left, *right;
	
	node() {
		left=right=NULL;
	};
	
	node(char c, int freq)
	{
		left=right=NULL;
		this->c = c;
		this->freq = freq;
	};
};

bool isEmpty(node*head)
{
	if(!(head)) return true;
	return false;
}

struct min_heap
{
	int n;
	node**list;	
	
	min_heap(int n)
	{
		this->n = n;
//		for(int j=0;j<n;j++) 
//		{
//			node*new_node = new node;
//			new_node=NULL;
//			list[j] = new_node;
//		} 
	};
};

void assignValues(node*n, char c, int f)
{
	n->freq = f;
	n->c = c;
}

void heapify(min_heap*h, int m, int n)
{
	int j, t;
	char c;
	t = h->list[m]->freq;
	c = h->list[m]->c;
	j=2*m;
	
	while(j<=n)
	{
		if(j<n && h->list[j+1]->freq < h->list[j]->freq) j++;
		if(t<h->list[j]->freq) break;
		else if(t>=h->list[j]->freq)
		{
			h->list[j/2]->freq = h->list[j]->freq;
			h->list[j/2]->c = h->list[j]->c;
			j*=2;
		}
	}
	h->list[j/2]->freq = t;
	h->list[j/2]->c = c;
	return;
}

min_heap*buildHeap(int c[], int n)
{
	min_heap h(n);
	
	int i=0, j=0;
	while(c[i])
	{
		if(c[i] != 0)
		{
			h.list[j] = new node;
			assignValues(h.list[j], char(i), c[i]);	
			j++;
		}
		i++;
	}
	
	n = h.n - 1;
    for (i = (n - 1) / 2; i >= 0; --i) heapify(&h, i, n);
	
	return &h;
}

int cSort(string a, int j, int *count)
{	
	for(int i=0;i<j;i++) count[a[i]]+=1;
		
	int k=0;	
	for(int i=0;i<RANGE;i++) if(count[i] != 0) k++;
	return k;
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

//int getUniqueChar(int*c)
//{
//	int i=0;
//	while(c[i]) i++;
//	return i;
//}

int main()
{
	int count[RANGE+1]={};
	string store = readFile();
	int n=cSort(store,getLen(store), count);
	
	min_heap*heap = buildHeap(count,n);
	for(int i=0;i<n;i++)
	cout<<heap->list[i]->c<<", "<<heap->list[i]->freq<<endl;	

	return 0;
}
