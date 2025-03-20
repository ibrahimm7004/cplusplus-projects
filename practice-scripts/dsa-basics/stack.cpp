#include<iostream>
using namespace std;

struct node
{
	node*next;
	int data;
	
	node()
	{
		next = NULL;
	};
	
	node(int data)
	{
		next = NULL;
		this->data = data;
	}
	
};

node*createStack()
{
	node*new_node = new node;
	new_node = NULL;
	return new_node;
}

node*createNode(int data)
{
	node*new_node = new node(data);
	return new_node;
}

bool isEmpty(node*head)
{
	if(!(head)) return true;
	return false;
}

void push(node**head, int data)
{
	node*new_node = new node(data);
	if(isEmpty(*head)) 
	{
		*head = new_node;
		return;
	}
	node*temp = *head;
	*head = new_node;
	(*head)->next = temp;
}

void pop(node**head)
{
	if(isEmpty(*head))
	{
		cout<<"\nStack is empty!";
		return;
	}
	node*node_to_dlt = *head;
	*head = node_to_dlt->next;
	delete node_to_dlt;
}

void print(node*head)
{
	node*temp = head;
	while(temp)
	{
		cout<<"Data: "<<temp->data<<" >> Address: "<< temp<<endl;
		temp = temp->next;
	}
	cout<<endl;
}

int main()
{
	node*head = createStack();

	push(&head, 10);
	push(&head, 1);
	push(&head, 3);
	
	print(head);
	
	pop(&head);
	print(head);
	
	pop(&head);
	print(head);
	
	return 0;
}
