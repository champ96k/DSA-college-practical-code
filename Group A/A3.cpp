/*Mr. Sujit A. Ahirrao
Sandip Institute of Engineering & Management
For given expression eg. a-b*c-d/e+f construct inorder sequence and 
traverse it using postorder traversal(non recursive). 	 
*/
#include<stdio.h>
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class Tree 
{
	typedef struct node
	{
		char data[10];
		struct node *left,*right;
	}btree;

	
	public:
	
	btree *root,*New;
	Tree();
	void create();
	void insert(btree *root, btree *New);
        void display();
	void recursive();
	void rec_postorder(btree *root);
  	void nonrecursive();
        void nonrec_postorder(btree *root);
};

	Tree::Tree()
	{
		root=NULL;
	}

void Tree::recursive()
{
   rec_postorder(root);
}
void Tree::rec_postorder(btree *root)
  {
    if(root!=NULL)
  	{
		rec_postorder(root->left);
		rec_postorder(root->right);
		cout<<"\t"<<root->data;
        }
  }
void Tree::nonrecursive()
  {
     nonrec_postorder(root);
   }
void Tree::nonrec_postorder(btree *root)
{
        if(!root)
        {
                 cout<<"\n Tree empty";
                        return;
               }
          stack<btree *> s;
          stack<btree *> op;
          s.push(root);
          while(!s.empty())
          {
                btree *curr=s.top();
                op.push(curr);
                s.pop();
                if(curr->left)
                        s.push(curr->left);
               if(curr->right)
                        s.push(curr->right);
            }
           while(!op.empty())
           {
                        cout<<op.top()->data<<"\t";
                        op.pop();
             }
 }
	void Tree::create()
	{

		New=new btree;
		cout<<"\n Enter the data which you want :- ";
		cin>>New->data;
		New->left = NULL;
		New->right= NULL;

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
		cout<<"\n\n You wnat to insert "<<New->data<<" at left or right child of "<<root->data<<" : ";
		cin>>ans;
		if(ans=='l'|| ans=='L')
		{
			if(root->left==NULL)
			{
				root->left=New;
			}
			else
			{
				insert(root->left,New);
			}
		}
		else
		{
			if(root->right==NULL)
			{
				root->right=New;
			}
			else
			{
				insert(root->right,New);
			}
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
		int ch;
		char ans;
		do
		{
			cout<<"\n\tExpression Tree ";
			cout<<"\n\t1. Create\n\t2. Display\n\t3. Exit\n\t..... Enter Your Choice: ";
			cin>>ch;
			switch(ch)
			{
				case 1:
					do
					{
						tr.create();
						cout<<"\n\t Do You Want to Insert More Elements: ";
						cin>>ans;
					}while(ans=='y'||ans=='Y');
					tr.display();
					break;
				case 2:
					cout<<"\n\t\t*****Display \n\t\t1. Recursive\n\t\t2. Non Recursive";
					cout<<"\n\t\t....Enter Your Choice: ";
					cin>>ch;
					switch(ch)
					{
						case 1: cout<<"\n\tRecursive Postorder Traversal\n";
							tr.recursive();
							break;
						case 2: cout<<"\n\tNon Recursive Postorder Traversal\n";
							tr.nonrecursive();
							break;
					}
					break;
				case 3:
					break;
			}
			cout<<"\n\t..... Do You Want to Continue: ";
			cin>>ans;
		}while(ans=='y'||ans=='Y');
		return(0);
	}
/*
siem@CGL:~/Desktop$ g++ ass2exp.cpp
siem@CGL:~/Desktop$ ./a.out

	Expression Tree 
	1. Create
	2. Display
	3. Exit
	..... Enter Your Choice: 1

 Enter the data which you want :- +

	 Do You Want to Insert More Elements: y

 Enter the data which you want :- a


 You wnat to insert a at left or right child of + : l

	 Do You Want to Insert More Elements: y

 Enter the data which you want :- *


 You wnat to insert * at left or right child of + : r

	 Do You Want to Insert More Elements: y

 Enter the data which you want :- b


 You wnat to insert b at left or right child of + : r


 You wnat to insert b at left or right child of * : l

	 Do You Want to Insert More Elements: y

 Enter the data which you want :- c


 You wnat to insert c at left or right child of + : r


 You wnat to insert c at left or right child of * : r

	 Do You Want to Insert More Elements: n

	Levelwise(BFS) Traversal
+
a	*
b	c	
	..... Do You Want to Continue: y

	Expression Tree 
	1. Create
	2. Display
	3. Exit
	..... Enter Your Choice: 2

		*****Display 
		1. Recursive
		2. Non Recursive
		....Enter Your Choice: 1

	Recursive Postorder Traversal
	a	b	c	*	+
	..... Do You Want to Continue: y

	Expression Tree 
	1. Create
	2. Display
	3. Exit
	..... Enter Your Choice: 2

		*****Display 
		1. Recursive
		2. Non Recursive
		....Enter Your Choice: 2

	Non Recursive Postorder Traversal
a	b	c	*	+	
	..... Do You Want to Continue: n
siem@CGL:~/Desktop$ 
*/


