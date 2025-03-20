#include<iostream>
#include"graph.cpp"
#include"queue.cpp"
using namespace std;

void bfs(node**top, node**rear, graph g)
{
	int i=1, n=9;
	
	bool traveresedArr[9] = {0};
	
	enQueue(g.list[0]->data, top, rear);
	traveresedArr[g.list[0]->data] = 1;
	
	while(!(isEmpty(*top, *rear)))
	{
		node*temp = *top;	
		vertex*t1 = g.list[temp->data];
		while(t1)
		{
			if(traveresedArr[t1->data] == 0)
			{
				enQueue(t1->data, top, rear);
				traveresedArr[t1->data] = 1;
			}
			t1 = t1->next;
		}
		i++;
		cout<<(*top)->data<<" ";
		deQueue(top, rear);
	}
}

int main()
{
	graph g(9);
	node*top, *rear;
	
	for(int i=0;i<9;i++) g.list[i] = createVertex(i);
	
	createEdge(g.list[0], g.list[1]);
	createEdge(g.list[0], g.list[5]);
	createEdge(g.list[1], g.list[2]);
	createEdge(g.list[1], g.list[3]);
	createEdge(g.list[3], g.list[4]);
	createEdge(g.list[4], g.list[7]);
	createEdge(g.list[5], g.list[6]);
	createEdge(g.list[5], g.list[8]);
	createEdge(g.list[6], g.list[7]);
	
	print(g, 9);
	cout<<endl<<endl;
	bfs(&top,&rear,g);
	
	
	return 0;
}