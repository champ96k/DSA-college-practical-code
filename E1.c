#include<stdio.h>

int main()
{
  int a[10],n,i,j,temp=0;
  printf("How many numbers do u want to enter \n ");
  scanf("%d",&n);
    printf("Enter %d numbers \n ",n);
   for(i=0;i<n;i++)
   {
     scanf("%d",&a[i]);
   }
   printf("\n Numbers which are stored as fallows \n");
  for(i=0;i<n;i++)
   {
     printf("\t %d ",a[i]);
   }
   for(i=0;i<n;i++)
    {
      for(j=0;j<n-1;j++)
      {
       if(a[i]<a[j])
       {
         temp=a[i];
         a[i]=a[j];
         a[j]=temp;
       }
        
      }
    } 
  printf("\n Sorted numbers are: \n\n");
  for(i=0;i<n;i++)
   {
     printf("\t %d ",a[i]);
   }
}
