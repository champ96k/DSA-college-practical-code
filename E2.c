#include<stdio.h>

int main()
{
  int a[40],n,i,j,temp=0;
  printf("How many numbers do u want to enter \n ");
  scanf("%d",&n);
    printf("Enter %d numbers \n ",n);
   for(i=0;i<n;i++)
   {
     scanf("%d",&a[i]);
   }
   for(i=1;i<=n-1;i++)
    {
      temp=a[i];
      j=i-1;
      while((temp<a[j])&&(a[j]>=0))
      {
      	a[j+1]=a[j];
      	j=j-1;
	  }
        a[j+1]=temp;
      } 
  printf("\n Sorted numbers are: \n\n");
  for(i=0;i<n;i++)
   {
     printf("\t %d ",a[i]);
   }
   return 0;
}
