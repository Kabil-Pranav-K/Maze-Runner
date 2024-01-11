#include<stdio.h>
#include<stdlib.h>
int matrixsol(int matrixcrea[],int n,int total)
{
    int s1,s2,d1,d2,b1,b2,g,x,r,x1,x2;
    printf("\nenter the starting point of the robot");
    scanf("%d %d",&s1,&s2);
    printf("\nenter the destination point of the robot");
    scanf("%d %d",&d1,&d2);
    s1=s1-1;
    s2=s2-1;
    //calculating the computarized value of s1,s2,d1,d2 
    d1=d1-1;
    d2=d2-1;
    b1=(n*s1)+s2;  //starting point
    matrixcrea[b1]=2;
    b2=(n*d1)+d2;  //ending point
    if(b2==(n*(s1-1))+(s2)||b2==(n*(s1))+(s2-1)||b2==(n*(s1+1))+s2||b2==(n*(s1))+(s2+1))
    {
        matrixcrea[b2]=2;
    }
    else
    {
        do
        {
            g=-1;
            do
            {
                do
                {
                    r=rand()%4;
                    while(r==g)
                    {
                        r=rand()%4;
                    }
                    if(r==0)
                    {
                        x=(n*(s1-1))+s2;  //top
                        x1=s1-1;
                        x2=s2;
                    }
                    else if(r==1)
                    {
                        x=(n*(s1+1))+s2;  //bottom
                        x1=s1+1;
                        x2=s2;
                    }
                    else if(r==2)
                    {
                        x=(n*s1)+s2+1;  //right
                        x1=s1;
                        x2=s2+1;
                    }
                    else
                    {
                        x=(n*s1)+s2-1;  //left
                        x1=s1; 
                        x2=s2-1;
                    }
                    g=r;
                }
                while(x<0||x>((n*n)-1)||x1<0||x1>(n-1)||x2<0||x2>(n-1));
            }
            while(matrixcrea[x]==0||matrixcrea[x]==2);
            matrixcrea[x]=2;
            s1=x1;
            s2=x2;
        }
        while(x!=b2);
    }
    printf("\n 2 is the path of the robot");
    printf("\n");
    int i,b;
    b=n;
    for(i=0;i<total;i++)
    {
        if(i==b)
        {
            printf("\n");
            b=b+n;
        }
        printf("%d ",matrixcrea[i]);
    }
}












int matrixrep(int matrixcrea[],int n,int total)
{
    int i,b;
    b=n;
    for(i=0;i<total;i++)
    {
        if(i==b)
        {
            printf("\n");
            b=b+n;
        }
        printf("%d ",matrixcrea[i]);
    }
    printf("\n Here 1 is non-obstacle and 0 is obstacle");
    matrixsol(matrixcrea,n,total);  //calling matrixsol function
}






int matrixcre(int n)
{
    int a,r,total;
    total=n*n;               //calculating the number of elements in the matrix n*n
    int matrixcrea[total];  //array has been created in the name of matrixcrea
    for(a=0;a<total;a++)
    {
        matrixcrea[a]=1;   
    }
    r=rand()%total;        
    for(a=0;a<=r;a++)
    {
        r=rand()%total;
        matrixcrea[r]=0;
    }
    matrixrep(matrixcrea,n,total);  //calling matrixrep function
}




int main()
{
    int n;
    printf("enter number for creating matrix(where n>1 or n<=4)");
    scanf("%d",&n);  //entering the number of rows and columns
    matrixcre(n);   //calling matrixcre function
}