#include<stdio.h>
void combination(char arr[],char data[],int start,int end,int index,int con_size);
void printCombination(char arr[], int arr_size, int con_size)
{
  char data[con_size];
  combination(arr, data, 0, arr_size-1, 0, con_size);
}
void combination(char arr[],char data[],int start,int end,int index,int con_size)
{
 int i,j;
 if (index == con_size)
 {
    for(j=0;j<con_size;j++)
    {
    printf("%c",data[j]);
    }
    printf("\n");
    return; 
  }
  else
  {
    for (i=start; i<=end && end-i+1 >= con_size-index; i++)
    {
        data[index] = arr[i];
        combination(arr, data, i+1, end, index+1, con_size);
    }
  }
}
int main()
{
  char arr[]={'a','b','2','d','4','f','G','5'};
  int con_size=4;
  int arr_size=sizeof(arr);
  printCombination(arr,arr_size,con_size);
}

