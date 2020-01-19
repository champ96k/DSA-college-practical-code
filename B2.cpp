#include<iostream>
using namespace std;

struct node
{
 int data;
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
 node *insert_beg(node *);
 void insert_after(node *);
 void insert_end(node *);
 node *remove(node *);
 node *createsorted();
 node *merge(node *,node *);
 };
 node *sll::create()
 {
  node *n,*last;
  int val;
  char ch;
  do 
  {
   cout << "\n Enter the number :\n";
   cin >> val;
   n=new node;
   n->data=val;
   n->next=NULL;
   
   if(head==NULL)
   {
     head = n;
     last = n;
   }
   else
   {
    last->next=n;
    last=n;
   }
   cout << "\n Do you want to insert more nodes: ?";
   cin >> ch;
  }while(ch=='y'||ch=='Y');
  return(head);
 }
 
 node *sll::insert_beg(node *head)
 {
  node *temp,*n;
  int val;
  temp=head;
  cout << "\nEnter  the number \n";
  cin >> val;
  n=new node;
  n->data=val;
  n->next=NULL;
  if(head==NULL)
  {
   head = n;
  }
  else
  {
   n->next=head;
   head=n;
  }
  return(head);
 }
 
 void sll::insert_end(node *head)
 {
  node *temp,*n;
  int val;
  temp=head;
  cout << "\nEnter the number:";
  cin >> val;
  n=new node;
  n->data=val;
  n->next=NULL;
  while(temp->next!=NULL)
  {
  temp=temp->next;
  }
  temp->next=n;
 }
 
 void sll::insert_after(node *head)
 {
  node *temp,*n;
  int val,d;
  temp=head;
  cout << "\nEnter the number \n";
  cin >> val;
  n=new node;
  n->data=val;
  n->next=NULL;
  
  cout << "\n Enter the data of node after which you want to insert the node \n";
  cin>>d;
  while(temp->next!=NULL)
  {
  if(temp->data==d)
  break;
  else
  temp=temp->next;
  }
  if(temp==NULL)
  {
  cout << "\n Node not found \n";
  }
  else
  {
  n->next=temp->next;
  temp->next=n;
  }
 }
 
 node *sll::remove(node *head)
  {
  node *curr,*prev;
  int d;
  curr=head;
  while(curr!=NULL)
   {
     if(curr->data<0)
     break;
     else
     {
        prev=curr;
        curr=curr->next;
     }
   }
   if(curr==NULL)
    cout << "\n Node not found \n";
    else
    {
     if(curr==head)
     head=head->next;
     else 
     prev->next=curr->next;
     cout < "\n Node deleted \n";
    }
    return(head);
   }
  
  node *sll::createsorted()
  {
   node *n,*temp,*prev,*head;
   int val;
   char ch;
   temp=NULL;
   head=NULL;
   do{
       
        cout << "Enter the number: \n";
        cin >> val;
        n=new node;
        n->data=val;
        n->next=NULL;
        if(head==NULL)
        {
         head=n;
        }
        else
        {
         temp=head;
         prev=NULL;
         while(temp!=NULL)
         {
          if(temp->data<n->data)
          {
           prev=temp;
           temp=temp->next;
          }
          else    
           break;
        } 
          if(prev==NULL)
          {
           n->next=head;
           head=n;
          }
          else
           
		   {
		   n->next=prev->next;
           prev->next=n;
         }
        }
         cout << "\nDo you want to continue \n";
         cin >> ch;
        }while(ch=='y'||ch=='Y');
        return (head);
     }

  
  node *sll::merge(node *head1,node *head2)
  {
   node *head3;
   head3=NULL;
   if(head1==NULL)
     return(head2);
     else if(head2==NULL)
      return(head1);
    if(head1->data<=head2->data)
    {
     head3=head1;
     head3->next=merge(head1->next,head2);
    }
   else
    {
    head3=head2;
    head3->next=merge(head1,head2->next);
    }
    return(head3);  
  }
  
  void sll::display(node *temp)
  {
   while(temp!=NULL)
    {
      cout << temp->data << "->";
      temp=temp->next;
    }
  }
  
  int main()
  {
    int cx,ch1;
    char c,c1;
    node *head,*head1,*head2,*head3;
    sll s;
    do{
      
      cout << "\nSelect a choice ";
      cout << "\n1.create \n2.display \n3.insert \n4.remove \n5.(createsorted / merge) \n";
      cin >> ch1;
      switch(ch1)
        {
        case 1:
        head=s.create();
        break;
        case 2:
        s.display(head);
        break;
        case 3:
        	do{	
        	   	cout << "\n Select a choice\n ";
        	   	cout << "\n1. insert beg \n2. inser end \n3. inser after\n\n";
        	   	cin >> cx;
        	   	switch(cx)
        	   	{
        	   		case 1:
        	   			head=s.insert_beg(head);
        	   			break;
        	   			case 2:
        	   				s.insert_end(head);
        	   				break;
        	   				case 3:
        	   					s.insert_after(head);
        	   					break;
				         }
				         cout << "\nDo you want to continue\n";
               				 cin >> c1;
                 } while(c1=='y'||c1=='Y');
           break;
        case 4:
         head=s.remove(head);
        break; 
        case 5:
        cout << "\nEmter the list of postitive numbers \n";
        head1=s.createsorted();
        s.display(head1);
        cout << "\n Emter the list of negative numbers \n";
        head2=s.createsorted();
        s.display(head2);
        cout << "\n The sorted list is ";
        head3=s.merge(head1,head2);
        cout << "\n";
        s.display(head3);
        break;
      }
      cout << "\nDo you want to continue\n";
      cin >> c;
    } while(c=='y'||c=='Y');
   return 0;
  }
