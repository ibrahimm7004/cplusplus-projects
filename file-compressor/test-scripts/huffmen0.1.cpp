#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int i = 0;

struct node
{
	char c;
	int freq, index;
	node*next;
	
	node(char c)
	{
		this->c = c;
		this->freq = 1;
		next = NULL;
	};
};

bool isEmpty(node*head)
{
	if(!(head)) return true;
	return false;
}

node*check(char c, node*head)
{
	node*temp = head;
	
	if(isEmpty(head)) return NULL;
	
	while(temp)
	{
		if(temp->c == c) return temp;
		temp=temp->next;
	}
	return NULL;
}

void createNode(node**head, char c)  // head should always be top node
{
	node*new_node = new node(c);
	if(isEmpty(*head)) 
	{
		*head=new_node;
		return;
	}
	
	node*temp = *head;
	*head=new_node;
	(*head)->next = temp;
}

struct tNode
{
	tNode*left, *right;
	char c;
	int freq;
	
	tNode(int freq, char c)
	{
		this->freq = freq;
		this->c = c;
	};
};

class binaryTree{
	public:

		bool isEmpty(tNode*root)
		{
			if(!(root)) return true;
			return false;
		}
		
		tNode*createNode(int freq, char c)
		{
			tNode*new_tNode = new tNode(freq, c);
			new_tNode->right = new_tNode->left = NULL;
			new_node->index = index++;
			return new_tNode;
		}
		
		tNode*insert(tNode*root, int freq, char c)
		{
			if(isEmpty(root)) return createNode(freq, c);
			if(freq>root->freq) root->right = insert(root->right, freq, c);
			else root->left = insert(root->left, freq, c);
			return root;
		}
		
		tNode*createTree(node**head, tNode*root)
		{
			node*temp=*head;
			while(temp)
			{
				root = insert(root, temp->freq, temp->c);
				temp=temp->next;
			}
			return root;
		}
		
		int i=0;
		void prePrint(tNode*root)
		{
			if(isEmpty(root)) return;
			cout<<i++<<" -> ("<<root->c<<", "<<root->freq<<")\n";
			prePrint(root->left);
			prePrint(root->right);
		}
};

void print(node*head)
{
	node*temp = head;
	int i=0;
	while(temp)
	{
		cout<<i++<<" -> Char: "<<temp->c<<" has a frequency of "<<temp->freq<<endl;
		temp=temp->next;
	}
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

node*sortChars(string store)
{
	node*head=NULL, *temp=NULL;	
	int i=0;
	
	while(store[i])
	{
		temp = check(store[i], head);
		if(temp == NULL) 
		{
			createNode(&head, store[i]);
		}
		else 
		{
			temp->freq++; 
		}
		i++;
	}
	return head;
}

class heap
{
	public:
		
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
	
	void getArray(node*root, int a[])
	{
		int i=0;
		node*temp = root;
		while(temp)
		{
			a[i] = temp->freq;
			i++;
			temp=temp->next
		}
	}
	
	void build_minheap(int *a, int n)
	{
	    int i;
	    for(i = n/2; i >= 1; i--)
	    {
	        min_heapify(a,i,n);
	    }
	}

		
};

int main()
{
	string store = readFile();
	
	node*head = sortChars(store);

	print(head);
	
	cout<<endl<<endl;
	binaryTree bt;
	tNode*root=NULL;
	root = bt.createTree(&head, root);
	bt.prePrint(root);

	return 0;
}