/*
 create the ADT that impleents set concept
 1. add(new element) place a value into the set
 2.remove
 3.contains return a true if element is in collection
 4.size returns no. of values in collection
 5.intersection of two sets
 6.union of two sets
*/
#include<iostream>
using namespace std;

class SetADT
  {
	int set1[10];
	int set2[10];
	int set3[10];
	public:
		SetADT();
		void add(int);
		void display();
		int find(int,int);
		int Delete(int,int);
		void size();
		void intersection();
		void Union();

  };
SetADT::SetADT()
  {
	int i;
	for(i=0;i<10;i++)
 	  {
		set1[i]=-1;
		set2[i]=-1;
		set3[i]=-1;
	  }
  }
void SetADT::Union()
  {
	int i,j,k=0;
	for(i=0;i<10;i++)
	  {
		if(set1[i]!=-1)
		  {
			set3[k]=set1[i];
			k++;
		  }
	  }
	for(i=0;i<10;i++)
	  {
		for(j=0;j<10;j++)
		  {
			if(set2[i]==set1[j])
			  {
				break;	
			  }
		  }
		if(j==10)
		  {
			set3[k]=set2[i];
			k++;
			
		  }
	  }
	cout<<"\n\tUnion set3 = {";
	for(i=0;i<k;i++)
	  {
		cout<<set3[i]<<", ";
	  }
	cout<<"\b\b }";
  }

void SetADT::intersection()
  {
	int i,j,k=0;
	for(i=0;i<10;i++)
	  {
		for(j=0;j<10;j++)
		  {
			if(set1[i]==set2[j])
			  {
				set3[k]=set1[i];
				k++;
				break;
			  }
		  }
	  }
	cout<<"\n\tIntersection set3 = {";
	for(i=0;i<k;i++)
	  {
		if(set3[i]!=-1)
		  cout<<set3[i]<<", ";
	  }
	cout<<"\b\b }";
  }

void SetADT::size()
  {
	int cnt1=0,cnt2=0,i;
	for(i=0;i<10;i++)
	  {
		if(set1[i]!=-1)
		  cnt1++;
		if(set2[i]!=-1)
		  cnt2++;
	  }
	cout<<"\n\tSize of Set 1 is "<<cnt1;
	cout<<"\n\tSize of Set 2 is "<<cnt2;
  }
int SetADT::Delete(int ch,int s)
  {
	int index=find(ch,s);
	if(s==1 && index!=-1)
	  {
		set1[index]=-1;
		return index;
       }
	if(s==2 && index!=-1)
	  {
		set2[index]=-1;
		return index;
       }
	return index;
  }

int SetADT::find(int ch, int s)
  {
	int i;
	for(i=0;i<10;i++)
	  {
		if(s==1 && set1[i]==ch)
		  {
			return i;
		  }
		if(s==2 && set2[i]==ch)
		  {
			return i;
		  }
	  }
	return -1;
  }

void SetADT::display()
  {
	int i;
	cout<<"\n\tSet 1 = { ";
	for(i=0;i<10;i++)
	  {
		if(set1[i]!=-1)
		  {
			cout<<set1[i]<<",";
		  }
	  }
	cout<<"\b }";
  	cout<<"\n\tSet 2 = { ";
	for(i=0;i<10;i++)
	  {
		if(set2[i]!=-1)
		  {
			cout<<set2[i]<<",";
		  }
	  }
	cout<<"\b }";
  }
		
void SetADT::add(int ch)
  {
	int cnt=0,i;
	char ans;
	do
	  {
		if(cnt>=10)
		  {
			cout<<"\n\tSet is Full";
			break;
		   }
		cout<<"\n\tEnter a Element: ";
		for(i=0;i<10;i++)
		  {
			 if(ch==1 && set1[i]==-1)
			   {
				cin>>set1[i];
				cnt++;
				break;
			   }
			  if(ch==2 && set2[i]==-1)
			   {
				cin>>set2[i];
				cnt++;
				break;
			   }
		  }
		cout<<"\n\t..... Do You Want Add More Elements: ";
		cin>>ans;
	  }while(ans=='y'||ans=='Y');
	display();
  }
			

main()
  {
  	SetADT obj;
	int ch,index,s;
	char ans;
	do
	  {
		cout<<"\n\t****** Set ADT ******";
		cout<<"\n\t1. Add\n\t2. Remove\n\t3. Find\n\t4. Size";
		cout<<"\n\t5. Intersection\n\t6. Union\n\t7. Exit";
		cout<<"\n\t...... Enter Choice: ";
		cin>>ch;
		switch(ch)
		  {
			case 1:	cout<<"\n\tYou Want Add Elemements in Set 1( Type 1) or Set 2(Type 2): ";
					cin>>ch;
					obj.add(ch);
					break;
			case 2:	cout<<"\n\tEnter a Element You Want to Delete: ";
					cin>>ch;
					cout<<"\n\tYou Want Delete Elemements in Set 1( Type 1) or Set 2(Type 2): ";
					cin>>s;
					index=obj.Delete(ch,s);
					if(index==-1)
					  {
						cout<<"\n\tElement Not Found";
					  }
					else
					  {
						cout<<"\n\tElement "<<ch<<" id Deleted from Location "<<index+1;
						obj.display();
					  }
					break;
			case 3:	cout<<"\n\tEnter a Element You Want to Search: ";
					cin>>ch;
					cout<<"\n\tYou Want Search Elemements in Set 1( Type 1) or Set 2(Type 2): ";
					cin>>s;
					index=obj.find(ch,s);
					if(index==-1)
					  {
						cout<<"\n\tElement Not Found";
					  }
					else
					  {
						cout<<"\n\tElement "<<ch<<" Found at Location "<<index+1;
					  }
					break;
			case 4:		obj.display();
					obj.size();
					break;
			case 5:		obj.intersection();
					break;
			case 6:		obj.Union();
					break;
			case 7:
					break;
			
		  }
		cout<<"\n\t..... Do You Want to Continue in Main Menu: ";
		cin>>ans;
	  }while(ans=='y'||ans=='Y');
  }
