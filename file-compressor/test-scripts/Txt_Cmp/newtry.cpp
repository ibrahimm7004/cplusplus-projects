#include<iostream>
#include <fstream>
#include <string>
#define RANGE 127
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

int getLen(string s)
{
	int i=0;
	while(s[i]) i++;
	return i;
}

void cSort(string s, int*freq)
{
	int j = getLen(s);
	
	for(int i=0;i<j;i++) freq[s[i]] += 1;	
}

int uniqueCharLen(int*freq)
{
	int j=0;
	for(int i=0;i<RANGE;i++)
		if(freq[i] != 0) j++;
	
	return j;
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

// Structure for tree nodes
struct Node {
	char character;
	int freq;
	struct Node *l, *r;
};

// Structure for min heap
struct Min_Heap {
	int size;
	struct Node** array;
};

Node*newNode(char c, int f)
{
	Node*new_node = new Node;
	new_node->character = c;
	new_node->freq = f;
	return new_node;
}

void Heapify(Min_Heap*Min_Heap, int i, int heap_size) {
  // Calculate the left and right child indices
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  // Find the index of the smallest element among the root, left child, and right child
  int smallest = i;
  if (left < heap_size && Min_Heap->array[left] < Min_Heap->array[smallest]) {
    smallest = left;
  }
  if (right < heap_size && Min_Heap->array[right] < Min_Heap->array[smallest]) {
    smallest = right;
  }

  // If the root is not the smallest element, swap it with the smallest element and heapify the sub-tree
  if (smallest != i) {
    swap(Min_Heap->array[i], Min_Heap->array[smallest]);
    Heapify(Min_Heap, smallest, heap_size);
  }
}

// Function to create min heap
struct Min_Heap* createAndBuildMin_Heap(char arr[], int freq[], int unique_size)
{
	int i;

	// Initializing heap
	Min_Heap* Min_Heap = (struct Min_Heap*)malloc(sizeof(struct Min_Heap));
	Min_Heap->size = unique_size;
	Min_Heap->array = (struct Node**)malloc(
		Min_Heap->size * sizeof(struct Node*));

	// Initializing the array of pointers in minheap.
	// Pointers pointing to new nodes of character
	// and their frequency
	for (i = 0; i < unique_size; ++i) {

		// newNode is a function
		// to initialize new node
		Min_Heap->array[i] = newNode(arr[i], freq[i]);
	}

	int n = Min_Heap->size - 1;
	for (i = (n - 1) / 2; i >= 0; --i) 
	{
		// Standard function for Heap creation
		Heapify(Min_Heap, i, n);
	}

	return Min_Heap;
}

#include <queue>


// Comparison function to compare two nodes of the min heap
struct Compare
{
    bool operator()(Node* l, Node* r)
    {
        return l->freq > r->freq;
    }
};

// Function to build Huffman Tree
//struct Node* buildHuffmanTree(char arr[], int freq[],
//							int unique_size, Min_Heap*Min_Heap)
//{
//	Node *l, *r, *top;
//	while (!isSizeOne(Min_Heap)) {
//		l = extractMinFromMin_Heap(Min_Heap);
//		r = extractMinFromMin_Heap(Min_Heap);
//		top = newNode('$', l->freq + r->freq);
//		top->l = l;
//		top->r = r;
//		insertIntoMin_Heap(Min_Heap, top);
//	}
//	return extractMinFromMin_Heap(Min_Heap);
//}

int main()
{
	// Get Data from file and store it in a string var:
	string fileData = readFile();
	
	// Using counting sort to get frequency of each char:
	int freq[RANGE+1]={};
	cSort(fileData, freq);
	
	// Make a char array of all unique characters in the file:
	int n=uniqueCharLen(freq);
	char charArr[n];
	cout<<n;
	getCharArr(freq, charArr);
	
	Min_Heap* minHeap = createAndBuildMin_Heap(charArr, freq, n);
	
	//Node* hTree = buildHuffmanTree(charArr, freq, n, Min_Heap);

	return 0;
}