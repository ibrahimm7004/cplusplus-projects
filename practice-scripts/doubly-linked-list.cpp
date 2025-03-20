#include<iostream>
using namespace std;

struct node
{
	node*next;
	node*previous;
	int data;
	
	node(int d)
	{
		data = d;
		next = NULL;
		previous = NULL;
	;}
};

void print(node*head)
{
	node*temp = head;
	cout << endl;
	while(temp)
	{
		cout << "Data: " << temp->data << "    Address: " << temp << endl;
		temp = temp->next;
	}
	cout << endl<<endl;
}

bool isEmpty(node*head)
{
	if (!(head)) return true;
	return false;
}

void insert_at_end(node**head, int data)
{
	node*new_node = new node(data);
	
	// Inserting first node:
	if(isEmpty(*head)) 
	{
		new_node->next = NULL;
		new_node->previous = NULL;
		*head = new_node;		
		return;
	}
	
	// Insertion when atleast one node already exists:
	node*temp = *head;
	while(temp->next) temp=temp->next;
	temp->next = new_node;
	new_node->next = NULL;
	new_node->previous = temp;
}

void insert(node**head, int data, int search_data)
{
	
	if (isEmpty(*head)) 
	{
		cout << "List is empty. Cannot insert at middle.\n";
		return;
	}
	
	bool found = false;
	node*temp = *head;
	while(temp) 
	{
		if (temp->data == search_data) 
		{
			found = true;
			break;
			temp = temp->next;
		}
	}
		
		if (found)
		{
			node*new_node = new node(data);
			new_node->next = temp->next;
			new_node->previous = temp;
			temp->next = new_node;
			return;
		}
		cout << "Node does not exist.\n";
}

void reverse(node**head)
{
	node*temp = *head;
	node*ptr = NULL;
	
	while(temp != NULL)
	{
		ptr = temp->previous;
		cout << endl << temp->data << "\t" << ptr << endl;
		temp->previous = temp->next;
		temp->next = ptr; 
		temp = temp->previous;
	}
	
	if (ptr != NULL)
        *head = ptr->previous;
}

void delete_end(node**head)
{
	node*temp = *head;
	
	if (isEmpty(*head)) 
	{
		cout << "List is already empty!\n";
		return;
	}
	
	if (temp->next == NULL)
	{
		*head = NULL;
		delete temp;
		return;
	}
	
	while(temp->next->next) temp = temp->next;
	temp->next = NULL;
	temp = temp->next;
	delete temp;
}

void search(node**head, int data)
{
	node*temp = *head;
	 
	while(temp)
	{
		if (temp->data == data) 
		{
			cout << "Data found at " << temp;
			break;
		}
	cout << "Data not found in list.\n";	
	}
}

void delete_first(node**head)

{
	node*temp = *head;
	
	if (isEmpty(*head)) 
	{
		cout << "List is already empty!\n";
		return;
	}
	
	if (temp->next == NULL)
	{
		*head = NULL;
		delete temp;
		return;
	}
	
	node*node_to_dlt = *head;
	temp = temp->next;
	temp->previous = NULL;
	*head = temp;
	delete node_to_dlt;
}

void delete_middle(node**head, int data)
{
	node*temp = *head;
	bool found = false;
	
	if (isEmpty(*head)) 
	{
		cout << "List is already empty!\n";
		return;
	}
	
	while (temp)
	{
		if (temp->data == data) 
		{
			break;
			found = true;
		}
		temp = temp->next;
	}
	
	if (found)
	{
		if (temp->next == NULL)
		{
			*head = NULL;
			delete temp;
			return;
		}
		
		node*prev = temp->previous;
		node*next_one = temp->next;
		prev->next = next_one;
		next_one->previous = prev;
	    delete temp;
	}
	else cout << "\nNode does not exist in list.\n";
}

void insert_at_start(node**head, int data)
{
	node*temp = *head;
	node*new_node = new node(data);
	
	// Inserting first node:
	if(isEmpty(*head)) 
	{
		new_node->next = NULL;
		new_node->previous = NULL;
		*head = new_node;		
		return;
	}
	
	temp->previous = new_node;
	new_node->previous = NULL;
	new_node->next = temp;
	*head = new_node;
}

void print_backwards(node*head)
{
	node*temp = head;
	
	if (head->next == NULL) return;
	
	while (temp->next->next) 
	temp = temp->next;  // Traverses to Second last
	
	temp = temp->next;   // Traverses to Last
	
	cout << endl;
	
	while(temp)
	{
		cout << "Data: " << temp->data << "    Address: " << temp << endl;
		temp = temp->previous;
	}
	
	cout << endl<<endl;
}

void empty_list(node**head)
{
	node*temp = *head;
	
	while(!(isEmpty(*head))) delete_end(head);
}

int len(node*head)
{
	node*temp = head;
	int i = 0;
	
	while (temp) 
	{
		temp = temp->next;
		i++;
	}
	return i;
}

void sort (node**head)
{
	int i, j, k;
	int l = len(*head);
	
	node*current = *head;
	node*next_node = *head;
	k=0;
	
	for (i=0;i<l-1;i++)
	{
		k--;
		current = *head;
		next_node  = (*head)->next;
			for(k=0;k<i;k++)
			{
				if(current->data > next_node->data)
				{
					j = current->data;
					current->data = next_node->data;
					next_node->data = j;
				}
			}
		current = current->next;
		next_node = next_node->next;	
	}
}

node*middle(node*start, node*last)
{
	node*fast = start;
	node*slow = start;
	
	while(fast != last)
	{
		fast = fast->next;
		
		if(fast == last) break;
		fast = fast->next;
		slow = slow->next;
	}
return slow;	
}

node* binary_search(node**head, int data)
{
 	node*temp = *head;
 	node*start = *head;
	while (temp->next->next) temp = temp->next;
	temp = temp->next;
	
	do{
	node*mid = middle(start, temp);
	
	if (mid == NULL) return NULL;
	if (mid->data == data) return mid;
	if (mid->data > data) temp = mid;
	else start = mid->next;
	}
	while (temp == NULL || temp!=start);
}

int main()
{
	node*head = NULL;
	int data, d;
	bool choice = true;
	
	while(choice!=false)
	
	{
	cout << "Choose from the following:\n1) Insert\n2) Reverse\n3) Delete\n4) Print Backwards\n5) Empty List\n6) Sort\n7) Binary Search\n8) Exit\n\n";
	cin>>data;
	
		switch(data)
		{
			
			case 1:
				cout << "\n1) Insert at start\n2) Insert at middle\n3) Insert at end\n\n";
				cin >> data;
				switch (data)
				{
					case 1:
						cout <<"\nInsert data: ";
						cin>>data;
						insert_at_start(&head, data);
						print(head);
						break;
					case 2:
						cout << "\nInsert after which node: ";
						cin >> data;
						cout<<"\nInsert data: ";
						cin >> d;
						insert(&head, d, data);
						print(head);
						break;	
					case 3:
						cout <<"\nInsert data: ";
						cin>>data;
						insert_at_end(&head, data);	
						print(head);
					default:
						cout<<"Enter correct option.";	
				}
			break;
				
			case 2:
				reverse(&head);
				print(head);
			break;
					
			case 3:
				cout << "\n1) Delete first node\n2) Delete a specific node\n3) Delete last node\n\n";
				cin >> data;
				switch (data)
				{
					case 1:
						delete_first(&head);
						print(head);
						break;
					case 2:
						delete_middle(&head, data);						
						print(head);
						break;
					case 3:
						cout << "\nWhich node to delete: ";
						cin >> data;
						delete_end(&head);	
						print(head);
					break;	
					default:
						cout<<"Enter correct option.";	
				}
			break;	
			
			case 4:
				print_backwards(head);
			break;
			
			case 5:
				empty_list(&head);
				print(head);
			break;
			
			case 6:
				sort(&head);
				print(head);
			break;	
			
			case 7:
					cout << "Which data to search: ";
					cin >> data;				
					binary_search(&head, data);
			break;
			case 8:
				choice = false;
				break;
			
			default:
				cout << "Enter correct option.\n";
		}
	}
	
	return 0;
}
