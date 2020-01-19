#include<iostream>
#define MAX 20
using namespace std;

class queue
{
public:
	int q[MAX];
	int front;
	int rear;
	queue()
	{
		front=-1;
		rear=-1;
	}
	void insert();
	void remove();
	int q_overflow();
	int q_undeflow();
	void display();
};

int queue::q_overflow()
{
	if(rear==MAX-1)
		return 1;
	else
		return 0;
}
int queue::q_undeflow()
{
	if(front==-1&rear==-1)
		return 1;
	else
		return 0;
}
void queue::insert()
{
	int x;
	cout << "\n Enter the element : \n ";
	cin >> x;
	if(q_overflow()==1)
		cout << "\nQueue is full \n";
	else
	{
		if(front==-1&&rear==-1)
		{
			front=0;
			rear=0;
			q[rear]=x;
		}
		else
		{
			rear++;
			q[rear]=x;
		}
	}
}
void queue::remove()
{
	int x;
	if(q_undeflow()==1)
		cout << "\n Queue is empty \n";
	else
	{
		if(front==rear)
		{
			x=q[front];
			front=-1;
			rear=-1;
		}
		else
		{
			x=q[front];
			front++;
		}
		cout << x << " is deleted \n";
	}
}

void queue::display()
{
	int i;
	if(q_undeflow()==1)
		cout << "\n Queue is empty \n";
	else
	{
		for(i=front;i<=rear;i++)
		{
			cout << "\t" << q[i];
		}
	}
}
int main()
{
	int ch;
	char c;
	queue q;
do{	
	cout << "\n1.Add job \n2.display Queue \n3. delete job\n";
	cout << "Enter your choice \n";
	cin >> ch;
	switch(ch)
	{
		case 1:
		q.insert();
		break;
		case 2:
		q.display();
		break;
		case 3:
		q.remove();
		break;
	}
	cout<< "\nDo you want to continue\n";
	cin >> c;
}while(c=='y'||c=='Y');

	return 0;
}