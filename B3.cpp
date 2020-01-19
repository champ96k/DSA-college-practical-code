#include<iostream>
#include<string.h>
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
  node * create();
  void display(node *);
  
  int uni(node *head1,node *head2);
  void inter(node *head1,node *head2);
  void sub1(node *head1,node *head2);
  void sub2(node *head1,node *head2);
  
};

node * sll::create()
{
   node *n,*last,*head;
   int val;
   char ch;
   head=NULL;
   do
   {

     cout<<"\nenter the data";
     cin>>val;
     
     n=new node;
     n->data=val;
     //strcpy(n->name,name1);
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
     cout<<"\ndo u want 2 insert more nodes?";
     cin>>ch;
   }while(ch=='y');
  return(head);
}
void sll::display(node *head)
{
  node *temp;
  temp=head;
  while(temp!=NULL)
  {
     cout<<temp->data<<"->";
     temp=temp->next;
  }
}
int sll::uni(node *head1,node *head2)
{
  node *p,*q;
  int found=0,count=0;
  p=head1;
  while(p!=NULL)
  {
    cout<<p->data<<"->";
    p=p->next;
    count++;
   }
   for(q=head2;q!=NULL;q=q->next)
   {
      found=0;
      for(p=head1;p!=NULL;p=p->next)
      {
         if(q->data==p->data)
          {
             found=1;
             break;
           }
       }
       if(found!=1)
       {
         cout<<q->data<<"->";
         count++;
        }
     }
   return count;
} 
void sll::inter(node *head1,node *head2)
{
  node *p,*q;
  int found=0;
  
   for(q=head2;q!=NULL;q=q->next)
   {
      found=0;
      for(p=head1;p!=NULL;p=p->next)
      {
         if(q->data==p->data)
          {
             found=1;
             break;
           }
       }
       if(found==1)
       {
         cout<<q->data<<"->";
         
        }
     }
   
} 
void sll::sub1(node *head1,node *head2)
{
  node *p,*q;
  int found=0;
  
   for(p=head1;p!=NULL;p=p->next)
   {
      found=0;
      for(q=head2;q!=NULL;q=q->next)
      {
         if(p->data==q->data)
          {
             found=1;
             break;
           }
       }
       if(found!=1)
       {
         cout<<p->data<<"->";
         
        }
     }
   
} 
void sll::sub2(node *head1,node *head2)
{
  node *p,*q;
  int found=0;
  
  
   for(q=head2;q!=NULL;q=q->next)
   {
      found=0;
      for(p=head1;p!=NULL;p=p->next)
      {
         if(q->data==p->data)
          {
             found=1;
             break;
           }
       }
       if(found!=1)
       {
         cout<<q->data<<"->";
         
        }
     }
   
} 
int main()
{
  int ch,count=0,m;
  char c;
  node * head,*head1;
  sll s;
  cout<<"\n enter total no of student";
  cin>>m;
  do
  {
    cout<<"\n1.create\n2.like either vanilla or butterscotch\n3.like both vanilla & butterscotc.\n4.like  vanilla only\n5.like  butterscotch only \n6.no of students who like neither vanilla nor butterscotch";
    cout<<"\nenter ur choice";
    cin>>ch;
    switch(ch)
    {
       case 1:cout<<"\nenter list of students who like vanilla";
              head=s.create();
              s.display(head);
              cout<<"\nenter list of students who like butterscotch";
              head1=s.create();
              s.display(head1);
              break;
       case 2:s.inter(head,head1);
            
              break;
       case 3:count=s.uni(head,head1);
              break;
       case 4:s.sub1(head,head1);
              break;
       case 5:s.sub2(head,head1);
              break;
       case 6:cout<<"\n no of students like neither vanilla nor butterscotch= "<<m-count;
              
              break;
      
    }
    cout<<"\ndo u want 2 cont?";
    cin>>c;
  }while(c=='y');
 return 0;
}
