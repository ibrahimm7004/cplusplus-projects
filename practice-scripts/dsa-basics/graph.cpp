#include<iostream>
using namespace std;

struct vertex{
	vertex*next;
	int data;
	
	vertex()
	{
		next = NULL;
	}
	
	vertex(int data)
	{
		next = NULL;
		this->data = data;
	}
};

struct graph{
	vertex**list;
	graph(int v)
	{
		list = new vertex*[v];
		for(int i=0;i<v;i++) list[i] = NULL;
	}
};

vertex*createVertex(int v_name)
{
	vertex*new_vertex = new vertex(v_name);
	return new_vertex;
}

vertex*returnLastVertex(vertex*v)
{
	vertex*temp = v;
	while(temp->next) temp=temp->next;
	return temp;
}

void createEdge(vertex*v1, vertex*v2)
{
	vertex*new1 = createVertex(v2->data);
	returnLastVertex(v1)->next = new1;
	
	vertex*new2 = createVertex(v1->data);
	returnLastVertex(v2)->next = new2;
}

void print(graph g, int v)
{
	vertex*temp;
	int i=0;
	
	while(i<v)
	{
		temp = g.list[i];
		while(temp)
		{
			cout<<temp->data<<"->";
			temp = temp->next;
		}
		i++;
		cout<<endl;
	}
}

int main()
{
	graph g(3);
	
	g.list[0] = createVertex(0);
	g.list[1] = createVertex(1);
	g.list[2] = createVertex(2);
	
	createEdge(g.list[0], g.list[1]);
	createEdge(g.list[0], g.list[2]);
	createEdge(g.list[1], g.list[2]);
	
	print(g, 3);
		
	return 0;
}