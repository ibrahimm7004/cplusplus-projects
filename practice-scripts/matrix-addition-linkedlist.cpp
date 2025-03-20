#include <iostream>
using namespace std;

	// Using Doubly Linked List.
	struct node
	{
		node*next;
		node*previous;
		int data;
		node(int d)
		{
			data = d;
			previous = NULL;
			next = NULL;
		};  // Using parametrized constructor.
	};	
	
	// Predicate function to check if list is empty or not:
	bool isEmpty(node*head)
	{
		if (!(head)) return true; 
		else return false;
	}

	// Matrix elements will be inserted at first node of linked list each time, older elements will get pushed to end of list.
	void insert_first(node**head, int data)
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
		
		// All Other Cases:
		temp->previous = new_node;
		new_node->previous = NULL;
		new_node->next = temp;
		*head = new_node;
	}
	
	// Deletio will be done by removal of first element of list each time, hence implementing FIFO, since insertion is done at first node as well.
	void remove_first(node**head) 
	{
		node*temp = *head;
		
		// In case no node exists:
		if (isEmpty(*head)) 
		{
			cout << "List is already empty!\n";
			return;
		}
		
		// In case one node exists
		if (temp->next == NULL)
		{
			*head = NULL;
			delete temp;
			return;
		}
		
		// All other cases:
		node*node_to_dlt = *head;
		temp = temp->next;
		temp->previous = NULL;
		*head = temp;
		delete node_to_dlt;
	}	
	
	// Function to elaborately take input for each matrix, element by element:
	void matrixDataEntry(int m, int n, node**head)
	{
		int data;
		
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{	
				cout << "Data for ["<<i<<"]["<<j<<"]: ";
				cin>>data;
				insert_first(head, data);
			}
		}
	}
	
	// Function to take User Input for dimensions of the arrays as well as their respective elements:	
	void userInput(int &m, int &n, node**head1, node**head2)
	{
		cout << "Please enter the number of row(s) and column(s) for the matrix.\nRow(s): ";
		cin >> m;
		cout << "Column(s): ";
		cin >> n;
		
		cout << "\nEnter values for first matrix.\n";
		matrixDataEntry(m, n, head1);
		cout << "\nEnter values for second matrix.\n";
		matrixDataEntry(m, n, head2);	 
	}
	
	
	// Function to sum both linked lists(matrices) and store each poistion's sum in a third linked list:
	void sum(int m, int n, node**head1, node**head2, node**headSum)  // Uses dimensions of the matrices as parameters and 3 head node pointers, 1 for each linked list used.
	{
		int sum;  
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{	
				sum = (*head1)->data + (*head2)->data;  // Stores value of sum for each pair of corresponding elements from both arrays.
				insert_first(headSum, sum);  // Inserts this calculated sum in our third linked list which is designated for storing sums.
				remove_first(head1);  // Deletes first element stored in linked list 1(matrix 1), i.e. the last entry of the matrix(because FIFO is being used)
				remove_first(head2);  // Deletes first element stored in linked list 2(matrix 2), i.e. the last entry of the matrix(because FIFO is being used)
			}
		}
	}
	
	// Print function to display the Sum linked list. Prints elements in normal order.
	void print(node*head, int m, int n)
	{
		node*temp = head;
		
		cout << endl;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{		
				cout << "\t" << temp->data;
				temp = temp->next;
			}
			cout << endl;
		}
	}
	
	// Print function to display first 2 linked lists, which store the values for matrices 1 and 2. Prints elements in reverse order.
	void print_backwards(node*head, int m, int n)
	{
		node*temp = head;
		
		if (isEmpty(head)) return;
		
		while (temp->next->next) 
		temp = temp->next;  // Traverses to Second last
		
		temp = temp->next;   // Traverses to Last
		
		cout << endl;
		
		while(temp)
		{
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<n;j++)
				{		
					cout << "\t" << temp->data;
					temp = temp->previous;
				}
				cout << endl;
			}
		}
	}
	
	int main()
	{
		node*head1= NULL, *head2 = NULL, *headSum = NULL;
		int m, n; 
		
		userInput(m, n, &head1, &head2);  // Takes Input for both matrices
		
		cout << "\nFirst Matrix:";       
		print_backwards(head1, m, n);    // Prints first matrix according to given format
		cout << "\nSecond Matrix:";
		print_backwards(head2, m, n);	// Prints second matrix according to given format
		
		sum(m, n, &head1, &head2, &headSum);  //Sums both matrices(linked lists) and stores the sum in a third list.
		
		cout << "\nAfter Sum:";
		print(headSum, m, n);    // Prints Sum matrix according to given format
		
		
		return 0;
	}











