#include <iostream>
using namespace std;

struct node
{
	int data;
	node*next;
		node(int d)
		{
			data = d;
			next = NULL;
		}
};

struct queue
{
	node*front;
	node*rear;
		queue()
		{
			front = rear = NULL;
		}	
		
	void enQueue(int d)
	{
		node*temp = new node(d);
		
		if (rear = NULL)	
	}	
};