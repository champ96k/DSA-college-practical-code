#include<iostream>
#include<string.h>
using namespace std;
int main()
  {
    int ch;
    char ans;
    char str1[50],str2[50];
    int len;
    do
      {
        cout<<"\n\t*********String Operation**********";
        cout<<"\n\t1.String length\n\t2.String Reverse\n\t3.String Copy\n\t4.String Campare\n\t5.String Combine ";
        cout<<"\n\t....Enter Your Choice: ";
        cin>>ch;
        switch(ch)
          {
                case 1:         cout<<"\n\tEnter A String: ";
                                cin>>str1;
                                len=strlen(str1);
                                cout<<"\n\tThe Length Of "<<str1<<" string Is: "<<len;
                                break;
                case 2:         char rev[10];
                                cout<<"\n\tEnter a String: ";
	                        cin>>str1;
	                        //strrev(str1);
                        	cout<<"The Reverse String is: "<<str1;
                                break;
                case 3:         cout<<"\n\tEnter A First String: ";
                                cin>>str1;
                                cout<<"\n\tEnter A Second String: ";
                                cin>>str2;
                                strcpy(str1,str2);
                                cout<<"\n\tThe Copy String Is "<<str2;
                                break;
                case 4:         cout<<"\n\tEnter A First String: ";
                                cin>>str1;
                                cout<<"\n\tEnter A Second String: ";
                                cin>>str2;
                                strcmp(str1,str2);
                                if(strcmp (str1,str2)==0)
                                  {
                                    cout<<"\n\tBoth String Is Equal ";
                                  }
                                else if(strcmp(str1,str2)==1)
                                  {
                                    cout<<"\n\tFirst String Is Greater Than Second";
                                  }
                                else
                                  {
                                    cout<<"\n\tSecond String Is Greater Than First";
                                  }
                                break;
               case 5:          cout<<"\n\tEnter A First String: ";
                                cin>>str1;
                                cout<<"\n\tEnter A Second String: ";
                                cin>>str2;
                                strcat(str1,str2);
                                cout<<"\n\tThe Combine String Is "<<str1;
                                break; 
          }
        cout<<"\n\tDo You Want To Continue: ";
        cin>>ans;
      }while(ans=='Y' || ans=='y');
    return 0;
  }
  
  
  
  
  
  
  
  
  
  
  
