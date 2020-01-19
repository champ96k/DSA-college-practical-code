/*Mr. Sujit A. Ahirrao
Sandip Institute of Engineering & Management
Write a function to get the number of vertices in an undirected graph and its edges. You may assume that no edge is input twice. 
ii. Use adjacency matrix representation of the graph and find runtime of the function 	 
*/
#include<iostream>
using namespace std;

class graph
  {
	int am[10][10];
	int v[10];
	public:
		graph();
		void create();
		void display();
		void DFS(int v1);
		static int edge_count;
		static int node_count;


  };
int graph::edge_count;
int graph::node_count;


graph::graph()
  {
    int i,j;
    for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
			{
				am[i][j]=0;
			}
	}
   for(i=0;i<10;i++)
	{
		v[i]=0;
	}
  }

void graph::create()
  {
	int v1,v2;
	char ans;
	do
	  {
		cout<<"\n\tEnter Source Vertex: ";
		cin>>v1;
		cout<<"\n\tEnter Destinaion Vertex: ";
		cin>>v2;
		am[v1][v2]=1;
		am[v2][v1]=1;
		cout<<"\n\t..... Do You Want to Add More Edges: ";
		cin>>ans;
		edge_count++;
	  }while(ans=='y'||ans=='Y');
  }

void graph::DFS(int v1)
  {
	int v2;
	cout<<"\t"<<v1;
	node_count++;
	v[v1]=1;
	for(v2=0;v2<edge_count;v2++)
		{
			if(am[v1][v2]==1 && v[v2]==0)
				{
					DFS(v2);
				}
		}
  }
void graph::display()
  {
	int i,j;
	for(i=0;i<node_count;i++)
	  {
		for(j=0;j<node_count;j++)
			{
				cout<<"\t"<<am[i][j];
			}
		cout<<"\n";
	  }
  }
	
main()
  {
	graph gr;
	int ch,v1;
	char ans;
	do
		{
			cout<<"\n\t***** Adjacency Matrix *****";
			cout<<"\n\t1. Create\n\t2. Display\n\t3. Exit\n\t..... Enter Your Choice: ";
			cin>>ch;
			switch(ch)
				{
					case 1:	gr.create();
							break;
					case 2:   cout<<"\n\t***** DFS Traversal of Graph *****";
							cout<<"\n\tEnter a Stating Vertex: ";
							cin>>v1;
							gr.DFS(v1);
							cout<<"\n\t***** Adjacency Matrix *****\n";
							gr.display();
							cout<<"\n\tTotal Number of Edges are "<<gr.edge_count;
							cout<<"\n\tTotal Number of Nodes are "<<gr.node_count;
							
							break;
					case 3:
							break;
				}
			cout<<"\n\t.... Do You Want to Continue: ";
			cin>>ans;
		}while(ans=='y'||ans=='Y');
  }

/*
	***** Adjacency Matrix *****
	1. Create
	2. Display
	3. Exit
	..... Enter Your Choice: 1

	Enter Source Vertex: 0

	Enter Destinaion Vertex: 1

	..... Do You Want to Add More Edges: y

	Enter Source Vertex: 0

	Enter Destinaion Vertex: 2

	..... Do You Want to Add More Edges: y

	Enter Source Vertex: 0

	Enter Destinaion Vertex: 3

	..... Do You Want to Add More Edges: y

	Enter Source Vertex: 1

	Enter Destinaion Vertex: 3

	..... Do You Want to Add More Edges: y

	Enter Source Vertex: 2

	Enter Destinaion Vertex: 3

	..... Do You Want to Add More Edges: y

	Enter Source Vertex: 2

	Enter Destinaion Vertex: 4

	..... Do You Want to Add More Edges: y

	Enter Source Vertex: 3

	Enter Destinaion Vertex: 4

	..... Do You Want to Add More Edges: n

	.... Do You Want to Continue: y

	***** Adjacency Matrix *****
	1. Create
	2. Display
	3. Exit
	..... Enter Your Choice: 2

	***** DFS Traversal of Graph *****
	Enter a Stating Vertex: 0
	0	1	3	2	4
	***** Adjacency Matrix *****
	0	1	1	1	0
	1	0	0	1	0
	1	0	0	1	1
	1	1	1	0	1
	0	0	1	1	0

	Total Number of Edges are 7
	Total Number of Nodes are 5
	.... Do You Want to Continue: n
*/
