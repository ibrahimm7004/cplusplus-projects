#include <iostream>
using namespace std;

struct node
{
	node*next;
	int data;
};

struct node*middle (node*start, node*last)
{
	
node*fast=start;
node*slow=start;

if(!start) return NULL;

while(fast!=last)
{
	
	fast = fast->next;
	if(fast!=last)
	{
		slow = slow->next;
		fast = fast->next;
	}
}
return slow;

};

struct node* bSearch (node*start, node*last, int val)
{
	node*mid = NULL;
	do
	{
		mid = middle(start, last);
		
		if(mid=NULL) return NULL;
		
		if(mid->data == val) return mid;
		else if (mid->data < val) start = mid->next;
		else last = mid;
	}
	while (last == NULL || last!=start);
}


void print(node*ptr)
{
	node * temp = new node();
	temp = ptr;
	
	cout<<endl;
	
	while(temp)
	{
		cout << temp->data << "    " << temp << endl;
		temp = temp->next;
	}
	
	cout << endl << endl;
}

int main()
{
	node*head = new node();
	node*node2 = new node();
	node*node3 = new node();
	node*node4 = new node();
	node*node5 = new node();
	
	head->data = 10;
	head->next = node2;
	node2->data = 20;
	node2->next = node3;
	node3->data = 30;
	node3->next = node4;
	node4->data = 40;
	node4->next = node5;
	node5->data = 50;
	node5->next = NULL;
	
	print(head);
	node*temp = new node();
	temp = bSearch(head, node5, 30);
	if (temp == NULL) cout << "Not found. ";
	else cout << "Found at " << temp;
	
	
	
	
	return 0;
}