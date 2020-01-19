/*Mr. Sujit A. Ahirrao
Sandip Institute of Engineering & Management
Consider telephone book database of N clients. Make use of a hash table implementation to 
quickly look up client‘s telephone number (with Replacement) 
*/
#include<iostream>
#include<string.h>
using namespace std;

class HashFunction
  {
     typedef struct hash
	{
		long key;
		char name[10];
	}hash;
	hash h[10];
   public:
	HashFunction();
	void insert();
	void display();
	int find(long);
	void Delete(long);


  };

HashFunction::HashFunction()
  {
	int i;
	for(i=0;i<10;i++)
	  {
		h[i].key=-1;
		strcpy(h[i].name,"NULL");
	  }
  }
void HashFunction::Delete(long k)
  {
	int index=find(k);
	if(index==-1)
	  {
		cout<<"\n\tKey Not Found";
	  }
	else
	  {
		h[index].key=-1;
		strcpy(h[index].name,"NULL");
		cout<<"\n\tKey is Deleted";
	  }
	
	
  }
int HashFunction::find(long k)
  {
	int i;
	for(i=0;i<10;i++)
	  {
		if(h[i].key==k)
		  {
			cout<<"\n\t"<<h[i].key<<" is Found at "<<i<<" Location With Name "<<h[i].name;
			return i;
		  }
	  }
	if(i==10)
   	  {
		return -1;
	  }

  }

	
void HashFunction::display()
  {
	int i;
	cout<<"\n\t\tKey\t\tName";
	for(i=0;i<10;i++)
 	  {
		cout<<"\n\th["<<i<<"]\t"<<h[i].key<<"\t\t"<<h[i].name;
	  }
  }

void HashFunction::insert()
  {
	char ans,n[10],ntemp[10];
	long k,temp;
	int v,hi,cnt=0,flag=0,i;
	
	do
	  {
		if(cnt>=10)
		  {
			cout<<"\n\tHash Table is FULL";
			break;
		  }
		cout<<"\n\tEnter a Telephone No: ";
		cin>>k;
		cout<<"\n\tEnter a Client Name: ";
		cin>>n;
		hi=k%10;// hash function
		if(h[hi].key==-1)
		  {
			h[hi].key=k;
			strcpy(h[hi].name,n);
		  }
	     else
 		  {
			
			if(h[hi].key%10!=hi)
			  {
				temp=h[hi].key;
				strcpy(ntemp,h[hi].name);
				h[hi].key=k;
				strcpy(h[hi].name,n);
				for(i=hi+1;i<10;i++)
			  	  {
					if(h[i].key==-1)
				  	  {
						h[i].key=temp;
						strcpy(h[i].name,ntemp);
						flag=1;
						break;
				   	  }
			  	  }
				for(i=0;i<hi && flag==0;i++)
			  	  {
					if(h[i].key==-1)
				  	  {
						h[i].key=temp;
						strcpy(h[i].name,ntemp);
						break;
				   	  }
			         }
		  	  }
			else
			  {
				for(i=hi+1;i<10;i++)
			  	  {
					if(h[i].key==-1)
				  	  {
						h[i].key=k;
						strcpy(h[i].name,n);
						flag=1;
						break;
				   	  }
			  	  }
				for(i=0;i<hi && flag==0;i++)
			  	  {
					if(h[i].key==-1)
				  	  {
						h[i].key=k;
						strcpy(h[i].name,n);
						break;
				   	  }
			       }
			  }	
			
		  }
	    	flag=0;
	     cnt++;
	     cout<<"\n\t..... Do You Want to Insert More Key: ";
	     cin>>ans;
	  }while(ans=='y'||ans=='Y');
	
  }
			


main()
  {
	long k;
	int ch,index;
	char ans;
	HashFunction obj;
	do
	  {
		cout<<"\n\t***** Dictionary (ADT) *****";
		cout<<"\n\t1. Insert\n\t2. Display\n\t3. Find\n\t4. Delete\n\t5. Exit";
		cout<<"\n\t..... Enter Your Choice: ";
		cin>>ch;
		switch(ch)
		  {
			case 1: 	obj.insert();
					break;
			case 2:	obj.display();
					break;
			case 3:	cout<<"\n\tEnter a Key Which You Want to Search: ";
					cin>>k;			
					index=obj.find(k);
					if(index==-1)
					  {
						cout<<"\n\tKey Not Found";
					  }
					break;
			case 4:	cout<<"\n\tEnter a Key Which You Want to Delete: ";
					cin>>k;			
					obj.Delete(k);
					break;
			case 5:
					break;
		  }
		cout<<"\n\t..... Do You Want to Continue in Main Menu: ";
		cin>>ans;
	  }while(ans=='y'||ans=='Y');
  }

/*
siem@siem-OptiPlex-3010:~/Desktop$ g++ hash3.cpp
siem@siem-OptiPlex-3010:~/Desktop$ ./a.out

	***** Dictionary (ADT) *****
	1. Insert
	2. Display
	3. Find
	4. Delete
	5. Exit
	..... Enter Your Choice: 1

	Enter a Telephone No: 1234567856

	Enter a Client Name: aa

	..... Do You Want to Insert More Key: y

	Enter a Telephone No: 1234567877

	Enter a Client Name: bb

	..... Do You Want to Insert More Key: y

	Enter a Telephone No: 1234567888

	Enter a Client Name: cc

	..... Do You Want to Insert More Key: y

	Enter a Telephone No: 1234567899

	Enter a Client Name: dd

	..... Do You Want to Insert More Key: n

	..... Do You Want to Continue in Main Menu: y

	***** Dictionary (ADT) *****
	1. Insert
	2. Display
	3. Find
	4. Delete
	5. Exit
	..... Enter Your Choice: 2

		Key		Name
	h[0]	-1		NULL
	h[1]	-1		NULL
	h[2]	-1		NULL
	h[3]	-1		NULL
	h[4]	-1		NULL
	h[5]	-1		NULL
	h[6]	1234567856		aa
	h[7]	1234567877		bb
	h[8]	1234567888		cc
	h[9]	1234567899		dd
	..... Do You Want to Continue in Main Menu: y

	***** Dictionary (ADT) *****
	1. Insert
	2. Display
	3. Find
	4. Delete
	5. Exit
	..... Enter Your Choice: 1

	Enter a Telephone No: 1234567890

	Enter a Client Name: ee

	..... Do You Want to Insert More Key: n

	..... Do You Want to Continue in Main Menu: y

	***** Dictionary (ADT) *****
	1. Insert
	2. Display
	3. Find
	4. Delete
	5. Exit
	..... Enter Your Choice: 2

		Key		Name
	h[0]	1234567890		ee
	h[1]	-1		NULL
	h[2]	-1		NULL
	h[3]	-1		NULL
	h[4]	-1		NULL
	h[5]	-1		NULL
	h[6]	1234567856		aa
	h[7]	1234567877		bb
	h[8]	1234567888		cc
	h[9]	1234567899		dd
	..... Do You Want to Continue in Main Menu: y

	***** Dictionary (ADT) *****
	1. Insert
	2. Display
	3. Find
	4. Delete
	5. Exit
	..... Enter Your Choice: 1

	Enter a Telephone No: 1234567887

	Enter a Client Name: ff

	..... Do You Want to Insert More Key: n

	..... Do You Want to Continue in Main Menu: y

	***** Dictionary (ADT) *****
	1. Insert
	2. Display
	3. Find
	4. Delete
	5. Exit
	..... Enter Your Choice: 2

		Key		Name
	h[0]	1234567890		ee
	h[1]	1234567887		ff
	h[2]	-1		NULL
	h[3]	-1		NULL
	h[4]	-1		NULL
	h[5]	-1		NULL
	h[6]	1234567856		aa
	h[7]	1234567877		bb
	h[8]	1234567888		cc
	h[9]	1234567899		dd
	..... Do You Want to Continue in Main Menu: y

	***** Dictionary (ADT) *****
	1. Insert
	2. Display
	3. Find
	4. Delete
	5. Exit
	..... Enter Your Choice: 1

	Enter a Telephone No: 1234567891

	Enter a Client Name: gg

	..... Do You Want to Insert More Key: n

	..... Do You Want to Continue in Main Menu: y

	***** Dictionary (ADT) *****
	1. Insert
	2. Display
	3. Find
	4. Delete
	5. Exit
	..... Enter Your Choice: 2

		Key		Name
	h[0]	1234567890		ee
	h[1]	1234567891		gg
	h[2]	1234567887		ff
	h[3]	-1		NULL
	h[4]	-1		NULL
	h[5]	-1		NULL
	h[6]	1234567856		aa
	h[7]	1234567877		bb
	h[8]	1234567888		cc
	h[9]	1234567899		dd
	..... Do You Want to Continue in Main Menu: y

	***** Dictionary (ADT) *****
	1. Insert
	2. Display
	3. Find
	4. Delete
	5. Exit
	..... Enter Your Choice: 3

	Enter a Key Which You Want to Search: 1234567887

	1234567887 is Found at 2 Location With Name ff
	..... Do You Want to Continue in Main Menu: y

	***** Dictionary (ADT) *****
	1. Insert
	2. Display
	3. Find
	4. Delete
	5. Exit
	..... Enter Your Choice: 4

	Enter a Key Which You Want to Delete: 1234567888

	1234567888 is Found at 8 Location With Name cc
	Key is Deleted
	..... Do You Want to Continue in Main Menu: y

	***** Dictionary (ADT) *****
	1. Insert
	2. Display
	3. Find
	4. Delete
	5. Exit
	..... Enter Your Choice: 2

		Key		Name
	h[0]	1234567890		ee
	h[1]	1234567891		gg
	h[2]	1234567887		ff
	h[3]	-1		NULL
	h[4]	-1		NULL
	h[5]	-1		NULL
	h[6]	1234567856		aa
	h[7]	1234567877		bb
	h[8]	-1		NULL
	h[9]	1234567899		dd
	..... Do You Want to Continue in Main Menu: 
*/

