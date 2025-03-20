#include<iostream>
using namespace std;

struct node{
	node*left, *right;
	int data;
	
	node(){	}
	
	node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

node*createNode(int data)
{
	node*new_node = new node(data);
	return new_node;
}

bool isEmpty(node*root)
{
	if(!root) return true;
	return false;
}

node*insert(node*root, int data)
{
	if(isEmpty(root)) return createNode(data);
	if(root->data > data) root->left = insert(root->left, data);
	else root->right = insert(root->right, data);
	return root;
}

void iPrint(node*root)
{
	if(isEmpty(root)) return;
	iPrint(root->left);
	cout<<root->data<<" ";
	iPrint(root->right);
}

void prePrint(node*root)
{
	if(isEmpty(root)) return;
	cout<<root->data<<" ";
	prePrint(root->left);
	prePrint(root->right);
}

void postPrint(node*root)
{
	if(isEmpty(root)) return;
	postPrint(root->left);
	postPrint(root->right);
	cout<<root->data<<" ";
}

node*search(node*root, int data)
{
	if(isEmpty(root)) return NULL;
	
	if(root->data == data) return root;
	if(data < root->data) return search(root->left,data);
	return search(root->right, data);
}

int main()
{
	node*root = createNode(10);
	node*left = createNode(4);
	node*right = createNode(13);
	root->left = left;
	root->right = right;
	
	cout<<"Infix:\n";
	iPrint(root);
	cout<<endl<<"\nPrefix:\n";
	prePrint(root);
	cout<<endl<<"\nPostfix:\n";
	postPrint(root);
	
	int data;
	cout<<"\n\nEnter data to search: ";
	cin>>data;
	if(search(root, data))
	cout<<endl<<(search(root, data)->data)<<" found at: "<<search(root, data);
	else cout<<"\nData not found";
	
	return 0;
}