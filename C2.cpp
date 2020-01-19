/*This program is to implement n-queen's problem using backtracking*/
#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;
class Queen
{
    public:
     int board[20];
     int count=0;
     void queen(int row, int n);
     void print_board(int n);
     int place(int row ,int column);
};
int main()
{
   int n,i,j;
   Queen q;

   cout<<"\n\t Program for queen's using backtracking";
   cout<<"\n\nEnter number of queen's ";
   cin>>n;
   q.queen(1,n);                                      //trace using backtrack
   return 0;
}


/*This function is for printing the solution to n-queen's problem*/
void Queen::print_board(int n)
{
   int i,j;
   cout<<"\n\n solution: "<<++count;
   cout<<"\n\n";
    //number of solution
   for(i=1;i<=n;i++)
   {
     cout<<"\t"<<i;
   }
   for(i=1;i<=n;i++)
   {
     cout<<"\n\n"<<i;
     for(j=1;j<=n;j++)        //for n*n board
     {
        if(board[i]==j)
          cout<<"\tQ";   //Queen at i,j position
        else
          cout<<"\t-";   //empty slot
     }
   }
   cout<<"\n Press any key to continue.....";

}
/*This function is for checking for the conflicts.If there is no conflict for the desired position it returns 1 otherwise it returns 0*/
int Queen::place(int row ,int column)
{
   int i;
   for(i=1;i<=row-1;i++)
   {
      //checking for column and diagonal conflicts
     if(board[i]==column)
       return 0;
     else
       if(abs(board[i]-column)==abs(i-row))
         return 0;
   }
//no conflicts hence Queen can be placed
return 1;
}

/*By this function we try the next free slot and check for proper positioning of queen */
void Queen::queen(int row, int n)
{
   int column;
   for(column=1;column<=n;column++)
   {
     if(place(row,column))
     {
        board[row]=column;   //no conflicts so place queen
        if(row==n)//dead end
           print_board(n);    //printing the board configuration
        else                     //try queen with next position
           queen(row+1,n);
     }
   }
}

/*OUTPUT
Program for n-Queen's using backtracking
Enter number of Queen's 4

Solution 1:
      1     2     3     4
1    -     Q     -     -
2    -     -      -    Q
3   Q     -      -     -
4    -      -     Q    -

Press any key to continue........*/
