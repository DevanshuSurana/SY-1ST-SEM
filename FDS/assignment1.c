/*
 ============================================================================
 Name        : lab1c
 Author      : Devanshu Surana
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>


void accept(int arr[10][10],int r,int c);

void display(int arr[10][10],int r,int c);

void add(int arr[10][10],int a[10][10],int b[10][10],int r,int c);

void substract(int arr[10][10],int a[10][10],int b[10][10],int r,int c);

void multipliaction(int arr[10][10],int a[10][10],int b[10][10],int r,int c,int row1,int col2,int col1);

void Transpose(int arr[10][10],int a[10][10],int r,int c);

int main()
{
    int a[10][10],b[10][10],c[10][10];
    int row1,col1,row2,col2,row3,col3;
    int change;


    printf("no of rows and columns of matrix 1:\n");
    scanf("%d%d",&row1,&col1);
    accept(a,row1,col1);
    display(a,row1,col1);


    printf("no of rows and columns of matrix 2:\n");
    scanf("%d%d",&row2,&col2);
    accept(b,row2,col2);
    display(b,row2,col2);


    printf("\nEnter choices:\n1.Addition\n2.Substraction\n3.Multipliaction\n4.Transpose");
    scanf("%d",&change);
        switch (change)
        {
            case 1:

            if
             ((row1==row2) && (col2==col1))
             {  row3=row1;
                col3=col1;
                 add(c,a,b,row3,col3);
             display(c,row3,col3);}
            else
             { printf ("can't be added\n");}
            break;

            case 2:
            if ((row1==row2) && (col2==col1))
             {  row3=row1;
                col3=col1;
                 substract(c,a,b,row3,col3);
             display(c,row3,col3);}
            else
             {printf ("can't be substracted \n");}
            break;


            case 3:
            if (row1==col2)
             {  row3=row1;
                col3=col2;
                 multipliaction(c,a,b,row3,col3,row1,col2,col1);
             display(c,row3,col3);}
            else
             {printf ("can't be multiplied \n");}
            break;

            case 4:
                {row3=col1;
                 col3=row1;
                 Transpose(c,a,row3,col3);
                 display(c,row3,col3);}
            break;

            default:
             printf("NOT APPLICABLE\n");
        }
return 0;

}


void accept(int arr[10][10],int r,int c)
    {
    int j,i;
    printf("enter elements of matrix\n");
    for(i=0;i<=(r-1);i++)
        {
            for(j=0;j<=c-1;j++)
            {
                scanf("%d",&arr[i][j]);

            }
        }
    }


void display(int arr[10][10],int r,int c)
{
    int j,i;
    for(i=0;i<=r-1;i++)
    {printf("\n");
        for(j=0;j<=c-1;j++)
        {
        printf("%d\t",arr[i][j]);
        }
    }
}

void add(int arr[10][10],int a[10][10],int b[10][10],int r,int c)
{
    int i,j;

    for(i=0;i<=r-1;i++)
        {

        for(j=0;j<=c-1;j++)
        { arr[i][j]=a[i][j]+b[i][j]; }
        }
}

void substract(int arr[10][10],int a[10][10],int b[10][10],int r,int c)
{
    int i,j;

    for(i=0;i<=r-1;i++)
    {

        for(j=0;j<=c-1;j++)
        { arr[i][j]=a[i][j]-b[i][j]; }
    }
}

void multipliaction(int arr[10][10],int a[10][10],int b[10][10],int r,int c,int row1,int col2,int col1)
{
    int i,j,k;

    for(i=0;i<=row1-1;i++)
    {

        for(j=0;j<=col2-1;j++)
            {for(k=0;k<=col1-1;k++)
             {arr[i][j]=0;
             arr[i][j]=arr[i][j]+a[i][k]*b[k][j];}
            }
    }
}
void Transpose(int arr[10][10],int a[10][10],int r,int c)
{
    int i,j;

    for(i=0;i<=r-1;i++)
    {

        for(j=0;j<=c-1;j++)
        { arr[i][j]=a[j][i]; }
    }
}

