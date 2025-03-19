 #include<iostream>
#include <fstream>
#include <string>
#define RANGE 255
#define MAX_TREE_HT 50
using namespace std;

char fileName[50];

string readFile(string fileName)
{
	ifstream myfile; 
	string store, line;
	
	myfile.open(fileName, ios::in);
	while(getline(myfile, line))
	{
		store += line;
	}
	myfile.close();
	
	return store;
}

double getLen(string s)
{
	int i=0;
	while(s[i]) i++;
	return i;
}

void cSort(string s, int*freq)
{
	int stringLength = getLen(s);
	
	for(int i=0;i<stringLength;i++) 
	{
		freq[s[i]] += 1;
	}	
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

void getFreqArr(int*f, int*freq)
{
	int j=-1;
	for(int i=0;i<RANGE;i++)
	{
		if(f[i]!=0) 
		{
			freq[++j] = f[i];
		}
	}
}

struct MinHNode 
{
  unsigned freq;
  char item;
  struct MinHNode *left, *right;
};

struct MinH 
{
  unsigned size;
  unsigned capacity;
  struct MinHNode **array;
};

// Creating Huffman tree node
struct MinHNode *newNode(char item, unsigned freq) 
{
  struct MinHNode *temp = (struct MinHNode *)malloc(sizeof(struct MinHNode));

  temp->left = temp->right = NULL;
  temp->item = item;
  temp->freq = freq;

  return temp;
}

// Create min heap using given capacity
struct MinH *createMinH(unsigned capacity) 
{
  struct MinH *minHeap = (struct MinH *)malloc(sizeof(struct MinH));
  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array = (struct MinHNode **)malloc(minHeap->capacity * sizeof(struct MinHNode *));
  return minHeap;
}

// Swap function
void swapMinHNode(struct MinHNode **a, struct MinHNode **b) 
{
  struct MinHNode *t = *a;
  *a = *b;
  *b = t;
}

void minHeapify(struct MinH *minHeap, int idx) 
{
  int smallest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
    smallest = left;

  if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
    smallest = right;

  if (smallest != idx) {
    swapMinHNode(&minHeap->array[smallest],
           &minHeap->array[idx]);
    minHeapify(minHeap, smallest);
  }
}

// Check if size if 1
int checkSizeOne(struct MinH *minHeap) 
{
  return (minHeap->size == 1);
}

// Extract the min
struct MinHNode *extractMin(struct MinH *minHeap) 
{
  struct MinHNode *temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];

  --minHeap->size;
  minHeapify(minHeap, 0);

  return temp;
}

// Insertion
void insertMinHeap(struct MinH *minHeap, struct MinHNode *minHeapNode) 
{
  ++minHeap->size;
  int i = minHeap->size - 1;

  while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
    minHeap->array[i] = minHeap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }

  minHeap->array[i] = minHeapNode;
}

// BUild min heap
void buildMinHeap(struct MinH *minHeap) 
{
  int n = minHeap->size - 1;
  int i;

  for (i = (n - 1) / 2; i >= 0; --i)
    minHeapify(minHeap, i);
}

int isLeaf(struct MinHNode *root) 
{
  return !(root->left) && !(root->right);
}

struct MinH *createAndBuildMinHeap(char item[], int freq[], int size) 
{
  struct MinH *minHeap = createMinH(size);

  for (int i = 0; i < size; ++i)
    minHeap->array[i] = newNode(item[i], freq[i]);

  minHeap->size = size;
  buildMinHeap(minHeap);

  return minHeap;
}

struct MinHNode *buildHfTree(char item[], int freq[], int size) 
{
  struct MinHNode *left, *right, *top;
  struct MinH *minHeap = createAndBuildMinHeap(item, freq, size);

  while (!checkSizeOne(minHeap)) {
    left = extractMin(minHeap);
    right = extractMin(minHeap);

    top = newNode('$', left->freq + right->freq);

    top->left = left;
    top->right = right;

    insertMinHeap(minHeap, top);
  }
  return extractMin(minHeap);
}

// Print the array
void printArray(char item, int arr[], int n) 
{
	ofstream fout;   
	fout.open(fileName,ios::app);
	int i;
	fout<<item;
	for (i = 0; i < n; ++i)
	fout << arr[i];
	
	fout.close(); // Closing the file
}

void printHCodes(struct MinHNode *root, int arr[], int top) 
{
  if (root->left) {
    arr[top] = 0;
    printHCodes(root->left, arr, top + 1);
  }

  if (root->right) {
    arr[top] = 1;
    printHCodes(root->right, arr, top + 1);
  }
  if (isLeaf(root)) {
    printArray(root->item, arr, top);
  }
}

void HuffmanCodes(char item[], int freq[], int size) 
{
 	struct MinHNode *root = buildHfTree(item, freq, size);

	int arr[MAX_TREE_HT], top = 0;
	
	printHCodes(root, arr, top);
}

void computeRatio(string orgFile, string newFile)
{
	cout<<"\nCompression successful!\n";
	cout<<"Size of original file: "<<getLen(orgFile)<<" Bytes";
	cout<<"\nSize of compressed file: "<<getLen(newFile)<<" Bytes";
	cout<<"\nCompression Ratio: "<<(double(getLen(orgFile)/getLen(newFile)))*100<<"%";
	
	cout<<endl<<endl;
}

void getInput()
{
	cout<<"Enter text file name and exact location: ";
	cin>>fileName;
}

int main() 
{
	// C:/compressedFiles/test.txt		
	getInput();
	
	// Get Data from file and store it in a string var:
	string fileData = readFile(fileName);
	
	// Using counting sort to get frequency of each char:
	int f[RANGE+1]={};  // freq array is of size 128
	cSort(fileData, f);
	
	int n = uniqueCharLen(f), freq[n]={};
	getFreqArr(f, freq);
	char charArr[n];
	getCharArr(f, charArr);
	
	int size = sizeof(charArr) / sizeof(charArr[0]);
	
	ofstream fout;   
	fout.open(fileName,ios::trunc);
	fout.close();

	HuffmanCodes(charArr, freq, size);
	
	string s = readFile(fileName);
	
	computeRatio(fileData, s);
	
	return 0;
}