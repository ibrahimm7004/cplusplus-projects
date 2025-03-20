#include <iostream>
using namespace std;

bool valid = true;

struct node
{
	int data;
	node * next;
};

void print(node*ptr)
{
	node * temp = new node;
	temp = ptr;
	
	cout<<endl;
	
	while(temp)
	{
		cout << temp->data << "    " << temp << endl;
		temp = temp->next;
	}
	
	cout << endl << endl;
}

void pushAtFirst(node**head)
{
	int data;
	node*newNode = new node();
	newNode->next = *head;
	*head = newNode;
	
	cout<<"\nEnter data: ";
	cin >> newNode->data;	
}

void push(node*ptr)
{
	int data;
	node*temp;
	node*newNode = new node();
	node*tempNode = new node();
	tempNode = ptr;
	
	cout << "\nInsert data after which node? " << endl;
	cin >> data;
	
	for(;tempNode;tempNode = tempNode->next)
	{
		if (tempNode->data == data)
		temp = ptr;
	}
	
	newNode->next = ptr->next;
	ptr->next = newNode; 
	
	cout << "\nInsert data: \n";
	cin >> newNode->data;
	
}

void pushAtEnd(node**head)
{
	int data;
	node*temp = *head;
	node*newNode = new node();
	
	while(temp)
	{
		if(temp->next == NULL) break;
		temp = temp->next;
	}
	
	temp->next = newNode;
	newNode->next = NULL;

	cout<<"Enter data: \n";
	cin >> newNode->data;

}

void remove(node**head)
{
	int data, count = 0;
	cout<<"\nDeletion of which node: ";
	cin >> data;
	
	node*temp = *head;
	node*previous = *head;
	
	if (temp->next != NULL)
	{
	while (temp->data != data) temp = temp->next;
	while(previous->next->data != data) previous = previous->next;
	previous->next = temp->next;
	delete temp;
	}
	else valid = false;
}

void popAtFirst(node**head)
{
	node*temp = *head;
	
	if (temp->next != NULL)
	{
	*head = (*head)->next;
	delete temp; 
	}
	else valid = false;
}

void popAtEnd(node**head)
{
	node*temp = *head;
	while(temp->next->next != NULL)
	temp = temp->next;
	
	if (temp->next != NULL)
	{
	temp->next = NULL;
	node*lastNode = new node();
	while(lastNode->next != NULL) lastNode = lastNode->next;
	delete lastNode;
	}
	else valid = false;
}

void search(node*head)
{
	int data;
	cout<<"\nEnter data to search: \n\n";
	cin >> data;
	bool check = false;
	node*ptr = new node();
	ptr = head; 
	
	while(ptr) 
	{
		if(ptr->data == data)
		{check = true; break;}
		ptr = ptr->next;
	}
	
	if (check == true)
	cout << "\nData found at address: "<<ptr<<endl<<endl;
	else cout<<"\nData not found.";
}

void reverse(node**head)
{
	node*current = *head;
	node*previous = new node();
	node*next1 = new node();
	previous = NULL;
	current = *head;

while(current)
{
	next1 = current->next;
	current->next = previous;
	previous = current;
	current = next1;
}

*head = previous;
}


int main()
{
	node*head = new node();
	head->next = NULL;
	node**doublePtr = &head;
		
	int input;
	char charInput;
	bool finish = false;
	int choice = 0;
	
	while(finish != true)
	{
	
	if (choice == 0) 
	{
	system("CLS"); 
	print(head);
	choice = 0;
	}
	else
	{
	if (input == 4) print(head);
	cout << "\nPress any key to continue.\n";	
	cin >> charInput; 
	system("CLS"); 
	choice = 0;
	}
	if (valid == false) 
	{
	cout << "Cannot delete last node.\n";
	valid = true;
	}
	cout << "\nChoose from the following operations: \n\n1) Insert\n2) Delete \n3) Search \n4) Reverse\n5) Exit\n\n";
	cin >> input;
	
	switch(input)
	{
		case 1:
			cout << "\nChoose from the following insertion operations: \n\n1) Front\n2) Middle\n3) End\n\n";
			cin >> input;
			cout<<endl;
			switch(input)
			{
				case 1:
					pushAtFirst(doublePtr);
					break;
				case 2:
					push(head);
					break;
				case 3:
					pushAtEnd(doublePtr);
					break;	
			}
			break;
		case 2:
			cout << "\nChoose from the following deletion operations: \n\n1) Front\n2) Middle\n3) End\n\n";	
			cin >> input;
			switch(input)
			{
				case 1:
					popAtFirst(doublePtr);
					break;
				case 2:
					remove(doublePtr);
					break;
				case 3:
					popAtEnd(doublePtr);
					break;	
			}
			break;
		case 3:
			choice = 1;
			search(head);
			break;
		case 4:
			reverse(doublePtr);
			choice = 1;
			break;
		case 5:
			finish = true;	
			break;	
		default:
			cout << "Enter a valid option.";		
	}
	
}

	return 0;
}