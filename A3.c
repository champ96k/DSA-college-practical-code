#include<stdio.h>
void main()
{
        int r,c,a[10][10],val,k,i,j,m[10],flag=1,z=0;
        printf("\n Enter the number of rows: ");
        scanf("%d",&r);
        printf("\n Enter the number of Columns: ");
        scanf("%d",&c);

        printf("\n Enter the elements: ");
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                scanf("%d",&a[i][j]);

        printf("\n Enterd Matrix is: \n");

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                printf("%d  ",a[i][j]);
            printf("\n");
        }

        for(k=1;k<=2;k++)
        {
            for(i=0;i<r;i++)
            {
                m[i]=a[i][0];
                for(j=1;j<c;j++)
                {
                    if(flag*m[i]<flag*a[i][j])
                        m[i]=a[i][j];
                }
            }

            for(i=0;i<c;i++)
            {
                val=a[0][i];
                for(j=1;j<r;j++)
                {
                    if(flag*val>flag*a[j][i])
                        val=a[j][i];
                }
                for(j=0;j<r;j++)
                {
                    if(val==a[j][i] && val==m[j])
                    {
                        printf("\n Saddle point = %d at location a[%d][%d]",val,j,i);
                        z=1;
                    }
                }
            }
        flag=-1;
        }
    if(z==0)
    {
        printf("\n No saddle point exist in given matrix");
    }
}



