#include<iostream>
using namespace std;

struct student
  {
    int roll;
    char name[10];
    int marks;
  };
  
int main()
  {
    struct student s[10];
    int i,n,j,ch,max,min,p,q;
    float sum=0,avg;
    char ch1;
    cout<<"\n\tEnter Number of Students of Class";
    cin>>n;
    
    for(i=0;i<n;i++)
      {
        cout<<"\n\tEnter Roll no. , Name & Marks of Student";
        cin>>s[i].roll>>s[i].name>>s[i].marks;
      }
    cout<<"\n\tRoll\tName\tMarks";
    
    for(i=0;i<n;i++)
      {
        cout<<"\n\t"<<s[i].roll<<"\t"<<s[i].name<<"\t"<<s[i].marks;
      }
      
    do
      {
        cout<<"\n1.Average score of class\n2.Highest & Lowest score of class\n3.Marks scored by most of the student\n4.List of absent student";
        cout<<"\nEnter your Choice : ";
        cin>>ch;
        switch(ch)
          {
            case 1:  for(i=0;i<n;i++)
            		{
            		  sum=sum+s[i].marks;
            		}
            	     avg=sum/n;
            	     cout<<"\nAverage score of class"<<avg;
            	     break;
             
            case 2:  max=0;
            	     for(i=0;i<n;i++)
            	       {
            	         if(s[i].marks>max)
            	           {
            	             max=s[i].marks;
            	           }
            	       }
            	       cout<<"\nHighest score="<<max;
            	       min=9999;
            	       for(i=0;i<n;i++)
            	         {
            	           if(s[i].marks!=0)
            	           {
            	             if(s[i].marks<min)
            	               {
            	                 min=s[i].marks;
            	               }
               	           }
            	         }
            	       cout<<"\nLowest score="<<min;
            	      break; 
            case 3: 
            	    p=0;q=0;
            	    for(i=0;i<n;i++)
            	      {
            	        p=0;
            	        for(j=i=1;j<n;j++)
            	          {
            	            if(s[j].marks!=0 && s[i].marks!=0)
            	              {
            	                if(s[j].marks==s[i].marks)
            	                  {
            	                    p++;
            	                  }
            	              }
            	          }
            	            if(p>q)
            	              {
            	                q=p;
            	                cout<<"\nMarks scored by most of the Students"<<s[i].marks<<" by "<<q+1<<" Student\n";
            	              }
            	      }
            	      break;
            case 4:
                    for(i=0;i<n;i++)
                      {
                        if(s[i].marks==0)
                          {
                            cout<<"\n"<<s[i].roll<<"\t"<<s[i].name<<"\t"<<s[i].marks<<"\n";
                          }
                      }
                      break;
          }
          cout<<"\nDo you want to Continue..(Y/N) : ";
          cin>>ch1;
             }while(ch1=='Y'||ch1=='y');
                
  }
