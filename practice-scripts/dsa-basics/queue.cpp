#include<iostream>
using namespace std;

struct node{
	node*next;
	int data;
	
	node()
	{
		next = NULL;
	}
	
	node(int data)
	{
		next = NULL;
		this->data = data;
	}
};

bool isEmpty(node*top, node*rear)
{
	if((!top) && (!rear)) return true;
	return false;
}

node*createNode(int data)
{
	node*new_node = new node(data);
	return new_node;
}

void insert(int data, node**top, node**rear)
{
	node*new_node = createNode(data);
	if(isEmpty(*top, *rear)) 
	{
		*top = *rear = new_node;
		return;
	}
	if((*top) == (*rear)) 
	{
		*rear = new_node;
		(*rear)->next = *top;
		return;
	}
	node*temp = *rear;
	*rear = new_node;
	(*rear)->next = temp;
}

void remove(node**top, node**rear)
{
	if(isEmpty(*top,*rear))
	{
		cout<<"\nQueue is empty!";
		return;
	}
	if((*top) == (*rear)) 
	{
		*rear = *top = NULL;
		delete *rear;
		delete *top;
		return;
	}
	node*node_to_dlt = *top;
	
	node*temp = *rear;
	while(temp->next != *top) temp = temp->next;
	
	*top = temp;
	(*top)->next = NULL;
	delete node_to_dlt;
}

void print(node*rear)
{
	node*temp = rear;
	while(temp)
	{
		cout<<"Data: "<<temp->data<<" << Address: "<<temp<<endl;
		temp = temp->next;
	}
	cout<<endl;
}

int main()
{
	node*top = NULL, *rear = NULL;
	
	insert(10, &top, &rear);
	insert(6, &top, &rear);
	insert(3, &top, &rear);
	print(rear);
	
	remove(&top, &rear);
	remove(&top, &rear);
	remove(&top, &rear);
	remove(&top, &rear);
	print(rear);
	
	return 0;
}