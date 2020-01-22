/*r.
Sandip Institute of Engineering & Management
A book consists of chapters, chapters consist of sections and sections consist of subsections.
Construct a tree and print the nodes. 
*/

#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
class Tree
  {
     typedef struct node
	{
		char data[10];
		struct node *left;
		struct node * right;
	}btree;
    public:
      btree *New,*root;
      Tree();
      void create();
      void insert(btree *root,btree *New);
      void display();
  };
Tree::Tree()
  {
    root=NULL;
  }

void Tree::create()
  {
     New=new btree;
     New->left=New->right=NULL;
     cout<<"\n\tEnter the Data: ";
     cin>>New->data;
     if(root==NULL)
     	{
		root=New;
	}
     else
        {
		insert(root,New);
        }
   }

void Tree::insert(btree *root,btree *New)
  {
     char ans;
     cout<<"\n\t"<<New->data<<" Want to Insert at "<<root->data<<" at Left(L) OR Right(R)";
	cin>>ans;
     if(ans=='L'||ans=='l')
        {
	    if(root->left==NULL)
		root->left=New;
            else
                insert(root->left,New);
	}
     else
        {
	    if(root->right==NULL)
		root->right=New;
            else 
                insert(root->right,New);
	}	
  }  

void Tree::display()
{
	int i=1;
            if(root==NULL)
             {
              cout<<"\n NULL Tree";
               return;
             }
          queue<btree *> q;
          q.push(root);
	  cout<<"\n\tLevelwise(BFS) Traversal\n";
          while(q.empty()==false)
          {
            btree *node=q.front();
	    if(i==1)
               cout<<node->data<<"\n";
	    if(i==2)
		cout<<node->data<<"\t";
	    if(i==3)
	        cout<<node->data<<"\n";
	    if(i==4||i==5||i==6||i==7)
	   	cout<<node->data<<"\t";
            i++;
            q.pop();
            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
               q.push(node->right);
          }
}
				       


int main()
  {
     Tree tr;
     int i=0;
     do
       {
          if(i==0)
            {
		cout<<"\n\tEnter Chapter Name";
  		tr.create();
  		i++;
            }
          if(i==1||i==2)
            {
		cout<<"\n\tEnter Section Name";
                tr.create();        
                i++;
            }
          if(i==3||i==4||i==5||i==6)
            {
		cout<<"\n\tEnter Sub-Section Name";
                tr.create();        
                i++;
             }
	   if(i==7)
             {
               cout<<"\n tree is:";
		tr.display();
                break;
             }
      }while(1);
   }

/*
siem@CGL:~/Desktop$ g++ ass1.cpp
siem@CGL:~/Desktop$ ./a.out

	Enter Chapter Name
	Enter the Data: 1

	Enter Section Name
	Enter the Data: 1.1

	1.1 Want to Insert at 1 at Left(L) OR Right(R)l

	Enter Section Name
	Enter the Data: 1.2

	1.2 Want to Insert at 1 at Left(L) OR Right(R)r

	Enter Sub-Section Name
	Enter the Data: 1.1.1

	1.1.1 Want to Insert at 1 at Left(L) OR Right(R)l

	1.1.1 Want to Insert at 1.1 at Left(L) OR Right(R)l

	Enter Sub-Section Name
	Enter the Data: 1.1.2

	1.1.2 Want to Insert at 1 at Left(L) OR Right(R)l

	1.1.2 Want to Insert at 1.1 at Left(L) OR Right(R)r

	Enter Sub-Section Name
	Enter the Data: 1.2.1

	1.2.1 Want to Insert at 1 at Left(L) OR Right(R)r

	1.2.1 Want to Insert at 1.2 at Left(L) OR Right(R)l

	Enter Sub-Section Name
	Enter the Data: 1.2.2

	1.2.2 Want to Insert at 1 at Left(L) OR Right(R)r

	1.2.2 Want to Insert at 1.2 at Left(L) OR Right(R)r

 tree is:
	Levelwise(BFS) Traversal
1
1.1	1.2
1.1.1	1.1.2	1.2.1	1.2.2	siem@CGL:~/Desktop$ 
*/
