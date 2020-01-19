#include<iostream>
#include<string.h>
using namespace std;

struct node
{
	int PRN;
	char name[10];
	struct node *next;
};
class sll
{
	public:
		node *head;
		sll()
		{
			head=NULL;
		}
		node *create();
		void display(node *);
		node *insert_president(node *);
		void insert_member(node *);
		void insert_secretary(node *);
		void total(node *);
		node *remove(node *);
		node *concat(node *, node *);
		void reverse(node *);
};

node *sll::create()
{
	node *n,*last,*head;
	int val;
	char ch,name1[10];
	head=NULL;
	do
	{
		cout << "\n Enter the PRN number of student\n";
		cin >> val;
		cout << "\n Enter the name of student\n";
		cin >> name1;
		n=new node;
		n->PRN=val;
		strcpy(n->name,name1);
		n->next=NULL;
		if(head==NULL)
		{
			head=n;
			last=n;
		}
		else
		{
			last->next=n;
			last=n;
		}
		cout <<"\n do you want to insert more nodes ?\n";
		cin >> ch;
	}while (ch=='y'||ch=='Y');
    return(head);
}

node *sll::insert_president(node *head)
{
	 node *temp,*n;
	 int val;
	 char name1[10];
	 temp=head;
	 cout << "\n Enter the PRN number \n";
	 cin >> val;
	 cout << "\n Enter the name of the students\n ";
	 cin >> name1;
	 
	 n= new node;
	 n->PRN=val;
	 strcpy(n->name,name1);
	 n->next=NULL;
	 if(temp==NULL)
	 {
	 	head=n;
	 }
	 else
	 {
	 	n->next=head;
	 	head=n;
	 }
	 return(head);
}

void sll::insert_secretary(node *head)
{
	node *temp,*n;
	int val;
	char name1[10];
	temp=head;
	cout << "\n Enter the PRN number \n";
	cin >> val;
	cout << "\n Enter the name of student \n";
	cin >> name1;
	
	n=new node;
	n->PRN=val;
	strcpy(n->name,name1);
	n->next=NULL;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=n;
}

void sll::insert_member(node *head)
{
	node*temp,*n;
	int val,d;
	char name1[10];
	temp=head;
	cout << "\nEnter the PRN number \n";
	cin >> val;
	cout << "\nEnter the name of stduent\n";
	cin >> name1;
	n=new node;
	n->PRN=val;
	strcpy(n->name,name1);
	n->next=NULL;
	cout << "\n enter the PRN of student after which you want to insert number \n ";
	cin >> d;
	while(temp->next!=NULL)
	{
		if(temp->PRN==d)
		break;
		else
		temp=temp->next;
	}
	if(temp==NULL)
	cout << "node not dound";
	else
	n->next=temp->next;
	temp->next=n;
}

node *sll::remove(node *head)
{
	node *curr,*prev;
	int d;
	curr=head;
	cout << "\n Enter the PRN of student that you want to delete \n ";
	cin >> d;
	while(curr!=NULL)
	{
		if(curr->PRN==d)
		break;
		else
		{
			prev=curr;
			curr=curr->next;
		}
	}
	if(curr==NULL)
	{
		cout <<"\n Node not found \n";
	}
	else
	{
		if(curr==head)
		{
			head=head->next;
		}
		else
		{
			prev->next=curr->next;
			cout << "\n Node deleted \n";
		}
	}
    return(head);
}

void sll::total(node *head)
{
	int count=0;
	node *temp;
	temp=head;
	if(temp==NULL)
		cout << "\n List is empty \n";
	else
	{
		while(temp!=NULL)
		{
			temp=temp->next;
			count++;
		}
	cout << "\nTotal no of nodes are :" << count;
	}
}

node *sll::concat(node *head1, node *head2)
{
	node *temp;
	temp=head1;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=head2;
	cout << "\n lists are concatinated \n";
	return(head1);
 }
void sll::reverse(node * head)
{
	if(head=NULL)
	return;
	reverse(head->next);
	cout << head->PRN <<"," << head->name << "->";
}
void sll::display(node * head)
{
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		cout << temp->PRN<<"," << temp->name << "->";
		temp=temp->next;
	}
}

int main()
{
	int ch,ch1;
	char c,cn;
	node *head,*head1,*head2,*head3;
	sll s;
	do
	{
		cout << "\n1. create ";
        cout << "\n2. Display ";
		cout << "\n3. insert memeber";
		cout << "\n4. delete member ";
		cout << "\n5. Total no of clubr ";
		cout << "\n6. concatinate two lists ";
		cout << "\n7. Display list reverse order";
		cout << "\n Enter ur choice \n";
		cin >>ch;
		switch(ch)
		{
		case 1:
			head=s.create();
			break;
		case 2:
			s.display(head);
			break;
		case 3:
			do
			{
				cout <<"\n1.insert_president \n2.insert_secretary\n3. insert_member\n";
				cout << "Enter your choice \n";
				cin>>ch1;
				switch(ch1)
				{
					case 1:
						head=s.insert_president(head);
						break;
					case 2:
						s.insert_secretary(head);
						break;
					case 3:
						s.insert_member(head);
						break;
				}
				cout << "\n Do you want to continue \n";
				cin >> cn;
			}while(cn=='Y'||cn=='Y');
			break;
		case 4:
		    head=s.remove(head);
			break;
		case 5:
			s.total(head);
			break;
		case 6:
			cout << "\nEnter the first list\n ";
			head1=s.create();
			s.display(head1);
	     	cout << "\nEnter the second list\n ";
			head2=s.create();
			s.display(head2);
			head3=s.concat(head1,head2);
			cout << "\n";
			s.display(head);
			break;
		case 7:
			s.reverse(head);
			break;
		}
		cout << "\nDo you want to continue \n";
		cin>>c;
	}while(c=='y'||c=='Y');
	return 0;
}
