#include<stdio.h>
int main()
{
    int n,i,j,k;
    int c=0,x=0,y=0;
    
    scanf("%d",&n);
    int u=n,v=0;
    int a[n][n];
    for(i=0;i<n;i++)
    {
       /* if(c==16)
        {
            break;
        }
        else*/ if(i%2==0)
        {
            for(j=0;j<n-i;j++)
            {
                c=c+1;
                a[x][y++]=c;
            }
            if(y==(u))
            {
                y=y-1;
                u=u-1;
            }
            for(k=i+1;k<n;k++)
            {c=c+1;
            x=x+1;
                a[x][y]=c;
            }
        }
        else
        {
            for(j=n-i;j>0;j--)
            {c=c+1;
                a[x][--y]=c;
            }

            for(k=i+1;k<n;k++)
            {c=c+1;
                a[--x][y]=c;
            }
            if(y==v)
            {
                y=y+1;
                v=v+1;
            }
        }
        
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}