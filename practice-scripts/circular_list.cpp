#include <iostream>
using namespace std;

struct node
{
	node*next;
	int data;
	
	node(int d){
		data = d;
		next = NULL;
	};
};

bool isEmpty(node*head)
{
	if (!(head)) return true;
	else return false;
}

int size(node*head)
{
	int i = 0;
	
	if (isEmpty(head)) return i;
	
	node*temp = head;
	
	do
	{
		i++;
		temp = temp->next;
	}
	while(temp != head);
	
	return i;
}

void L_search(node*head, int data)
{
	node*temp = head;
	
	do
	{
		if (temp->data == data)
		{
			cout << "\nFound " << data << " at Address: " << temp<<endl;
			return;
		}	
		temp = temp->next;
	}
	while(temp!=head);
	cout << "\nData not found.\n";
}

void create_firstNode(node**head, int data)
{
	node*new_node = new node(data);
	*head = new_node;
	(*head)->next = *head;
}

void push_at_start(node**head, int data)
{
	
	if (isEmpty(*head))         // First node
	{
		create_firstNode(head, data);
		return;	
	}
	node*new_node = new node(data);
	node*temp = (*head)->next;       
	new_node->next = temp;
	(*head)->next = new_node;
}

void push(node**head, int data, int search_data)
{
	bool found = false;
	node*temp = (*head);
	
	do
	{
		if (temp->data == search_data)
		{	
			found = true;
			break;
		}
		temp = temp->next;
	}
	while(temp!=(*head));
	
	if(found)
	{
		node*new_node = new node(data);
		new_node->next = temp->next;
		temp->next = new_node;
		return;	
	}
	cout << "Data not found in list.\n";
}

void push_at_end(node**head, int data)
{
	
	if (isEmpty(*head))
	{
		create_firstNode(head, data);
		return;	
	}
	
	node*new_node = new node(data);
	node*temp =  *head;
	new_node->next = (*head)->next;
	(*head)->next = new_node;
	*head = new_node;
	new_node = temp;
}

void pop_first(node**head)
{
	if (isEmpty(*head)) 
	{
		cout << "\nList is empty, no nodes to delete.\n";
		return;
	}
	node*node_to_dlt = (*head)->next;
	node*temp1 = (*head)->next->next;
	(*head)->next = temp1;
	delete node_to_dlt;
}

void pop(node**head, int data)
{
	node*temp = *head;
	bool found = false;
	
		if (isEmpty(*head)) 
	{
		cout << "\nList is empty, no nodes to delete.\n";
		return;
	}
	
	do
	{
		if (temp->next->data == data) 
		{
			found = true;
			break;
		}
		temp = temp->next;
	}
	while(temp != *head);
	
	if (found)
	{
		node*node_to_dlt = temp;
		node_to_dlt = node_to_dlt->next;
		temp->next = node_to_dlt->next;
		delete node_to_dlt;
		return;
	}
	cout << "Data does not exist in list.\n";
}

void pop_last(node**head)
{
	if (isEmpty(*head)) 
	{
		cout << "\nList is empty, no nodes to delete.\n";
		return;
	}
	node*node_to_dlt = *head;
	node*temp = *head;
	while(temp->next != (*head)) temp = temp->next;
	*head = temp;
	(*head)->next = node_to_dlt->next;
	delete node_to_dlt;
}

void update(node**head, int data, int data_to_update)
{
	node*temp = *head;
	bool found = false;
	
	do
	{
		if (temp->data == data_to_update)
		{	
			found = true;
			temp->data = data;
			return;
		}
		temp = temp->next;
	}
	while(temp!=(*head));
	
	cout << "\nData not found in list.\n";
}

void print(node*head)
{
	if (isEmpty(head)) return;
	
	node*temp = head->next;

	cout << endl;
	while(temp->next != head->next)
	{
		cout << "\tData: " << temp->data << "    Address: " << temp << endl;
		temp = temp->next;
	}
	cout << "\tData: " << temp->data << "    Address: " << temp << endl;
}
//
//node* middle(node*first, node*last)
//{
//	node*fast = first;
//	node*last = first;
//	
//	if (first == NULL) return NULL;
//	
//	while(fast!=last)
//	{
//		fast = fast->next;
//		if (fast!=last)
//		{
//			fast = fast->next;
//			slow = slow->next;
//		}
//	}
//	return slow;
//}

void sort(node**head)
{
	int l = size(*head);
	int a, b, c, temp;
	
	node*current = new node(0);
	node*new_node = new node(0);
	
	for (a=0;a<l-1;a++)
	{
		c--;
		current = *head;
		new_node = (*head)->next;
			for (b=0;b<c;b++)
			{
				if (current->data > new_node->data)
				{
					temp = current->data;
					current->data = new_node->data;
					new_node->data = temp;
				}
				current = new_node;
				new_node = new_node->next;
			}
	}
}

int main()
{
	node*head = NULL;
	int data, d;
	bool valid = true, print_list = true;
	
	cout << "CIRCULAR LINKED LIST";
	
	while(valid)
	{
		print_list = true;
		cout << "\n\n1) Insertion\n2) Deletion\n3) Update\n4) Linear Search\n5) Sort\n6) Binary Search\n7) Is Empty\n8) Size\n9) Exit\n\n";
		cin >> data;
		
		switch(data)
		{
			case 1:
				cout << "\n1) Insert at start\n2) Insert in the middle\n3) Insert at end\n\n";
				cin >> data;
				switch(data)
				{
					case 1:
						cout << "\nEnter data to insert: ";
						cin >> data;
						push_at_start(&head, data);
					break;
					case 2:
						if (isEmpty(head)) 
						{
							cout << "\nList is empty, cannot insert in the middle.\n";
							break;
						}
						cout << "\nWhich node to insert after: ";
						cin >> d;
						cout << "Enter data to insert: ";
						cin >> data;
						push(&head, data, d);
					break;	
					case 3:
						cout << "\nEnter data to insert: ";
						cin >> data;
						push_at_end(&head, data);
					break;	
					default:
						cout << "\nEnter a valid option.\n";
				}
			break;
				
			case 2:	
				if (isEmpty(head)) 
					{
						cout << "\nList is empty, no node to delete.\n";
						break;
					}
				cout << "\n1) Delete First Node\n2) Delete A Specific Node\n3) Delete Last Node\n\n";
				cin >> data;
					switch(data)
				{
					case 1:
						pop_first(&head);
					break;
					case 2:
						cout << "\nWhich node to delete: ";
						cin >> data;
						pop(&head, data);
					break;	
					case 3:
						pop_last(&head);
					break;	
					default:
						cout << "\nEnter a valid option.\n";
				}
			break;
			
			case 3:
				cout <<"\nWhich data to update: ";
				cin >> d;
				cout <<"Enter new data to insert: ";
				cin >> data;
				update(&head, data, d);
			break;
				
			case 4:
				cout <<"\nEnter data to search for: ";
				cin >> data;
				L_search(head, data);	
				print_list = false;
			break;
			
			case 5:
				sort(&head);
			break;	
				
			case 7:
				if (isEmpty(head)) cout << "\nList is Empty\n";
				else cout << "\nList is not Empty\n";
				print_list = true;
			break;
				
			case 8:
				cout << "\nSize of list is: " << size(head) << endl;
				print_list = false;
			break;
				
			case 9:
				valid = false;
				print_list = false;
			break;
		}
	
		if (print_list) print(head);
	}
	
	return 0;
}

















